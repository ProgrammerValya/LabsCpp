#pragma once

using namespace std;
#ifndef _TREE_H
#define _TREE_H


template <class NODETYPE> class Tree;
#include "NODE.h"

template <class NODETYPE> // ������-�������� �������� � �������
class Tree
{
public:
	Tree();                                                    /* ����������� */
	int insert_node(const NODETYPE &);                         /* ��������� ���� */
	TreeNode<NODETYPE>* delete_node(TreeNode<NODETYPE> *);     /* ������� ���� */
	void print(TreeNode<NODETYPE>*);                           /* �������� ��� ����� � ����������� ������� */
	
	
	TreeNode<NODETYPE>* find_node(TreeNode<NODETYPE>*, const NODETYPE &); /*����� ��������*/
	TreeNode<NODETYPE>* find_succ(const NODETYPE &);            /* ������� ������� � ������, ��������� �� ������ ������ */
	void get_height(TreeNode<NODETYPE>* n, int &res);                         /* �������� ������ ������ � ��� ������� */
	TreeNode<NODETYPE> *get_root();                             /* ���������� ��������� �� ������ ������ */
private:
	TreeNode<NODETYPE> *root;                                   /*������ */
};

template<class NODETYPE>
Tree<NODETYPE>::Tree()
{
	root = 0;                      /* � ������ ������ ����� */
}

template<class NODETYPE>
int Tree<NODETYPE>::insert_node(const NODETYPE &x)        /* ��������� ���� */
{
	TreeNode<NODETYPE>* n = new TreeNode<NODETYPE>(x);  /* ������� ����� ����, ��� �� ����� ��������� */
	TreeNode<NODETYPE>* ptr;
	TreeNode<NODETYPE>* ptr1=0;

	n->parent = n->left = n->right = 0;          /* ����� ���� �������� ������ �.�. ������ � ������� �������� � ���� ���� ��� */
	ptr = root;
	while (ptr != 0)                     /* ���� �� ����� � ���� ���������� ����� ��� ������ ��������, ��� ������ ���� �������� */
	{
		ptr1 = ptr;                 /* ptr1 -������� �������� ������ ����, ptr-����� ���� */
		if (x < ptr->get_data()) /*���������� �������� �������� ���� �� ��������� ���� � ������*/
			ptr = ptr->left;     /* �� ����������� ������ - ����� �������� ����� ������ ��������, */
		else
			ptr = ptr->right;   /* ������ - ������ */
	}
	n->parent = ptr1;                  //����� �������� ������ ����
	if (ptr1 == 0)                       /* ���� ������ ���� �����, �� ����� ����- ������*/
		root = n;
	else
	{
		if (x < ptr1->get_data())       /*���������� �������� ����*/
			ptr1->left = n;             /*���� ������ �� �������*/
		else
			ptr1->right = n;            /*���� ������ �� ������*/
	}
	return 0;
}

/* �������� ��� ������ ��� �������� ���� z
1.���� � z ��� �����, �� �������� 0 � ��������������� ���� �������� z
2.���� � z ���� ���� �������, �� ����� �������� z, �������� ��� �������� �������� �
��� ��������
3.���� ����� ����, �� ������� ��������� �� z ������� y; � �������� ���� ��� ������ �������.
����� �������� ���� � �������������� ������ �� ������� y � ������� z, � ���� ������� y ������� */

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::delete_node(TreeNode<NODETYPE> *z)   /* ������� ���� */
{
	TreeNode<NODETYPE>* y;
	TreeNode<NODETYPE>* x;
	if (z->left == 0 || z->right == 0)               /* ���� ������� y, ������� ����� ����� �������� �� ������*/
		y = z;                                       /*���� � z ��� �����, �� ����� �������� ���� z*/
	else
		y = find_succ(z->get_data());               /*���� ���� ����, �������� ��������� �� z �������*/
	if (y->left != 0)                                  /* x - ��������� �� ������������� ������� y ��� 0 ���� ����� ��� */
		x = y->left;
	else
		x = y->right;
	if (x != 0)
		x->parent = y->parent;                      /*���� � ���� ����, �� ��������� ��������� x � y */
	if (y->parent == 0)
		root = x;                                    /*���� � y ��� �������� ������ x ���������� ������ ������*/
	else
	{
		if (y == (y->parent)->left)                /*���� y-����� �������*/
			(y->parent)->left = x;                 /*������ ������� y ����������� x*/
		else
			(y->parent)->right = x;                /*���� y-������ ������� �������*//*������ ������� y ����������� x */
	}
	if (y != z)                                        /* ���� �� �������� ������, �������� �� z, �� �� ������ ���������� � z */
		z->data = y->get_data();
	return y;
}



template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_succ(const NODETYPE & val) /* ������� ��������� ������� */
{
	TreeNode<NODETYPE>* x = find_node(root, val);                     /* ������� ��������� �� ���� � ������ val */
	TreeNode<NODETYPE>* y;
	if (x == 0)                                                       /*���� � ����������� ���� ��� �����, ���������� ����*/
		return 0;
	if (x->right != 0)		       /* ���� � ���� ���� ������ ����, �� ��������� ������� - ����������� � ������ ��������� */
	{
		while (x->left != 0)
			x = x->left;
	}

	y = x->parent;
	while (y != 0 && x == y->right)                                   /* ����� - ���� ����� � ���� ������ �������, ���������� �����
																	  �������� ������ �������� */
	{
		x = y;
		y = y->parent;
	}
	return y;
}

template<class NODETYPE>
void Tree<NODETYPE>::get_height(TreeNode<NODETYPE>* n, int &res)/* �������� ������ ������ � ��� ������� */
{
	if (n != 0)
	{
		get_height(n->left,res);
		res++;
		get_height(n->right,res);
	}
}

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_node(TreeNode<NODETYPE>* n, const NODETYPE & val) /*����� ��������*/
{
	if (n == 0 || val == n->get_data())   /*���� ����� �������� ��������, �� ���������� ��������� ����*/
		return n;
	if (val > n->get_data())              /*���� ������� �������� > ��������*/
		return find_node(n->right, val);  /*���������� ����� ������*/
	else
		return find_node(n->left, val); /*����� ���������� ����� �����*/
}

template<class NODETYPE>
void Tree<NODETYPE>::print(TreeNode<NODETYPE>* n) /* �������� ��� ����� � ����������� ������� */
{
	if (n != 0)
	{
		print(n->left);
		cout << n->get_data() << endl;
		print(n->right);
	}
}

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::get_root()   /* ���������� ��������� �� ������ ������ */
{
	return root;
}
#endif
