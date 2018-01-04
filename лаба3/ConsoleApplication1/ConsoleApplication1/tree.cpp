#include "stdafx.h"
#include "tree.h"

template<class NODETYPE>
Tree<NODETYPE>::Tree()
{
	root = 0;                      /* в начале дерево пусто */
}

template<class NODETYPE>
int Tree<NODETYPE>::insert_node(const NODETYPE &x)        /* вставляет узел */
{
	TreeNode<NODETYPE>* n = new TreeNode<NODETYPE>(x);  /* создаем новый узел, его мы будем вставлять */
	TreeNode<NODETYPE>* ptr;
	TreeNode<NODETYPE>* ptr1 = 0;

	n->parent = n->left = n->right = 0;          /* новый узел является листом т.е. левого и правого потомков у него пока нет */
	ptr = root;
	while (ptr != 0)                     /* идем от корня и ищем подходящее место для нового элемента, оно должно быть свободно */
	{
		ptr1 = ptr;                 /* ptr1 -будущий родитель нового узла, ptr-новый узел */
		if (x < ptr->get_data()) /*сравниваем значение текущего узла со значением узла в дереве*/
			ptr = ptr->left;     /* по определению дерева - слева значение ключа меньше родителя, */
		else
			ptr = ptr->right;   /* справа - больше */
	}
	n->parent = ptr1;                  //нашли родителя нового узла
	if (ptr1 == 0)                       /* если дерево было пусто, то новый узел- корень*/
		root = n;
	else
	{
		if (x < ptr1->get_data())       /*записываем значение узла*/
			ptr1->left = n;             /*если меньше то направо*/
		else
			ptr1->right = n;            /*если больше то налево*/
	}
	return 0;
}

/* Возможны три случая при удалении узла z
1.если у z нет детей, то помещаем 0 в соответствующее поле родителя z
2.если у z есть один ребенок, то можно вырезать z, соединив его родителя напрямую с
его ребенком
3.если детей двое, то находим следующий за z элемент y; у которого него нет левого ребенка.
Затем копируем ключ и дополнительные данные из вершины y в вершину z, а саму вершину y удаляем */

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::delete_node(TreeNode<NODETYPE>* tree, int z)   /* удаляет узел */
{
	if (tree == NULL)
		return tree;

	if (z < tree->get_data())
	{
		(*tree).left = delete_node((*tree).left, z);     //если текущий узел больше заданного, то двигаемся влево
	}
	else
		if (z > tree->get_data())
		{
			(*tree).right = delete_node((*tree).right, z);  //если текущий узел меньше заданного, то двигаемся вправо
		}
		else
			if ((tree->left != NULL) & (tree->right != NULL))    //если есть правый и левый потомки
			{
				tree->data = find_min(tree->right)->get_data();   //заменяем минимальным элементом из правого поддерева 			
				tree->right = delete_node(tree->right, tree->get_data()); 	//рекурсивно удаляем этот минимальный элемент
			}
			else
				if (tree->left != NULL)   //если есть  левый потомок
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
				else          //если нет левого потомка
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

/*поиск минимального элемента*/
template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_min(TreeNode<NODETYPE>* x)
{
	while (x->left != 0)
		x = x->left;
	return x;
}


template<class NODETYPE>
int Tree<NODETYPE>::get_height(TreeNode<NODETYPE>* n)/* вычисяет высоту дерева */
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
TreeNode<NODETYPE>* Tree<NODETYPE>::find_node(TreeNode<NODETYPE>* n, const NODETYPE & val) /*поиск элемента*/
{
	if (n == 0 || val == n->get_data())   /*если нашли искодмое значение, то возвращаем найденный узел*/
		return n;
	if (val > n->get_data())              /*если искомое значение > текущего*/
		return find_node(n->right, val);  /*продолжаем поиск справа*/
	else
		return find_node(n->left, val); /*иначе продолжаем поиск слева*/
}

template<class NODETYPE>
void Tree<NODETYPE>::print(TreeNode<NODETYPE>* n) /* печатает все ключи в неубывающем порядке */
{
	if (n != 0)
	{
		print(n->left);
		cout << n->get_data() << endl;
		print(n->right);
	}
}

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::get_root()   /* возвращает указатель на корень дерева */
{
	return root;
}