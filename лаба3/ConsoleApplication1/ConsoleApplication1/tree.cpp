#include "stdafx.h"
#include "tree.h"
#include "NodeTree.h"

template<class NODETYPE>
Tree<NODETYPE>::Tree()
{
	root = 0;                      /* в начале дерево пусто */
}

/* вставляет узел */
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
TreeNode<NODETYPE>* Tree<NODETYPE>::get_root()   /* возвращает указатель на корень дерева */
{
	return root;
}

/* удаляет узел */
template<class NODETYPE>
void Tree<NODETYPE>::delete_node1(int z)
{
	
	root = root->delete_node(root, z);
}

/*высота дерева*/
template<class NODETYPE>
int Tree<NODETYPE>::get_height(TreeNode<NODETYPE>* n)
{

	return root->get_height();
}

/*поиск элемента*/
template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_node(TreeNode<NODETYPE>* n, const NODETYPE & val)/*поиск элемента*/
{
	return root->find_node(val);
}

/* печатает все ключи в неубывающем порядке */
template<class NODETYPE>
void Tree<NODETYPE>::print(TreeNode<NODETYPE>* n) /* печатает все ключи в неубывающем порядке */
{
	root->print();
}