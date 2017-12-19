// ConsoleApplication16.cpp: ���������� ����� ����� ��� ����������� ����������.
/*������� ����� Angle ��� ������ � ������ �� ���������, ���������� � �������� � �������.
����������� ������ ���� �����������:������� � �������, ���������� � ��������� 0-360, ���������� � ���������� ����
�� �������� ��������, ��������� ������, ��������� �����.*/

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
	cout << "������� ������ ����" << endl;
	Angle ang1 = Angle::create_elem();
	int variant = 0;
	while (variant != 8) 
	{
		cout
			<< "1. ����������� ������ �� ����\n"
			<< "2. �������� � ��������� 0-360\n"
			<< "3. �������� �������� � ��������\n"
			<< "4. ��������� ���� �� �������� ��������\n"
			<< "5. ��������� ���� �� �������� ��������\n"
			<< "6. �������� ���� � ��������\n"
			<< "7. ����� sin\n"
			<< "8. �����\n" << endl;
		cout << ">>> ";
		cout << "�������� �������: ";
		cin >> variant;
		while ((variant <= 0) || (variant >= 9))
		{
			cout << "������� ������������ ��������. ��������� ���� \n\n";
			cin >> variant;
		}

		switch (variant)
		{
		case 1: ang1.Display();
			break;
		case 2:
			ang1.Normalize();
			cout << "���������:" << endl;
			ang1.Display();
			break;
		case 3:
			ang1.ConvertToRadian();
			cout << ang1.ToString()<< "="<< ang1.ConvertToRadian()<<"������" << endl;
			break;		
		case 4:
		{
			cout << "������� ������ ����" << endl;
			Angle ang2 = Angle::create_elem();
			ang1.DecreaseAngle(ang2);
			cout << "���������:" << endl;
			ang1.Display();
			break;
		}
		case 5:
		{
			cout << "������� ������ ����" << endl;
			Angle ang2 = Angle::create_elem();

			ang1.IncreaseAngle(ang2);
			cout << "���������:" << endl; 
			ang1.Display();
			break;
		}
		case 6:
		{
			cout << "������� �������� ����" << endl;
			Angle ang2 = Angle::create_elem();
			if (ang1<ang2) cout << "�������� ���� ������ ��������" << endl;
			else cout << "�������� ���� ������ ��������" << endl;
			break;
		}
		case 7:
			cout << "sin="<< ang1.GetSin() << endl;
			ang1.GetSin();
			break;
		case 8:
			cout << "����� �� ���������..." << endl;
			exit(EXIT_SUCCESS);
			break;
		default:
			cerr << "�� ������� �������� �������" << endl;
			exit(EXIT_FAILURE);
		}
	}

	system("pause");
	return 0;
}
