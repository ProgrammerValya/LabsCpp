#pragma once
using namespace std;

template <class NODETYPE> class Tree;
#include "NodeTree.cpp"

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

