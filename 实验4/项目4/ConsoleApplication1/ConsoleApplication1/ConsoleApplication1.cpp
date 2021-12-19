//版权声明
//Copyright 2021-2099 ZhantengZhang.
//202030310284 张展腾

#include <iostream>
#include <string>
using namespace std;
static float classmoney;
class tstudent {
private:
	string name[100];
public:
	
	tstudent()
	{
		classmoney = 1000;//解析函数初始化
	}
	/*void initstudent(string name1)
	{
		int i = 1;
		name[i] = name1;
		++i;
	}*/
	void expendmoney(float money)
	{
		classmoney = classmoney - money;
	}
	void showmoney()
	{
		cout << "班级的余额为"<<classmoney << endl;
	}
};
int main()
{
	tstudent A, B, C;

	A.expendmoney(50);
	A.showmoney();
	B.expendmoney(98.5);
	B.showmoney();
	C.expendmoney(500.53);
	C.showmoney();
	
}