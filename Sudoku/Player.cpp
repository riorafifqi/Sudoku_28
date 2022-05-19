#include "Player.h"

void Player::setName(string name)
{
	this->name = name;
}

string Player::getName()
{
	return this->name;
}

void Player::setScore(int score)
{
	this->score = score;
}

int Player::getScore()
{
	return this->score;
}
