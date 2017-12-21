#pragma once
using namespace std;

template <class NODETYPE> class Tree;
#include "NodeTree.cpp"

template <class NODETYPE> // шаблон-основные операции с деревом
class Tree
{
public:
	Tree();                                                    /* конструктор */
	int insert_node(const NODETYPE &);                         /* вставляет узел */
	TreeNode<NODETYPE>* delete_node(TreeNode<NODETYPE> *);     /* удаляет узел */
	void print(TreeNode<NODETYPE>*);                           /* печатает все ключи в неубывающем порядке */


	TreeNode<NODETYPE>* find_node(TreeNode<NODETYPE>*, const NODETYPE &); /*поиск элемента*/
	TreeNode<NODETYPE>* find_succ(const NODETYPE &);            /* находит элемент с ключем, следующим за данным числом */
	void get_height(TreeNode<NODETYPE>* n, int &res);                         /* вычисяет высоту дерева и его размеры */
	TreeNode<NODETYPE> *get_root();                             /* возвращает указатель на корень дерева */
private:
	TreeNode<NODETYPE> *root;                                   /*корень */
};

