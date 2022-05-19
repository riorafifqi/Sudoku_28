#include "Invoker.h"

void Invoker::pushCommand(Commands *command)
{
	commands.push(*command);
}

Commands* Invoker::popCommand()
{
	cout << "Pop" << endl;
	Commands* temp;

	temp = &commands.top();
	commands.pop();

	return temp;
}
