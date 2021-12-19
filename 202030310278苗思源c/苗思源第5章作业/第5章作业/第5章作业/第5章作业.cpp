 
 

#include <iostream>
using namespace std;
class complex {
public:
    complex() {
        real = 0.0;
        imag = 0.0;
    }
    complex(double r_, double i_) {
        real = r_;
        imag = i_;
    }
    void print() {
        if (imag >= 0)
            cout << real << "+" << imag << "i" << endl;
        else
            cout << real << imag << "i" << endl;
    }
    
    complex multiply(const complex& z2) {
        complex result;
        result.real = real * z2.real - imag * z2.imag;
        result.imag = real * z2.imag + imag * z2.real;
        return result;
    }
private:
    // real and imaginary part
    double real, imag;
};
int main() {
    complex c1(1, 4), c2(3.3, -4.13);
    complex c3 ;
    
    c3 = c1.multiply(c2);
    c1.print();
    c2.print();
     
    cout << "c1*c2=";
    c3.print();
    return 0;
}
 