/*************************************\
* C File
* AUTHOR:   p-tank
* FILE:     push_ops.c
* CREATED:  15:19:03 19/08/2013
* MODIFIED: 15:19:03 19/08/2013
\*************************************/

#include <stdlib.h>
#include "../includes/bistromathique.h"

int	first_neg(char *expr, int *i, char *ops)
{
	int	positiv;
	int	negativ;

	positiv = 0;
	negativ = 0;
	while (expr[*i] == ops[2] || expr[*i] == ops[3])
	{
		if (expr[*i] == ops[2])
		{
			positiv++;
		}
		else
		{
			negativ++;
		}
		*i = *i + 1;
	}
	if (positiv < negativ)
	{
		return(1);
	}
	return (0);
}
char	test_ops(char expr, char *ops)
{
	int	i;
	char	*str_ops;

	str_ops = "()+-*/%";
	i = 0;
	while (ops[i] != expr)
	{
		i++;
	}
	return (str_ops[i]);
}
t_stree		*push_ops(char *expr, t_stree *begin, int *neg, char *ops, char *base)
{
	t_stree	*current_elem;
	t_stree *last;
	char	*expr_test;

	last = read_stree(begin);
	if (*expr == ops[2])
	{
		current_elem = push('+', NULL, neg);
		if (last->number != NULL)
		{
			current_elem->left = begin;
		}
		else
		{
			current_elem->right = begin;
		}
		begin = current_elem;
	}
	else if (*expr == ops[3])
	{
		expr_test = expr - 1;
		while (if_digits(*expr_test, base) == 0 && if_ops(*expr_test, ops) == 0)
		{
			expr_test = expr_test - 1;
		}
		if (if_ops(*expr_test, ops))
		{
			*neg = 1;
		}
		else 
		{
			current_elem = push('-', NULL, neg);
			if (last->number != NULL)
			{
				current_elem->left = begin;
			}
			else
			{
				current_elem->right = begin;
			}
			begin = current_elem;
		}
	}
	else
	{
		current_elem = push(test_ops(*expr, ops), NULL, neg);
		if (last->number != NULL)
		{
			current_elem->left = begin;
			begin = current_elem;
		}
		else
		{
			last->right = current_elem;
		}
	}
	return (begin);
}
