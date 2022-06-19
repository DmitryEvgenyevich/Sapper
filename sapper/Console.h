#pragma once 
#include<string>

/*Список кодов цветов*/
enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White,
};

/*Список кодов клавиш клавиатуры*/
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

/*	Функция для смены цвета в консоли
	1:	Цвет текста 
	2:	Цвет фона
*/
void setColor(ConsoleColor text = White, ConsoleColor background = Black);

/*	Присвоить новую позицию в консоли
	1:	Новые координаты X
	2:	Новые координаты Y
*/
void setPosition(int, int);

/*	Число в текст
	1:	Число которое хотим переобразовать в текст
*/
std::string intToStr(int);

/*	Присвоить размер окна консоли
	1:	Ширина
	2:	Высота
*/
void setWindowSize(int, int);

/*Получить X позицыю*/
int getPositionX();

/*Получить Y позицыю*/
int getPositionY();
