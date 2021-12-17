#include <iostream>
using namespace std;

class complex {
private:
	float real;
	float imag;
public:
	complex operator*(complex p)
	{
		complex temp;
		temp.real = real * p.real - imag * p.imag;
		temp.imag = real * p.imag + imag * p.real;
		return temp;
	}
	complex(float a = 0, float b = 0)
	{
		real = a;
		imag = b;
	}
	void show()
	{
		cout << "(" << real << "," << imag << ")"<<endl;
	}
	
};
int main()
{
	complex a(4, 6), b(4, -6), c;
	c = a * b;
	c.show();

}