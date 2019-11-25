//
// Created by Kratos on 2019/11/14.
//

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
