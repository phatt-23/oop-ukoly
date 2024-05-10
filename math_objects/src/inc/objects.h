#ifndef __objects_h__
#define __objects_h__

#include "precomp.h"

// pure abstract class - only pure virtual methods
class MathObj {
    protected:
        int m_area;
        int m_circum;

    public:
        MathObj();
        virtual ~MathObj();
        virtual int get_area() = 0;
        virtual int get_circum() = 0;
        virtual void print() = 0;
};

class Circle : public MathObj {
    private:
        int m_radius;

    public:
        Circle(int t_r);
        ~Circle() override;
        int get_area() override;
        int get_circum() override;
        void print() override;
};

class Square : public MathObj {
    private:
        int m_side;

    public:
        Square(int t_s);
        ~Square() override;
        int get_area() override;
        int get_circum() override;
        void print() override;
};

// abstract class - has a pure virtual method
class AbstractRectangle : public MathObj {
    protected:
        int m_s0, m_s1;

    public:
        AbstractRectangle(int t_s0, int t_s1); 
        virtual ~AbstractRectangle();
        virtual int get_area() override;
        virtual int get_circum() override;
        virtual void print() override;
        virtual int getDiagonalLength() = 0;
};

class Rectangle : public AbstractRectangle {
    public:
        Rectangle(int t_s0, int t_s1);
        ~Rectangle() override;
        void print() override;
        int getDiagonalLength() override;
};

class TextureRectangle : public AbstractRectangle {
        std::string texture_path;
    public:
        TextureRectangle(const std::string& texture_path, int height, int width);
        ~TextureRectangle() override;
        void print() override;
        int getDiagonalLength() override;
};

#endif//__objects_h__
