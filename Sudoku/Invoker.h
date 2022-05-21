#pragma once
#include <iostream>
#include <stack>
#include "Commands.h"
#include "Command_Delete.h"
#include "Command_Fill.h"

using namespace std;

class Invoker
{
	stack<Commands*> commands;
public:
	Invoker();
	void pushCommand(Commands*);
	Commands* popCommand();
};

