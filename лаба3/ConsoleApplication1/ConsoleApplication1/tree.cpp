#include "stdafx.h"
#include "tree.h"
#include "NodeTree.h"

template<class NODETYPE>
Tree<NODETYPE>::Tree()
{
	root = 0;                      /* � ������ ������ ����� */
}

/* ��������� ���� */
template<class NODETYPE>
int Tree<NODETYPE>::insert_node(const NODETYPE &n)        
{
	if (root == 0)
	{
		root= new TreeNode<NODETYPE>(n);
	}
	else
	 root->insert_node(root,n);

	return 0;
}


template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::get_root()   /* ���������� ��������� �� ������ ������ */
{
	return root;
}

/* ������� ���� */
template<class NODETYPE>
void Tree<NODETYPE>::delete_node1(int z)
{
	
	root = root->delete_node(root, z);
}

/*������ ������*/
template<class NODETYPE>
int Tree<NODETYPE>::get_height(TreeNode<NODETYPE>* n)
{

	return root->get_height();
}

/*����� ��������*/
template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_node(TreeNode<NODETYPE>* n, const NODETYPE & val)/*����� ��������*/
{
	return root->find_node(val);
}

/* �������� ��� ����� � ����������� ������� */
template<class NODETYPE>
void Tree<NODETYPE>::print(TreeNode<NODETYPE>* n) /* �������� ��� ����� � ����������� ������� */
{
	root->print();
}