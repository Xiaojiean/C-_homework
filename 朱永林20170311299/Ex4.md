# Ex4

## 逻辑思路

​		改造原本的选择和攻击函数,是之可以指定两个目标,增加了用于判断某个敌人是否已经被选中的代码.

## 产生的错误和解决办法

​		如果连续选择同一个敌人的话,会出现非法内存访问的情况,经过调试排除问题

## 思想感悟

​		代码可重用性很低.

## 代码

```c++
//main.cpp

#include <iostream>
#include "enemy.h"
#include "baseOperation.h"

using namespace std;

int main()
{
	int enemy_hp[kEnemyNum] = { 50 , 100, 150, 200, 250 };
	CEnemy* enemies[kEnemyNum];
	for (auto i = 0; i < kEnemyNum; ++i)
	{
		enemies[i] = new class CEnemy(enemy_hp[i]);
	}

	while (true)
	{
		CheckRemainingEnemies(enemies);
		int enemy_id[kAttackNum] = { SelectEnemy(enemies),  SelectEnemy(enemies) };
		const auto skill_kind = AttackWay(enemies[enemy_id[0]]);
		for(auto i = 0; i < kAttackNum; i++)
		{
			if (enemy_id[i] != -1)
			{
				enemies[enemy_id[i]]->hurt(skill_kind);
				if (IsDeath(enemies[enemy_id[i]]))
				{
					delete enemies[enemy_id[i]];
					enemies[enemy_id[i]] = nullptr;
					if (IsPentaKill())
					{
						cout << "五连绝世!" << endl;
						goto end;
					}
				}
			}
		}
	}

	end:
	return 0;
}
```

```c++
//baseOperation.h

#pragma once

constexpr auto kEnemyNum = 5;
constexpr auto kAttackNum = 2;

int SelectEnemy(CEnemy** enemies);
int AttackWay(CEnemy* en);
bool IsDeath(CEnemy* en);
int CheckRemainingEnemies(CEnemy** enemies);
bool IsPentaKill();
```

```c++
//baseOperation.cpp

#include <iostream>
#include "enemy.h"
#include "baseOperation.h"

using namespace std;

int CheckRemainingEnemies(CEnemy** enemies)
{
	cout << "The living enemy: " << endl;
	auto num = 0;
	for (auto i = 0; i < kEnemyNum; ++i)
	{
		if (enemies[i] != nullptr)
		{
			cout << i << '\t';
			num++;
		}
	}
	cout << endl;
	return num;
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
		if (enemies[enemy_id] != nullptr and enemy_id < kEnemyNum and !enemies[enemy_id]->is_checked())
		{
			return enemies[enemy_id]->check();
		}
		if(enemies[enemy_id] != nullptr and enemy_id < kEnemyNum and CheckRemainingEnemies(enemies) == 1)
		{
			return -1;
		}
		cout << "The enemy has been killed or chosen or non-existent. Another please." << endl;
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
	bool checked_;
	int uncheck();	
public:
	explicit CEnemy(int hp);
	int get_health() const;
	static int get_killed_num();
	int hurt(int kinds);
	bool is_checked() const;
	int check();	
	~CEnemy();
};
```

```C++
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
	checked_ = false;
}

CEnemy::~CEnemy()
{
	std::cout << "You killed " << this->enemy_id_ << std::endl;
	std::cout << "KILLED:" << ++killed_num_ << std::endl;
}

bool CEnemy::is_checked() const
{
	return checked_ ? true : false;
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
	uncheck();
	if (kinds == 1)
		return health_point_ -= kNormalAttackDamage;
	return health_point_ -= kSpecialAttackDamage;
}

int CEnemy::check()
{
	checked_ = true;
	return this->enemy_id_;
}

int CEnemy::uncheck()
{
	checked_ = false;
	return this->enemy_id_;
}
```

