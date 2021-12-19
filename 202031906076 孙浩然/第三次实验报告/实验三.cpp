#include<iostream>
using namespace std;
class Coordinate{  // 定义Coordinate类
public:
    Coordinate()
    {           times=2;
          cout<<"Coordinate construction1 called!"<<endl;
    }
    Coordinate(int times1)
    {          times=times1;
          cout<<"Coordinate construction2 called!"<<endl;
}
    ~Coordinate()
    {          cout<<"Coordinate destruction called!"<<endl;
}
    void InputCoord()
    {

        for(int i=0;i<times;i++)
          {
               cout<<"Please Input x:"<<endl;
               cin>>Coord[i][1];
               cout<<"Please Input y:"<<endl;
               cin>>Coord[i][2];
           }
    }
     void ShowCoord()
     {            cout<<"The coord is:"<<endl;
           for(int i=0;i<times;i++)
           {
                 cout<<"("<<Coord[i][1]<<","<<Coord[i][2]<<")"<<endl;
            }
}
     void ShowAvgCoord()
     {           float avgx = 0;
           float avgy = 0;
           for(int i=0;i<times;i++)
          {
                avgx = avgx + Coord[i][1];
                avgy = avgy + Coord[i][2];
          }
          avgx = avgx/times;
          avgy = avgy/times;
          cout<<"The AVG coord is:"<<endl;
          cout<<"("<<avgx<<","<<avgy<<")"<<endl;
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
   return 0;

}
//Copyright ©2021-2099 HaoranSun. All rights reserved