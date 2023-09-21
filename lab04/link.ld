OUTPUT_ARCH( "riscv" )
ENTRY(main)

SECTIONS
{
  . = 0x80000000;
  . = ALIGN(0x1000);
  .text : { *(.text) }
  . = ALIGN(0x1000);
  . = 0x80001000;
  .data : { *(.data) }
  . = ALIGN(0x1000);
  
  _end = .;
}