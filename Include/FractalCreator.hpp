#ifndef FRACTAL_CREATOR_HPP
#define FRACTAL_CREATOR_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "Bitmap.hpp"
#include "Zoom.hpp"
#include "ZoomList.hpp"
#include "RGB.hpp"

class FractalCreator {
    public:

    FractalCreator(int width, int height);

    void run();

    void addZoom(const Zoom& zoom);
    
    void addColorRange(double rangeEnd, const RGB& rgb);

    private:

    int m_width{0};
    int m_height{0};
    std::unique_ptr<int[]> m_histogram;
    std::unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;
    int m_total{0};
    std::vector<int> m_ranges;
    std::vector<RGB> m_colors;
    std::vector<int> m_rangeTotals;

    bool m_gotFirstRange{false};

    int getRange(int interations) const;

    void calculateIteration();

    void CalculateTotalInterations();

    void CalculateRangeTotals();

    void drawFractal();

    void saveBitmap(const std::string& fileName);
};


#endif // FRACTAL_CREATOR_HPP
