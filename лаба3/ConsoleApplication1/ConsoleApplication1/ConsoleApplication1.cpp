// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
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
	Tree<int> intTree;           /* создаем новой бинароное дерево с ключем типа int */	
	int a;
	int variant = 0;
	while (variant != 6)
	{
		cout
			<< "1. Вставка элемента в дерево\n"
			<< "2. Удаление элемента из дерева\n"
			<< "3. Поиск элемента\n"
			<< "4. Вычисление высоты дерева и его размера\n"
			<< "5. Метод печати дерева\n"
			<< "6. Выход\n" << endl;
		cout << ">>> ";
		cout << "Выберите вариант: ";
		cin >> variant;
		while ((variant <= 0) || (variant >= 7))
		{
			cout << "Введено неккоректное значение. Повторите ввод \n\n";
			cin >> variant;
		}
		switch (variant)
		{
		case 1: cout << "Введите значение элемента: " << endl;   /* заполняем его */			
				cin >> a;
				intTree.insert_node(a);
			break;
		case 2:
			cout << "Введите элемент, который нужно удалить: ";     /* попробуем удалить узел с ключем a */
			cin >> a;
			intTree.delete_node(intTree.get_root(),a);    /* если их несколько, то удалится первый найденный */
			cout << "Результат" << endl;
			intTree.print(intTree.get_root());
			break;
		case 3:
			cout << "Введите элемент, который нужно найти: ";     
			cin >> a;
			if (intTree.find_node(intTree.get_root(),a)!=0) cout << "Элемент найден"<<endl;
			break;
		case 4:
		{
			cout << "Высота дерева: " << intTree.get_height(intTree.get_root()) << endl;
			break;
		}
		case 5:
		{
			intTree.print(intTree.get_root());		
			break;
		}
		case 6:
		{
			cout << "Выход из программы..." << endl;
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