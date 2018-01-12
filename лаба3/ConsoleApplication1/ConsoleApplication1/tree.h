#pragma once
using namespace std;

template <class NODETYPE> class Tree;
#include "NodeTree.cpp"

template <class NODETYPE> // ������-�������� �������� � �������
class Tree
{
public:
	Tree();                                                    /* ����������� */
	TreeNode<NODETYPE>* get_root();   /* ���������� ��������� �� ������ ������ */
	void delete_node1(int z);				/* ������� ���� */
	int insert_node(const NODETYPE &x);        /* ��������� ���� */
	int get_height(TreeNode<NODETYPE>* n);		/*������ ������*/
	TreeNode<NODETYPE>* find_node(TreeNode<NODETYPE>* n, const NODETYPE & val);/*����� ��������*/
	void print(TreeNode<NODETYPE>* n);			/* �������� ��� ����� � ����������� ������� */
private:
	TreeNode<NODETYPE> *root;                                   /*������ */
	
};
