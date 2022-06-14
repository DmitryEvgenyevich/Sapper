#pragma once
#include <string>

class Button
{
public:
	Button();
	Button(std::string);
	~Button();
	void printButton(int, int);

private:
	std::string text;
};
