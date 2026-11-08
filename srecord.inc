;==============================================================================
; MOTOROLA S-RECORD
;==============================================================================

format binary as 's19'

; Configuration Settings:
SRECORD.force_addr_bytes    = 4               ; 0 = Auto, 2 = S1/S9, 3 = S2/S8, 4 = S3/S7
SRECORD.chunk_size          = 32              ; Data bytes per line (e.g. 16, 32, 64)
SRECORD.header_text         = 'test'          ; Custom S0 header text (set to '' for blank)
SRECORD.enable_record_count = 0               ; 1 = Emit S5/S6 line count record, 0 = Disable
SRECORD.eol_mode            = 0               ; 0 = CRLF (13,10), 1 = LF (10)

; Global State Initialization
if SRECORD.force_addr_bytes > 0
   SRECORD.addr_bytes = SRECORD.force_addr_bytes
else
   SRECORD.addr_bytes = 2
end if

SRECORD.is_virtual_open   = 0
SRECORD.entry_addr        = -1
SRECORD.data_record_count = 0

virtual at 0
   HexDigits::
   db '0123456789ABCDEF'
end virtual

macro SRECORD.emit_eol
   if SRECORD.eol_mode = 1
      db 10
   else
      db 13, 10
   end if
end macro

macro SRECORD.hex_db value*
   val = value and 0FFh
   load d1:1 from HexDigits : (val shr 4)
   load d2:1 from HexDigits : (val and 0Fh)
   db d1, d2
end macro

macro SRECORD.byte value*
   SRECORD.checksum = (SRECORD.checksum + value) and 0FFh
   SRECORD.hex_db value
end macro

macro SRECORD.line rectype_char*, address*, addr_bytes*, buffer_area:0, data_addr:0, data_len:0
   local b, addr_val
   SRECORD.checksum = 0
   db 'S', rectype_char
   SRECORD.byte (addr_bytes + data_len + 1)

   addr_val = (address) bswap addr_bytes

   repeat addr_bytes
      SRECORD.byte addr_val and 0FFh
      addr_val = addr_val shr 8
   end repeat

   repeat data_len
      load b:1 from buffer_area : (data_addr + % - 1)
      SRECORD.byte b
   end repeat

   SRECORD.hex_db (not SRECORD.checksum)
   SRECORD.emit_eol
end macro

macro SRECORD.emit_header text*
   local area
   virtual at 0
      area::
      db text
   end virtual
   SRECORD.line '0', 0, 2, area, 0, lengthof text
end macro

macro SRECORD.seg address:0
   SRECORD.is_virtual_open = 1
   local area
   SRECORD.current_area = area
   virtual at address
      area::
end macro

macro SRECORD.endseg
   if SRECORD.is_virtual_open
      SRECORD.is_virtual_open = 0
      local address, size, end_addr, chunk, addr_bytes, cur_addr, area
      address = $$
      size = $ - $$
      area = SRECORD.current_area
      end virtual

      if size > 0
         if SRECORD.entry_addr = -1
            SRECORD.entry_addr = address
         end if

         if SRECORD.force_addr_bytes > 0
            addr_bytes = SRECORD.force_addr_bytes
         else
            end_addr = address + size - 1
            addr_bytes = 2
            if end_addr > 0FFFFFFh
               addr_bytes = 4
            else if end_addr > 0FFFFh
               addr_bytes = 3
            end if
         end if

         if addr_bytes > SRECORD.addr_bytes
            SRECORD.addr_bytes = addr_bytes
         end if

         cur_addr = address
         while size > 0
            chunk = SRECORD.chunk_size
            if size < chunk
               chunk = size
            end if

            SRECORD.line (47 + addr_bytes), cur_addr, addr_bytes, area, cur_addr, chunk
            SRECORD.data_record_count = SRECORD.data_record_count + 1

            cur_addr = cur_addr + chunk
            size = size - chunk
         end while
      end if
   end if
end macro

macro org? address*
   SRECORD.endseg
   SRECORD.seg address
end macro

macro entry? address*
   SRECORD.entry_addr = address
end macro


SRECORD.emit_header SRECORD.header_text


postpone
   SRECORD.endseg

   if SRECORD.enable_record_count & (SRECORD.data_record_count > 0)
      if SRECORD.data_record_count <= 0FFFFh
         SRECORD.line '5', SRECORD.data_record_count, 2
      else
         SRECORD.line '6', SRECORD.data_record_count, 3
      end if
   end if

   ; Fallback if no data was written and no entry directive was specified
   if SRECORD.entry_addr = -1
      SRECORD.entry_addr = 0
   end if

   SRECORD.line (59 - SRECORD.addr_bytes), SRECORD.entry_addr, SRECORD.addr_bytes
end postpone


SRECORD.seg