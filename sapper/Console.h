#pragma once 
#include<string>

/*������ ����� ������*/
enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White,
};

/*������ ����� ������ ����������*/
enum KeyboardKeys
{
	Backspace = 8,
	escape = 27,
	Space = 32,
	Enter = 13,
	UpArrow = 72,
	DownArrow = 80,
	LeftArrow = 75,
	RightArrow = 77,
};

/*	������� ��� ����� ����� � �������
	1:	���� ������ 
	2:	���� ����
*/
void setColor(ConsoleColor text = White, ConsoleColor background = Black);

/*	��������� ����� ������� � �������
	1:	����� ���������� X
	2:	����� ���������� Y
*/
void setPosition(int, int);

/*	����� � �����
	1:	����� ������� ����� �������������� � �����
*/
std::string intToStr(int);

/*	��������� ������ ���� �������
	1:	������
	2:	������
*/
void setWindowSize(int, int);

/*�������� X �������*/
int getPositionX();

/*�������� Y �������*/
int getPositionY();
