#ifndef ZOOM_LIST_HPP
#define ZOOM_LIST_HPP

#include <vector>
#include <utility>
#include "Zoom.hpp"

class ZoomList {
    private:

    int m_width{0};
    int m_height{0};
    std::vector<Zoom> m_zooms;

    double m_xCenter{0.0f};
    double m_yCenter{0.0f};
    double m_scale{1.0f};

    public:

    ZoomList(int width, int height);

    void add(const Zoom& zoom);

    std::pair<double, double> doZoom(int x, int y);

};

#endif // ZOOM_LIST_HPP