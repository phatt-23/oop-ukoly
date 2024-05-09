#include "inc/objects.h"

MathObj::MathObj()
{}

MathObj::~MathObj()
{}

void MathObj::print() {
    std::cout << "area: " << get_area() << ", circum: " << get_circum() << std::endl;
}

int MathObj::get_area() {
    printf("in the MathObj get_area\n");
    return 0;
}

int MathObj::get_circum() {
    printf("in the MathObj get_circum\n");
    return 0;
}

Circle::Circle(int t_r)
: MathObj()
, m_radius(t_r)
{}

Circle::~Circle()
{}

int Circle::get_area()
{
    m_area = M_PI * pow(m_radius, 2);
    return m_area;
}

int Circle::get_circum()
{
    m_circum = 2 * M_PI * m_radius;
    return m_circum;
}


Square::Square(int t_s)
: MathObj()
, m_side(t_s)
{}

Square::~Square()
{}

int Square::get_area()
{
    m_area = m_side * m_side;
    return m_area;
}

int Square::get_circum()
{
    m_circum = 4 * m_side;
    return m_circum;
}


Rectangle::Rectangle(int t_s0, int t_s1)
: MathObj()
, m_s0(t_s0), m_s1(t_s1)
{}

Rectangle::~Rectangle()
{}

int Rectangle::get_area()
{
    m_area = m_s0 * m_s1;
    return m_area;
}

int Rectangle::get_circum()
{
    m_circum = 2*m_s0 + 2*m_s1;
    return m_circum;
}

void Rectangle::print() {
    std::cout << "area: " << get_area() << ", circum: " << get_circum() << std::endl;
}

void Circle::print() {
    std::cout << "area: " << get_area() << ", circum: " << get_circum() << std::endl;
}

void Square::print() {
    std::cout << "area: " << get_area() << ", circum: " << get_circum() << std::endl;
}

TextureRectangle::TextureRectangle(const std::string& texture_path, int height, int width)
: Rectangle(height, width), texture_path(texture_path)
{}

TextureRectangle::~TextureRectangle() =  default;
