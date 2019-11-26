#include<iostream>
#include"add.h"
using namespace std;
int main()
{
	int x,y,sum;
	cout<<"Enter two numbers:"<<endl;
	cin>>x>>y;
	sum =add(x,y);
	cout<<x<<"+"<<y<<"="<<sum<<endl;
	return 0;
}
