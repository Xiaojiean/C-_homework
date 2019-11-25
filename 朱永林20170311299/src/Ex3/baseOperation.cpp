//
// Created by Kratos on 2019/11/14.
//

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
