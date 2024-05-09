#ifndef __objects_h__
#define __objects_h__

#include "precomp.h"

// pure abstract class 
class MathObj {
protected:
    int m_area;
    int m_circum;

public:
    MathObj();
    ~MathObj();
    virtual int get_area() = 0;
    virtual int get_circum() = 0;
    virtual void print() = 0;
};

// abstract class derived from pure abstract class
class Circle : public MathObj {
    int m_radius;
    
public:
    Circle(int t_r);
    ~Circle();
    virtual int get_area() override;
    virtual int get_circum() override;
    virtual void print() override;
};

// abstract class derived from pure abstract class
class Square : public MathObj {
    int m_side;

public:
    Square(int t_s);
    ~Square();
    virtual int get_area() override;
    virtual int get_circum() override;
    virtual void print() override;
};

// abstract class derived from pure abstract class
class Rectangle : public MathObj {
    int m_s0, m_s1;
public:
    Rectangle(int t_s0, int t_s1);
    ~Rectangle();
    virtual int get_area() override;
    virtual int get_circum() override;
    virtual void print() override;
};

// class derived from abstract class
class TextureRectangle : public Rectangle {
        std::string texture_path;
    public:
        TextureRectangle(const std::string& texture_path, int height, int width);
        ~TextureRectangle();
};

#endif//__objects_h__
