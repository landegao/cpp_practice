#include <iostream>
#include <math.h>
#include "Complex.h"

/*
create new object
1. Complex a(1,2);  //object created in stack, and calls normal constructor
                    //will automatically destructed out of it"s range
2. Complex a = 12;  //object created in stack, calls conversion constructor
3. Complex a = new Complex(1,2);  //object created in heap, it will not be destructed 
   delete a;                      //only delete by manually
*/


/*normal comstructor*/
Complex::Complex(double real, double image)
        :m_real(real), m_image(image){}

/*
it called when initialize new object in following situations
1.  Complex a = 12;  new object
2.  Complex a = b + 12,  temporary object passed info function
b + 12 same as b.operator+(12), 12 will be transformed Complex object
and passed into function

In both conditions, if keyword explicti added, all conversion should like this static_cast<Complex>(12)
Complex a = static_cast<Complex>(12);
Complex a = b + static_cast<Complex>(12);

with explicit conversion, operator +... overload, only need to implement following signature
    Complex operator+(const Complex& c) const;
because all + operation based on Complex object
*/
Complex::Complex(double n) //conversion constructor
        :m_real(n), m_image(0.0){}

/*
copy constructor used to initialize new object with a existing object
Complex a(12,5)
Complex b(a) //copy constructor called at this line to create object b 
and initialized with object a. all member value same as object a.

two types of copy constructor 
1. shallow copy constructor
   This the default copy constructor, it only copy the object pointer address, so
   two object share the same address, member modificatio of one object and will affect 
   another. destruct of one object, the actual content of the other object no longer exists,
   access that memory will cause serious problem.
2. deep copy constructor
    This the user defined function, it copy the actual content of original object, so they have the same
    member value but do not share same memory address.

copy constructor called in three situations.
1. create new object
   Complex a(c)
2. pass object into function not in pointer or reference form
   void foo(Complex a);  //signature
   Complex a(12,5);
   foo(a)
3. return object in function not in pointer or reference form
    Complex foo(){
        Complex a = new Complex(5);
        return a;
    }

ATTENTION: 
When passing parameters by reference to functions or constructors, be very
careful about const correctness. Pass by non-const reference ONLY if
the function will modify the parameter and it is the intent to change
the caller-s copy of the data, otherwise pass by const reference.

There is a small clause in the C++ standard
that says that non-const references cannot bind to temporary objects.

Complex a(Complex(12,5)); error will happen when reference is not const

*/
Complex::Complex(const Complex& c) //copy constructor
        :m_real(c.m_real), m_image(c.m_image){}

double Complex::getRealPart(const Complex& c){
    return c.m_real;
}

double Complex::getImagePart(const Complex& c){
    return c.m_image;
}

void Complex::setRealPart(double n){
    m_real = n;
}

void Complex::setImagePart(double n){
    m_image = n;
}

/*
*/
std::ostream& operator<<(std::ostream& out, Complex& c){
    if(c.m_image > 0){
        out << c.m_real << " + " << c.m_image << "i";
    }else if(c.m_image == 0){
        out << c.m_real << " ";
    }else if(c.m_image < 0){
        out << c.m_real << " - " << abs(c.m_image) << "i";
    }
    return out;
}

double Complex::Modulus(){
    return sqrt(m_real*m_real + m_image*m_image);
}

/*It return a new Complex object and keep original object stay unchanged
  it calls copy constructor.
  first const means c.m_real = 1; not allowed, 
  second const means member value do not changed
*/
Complex Complex::operator+(const Complex& c) const{
    return Complex(m_real+c.m_real, m_image+c.m_image);
}

Complex Complex::operator-(const Complex& c) const{
    return Complex(m_real-c.m_real, m_image-c.m_image);
}

/*
  overload operator + as global funcition, not 
*/
Complex operator+(double n, const Complex& c){
    return Complex(n+c.m_real, c.m_image);
}

Complex operator-(double n, const Complex& c){
    return Complex(n-c.m_real, c.m_image);
}

/*assign operator equal to 
a.operator=(const Complex& other)
This should modify the content of object a itself
*/
Complex& Complex::operator=(const Complex& other){
    std::cout << "operator overload" << std::endl;
    m_real = other.m_real;
    m_image = other.m_image;
    return *this;
}

bool Complex::operator==(const Complex& other){
    return (m_real == other.m_real) && (m_image == other.m_image);
}
/*
normal destructor
*/
Complex::~Complex(){
    //do not need implement
}
