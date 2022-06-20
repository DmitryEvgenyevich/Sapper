#pragma once
#include <iostream>

class Field
{
public:
	void printField(int x, int y);
	void setField(int h_, int w_, int bomb_);
	void getPresButton();

private:
	int h;
	int w;
	int bomb;
	int** field;
	void createField();
	void NumForField();
	int wForPrintField;
};
