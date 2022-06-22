#pragma once
#include "Console.h"
#include <string>
#include <vector>
#include <windows.h>
#include <iostream>
#include <conio.h>

/*Класс описывающий кнопку*/
class Button
{
public:
	
	/*Констуктор*/
	Button();
	
	/*	Констуктор с параметрами
		1:	Текст кнопки
		2:	Координаты вывода кнопки X
		3:	Координаты вывода кнопки Y
		4:	Функция закрепленная за кнопкой
	*/
	Button(std::string, int, int, void (*fun_)());
	
	/*Деструктор*/
	~Button();
	
	/*Функция для вивода кнопки*/
	void printButton(ConsoleColor message = White, ConsoleColor background = Black);
	
	/*Функция для вызова функции кнопки*/
	void callFun();
	
private:
	
	/*Текст кнопки*/
	std::string text;
	
	/*Координаты вывода кнопки*/
	int x;
	
	/*Координаты вывода кнопки*/
	int y;
	
	/*Функция закрепленная за кнопкой*/
	void (*fun)();
};

/*	Перемещение между кнопками
		1: массви из "Button"
*/
Button buttonSelection(std::vector<Button>&);

/*Создание кнопки и занисение его в массив*/
void creationButons(std::string, int, int, void(*fun)(), std::vector<Button>&);

