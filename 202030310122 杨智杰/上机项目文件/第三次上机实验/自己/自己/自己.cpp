#include <iostream>
using namespace std;

class Score
{
public:
	void inputcj(int);
	void showcjavg();
	void avg();
	Score()
	{
		time = 2;
		cout << "默认参数解析函数的调用" << endl;
	}
	Score(int x)
	{
		time = x; //用户输入参数
		cout << "用户自定义解析函数的调用" << endl;
	}
	~Score()
	{
		cout << "析构函数的调用" << endl;
	}

private:
	float cj[100][100];
	int time;
};
int main()
{
	Score A;
	A.inputcj(3);
	A.showcjavg();
	A.avg();

	return 0;
}