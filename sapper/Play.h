#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <ctime>
enum FieldLabels
{
	NullB, OneB, TwoB, TreeB, FourB, FiveB, SixB, Bomb = 9, CheckBox = 10, Open = 100,
};


class Field
{
public:
	void printField(const int x, const int y);
	void setField(int h_, int w_, int bomb_);
	void Play();

private:
	int h;
	int w;
	int bomb;
	int** field;
	void createField();
	void NumForField();
	void NullB(int, int, int, int);
	void PrintAllBomb(const int, const int);
	int bombCheck();
	void loss(const int, const int, int, int);
	void win();
	int wForPrintField;
	int middleX;
};
