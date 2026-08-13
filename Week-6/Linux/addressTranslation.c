// Address Translation
// Objective:
// In hardware, the Memory Management Unit (MMU) uses fast bitwise operations
// rather than arithmetic division to split virtual addresses into a Page Number
// and an Offset.

// Given a 32-bit system with a standard 4096-byte (4 KB) page size:

// Task:
// Extract the Page Number
// Extract the Offset

#include <stdint.h>
#include <stdio.h>

void address_translation(uint32_t virtual_address) {
  uint32_t page_number = 0;
  uint32_t offset = 0;

  page_number = virtual_address >> 12;

  offset = virtual_address & 0xFFF;

  printf("[1A] Addr: 0x%08X -> Page: %u (0x%X), Offset: %u (0x%X)\n",
         virtual_address, page_number, page_number, offset, offset);
}

int main() {
  address_translation(0x00000000);
  address_translation(0x00000FFF);
  address_translation(0x00001000);
  address_translation(0x00003A2C);

  return 0;
}