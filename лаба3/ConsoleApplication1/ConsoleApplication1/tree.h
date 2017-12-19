#pragma once

using namespace std;
#ifndef _TREE_H
#define _TREE_H


template <class NODETYPE> class Tree;
#include "NODE.h"

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

template<class NODETYPE>
Tree<NODETYPE>::Tree()
{
	root = 0;                      /* в начале дерево пусто */
}

template<class NODETYPE>
int Tree<NODETYPE>::insert_node(const NODETYPE &x)        /* вставляет узел */
{
	TreeNode<NODETYPE>* n = new TreeNode<NODETYPE>(x);  /* создаем новый узел, его мы будем вставлять */
	TreeNode<NODETYPE>* ptr;
	TreeNode<NODETYPE>* ptr1=0;

	n->parent = n->left = n->right = 0;          /* новый узел является листом т.е. левого и правого потомков у него пока нет */
	ptr = root;
	while (ptr != 0)                     /* идем от корня и ищем подходящее место для нового элемента, оно должно быть свободно */
	{
		ptr1 = ptr;                 /* ptr1 -будущий родитель нового узла, ptr-новый узел */
		if (x < ptr->get_data()) /*сравниваем значение текущего узла со значением узла в дереве*/
			ptr = ptr->left;     /* по определению дерева - слева значение ключа меньше родителя, */
		else
			ptr = ptr->right;   /* справа - больше */
	}
	n->parent = ptr1;                  //нашли родителя нового узла
	if (ptr1 == 0)                       /* если дерево было пусто, то новый узел- корень*/
		root = n;
	else
	{
		if (x < ptr1->get_data())       /*записываем значение узла*/
			ptr1->left = n;             /*если меньше то направо*/
		else
			ptr1->right = n;            /*если больше то налево*/
	}
	return 0;
}

/* Возможны три случая при удалении узла z
1.если у z нет детей, то помещаем 0 в соответствующее поле родителя z
2.если у z есть один ребенок, то можно вырезать z, соединив его родителя напрямую с
его ребенком
3.если детей двое, то находим следующий за z элемент y; у которого него нет левого ребенка.
Затем копируем ключ и дополнительные данные из вершины y в вершину z, а саму вершину y удаляем */

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::delete_node(TreeNode<NODETYPE> *z)   /* удаляет узел */
{
	TreeNode<NODETYPE>* y;
	TreeNode<NODETYPE>* x;
	if (z->left == 0 || z->right == 0)               /* ищем вершину y, которую потом нужно вырезать из дерева*/
		y = z;                                       /*если у z нет детей, то будем вырезать узел z*/
	else
		y = find_succ(z->get_data());               /*если есть дети, вырезаем следующий за z элемент*/
	if (y->left != 0)                                  /* x - указатель на существующего ребенка y или 0 если детей нет */
		x = y->left;
	else
		x = y->right;
	if (x != 0)
		x->parent = y->parent;                      /*если у есть дети, то соединяем родителей x и y */
	if (y->parent == 0)
		root = x;                                    /*если у y нет родителя значит x становится корнем дерева*/
	else
	{
		if (y == (y->parent)->left)                /*если y-левый ребенок*/
			(y->parent)->left = x;                 /*левому ребенку y присваиваем x*/
		else
			(y->parent)->right = x;                /*если y-правый ребенок ребенок*//*правму ребенку y присваиваем x */
	}
	if (y != z)                                        /* если мы вырезали вершин, отличную от z, то ее данные перемещаем в z */
		z->data = y->get_data();
	return y;
}



template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_succ(const NODETYPE & val) /* находит следующий элемент */
{
	TreeNode<NODETYPE>* x = find_node(root, val);                     /* получим указатель на узел с ключем val */
	TreeNode<NODETYPE>* y;
	if (x == 0)                                                       /*если у полученного узла нет детей, возвращаем ноль*/
		return 0;
	if (x->right != 0)		       /* если у него есть правые дети, то следующий элемент - минимальный в правом поддереве */
	{
		while (x->left != 0)
			x = x->left;
	}

	y = x->parent;
	while (y != 0 && x == y->right)                                   /* иначе - идем вверх и ищем первый элемент, являющийся левым
																	  потомком своего родителя */
	{
		x = y;
		y = y->parent;
	}
	return y;
}

template<class NODETYPE>
void Tree<NODETYPE>::get_height(TreeNode<NODETYPE>* n, int &res)/* вычисяет высоту дерева и его размеры */
{
	if (n != 0)
	{
		get_height(n->left,res);
		res++;
		get_height(n->right,res);
	}
}

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_node(TreeNode<NODETYPE>* n, const NODETYPE & val) /*поиск элемента*/
{
	if (n == 0 || val == n->get_data())   /*если нашли искодмое значение, то возвращаем найденный узел*/
		return n;
	if (val > n->get_data())              /*если искомое значение > текущего*/
		return find_node(n->right, val);  /*продолжаем поиск справа*/
	else
		return find_node(n->left, val); /*иначе продолжаем поиск слева*/
}

template<class NODETYPE>
void Tree<NODETYPE>::print(TreeNode<NODETYPE>* n) /* печатает все ключи в неубывающем порядке */
{
	if (n != 0)
	{
		print(n->left);
		cout << n->get_data() << endl;
		print(n->right);
	}
}

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::get_root()   /* возвращает указатель на корень дерева */
{
	return root;
}
#endif
