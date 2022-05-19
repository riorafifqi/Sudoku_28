#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player
{
	int score;
	string name;
public:
	void setName(string);
	string getName();
	void setScore(int);
	int getScore();
};

