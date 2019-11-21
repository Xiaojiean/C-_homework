//
// Created by Kratos on 2019/11/14.
//

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
