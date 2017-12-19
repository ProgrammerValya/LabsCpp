#pragma once
#ifndef _NODE_H
#define _NODE_H

template <class NODETYPE> class TreeNode //шаблон-описание узлов дерева
{
	friend class Tree<NODETYPE>;
public:
	TreeNode(const NODETYPE &);  //конструктору передаётся ключ
	NODETYPE get_data();
protected:
	TreeNode* left;           /* указатель на левого ребенка */
	TreeNode* right;          /* указатель на правого ребенка */
	TreeNode* parent;         /* указатель на родителя */
	NODETYPE data;            /* ключ или значение узла*/
};

template<class NODETYPE>
TreeNode <NODETYPE>::TreeNode(const NODETYPE &a)     /*при создании узла, создаем левого и правого ребенка и заносим значение узла*/
{
	data = a;
	left = right = 0;
}
template <class NODETYPE>
NODETYPE TreeNode <NODETYPE>::get_data()             /*метод для получения ключа (или значение) узла*/
{
	return data;
}
#endif
