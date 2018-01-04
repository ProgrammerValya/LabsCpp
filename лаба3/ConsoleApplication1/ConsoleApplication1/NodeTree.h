#pragma once

template <class NODETYPE> 
class TreeNode //шаблон-описание узлов дерева
{
friend class Tree<NODETYPE>;   //доступ к приватным элементам классу Tree */
public:
	TreeNode(const NODETYPE &a);  //конструктору передаётся ключ
	NODETYPE get_data();
protected:
	TreeNode* left;           /* указатель на левого ребенка */
	TreeNode* right;          /* указатель на правого ребенка */
	TreeNode* parent;         /* указатель на родителя */
	NODETYPE data;            /* ключ или значение узла*/
};

