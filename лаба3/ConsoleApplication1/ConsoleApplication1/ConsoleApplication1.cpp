// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include<locale.h>  
#include <iostream>
#include <iomanip>
#include "tree.cpp"
#include "NodeTree.cpp"
#include <string>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "RUS");
	Tree<int> intTree;           /* ������� ����� ��������� ������ � ������ ���� int */	
	int a;
	int variant = 0;
	while (variant != 6)
	{
		cout
			<< "1. ������� �������� � ������\n"
			<< "2. �������� �������� �� ������\n"
			<< "3. ����� ��������\n"
			<< "4. ���������� ������ ������ � ��� �������\n"
			<< "5. ����� ������ ������\n"
			<< "6. �����\n" << endl;
		cout << ">>> ";
		cout << "�������� �������: ";
		cin >> variant;
		while ((variant <= 0) || (variant >= 7))
		{
			cout << "������� ������������ ��������. ��������� ���� \n\n";
			cin >> variant;
		}
		switch (variant)
		{
		case 1: cout << "������� �������� ��������: " << endl;   /* ��������� ��� */			
				cin >> a;
				intTree.insert_node(a);
			break;
		case 2:
			cout << "������� �������, ������� ����� �������: ";     /* ��������� ������� ���� � ������ a */
			cin >> a;
			intTree.delete_node(intTree.get_root(),a);    /* ���� �� ���������, �� �������� ������ ��������� */
			cout << "���������" << endl;
			intTree.print(intTree.get_root());
			break;
		case 3:
			cout << "������� �������, ������� ����� �����: ";     
			cin >> a;
			if (intTree.find_node(intTree.get_root(),a)!=0) cout << "������� ������"<<endl;
			break;
		case 4:
		{
			cout << "������ ������: " << intTree.get_height(intTree.get_root()) << endl;
			break;
		}
		case 5:
		{
			intTree.print(intTree.get_root());		
			break;
		}
		case 6:
		{
			cout << "����� �� ���������..." << endl;
			exit(EXIT_SUCCESS);
			break;
		}
		default:

			exit(EXIT_FAILURE);
		}
	}

	system("pause");
	return 0;


}