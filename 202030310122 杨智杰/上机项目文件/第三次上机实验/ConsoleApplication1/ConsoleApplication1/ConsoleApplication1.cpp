#include<iostream>
using namespace std;
class Coordinate {  // 定义Coordinate类
public:
	Coordinate()
	{
		times = 2;
		cout << "Coordinate construction1 called!" << endl;
		// 设置默认的输入坐标数目
	}
		Coordinate(int times1)
		{
			times = times1;
			cout << "Coordinate construction2 called!" << endl;
			// 设置输入坐标数目
		}
			~Coordinate()
			{
				cout << "Coordinate destruction called!" << endl;

				// 析构函数
			}
				void InputCoord()
				{
					for (int i = 0; i < times; i++)
					{
						cout << "Please Input x:" << endl;
						cin >> Coord[i][1];
						cout << "Please Input y:" << endl;
						cin >> Coord[i][2];
					}

					// 输入坐标
				}
					void ShowCoord()
					{
						cout << "The coord is:" << endl;
						for (int i = 0; i < times; i++)
						{
							cout << "(" << Coord[i][1] << "," << Coord[i][2] << ")" << endl;
						}

						// 显示已经输入的坐标
					}
						void ShowAvgCoord()
						{ 
							float avgx = 0;
							float avgy = 0;
							for (int i = 0; i < times; i++)
							{
								avgx = avgx + Coord[i][1];
								avgy = avgy + Coord[i][2];
							}
							avgx = avgx / times;
							avgy = avgy / times;
							cout << "The AVG coord is:" << endl;
							cout << "(" << avgx << "," << avgy << ")" << endl;

							// 显示输入坐标的均值
						}
						private:
							float Coord[100][100]; // 存放输入坐标的数组
							int times; // 存放输入坐标数目
						};
						int main()
						{
							Coordinate x; 
							x.InputCoord();
							x.ShowCoord();
							x.ShowAvgCoord();

							// 定义对象
							// 执行显示和坐标均值运算
							return 0;
						}
