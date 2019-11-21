//
// Created by Kratos on 2019/11/14.
//

#pragma once

class CEnemy {
	int health_point_;
	static int killed_num_;
	static int enemy_id_;
public:
	explicit CEnemy(int hp);
	int get_health() const;
	static int get_killed_num();
	int hurt(int kinds);
	~CEnemy();
};
