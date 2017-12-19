/*��������������� ������ ������� ������ ����� � ������������� ������ ���������. 
����������� ������ � ������������ � ��������� �� �������������*/
// ConsoleApplication8.cpp: ���������� ����� ����� ��� ����������� ����������.

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
	int **a = new int *[nrow]; // ��������� ������ ��� ������
	for (int i = 0; i < nrow; i++)
		a[i] = new int[ncol]; // ��������� ������
	cout << "Enter massiv" << endl;
	for (int i = 0; i < nrow; i++) // ���� �������
		for (int j = 0; j < ncol; j++) std::cin >> a[i][j];

	std::pair<long, int*> *HelpMas = new std::pair<long, int*>[nrow]; //������ �� ��� ����� � ������-��������� �� ������
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
	for (int i = 0; i < nrow; i++) { // ����� ������������� �������		
		str = HelpMas[i].second;
		for (int j = 0; j < ncol; j++)
			cout << setw(4) << str[j] << " ";
		cout << setw(2) << "|" <<HelpMas[i].first << endl;
	}	
	getchar();
	getchar();
    return 0;
}

