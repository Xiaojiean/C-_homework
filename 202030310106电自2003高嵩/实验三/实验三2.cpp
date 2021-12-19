// 实验三2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;

class Score
{
public:
	Score(int stnumber = 2)
	{
		if (stnumber > 100)
			number = 100;
		else number = stnumber;
	}

	void input()
	{
		for (int i = 0; i < number; i++)
		{
			//输入姓名
			cout << "请输入学生姓名:" << endl;
			cin >> name[i];
			//输入学生成绩
			cout << "请输入科目A成绩：" << endl;
			cin >> grade[i][1];
			cout << "请输入科目B成绩：" << endl;
			cin >> grade[i][2];
			cout << "请输入科目C成绩：" << endl;
			cin >> grade[i][3];
		}
	}

	void showallstu()
	{
		for (int i = 0; i < number; i++)
		{
			cout << "姓名：" << name[i] << " 科目A成绩：" << grade[i][1] << " 科目B成绩：" << grade[i][2] << " 科目C成绩：" << grade[i][2] << endl;
		}
	}

	void showstuavg(int m)
	{
		cout << "姓名:" << name[m] << " 平均成绩：" << (grade[m][1] + grade[m][2] + grade[m][3]) / 3 << endl;
	}

	void showavg(int i)
	{
		double all = 0;
		switch (i)
		{
		case 1:
			for (int m = 0; m < number; m++)
			{
				all += grade[m][1];
			};
			cout << "课程名称：A平均成绩：" << all / number << endl;
			break;
		case 2:
			for (int m = 0; m < number; m++)
			{
				all += grade[m][2];
			};
			cout << "课程名称：B平均成绩：" << all / number << endl;
			break;
		case 3:
			for (int m = 0; m < number; m++)
			{
				all += grade[m][3];
			};
			cout << "课程名称：C平均成绩：" << all / number << endl;
			break;
		}
	}

	void rank(int m)
	{
		int temp;
		char tempname[100];
		switch (m)
		{
		case 1:cout << "课程名：A" << endl;
			break;
		case 2:cout << "课程名：B" << endl;
			break;
		case 3:cout << "课程名：C" << endl;
			break;
		}
		for (int i = 0; i < number - 1; i++)
		{
			if (grade[i][m] > grade[i + 1][m])
			{
				temp = grade[i + 1][m];
				grade[i + 1][m] = grade[i][m];
				grade[i][m] = grade[i + 1][m];
				tempname[100] = name[i + 1][100];
				name[i + 1][100] = name[i][100];
				name[i][100] = tempname[100];
			}
		}
		for (int i = number - 1; i > -1; i--)
		{
			cout << "姓名：" << name[i] << " 成绩：" << grade[i][m] << endl;
		}
	}

private:
	int number;
	char name[100][100];
	double grade[100][3];
};

int main()
{
	Score stu;
	stu.input();
	stu.showallstu();
	stu.showstuavg(1);
	stu.showavg(1);
	stu.rank(1);
	getchar();
	getchar();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
