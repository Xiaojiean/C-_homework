#include <iostream>
#include <string>
using namespace std;

static float classmoney;
static int i = 1;
static float n[100];
class student {

public:
	student()
	{
		classmoney = 1000;
	}
	static void initstudent()
	{
		cin >> n[i];
		//name[i] = n;
		++i;
	}
	void showmoney()
	{
		cout << "目前余额为" << classmoney << endl;
	}
	void expendmoney()
	{
		classmoney = classmoney - n[i-1];
		cout <<"花费了" << n[i-1] << endl;
	}
};
int main()
{
	student A, B, C;
	A.initstudent();
	A.expendmoney();
	A.showmoney();
	B.initstudent();
	B.expendmoney();
	B.showmoney();
	C.initstudent();
	C.expendmoney();
	C.showmoney();

	return 0;
}