#include "stdafx.h"
#include "NodeTree.h"

template <class NODETYPE>
NODETYPE TreeNode <NODETYPE>::get_data()             //����� ��� ��������� ����� (��� ��������) ����
{
	return data;
}
template<class NODETYPE>
TreeNode<NODETYPE>::TreeNode(const NODETYPE &a)
{
	data = a;
	left = right = 0;
}



