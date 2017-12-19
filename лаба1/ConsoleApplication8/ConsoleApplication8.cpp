/*Характеристикой строки матрицы назовём сумму её отрицательных четных элементов. 
Расположить строки в соответствии с убыванием их характеристик*/
// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.

#include <stdafx.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <array>
#include <vector>
using namespace std;

int main()
{
	int nrow, ncol;
	cout << "Enter number of raws: ";
	std::cin >> nrow;
	cout << "Enter number of columns: ";
	std::cin >> ncol;
	int **a = new int *[nrow]; // выделение памяти под массив
	for (int i = 0; i < nrow; i++)
		a[i] = new int[ncol]; // выделение памяти
	cout << "Enter massiv" << endl;
	for (int i = 0; i < nrow; i++) // ввод массива
		for (int j = 0; j < ncol; j++) std::cin >> a[i][j];

	std::pair<long, int*> *HelpMas = new std::pair<long, int*>[nrow]; //массив из пар сумма в строке-указатель на строку
	long sum;

	for (int i = 0; i < nrow; i++) {
		sum = 0;
		for (int j = 0; j < ncol; j++)
			if ((a[i][j]<0) && ((a[i][j] % 2)==0))
				sum += a[i][j];
		HelpMas[i] = make_pair(sum, a[i]);
	}

	std::sort(HelpMas, HelpMas+nrow, greater<>());
	cout << "---------Result--------" << endl;
	int *str;
	for (int i = 0; i < nrow; i++) { // вывод упорядоченной матрицы		
		str = HelpMas[i].second;
		for (int j = 0; j < ncol; j++)
			cout << setw(4) << str[j] << " ";
		cout << setw(2) << "|" <<HelpMas[i].first << endl;
	}	
	getchar();
	getchar();
    return 0;
}

