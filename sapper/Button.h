#pragma once
#include <string>
#include <vector>

class Button
{
public:
	Button();
	Button(std::string, int, int, void (*fun_)());
	~Button();
	void printButton(ConsoleColor message = White, ConsoleColor background = Black);
	void (*fun)();
	
private:
	std::string text;
	int x;
	int y;
	
};

Button buttonSelection(std::vector<Button>);
