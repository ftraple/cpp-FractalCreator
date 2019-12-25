#include <iostream>
#include "Zoom.hpp"
#include "FractalCreator.hpp"

int main() {

    FractalCreator fractalCreator(800, 600);

    fractalCreator.addColorRange(0.0, RGB(0, 0, 0));
    fractalCreator.addColorRange(0.05, RGB(255, 99, 71));
    fractalCreator.addColorRange(0.08, RGB(255, 255, 0));
    fractalCreator.addColorRange(1.0, RGB(255, 255, 255));

    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.run();

    std::cout << "Finished!"  << std::endl;
    return EXIT_SUCCESS;
}
