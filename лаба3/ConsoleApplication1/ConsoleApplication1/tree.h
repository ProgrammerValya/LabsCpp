#pragma once
using namespace std;

template <class NODETYPE> class Tree;
#include "NodeTree.cpp"

template <class NODETYPE> // шаблон-основные операции с деревом
class Tree
{
public:
	Tree();                                                    /* конструктор */
	TreeNode<NODETYPE>* get_root();   /* возвращает указатель на корень дерева */
	void delete_node1(int z);				/* удаляет узел */
	int insert_node(const NODETYPE &x);        /* вставляет узел */
	int get_height(TreeNode<NODETYPE>* n);		/*высота дерева*/
	TreeNode<NODETYPE>* find_node(TreeNode<NODETYPE>* n, const NODETYPE & val);/*поиск элемента*/
	void print(TreeNode<NODETYPE>* n);			/* печатает все ключи в неубывающем порядке */
private:
	TreeNode<NODETYPE> *root;                                   /*корень */
	
};
