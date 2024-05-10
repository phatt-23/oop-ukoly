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


AbstractRectangle::AbstractRectangle(int t_s0, int t_s1)
: MathObj()
, m_s0(t_s0), m_s1(t_s1)
{}

AbstractRectangle::~AbstractRectangle() = default;

Rectangle::~Rectangle()
{}

int AbstractRectangle::get_area()
{
    m_area = m_s0 * m_s1;
    return m_area;
}

int AbstractRectangle::get_circum()
{
    m_circum = 2*m_s0 + 2*m_s1;
    return m_circum;
}

void AbstractRectangle::print()
{
    std::cout << "AbstractRectangle => " << "a: " << this->m_s0 << ", b: " << this->m_s1 << ", circum: " << get_circum() << std::endl;
} 

Rectangle::Rectangle(int t_s0, int t_s1)
    : AbstractRectangle(t_s0, t_s1)
{}

void Rectangle::print() {
    std::cout << "Rectangle => " << "a: " << this->m_s0 << ", b: " << this->m_s1 << ", area: " << get_area()<< ", circum: " << get_circum() << std::endl;
}

int Rectangle::getDiagonalLength() {
    return sqrt( m_s0*m_s0 + m_s1*m_s1 );
}

void Circle::print() {
    std::cout << "Circle => " << "r: " << m_radius << ", area: " << get_area() << ", circum: " << get_circum() << std::endl;
}

void Square::print() {
    std::cout << "Square => " << "a: " << m_side << ", area: " << get_area() << ", circum: " << get_circum() << std::endl;
}

TextureRectangle::TextureRectangle(const std::string& texture_path, int height, int width)
: AbstractRectangle(height, width), texture_path(texture_path)
{}

TextureRectangle::~TextureRectangle() =  default;

int TextureRectangle::getDiagonalLength() {
    return sqrt( m_s0*m_s0 + m_s1*m_s1 );
}

void TextureRectangle::print() {
    std::cout << "TextureRectangle => " << "a: " << this->m_s0 << ", b: " << this->m_s1 << ", area: " << get_area() << ", circum: " << get_circum() << ", path: " << this->texture_path << std::endl;
}

