/*************************************\
* C File
* AUTHOR:   p-tank
* FILE:     ft_stack.c
* CREATED:  14:49:19 17/08/2013
* MODIFIED: 14:49:19 17/08/2013
\*************************************/

#include <unistd.h>
#include <stdlib.h>
#include "../header/bistromathique.h"

t_stree		*init_stree(void)
{
	t_stree	*new_elem;

	new_elem = malloc(sizeof(t_stree));
	if (!new_elem)
	{
		write(2, SYNTAX_ERROR_MSG, ft_strlen(SYNTAX_ERROR_MSG));
		return (NULL);
	}
	new_elem->op_id = '0';
	new_elem->number = NULL;
	new_elem->neg = 0;
	new_elem->right = NULL;
	new_elem->left = NULL;
	return (new_elem);
}
t_stree		*push(char op_id, char *number, int *neg)
{
	t_stree	*new_elem;

	new_elem = init_stree();
	new_elem->op_id = op_id;
	new_elem->number = number;
	new_elem->neg = *neg;
	return (new_elem);
}
t_stree		*read_stree(t_stree *begin)
{
	t_stree *next;

	next = begin;
	if (next->right != NULL && next->right->op_id != '0')
	{
		return(next = read_stree(next->right));
	}
	return (next);
}
t_stree		*read_stree_left(t_stree *begin)
{
	t_stree *next;

	next = begin;
	if (next->left != NULL && next->right != NULL)
	{
		return(next = read_stree(next->right));
	}
	return (next);
}
