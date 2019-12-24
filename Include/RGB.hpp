#ifndef RGB_HPP
#define RGB_HPP

struct RGB {
    double r;
    double g;
    double b;
    RGB(double r, double g, double b);
};

RGB operator-(const RGB& first, const RGB& second);

#endif // RGB_HPP