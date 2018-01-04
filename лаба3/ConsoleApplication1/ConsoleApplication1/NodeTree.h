#pragma once

template <class NODETYPE> 
class TreeNode //������-�������� ����� ������
{
friend class Tree<NODETYPE>;   //������ � ��������� ��������� ������ Tree */
public:
	TreeNode(const NODETYPE &a);  //������������ ��������� ����
	NODETYPE get_data();
protected:
	TreeNode* left;           /* ��������� �� ������ ������� */
	TreeNode* right;          /* ��������� �� ������� ������� */
	TreeNode* parent;         /* ��������� �� �������� */
	NODETYPE data;            /* ���� ��� �������� ����*/
};

