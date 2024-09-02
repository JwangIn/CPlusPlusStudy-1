#pragma once
#include <iostream>
#include <string>
#include <vector>

class Bullet
{
private:
	int range;
public:
	Bullet() {}
	~Bullet(){}
	void Shoot();
};


class Monster
{
private:
	int HP;
	Bullet* bullet;
public:
	Monster(){}
	~Monster(){}
	void Attack();
};

class Player
{
private:
	int HP;
	Bullet* bullet;
public:
	Player(){}
	~Player(){}
	void Move();
	void Attack();
};