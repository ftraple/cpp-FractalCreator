#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.hpp"
#include "Mandelbrot.hpp"
#include "Zoom.hpp"
#include "ZoomList.hpp"

int main() {

    const int WIDTH = 800;
    const int HEIGHT = 600;
    //double min = 999999;
    //double max = -999999;

    Bitmap bitmap(WIDTH, HEIGHT);

    ZoomList zoomList(WIDTH, HEIGHT);
    zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
    zoomList.add(Zoom(295, HEIGHT-202, 0.1));
    zoomList.add(Zoom(312, HEIGHT-304, 0.1));


    std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    std::unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{0});

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            auto coords = zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(coords.first, coords.second);
            
            fractal[y * WIDTH + x] = iterations;

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                histogram[iterations]++;
            }
        }
    }

    int total{0};
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        total += histogram[i];
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            uint8_t red = 0;            
            uint8_t green = 0;
            uint8_t blue = 0;           

            int iterations = fractal[y*WIDTH+x];
            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                double hue{0.0f};
                for (int i =0; i < iterations; i++) {
                    hue += (double)histogram[i]/total;
                }
                green = std::pow(255, hue);
            }
            bitmap.setPixel(x, y, red, green, blue);
        }
    }

    std::string fileName{"Test.bmp"};
    bitmap.save(fileName);

    return EXIT_SUCCESS;
}
