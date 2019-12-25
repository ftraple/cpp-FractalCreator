#include <cstdint>
#include <math.h>
#include "FractalCreator.hpp"
#include "Mandelbrot.hpp"


FractalCreator::FractalCreator(int width, int height):
    m_width(width), m_height(height),
    m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
    m_fractal(new int[m_width*m_height]{0}),
    m_bitmap(width, height),
    m_zoomList(width, height) {

    m_zoomList.add(Zoom(m_width/2, m_height/2, 4.0/m_width));
}

void FractalCreator::run() {
    calculateIteration();
    CalculateTotalInterations();
    CalculateRangeTotals();
    drawFractal();
    std::string fileName{"Test.bmp"};
    saveBitmap(fileName);
}

void FractalCreator::addColorRange(double rangeEnd, const RGB& rgb) {
    m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
    m_colors.push_back(rgb);

    if (m_gotFirstRange) {
        m_rangeTotals.push_back(0);
    }
    m_gotFirstRange = true;
}

void FractalCreator::addZoom(const Zoom& zoom) {
    m_zoomList.add(zoom);
}

int FractalCreator::getRange(int interations) const {
    int range{0};
    for (size_t i = 1; i < m_ranges.size(); i++) {
        range = i;
        if (m_ranges[i] > interations) {
            break;
        }
    }
    range--;
    return range;
}

void FractalCreator::calculateIteration() {
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {

            auto coords = m_zoomList.doZoom(x, y);
            int iterations = Mandelbrot::getIterations(coords.first, coords.second);
           
            m_fractal[y * m_width + x] = iterations;
            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                m_histogram[iterations]++;
            }
        }
    }
}

void FractalCreator::CalculateTotalInterations() {
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        m_total += m_histogram[i];
    }
}

void FractalCreator::drawFractal() {

    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            uint8_t red = 0;            
            uint8_t green = 0;
            uint8_t blue = 0;           

            int iterations = m_fractal[y * m_width + x];
            int range = getRange(iterations);
            int rangeTotal = m_rangeTotals[range];
            int rangeStart = m_ranges[range];

            RGB& startColor = m_colors[range];
            RGB& endColor = m_colors[range+1];
            RGB colorDiff = endColor - startColor;

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                int totalPixels = 0;
                for (int i = rangeStart; i < iterations; i++) {
                    totalPixels += m_histogram[i];
                }

                red = startColor.r + colorDiff.r * (double)totalPixels/rangeTotal;
                green = startColor.g + colorDiff.g * (double)totalPixels/rangeTotal;
                blue = startColor.b + colorDiff.b * (double)totalPixels/rangeTotal;
            }
            m_bitmap.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalCreator::CalculateRangeTotals() {
    int rangeIndex = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        int pixels = m_histogram[i];
        if (i >= m_ranges[rangeIndex+1]) {
            rangeIndex++;
        }
        m_rangeTotals[rangeIndex] += pixels;
    }
}


void FractalCreator::saveBitmap(const std::string& fileName) {
    m_bitmap.save(fileName);
}
