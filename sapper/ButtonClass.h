#pragma once
#include "Console.h"
#include <string>
#include <vector>
#include <windows.h>
#include <iostream>
#include <conio.h>

/*����� ����������� ������*/
class Button
{
public:
	
	/*����������*/
	Button();
	
	/*	���������� � �����������
		1:	����� ������
		2:	���������� ������ ������ X
		3:	���������� ������ ������ Y
		4:	������� ������������ �� �������
	*/
	Button(std::string, int, int, void (*fun_)());
	
	/*����������*/
	~Button();
	
	/*������� ��� ������ ������*/
	void printButton(ConsoleColor message = White, ConsoleColor background = Black);
	
	/*������� ��� ������ ������� ������*/
	void callFun();
	
private:
	
	/*����� ������*/
	std::string text;
	
	/*���������� ������ ������*/
	int x;
	
	/*���������� ������ ������*/
	int y;
	
	/*������� ������������ �� �������*/
	void (*fun)();
};

/*	����������� ����� ��������
		1: ������ �� "Button"
*/
Button buttonSelection(std::vector<Button>&);

/*�������� ������ � ��������� ��� � ������*/
void creationButons(std::string, int, int, void(*fun)(), std::vector<Button>&);

