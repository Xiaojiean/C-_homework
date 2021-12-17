#include <iostream>
using namespace std;
int add(int, int);
int main()
{
	int x, y, sum;
	cout << "Enter two numbers:" << endl;
	cin >> x>>y;
	sum = add(x, y);
	cout << sum << endl;
	return 0;
}
int add(int a, int b)
{
	return a + b;
}