#ifndef FRACTAL_CREATOR_HPP
#define FRACTAL_CREATOR_HPP

#include <iostream>
#include <memory>
#include "Bitmap.hpp"
#include "Zoom.hpp"
#include "ZoomList.hpp"


class FractalCreator {
    private:

    int m_width{0};
    int m_height{0};
    std::unique_ptr<int[]> m_histogram;
    std::unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;
    int m_total{0};

    public:

    FractalCreator(int width, int height);

    void calculateIteration();

    void CalculateTotalInterations();

    void drawFractal();

    void addZoom(const Zoom& zoom);

    void saveBitmap(const std::string& fileName);

};


#endif // FRACTAL_CREATOR_HPP
