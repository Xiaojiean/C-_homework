//版权声明
//Copyright 2021-2099 ZhantengZhang.
//202030310284 张展腾

#include <iostream>
#include <string>
using namespace std;

class score
{
public:
	score()
	{
		time = 2;//默认为2
		cout << "无参数解析函数的调用" << endl;
	}
	score(int time1)
	{
		time = time1;
		cout << "用户自定义解析函数的调用" << endl;
	}
	~score()
	{
		cout << "析构函数的调用" << endl;
	}
	void input()
	{
		for (int i = 0; i < time; ++i)
		{
			cout << "请输入学生的姓名和三科的成绩" << endl;
			cin >> name[i];
			cin >> cj[i][1] >> cj[i][2] >> cj[i][3];
		}
	}
	void show()
	{
		for (int i = 0; i < time; ++i)
		{
			cout  << name[i] << "学科A的成绩为：" << cj[i][1] << " ";
			cout  << name[i] << "学科B的成绩为：" << cj[i][2] << " ";
			cout  << name[i] << "学科C的成绩为：" << cj[i][3] << endl;
		}
	}
	void avg()
	{
		double a=0;
		for (int i = 0; i < time; ++i)
		{
			a = cj[i][1] + cj[i][2] + cj[i][3];
			cout << name[i] << "平均成绩为" << a/3 <<" ";
		}
		cout << endl;
	}
	void showavg()
	{
		double a=0;
		double b=0;
		double c=0;
		for (int i=0; i < time; ++i)
			a = a + cj[i][1];
		for (int i=0; i < time; ++i)
			b = b + cj[i][2];
		for (int i=0; i < time; ++i)
			c = c + cj[i][3];
		cout << "学科A的平均成绩为" << a / time << " ";
		cout << "学科B的平均成绩为" << b / time << " ";
		cout << "学科C的平均成绩为" << c / time << endl;
	}
	void px()
	{
		for (int i = 0; i < time; ++i) //将name【】数组复制一个
			copy[i] = name[i];
		for (int i = 0; i < time - 1; i++)   
			for (int j = 0; j < time - i - 1; j++)   
				if (cj[j][1] < cj[j + 1][1])      //改变了name【】数组数据的位置
				{
					double temp = cj[j + 1][1];      
					cj[j + 1][1] = cj[j][1];
					cj[j][1] = temp;
					string t = name[j + 1];
					name[j + 1] = name[j];
					name[j] = t;
				}
		cout << "学科A的排序为" << endl;
		for (int i = 0; i < time; ++i)		//打印姓名和对应的成绩
		{
			cout << name[i] << " " << cj[i][1] << endl;
		}
		for (int i = 0; i < time; ++i)    //重置name【】数组
			name[i] = copy[i];
		for (int i = 0; i < time - 1; i++)  
			for (int j = 0; j < time - i - 1; j++)   
				if (cj[j][2] < cj[j + 1][2])     
				{
					double temp = cj[j + 1][2];     
					cj[j + 1][2] = cj[j][2];
					cj[j][2] = temp;
					string t = name[j + 1];
					name[j + 1] = name[j];
					name[j] = t;
					
				}
		cout << "学科B的排序为" << endl;
		for (int i = 0; i < time; ++i)	//打印姓名和对应的成绩
		{
			cout << name[i] << " " << cj[i][2] << endl;
		}
		for (int i = 0; i < time; ++i)		 //重置name【】数组
			name[i] = copy[i];
		for (int i = 0; i < time - 1; i++)    
			for (int j = 0; j < time - i - 1; j++)   
				if (cj[j][3] < cj[j + 1][3])      
				{
					double temp = cj[j + 1][3];     
					cj[j + 1][3] = cj[j][3];
					cj[j][3] = temp;
					string t = name[j + 1];
					name[j + 1] = name[j];
					name[j] = t;
				}
		

		cout << "学科C的排序为" << endl;	//打印姓名和对应的成绩
		for (int i = 0; i < time; ++i)
		{
			cout << name[i] <<" "<< cj[i][3] << endl;
		}
	}
private:
	int time;
	double cj[100][100];
	string name[100];
	string copy[100];
};
int main()
{
	score a(3);
	a.input();
	a.show();
	a.avg();
	a.showavg();
	a.px();
	
	return 0;
}