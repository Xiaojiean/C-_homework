# Ex2

## 设计程序的逻辑思路

​		将敌人抽象为一个类,可通过对象数组方便地批量创建.不同类型的敌人可以由一个基类派生出来.通过Private权限可以将敏感数据保护起来,只能通过预留的接口来访问.

​		通过动态内存分配来创建对象,可以方便地进行内存管理,当一个敌人死亡时,可以立即回收该对象占用的内存.通过析构函数被调用的次数可以准确计数消灭敌人的数量.

## 产生的错误和解决方法

​		C++在创建对象指针数组时只能调用无参数的构造函数,因此只好选择在循环中创建对象.

​		在将对象指针数组传到函数中时遇到了不小的困难,数组名作为参数是一个二级指针,使用时需注意.

​		C++无法确认是否已经释放某一空间,因此选择将delete了的对象指针赋值为nullptr,通过检测是否为空指针进行判断.

​		处理用户输入时,cin.clear()和cin.get()要结合使用,否则无法正常处理,容易造成死循环.

## 思想感悟和兴趣创新

​	C++超级复杂,功能也超级强大.

## 代码

```c++
//main.cpp
#include <iostream>
#include "enemy.h"
#include "baseOperation.h"

using namespace std;

int main()
{
	int enemyHP[ENEMY_NUM] = { 50, 100, 150, 200, 250 };
	enemy* enemies[ENEMY_NUM];
	for (int i = 0; i < 5; ++i)
	{
		enemies[i] = new class enemy(enemyHP[i]);
	}

	while (true)
	{
		checkRemainingEnemies(enemies);
		int enemyID = selectEnemy(enemies);
		int attackKind = attackWay(enemies[enemyID]);
		enemies[enemyID]->hurt(attackKind);
		if (checkDeath(enemies[enemyID]))
		{
			delete enemies[enemyID];
			enemies[enemyID] = nullptr;
		}
		if (checkPentaKill())
		{
			cout << "五连绝世!" << endl;
			break;
		}
	}

	return 0;
}
```

```c++
//baseOperation.h
#pragma once

constexpr auto ENEMY_NUM = 5;

int selectEnemy(enemy** enemies);
int attackWay(enemy* en);
bool checkDeath(enemy* en);
void checkRemainingEnemies(enemy** enemies);
bool checkPentaKill();
```

```c++
//baseOperation.cpp
#include <iostream>
#include "enemy.h"
#include "baseOperation.h"

using namespace std;

int selectEnemy(enemy** enemies)
{
	while (true)
	{
		char test;
		cout << "Which enemy?" << endl;
		int enemyID;
		while (!(cin >> enemyID))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Unexpected value. Try again." << endl;
		}

		if (enemies[enemyID] != nullptr and enemyID < ENEMY_NUM)
			return enemyID;
		else
			cout << "The enemy has been killed or non-existent. Another please." << endl;
	}
}

int attackWay(enemy* en)
{
	cout << "Which way?" << endl;
	cout << "[1].normalAttack\t[2].specialAttack" << endl;
	int kind;
	if (!(cin >> kind))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	while ((kind != 1) and (kind != 2))
	{
		cout << "Unexpected value. Try again." << endl;
		if (!(cin >> kind))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
	}

	return kind;
}

bool checkDeath(enemy* en)
{
	return (en->getHealth() <= 0) ? true : false;
}

void checkRemainingEnemies(enemy** enemies)
{
	cout << "The living enemy: " << endl;
	for (int i = 0; i < ENEMY_NUM; ++i)
		if (enemies[i] != nullptr)
			cout << i << '\t';
	cout << endl;
}

bool checkPentaKill()
{
	return (enemy::getKilledNum() == 5) ? true : false;
}
```

```c++
//enemy.h
#pragma once

class enemy {
private:
	int healthPoint;
	static int killedNum;
	static int enemyID;
public:
	explicit enemy(int hp);
	int getHealth();
	static int getKilledNum();
	int hurt(int kinds);
	~enemy();
};
```

```c++
//enemy.cpp
#include "enemy.h"
#include <iostream>

int enemy::killedNum = 0;
int enemy::enemyID = 0;

enemy::enemy(int hp) :healthPoint(hp)
{
	enemyID++;
}

enemy::~enemy()
{
	std::cout << "KILLED:" << ++killedNum << std::endl;
}

int enemy::getHealth()
{
	return healthPoint;
}

int enemy::getKilledNum()
{
	return killedNum;
}

int enemy::hurt(int kinds)
{
	if (kinds == 0)
		return healthPoint -= 50;
	else
		return healthPoint -= 100;
}
```

