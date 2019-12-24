#include <iostream>
#include "Zoom.hpp"
#include "FractalCreator.hpp"

int main() {

    FractalCreator fractalCreator(800, 600);
    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.run();

    std::cout << "Finished!"  << std::endl;
    return EXIT_SUCCESS;
}
