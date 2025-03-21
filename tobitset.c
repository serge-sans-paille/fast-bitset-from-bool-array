#include <stdint.h>
#include <string.h>

// Generate a bitset from an array of boolean.
unsigned char tobitset(unsigned char unpacked[8]) {
    uint64_t data;
    memcpy(&data, unpacked, sizeof(uint64_t));

    const uint64_t magic = (
        0x80 + 0x4000 + 0x200000 + 0x10000000 +
        0x0800000000 + 0x040000000000 + 0x02000000000000 + 0x0100000000000000
    );

    unsigned char res = ((data * magic) >> 56) & 0xFF;
    return res;
}
