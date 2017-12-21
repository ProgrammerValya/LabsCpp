#include "stdafx.h"
#include "NodeTree.h"

template<class NODETYPE>
TreeNode <NODETYPE>::TreeNode(const NODETYPE &a)     /*при создании узла, создаем левого и правого ребенка и заносим значение узла*/
{
	data = a;
	left = right = 0;
}

template <class NODETYPE>
NODETYPE TreeNode <NODETYPE>::get_data()             /*метод для получения ключа (или значение) узла*/
{
	return data;
}



