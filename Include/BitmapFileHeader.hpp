#ifndef BITMAP_FILE_HEADER_HPP
#define BITMAP_FILE_HEADER_HPP

#include <cstdint>

#pragma pack(2) // Avoid padding
struct BitmapFileHeader {
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserver{0};
    int32_t dataOffset;
};

#endif // BITMAP_FILE_HEADER_HPP