#include "stdafx.h"
#include "NodeTree.h"

template <class NODETYPE>
NODETYPE TreeNode <NODETYPE>::get_data()             //метод для получения ключа (или значение) узла
{
	return data;
}
template<class NODETYPE>
TreeNode<NODETYPE>::TreeNode(const NODETYPE &a)
{
	data = a;
	left = right = 0;
}



