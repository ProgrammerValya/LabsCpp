#pragma once
//#include "tree.h"

template <class NODETYPE>
class TreeNode //шаблон-описание узлов дерева
{
public:
	TreeNode(const NODETYPE &a);  //конструктору передаётся ключ	
	void insert_node(TreeNode<NODETYPE>* n, const NODETYPE &z); /*вставка узла*/
	NODETYPE get_data();
	void print( ); /* печатает все ключи в неубывающем порядке */
	TreeNode<NODETYPE>* delete_node(TreeNode<NODETYPE>* tree, int z);   /* удаляет узел */
	TreeNode<NODETYPE>* find_min(TreeNode<NODETYPE>* x);
	TreeNode<NODETYPE>* find_node(const NODETYPE & val);/*поиск элемента*/
	int get_height();/* вычисяет высоту дерева */
protected:
	TreeNode* left;           /* указатель на левого ребенка */
	TreeNode* right;          /* указатель на правого ребенка */
	TreeNode* parent;         /* указатель на родителя */
	NODETYPE data;            /* ключ или значение узла*/
	
};













