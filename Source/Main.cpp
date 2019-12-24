#include <iostream>
#include "Zoom.hpp"
#include "FractalCreator.hpp"

int main() {

    const int WIDTH = 800;
    const int HEIGHT = 600;

    FractalCreator fractalCreator(WIDTH, HEIGHT);

    fractalCreator.addZoom(Zoom(295, HEIGHT-202, 0.1));
    fractalCreator.addZoom(Zoom(312, HEIGHT-304, 0.1));

    fractalCreator.calculateIteration();
    fractalCreator.CalculateTotalInterations();
    fractalCreator.drawFractal();

    std::string fileName{"Test.bmp"};
    fractalCreator.saveBitmap(fileName);

    std::cout << "Finished!"  << std::endl;

    return EXIT_SUCCESS;
}
