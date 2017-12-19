// ConsoleApplication16.cpp: определяет точку входа для консольного приложения.
/*Создать класс Angle для работы с углами на плоскости, задаваемые в градусах и минутах.
Обязательно должны быть реализованы:перевод в радианы, приведение к диапозону 0-360, увеличение и уменьшение угла
на заданную величину, получение синуса, сравнение углов.*/

#include "stdafx.h"
#include <iostream>
#include<locale.h>  
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Angle.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите первый угол" << endl;
	Angle ang1 = Angle::create_elem();
	int variant = 0;
	while (variant != 8) 
	{
		cout
			<< "1. Просмотреть данные об угле\n"
			<< "2. Привести к диапозону 0-360\n"
			<< "3. Показать значение в радианах\n"
			<< "4. Уменьшить угол на заданную величину\n"
			<< "5. Увеличить угол на заданную величину\n"
			<< "6. Сравнить угол с заданным\n"
			<< "7. Найти sin\n"
			<< "8. Выход\n" << endl;
		cout << ">>> ";
		cout << "Выберите вариант: ";
		cin >> variant;
		while ((variant <= 0) || (variant >= 9))
		{
			cout << "Введено неккоректное значение. Повторите ввод \n\n";
			cin >> variant;
		}

		switch (variant)
		{
		case 1: ang1.Display();
			break;
		case 2:
			ang1.Normalize();
			cout << "Результат:" << endl;
			ang1.Display();
			break;
		case 3:
			ang1.ConvertToRadian();
			cout << ang1.ToString()<< "="<< ang1.ConvertToRadian()<<"радиан" << endl;
			break;		
		case 4:
		{
			cout << "Введите второй угол" << endl;
			Angle ang2 = Angle::create_elem();
			ang1.DecreaseAngle(ang2);
			cout << "Результат:" << endl;
			ang1.Display();
			break;
		}
		case 5:
		{
			cout << "Введите второй угол" << endl;
			Angle ang2 = Angle::create_elem();

			ang1.IncreaseAngle(ang2);
			cout << "Результат:" << endl; 
			ang1.Display();
			break;
		}
		case 6:
		{
			cout << "Введите заданный угол" << endl;
			Angle ang2 = Angle::create_elem();
			if (ang1<ang2) cout << "Заданный угол больше текущего" << endl;
			else cout << "Заданный угол меньше текущего" << endl;
			break;
		}
		case 7:
			cout << "sin="<< ang1.GetSin() << endl;
			ang1.GetSin();
			break;
		case 8:
			cout << "Выход из программы..." << endl;
			exit(EXIT_SUCCESS);
			break;
		default:
			cerr << "Вы выбрали неверный вариант" << endl;
			exit(EXIT_FAILURE);
		}
	}

	system("pause");
	return 0;
}
