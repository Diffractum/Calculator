/*************************************\
* C File
* AUTHOR:   p-tank
* FILE:     push_digit.c
* CREATED:  17:58:11 27/08/2013
* MODIFIED: 17:58:11 27/08/2013
\*************************************/

#include <stdlib.h>
#include <unistd.h>
#include "../header/bistromathique.h"

t_stree		*push_digit(char *expr,char *base, int *i, int *neg, t_stree *begin)
{
	int	j;
	int	k;
	char	*number;
	t_stree	*last;

	j = 0;
	while ((if_digits(expr[*i], base)) != 0)
	{
		j++;
		*i = *i + 1;
	}
	number = malloc(sizeof(char) * j + 1);
	if (!number)
	{
		write(2, SYNTAX_ERROR_MSG, ft_strlen(SYNTAX_ERROR_MSG));
		return (NULL);
	}
	*i = *i - j;
	k = 0;
	while (k != j)
	{
		number[k] = expr[*i];
		*i = *i + 1;
		k++;
	}
	*i = *i - 1;
	number[k] = '\0';
	last = read_stree_left(begin);
	if (last->number == NULL && last->op_id == '0')
	{
		last->number = number;
		last->neg = *neg;
	}
	else if (last->left == NULL)
	{
		last->left = push('0', number, neg);
	}
	else 
	{
		last->right = push('0', number, neg);
	}
	return (begin);
}
t_stree		*push_digit_brac(t_stree *expr, int *neg, t_stree *begin)
{
	t_stree	*last;

	last = read_stree_left(begin);
	if (last->number == NULL && last->op_id == '0')
	{
		last->number = expr->number;
		last->neg = (*neg + expr->neg) / 2;
	}
	else if (last->left == NULL)
	{
		last->left = expr;
		last->left->neg = (*neg + expr->neg) / 2;

	}
	else 
	{
		last->right = expr;
		last->right->neg = (*neg + expr->neg) / 2;
	}
	return (begin);
}
