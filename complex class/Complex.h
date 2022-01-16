#include <iostream>

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
public:
    Complex(double real, double image);
    Complex(const Complex& c); //deep copy consructor
    Complex(double n);
    double Modulus();
    double getRealPart(const Complex& c);
    double getImagePart(const Complex& c);
    void setRealPart(double n);
    void setImagePart(double n);
    Complex operator+(const Complex& c) const;
    friend Complex operator+(double n, const Complex& c) ;
    Complex operator-(const Complex& c) const;
    friend Complex operator-(double n, const Complex& c) ;
    friend std::ostream& operator<<(std::ostream& out, Complex& c);//it access private number of Complex class
    Complex& operator=(const Complex& c);
    bool operator==(const Complex& other); 
    ~Complex();

private:
    double m_real;
    double m_image;
};


#endif // COMPLEX_H
