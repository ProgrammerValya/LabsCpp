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
	TreeNode<NODETYPE>* delete_node(TreeNode<NODETYPE>* tree, int z);     /* ������� ���� */
	void print(TreeNode<NODETYPE>*);                           /* �������� ��� ����� � ����������� ������� */
	TreeNode<NODETYPE>* find_min(TreeNode<NODETYPE>* x);       /*����� ������������ ��������*/

	TreeNode<NODETYPE>* find_node(TreeNode<NODETYPE>*, const NODETYPE &); /*����� ��������*/

	int get_height(TreeNode<NODETYPE>* n);                         /* �������� ������ ������ � ��� ������� */
	TreeNode<NODETYPE> *get_root();                             /* ���������� ��������� �� ������ ������ */
private:
	TreeNode<NODETYPE> *root;                                   /*������ */
};

