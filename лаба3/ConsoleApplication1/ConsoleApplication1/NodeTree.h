#pragma once
//#include "tree.h"

template <class NODETYPE>
class TreeNode //������-�������� ����� ������
{
public:
	TreeNode(const NODETYPE &a);  //������������ ��������� ����	
	void insert_node(TreeNode<NODETYPE>* n, const NODETYPE &z); /*������� ����*/
	NODETYPE get_data();
	void print( ); /* �������� ��� ����� � ����������� ������� */
	TreeNode<NODETYPE>* delete_node(TreeNode<NODETYPE>* tree, int z);   /* ������� ���� */
	TreeNode<NODETYPE>* find_min(TreeNode<NODETYPE>* x);
	TreeNode<NODETYPE>* find_node(const NODETYPE & val);/*����� ��������*/
	int get_height();/* �������� ������ ������ */
protected:
	TreeNode* left;           /* ��������� �� ������ ������� */
	TreeNode* right;          /* ��������� �� ������� ������� */
	TreeNode* parent;         /* ��������� �� �������� */
	NODETYPE data;            /* ���� ��� �������� ����*/
	
};













