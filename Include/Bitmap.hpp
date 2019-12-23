#ifndef BITMAP_HPP
#define BITMAP_HPP
#include <iostream>
#include <cstdint>
#include <memory>
#include "BitmapFileHeader.hpp"
#include "BitmapInfoHeader.hpp"

class Bitmap {
    private:

    int m_width{0};
    int m_height{0};
    std::unique_ptr<uint8_t[]> m_pixels{nullptr};


    public:

    Bitmap(int width, int height);

    bool save(std::string& fileName);
    
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

    ~Bitmap();

};

#endif // BITMAP_HPP