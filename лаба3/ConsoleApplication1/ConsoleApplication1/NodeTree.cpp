#include "stdafx.h"
#include "NodeTree.h"

template<class NODETYPE>
TreeNode<NODETYPE>::TreeNode(const NODETYPE &a)
{
	data = a;
	left = right = 0;

}

/* ��������� ���� */
template<class NODETYPE>
void TreeNode<NODETYPE>::insert_node(TreeNode<NODETYPE>* x, const NODETYPE &n)
{
	TreeNode<NODETYPE>* z = new TreeNode<NODETYPE>(n);

	while (x != 0)
	{
		if (z->data > x->data)

			if (x->right != 0)
				x = x->right;
			else
			{
				z->parent = x;
				x->right = z;
				break;
			}

		else
		{
			if (z->data < x->data)
				if (x->left != 0)
					x = x->left;
				else
				{
					z->parent = x;
					x->left = z;
					break;
				}
		}
	}
}

//����� ��� ��������� ����� (��� ��������) ����
template <class NODETYPE>
NODETYPE TreeNode <NODETYPE>::get_data()
{
	return data;

}

/* �������� ��� ����� � ����������� ������� */
template<class NODETYPE>
void TreeNode<NODETYPE>::print(/*TreeNode<NODETYPE>* n*/)
{
	if (this != 0)
	{
		this->left->print();
		cout << this->get_data() << endl;
		this->right->print();
	}
}

/*����� ������������ ��������*/
template<class NODETYPE>
TreeNode<NODETYPE>* TreeNode<NODETYPE>::find_min(TreeNode<NODETYPE>* x)
{
	while (x->left != 0)
		x = x->left;
	return x;
}

/*����� ��������*/
template<class NODETYPE>
TreeNode<NODETYPE>* TreeNode<NODETYPE>::find_node(const NODETYPE & val)
{
	if (this == 0 || val == this->get_data())   /*���� ����� �������� ��������, �� ���������� ��������� ����*/
		return this;
	if (val > this->get_data())              /*���� ������� �������� > ��������*/
		return this->right->find_node(val);  /*���������� ����� ������*/
	else
		return this->left->find_node(val); /*����� ���������� ����� �����*/
}



template<class NODETYPE>
int TreeNode<NODETYPE>::get_height()
{
	if (this == 0)
		return 0;
	int left, right;
	if (this->left != NULL) {
		left = this->left->get_height();
	}
	else
		left = 0;
	if (this->right != NULL) {
		right = this->right->get_height();
	}
	else
		right = 0;
	int max;
	if (left > right)
		max = left;
	else
		max = right;
	return max + 1;
}

/* ������� ���� */
template<class NODETYPE>
TreeNode<NODETYPE>* TreeNode<NODETYPE>::delete_node(TreeNode<NODETYPE>* tree, int z)
{
	if (tree == NULL)
		return tree;

	if (z < tree->get_data())
	{
		(*tree).left = delete_node((*tree).left, z);     //���� ������� ���� ������ ���������, �� ��������� �����
	}
	else if (z > tree->get_data())
	{
		(*tree).right = delete_node((*tree).right, z);  //���� ������� ���� ������ ���������, �� ��������� ������
	}
	else
	{
		if ((tree->left != NULL) && (tree->right != NULL))    //���� ���� ������ � ����� �������
		{
			tree->data = tree->find_min(tree->right)->get_data();   //�������� ����������� ��������� �� ������� ��������� 			
			tree->right = delete_node(tree->right, tree->get_data()); 	//���������� ������� ���� ����������� �������
		}
		else
		{
			if (tree->left != NULL)   //���� ����  ����� �������
			{

				tree = tree->left;
			}
			else          //���� ��� ������ �������
			{

				tree = tree->right;
			}

			if (tree != nullptr)
				tree->parent = tree->parent->parent;
		}
	}

	return tree;
}
