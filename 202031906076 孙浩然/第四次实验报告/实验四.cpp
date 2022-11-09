#include <iostream>
#include <string.h>
using namespace std;
class TStudent
{
private:
    char m_Name[6];
    static float m_ClassMoney;
    //m_ClassMoney为静态成员变量，保存班费
public:
    void InitStudent(char *);
    void ExpendMoney(float);
    static void ShowMoney(); //静态成员函数
};
float TStudent::m_ClassMoney=1000; //静态成员变量的初始化
void TStudent::InitStudent(char name[])
{
    strcpy(m_Name,name);
}
void TStudent::ExpendMoney(float money)
{
    m_ClassMoney-=money; //班费为原先的减去花费的
    cout<<m_Name<<"花费班费"<<m_ClassMoney<<endl;
}
void TStudent::ShowMoney()
{
    cout<<"班费还剩余"<< m_ClassMoney<<endl;
}
int main()
{
    TStudent stu[3];//定义三个学生
    stu[0].InitStudent("A");
    stu[1].InitStudent("B");
    stu[2].InitStudent("C");
    stu[0].ExpendMoney(50);
    TStudent::ShowMoney();
     stu[1].ExpendMoney(98.5);
    TStudent::ShowMoney();
    stu[2].ExpendMoney(500.53);
    TStudent::ShowMoney();
}
//Copyright ©2021-2099 HaoranSun. All rights reserved