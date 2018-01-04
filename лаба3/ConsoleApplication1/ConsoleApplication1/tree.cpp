#include "stdafx.h"
#include "tree.h"

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
	TreeNode<NODETYPE>* ptr1 = 0;

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
TreeNode<NODETYPE>* Tree<NODETYPE>::delete_node(TreeNode<NODETYPE>* tree, int z)   /* ������� ���� */
{
	if (tree == NULL)
		return tree;

	if (z < tree->get_data())
	{
		(*tree).left = delete_node((*tree).left, z);     //���� ������� ���� ������ ���������, �� ��������� �����
	}
	else
		if (z > tree->get_data())
		{
			(*tree).right = delete_node((*tree).right, z);  //���� ������� ���� ������ ���������, �� ��������� ������
		}
		else
			if ((tree->left != NULL) & (tree->right != NULL))    //���� ���� ������ � ����� �������
			{
				tree->data = find_min(tree->right)->get_data();   //�������� ����������� ��������� �� ������� ��������� 			
				tree->right = delete_node(tree->right, tree->get_data()); 	//���������� ������� ���� ����������� �������
			}
			else
				if (tree->left != NULL)   //���� ����  ����� �������
				{
					if (tree->parent == 0)
					{
						if (tree->left != 0)
							tree->left->parent = tree->parent;
						root = tree->left;

					}
					else
						tree = tree->left;

				}
				else          //���� ��� ������ �������
				{
					if (tree->parent == 0)
					{
						if (tree->right != 0)
							tree->right->parent = tree->parent;
						root = tree->right;

					}
					else
						tree = tree->right;

				}

	return tree;
}

/*����� ������������ ��������*/
template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_min(TreeNode<NODETYPE>* x)
{
	while (x->left != 0)
		x = x->left;
	return x;
}


template<class NODETYPE>
int Tree<NODETYPE>::get_height(TreeNode<NODETYPE>* n)/* �������� ������ ������ */
{
	if (n == 0)
		return 0;
	int left, right;
	if (n->left != NULL) {
		left = get_height(n->left);
	}
	else
		left = 0;
	if (n->right != NULL) {
		right = get_height(n->right);
	}
	else
		right = 0;
	int max = left > right ? left : right;
	return max + 1;
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