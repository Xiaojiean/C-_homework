#include<iostream>
using namespace std;
class Base{
public:
    void setx(int i)
    {  x=i;  }
    int getx()
    {  return x; }
protected:
    int x;
};
class Derived:private Base{
public:
     void sety(int i)
     {  y=i;  }
     int gety()
     {  return y; }
     void show()
    { cout<<"Base::x="<<x<<endl;  }
public:
    int y;
};
int main()
{
     Derived bb;                             // 语句2
     bb.setx(16);                            // 语句3
     bb.sety(25);                            // 语句4
     bb.show();                              // 语句5
    cout<<"Base::x="<<bb.x<<endl;           // 语句6
    cout<<"Derived::y="<<bb.y<<endl;        // 语句7
    cout<<"Base::x="<<bb.getx()<<endl;      // 语句8
    cout<<"Derived::y="<<bb.gety()<<endl;   // 语句9
    return 0;
}
//Copyright ©2021-2099 HaoranSun. All rights reserved