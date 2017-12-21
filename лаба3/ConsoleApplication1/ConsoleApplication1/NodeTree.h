#pragma once
template <class NODETYPE> class TreeNode //������-�������� ����� ������
{
	friend class Tree<NODETYPE>;   //������ � ��������� ��������� ������ Tree
public:
	TreeNode(const NODETYPE &);  //������������ ��������� ����
	NODETYPE get_data();
protected:
	TreeNode* left;           /* ��������� �� ������ ������� */
	TreeNode* right;          /* ��������� �� ������� ������� */
	TreeNode* parent;         /* ��������� �� �������� */
	NODETYPE data;            /* ���� ��� �������� ����*/
};




