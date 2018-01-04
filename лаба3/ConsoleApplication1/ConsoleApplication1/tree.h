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
	TreeNode<NODETYPE>* delete_node(TreeNode<NODETYPE>* tree, int z);     /* удаляет узел */
	void print(TreeNode<NODETYPE>*);                           /* печатает все ключи в неубывающем порядке */
	TreeNode<NODETYPE>* find_min(TreeNode<NODETYPE>* x);       /*поиск минимального элемента*/

	TreeNode<NODETYPE>* find_node(TreeNode<NODETYPE>*, const NODETYPE &); /*поиск элемента*/

	int get_height(TreeNode<NODETYPE>* n);                         /* вычисяет высоту дерева и его размеры */
	TreeNode<NODETYPE> *get_root();                             /* возвращает указатель на корень дерева */
private:
	TreeNode<NODETYPE> *root;                                   /*корень */
};

