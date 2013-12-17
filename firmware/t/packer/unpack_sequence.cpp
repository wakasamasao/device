#include "IrPacker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Arduino can load from EEPROM, but we can't
void fillTree(IrPacker *packer) {
    uint16_t tree[TREE_SIZE] = {
        205, 213, 220, 228, 236, 244, 253, 262,
        271, 280, 290, 300, 311, 322, 333, 345,
        357, 369, 382, 395, 409, 424, 439, 454,
        470, 486, 503, 521, 539, 558, 578, 598,
        619, 640, 663, 686, 710, 735, 761, 787,
        815, 843, 873, 904, 935, 968, 1002, 1037,
        1073, 1111, 1150, 1190, 1232, 1275, 1319, 1366,
        1413, 1463, 1514, 1567, 1622, 1679, 1738, 1798,
        1861, 1927, 1994, 2064, 2136, 2211, 2288, 2368,
        2451, 2537, 2626, 2718, 2813, 2911, 3013, 3119,
        3228, 3341, 3458, 3579, 3704, 3834, 3968, 4107,
        4251, 4400, 4554, 4713, 4878, 5049, 5226, 5408,
        5598, 5794, 5997, 6206, 6424, 6648, 6881, 7122,
        7371, 7629, 7896, 8173, 8459, 8755, 9061, 9379,
        9707, 10047, 10398, 10762, 11139, 11529, 11932, 12350,
        12782, 13230, 13693, 14172, 14668, 15181, 15713, 16263,
        16832, 17421, 18031, 18662, 19315, 19991, 20691, 21415,
        22165, 22940, 23743, 24574, 25434, 26325, 27246, 28200,
        29187, 30208, 31265, 32360, 33492, 34665, 35878, 37134,
        38433, 39779, 41171, 42612, 44103, 45647, 47245, 48898,
        50610, 52381, 54214, 56112, 58076, 60108, 62212, 64390
    };
    memcpy( packer->tree, tree, sizeof(tree) );
}

void onUnpack(uint16_t out) {
    printf( "%d ", out );
}

int main(int argc,char *argv[]) {
    uint8_t buff[ 1 ];
    IrPacker packer( buff );
    fillTree( &packer );

    uint8_t input[] = {
        0x8E, 0x76, 0x1, 0x42, 0x70, 0x3, 0x40, 0x1,
        0x55, 0x42, 0x6, 0x54, 0x70, 0x42, 0x1, 0x55,
        0x42, 0x8, 0x55, 0x70, 0x42, 0x55, 0x42, 0x1,
        0x70, 0x42, 0x4, 0x50, 0x55, 0x42, 0x1, 0x70,
        0x42, 0xA, 0x55, 0x40, 0x1, 0x55, 0x42, 0x4,
        0x50, 0x70, 0x42, 0x1, 0x55, 0x42, 0xC, 0x55,
        0x50, 0x1, 0x70, 0x42, 0xA, 0x55, 0x40, 0x55,
        0x42, 0x1, 0x70, 0x42, 0x4, 0x50, 0x1, 0x55,
        0x42, 0x18, 0x55, 0x55, 0x55, 0x1, 0x70, 0x42,
        0x8, 0x55, 0x1, 0x55, 0x42, 0x8, 0x55, 0xC2,
        0x8E, 0x76, 0x42, 0x70, 0x42, 0x1, 0x55, 0x42,
        0x6, 0x54, 0x70, 0x42, 0x1, 0x55, 0x42, 0x8,
        0x55, 0x70, 0x42, 0x55, 0x42, 0x1, 0x70, 0x42,
        0x4, 0x50, 0x55, 0x42, 0x1, 0x70, 0x42, 0xA,
        0x55, 0x40, 0x1, 0x55, 0x42, 0x4, 0x50, 0x70,
        0x42, 0x1, 0x55, 0x42, 0x14, 0x55, 0x55, 0x50,
        0x1, 0x70, 0x42, 0x4, 0x50, 0x1, 0x55, 0x42,
        0x4, 0x50, 0x70, 0x42, 0x55, 0x42, 0x1, 0x70,
        0x42, 0x4, 0x50, 0x1, 0x55, 0x42, 0x6, 0x54,
        0x1, 0x70, 0x42, 0x4, 0x50, 0x1, 0x55, 0x42,
        0x6, 0x54, 0x70, 0x42, 0x1, 0x55, 0x42, 0x6,
        0x54, 0x1, 0x70, 0x42, 0x8, 0x55, 0x1, 0x55,
        0x42, 0x12, 0x55, 0x55, 0x40, 0x70, 0x42, 0x1,
        0x55, 0x42, 0xC, 0x55, 0x50, 0x1, 0x70, 0x42,
        0x8, 0x55, 0x1, 0x55, 0x42, 0x6, 0x54, 0x1,
        0x70, 0x42, 0x6, 0x54, 0x55, 0x42, 0x70, 0x42,
        0x1, 0x55, 0x42, 0xE, 0x55, 0x54, 0x70, 0x42,
        0x1, 0x55, 0x42, 0xA, 0x55, 0x40, 0x70, 0x42,
        0x1, 0x55, 0x42, 0x4, 0x50, 0x70, 0x42, 0x1,
        0x55, 0x42, 0x4, 0x50, 0x70, 0x42
    };

    packer.unpackSequence( input, 238, &onUnpack );

    exit(0);
}