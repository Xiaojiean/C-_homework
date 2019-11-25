# EX3

## 逻辑思路

​		同Ex2

## 产生的错误和解决办法

​		由于采用静态成员变量进行计数,所以不能通过它直接判断调用了哪个对象的析构函数,所以引入了一个成员变量作为id来区分各个对象.

## 代码

```C++
//main.cpp
#include <iostream>
#include "enemy.h"
#include "baseOperation.h"

using namespace std;

int main()
{
	int enemy_hp[kEnemyNum] = { 50, 100, 150, 200, 250 };
	CEnemy* enemies[kEnemyNum];
	for (auto i = 0; i < kEnemyNum; ++i)
	{
		enemies[i] = new class CEnemy(enemy_hp[i]);
	}

	while (true)
	{
		CheckRemainingEnemies(enemies);
		const auto enemy_id = SelectEnemy(enemies);
		enemies[enemy_id]->hurt(AttackWay(enemies[enemy_id]));
		if (IsDeath(enemies[enemy_id]))
		{
			delete enemies[enemy_id];
			enemies[enemy_id] = nullptr;
			if (IsPentaKill())
			{
				cout << "五连绝世!" << endl;
				break;
			}
		}
	}

	return 0;
}
```

```C++
//baseOperation.h
#pragma once

constexpr auto kEnemyNum = 5;

int SelectEnemy(CEnemy** enemies);
int AttackWay(CEnemy* en);
bool IsDeath(CEnemy* en);
void CheckRemainingEnemies(CEnemy** enemies);
bool IsPentaKill();
```

```C++
//baseOperation.cpp
#include <iostream>
#include "enemy.h"
#include "baseOperation.h"

using namespace std;

void CheckRemainingEnemies(CEnemy** enemies)
{
	cout << "The living enemy: " << endl;
	for (auto i = 0; i < kEnemyNum; ++i)
		if (enemies[i] != nullptr)
			cout << i << '\t';
	cout << endl;
}

int SelectEnemy(CEnemy** enemies)
{
	while (true)
	{
		cout << "Which enemy?" << endl;
		int enemy_id;
		while (!(cin >> enemy_id))
		{
			cin.clear();
			while (cin.get() != '\n')
				;
			cout << "Unexpected value. Try again." << endl;
		}
		if (enemies[enemy_id] != nullptr and enemy_id < kEnemyNum)
			return enemy_id;
		cout << "The enemy has been killed or non-existent. Another please." << endl;
	}
}

int AttackWay(CEnemy* en)
{
	cout << "Which way?" << endl;
	cout << "[1].normalAttack\t[2].specialAttack" << endl;
	int kind;
	if (!(cin >> kind))
	{
		cin.clear();
		while (cin.get() != '\n')
			;
	}
	while ((kind != 1) and (kind != 2))
	{
		cout << "Unexpected value. Try again." << endl;
		if (!(cin >> kind))
		{
			cin.clear();
			while (cin.get() != '\n')
				;
		}
	}
	return kind;
}

bool IsDeath(CEnemy* en)
{
	return (en->get_health() <= 0) ? true : false;
}

bool IsPentaKill()
{
	return (CEnemy::get_killed_num() == 5) ? true : false;
}
```

```C++
//enemy.h
#pragma once

class CEnemy {
	static int enemy_num_;
	int enemy_id_;
	int health_point_;
	static int killed_num_;
public:
	explicit CEnemy(int hp);
	int get_health() const;
	static int get_killed_num();
	int hurt(int kinds);
	~CEnemy();
};
```

```c++
//enemy.cpp
#include "enemy.h"
#include <iostream>

constexpr auto kNormalAttackDamage = 50;
constexpr auto kSpecialAttackDamage = 100;
int CEnemy::killed_num_ = 0;
int CEnemy::enemy_num_ = 0;

CEnemy::CEnemy(const int hp) :health_point_(hp)
{
	enemy_id_ = enemy_num_++;
}

CEnemy::~CEnemy()
{
	std::cout << "You killed " << this->enemy_id_ << std::endl;
	std::cout << "KILLED:" << ++killed_num_ << std::endl;
}

int CEnemy::get_health() const
{
	return health_point_;
}

int CEnemy::get_killed_num()
{
	return killed_num_;
}

int CEnemy::hurt(const int kinds)
{
	if (kinds == 1)
		return health_point_ -= kNormalAttackDamage;
	return health_point_ -= kSpecialAttackDamage;
}
```

