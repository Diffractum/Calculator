/*************************************\
* C File
* AUTHOR:   p-tank
* FILE:     ft_eval_expr.c
* CREATED:  12:11:52 17/08/2013
* MODIFIED: 12:11:52 17/08/2013
\*************************************/

#include <stdlib.h>
#include <unistd.h>
#include "../header/bistromathique.h"


int	test_base_and_ops(char *base, char *ops)
{
	int	i;

	if ((ft_strcmp_repeat(base, base)) == 1 || (ft_strcmp_repeat(base, ops)) == 1)
	{
		return (1);
	}
	i = 0;
	while (ops[i] != '\0')
	{
		i++;
	}
	if (i != 7 || (ft_strcmp_repeat(ops, ops)) == 1)
	{
		return (1);
	}
	return (0);
}
t_stree		*parser_brac(char *base, char *ops, int *i, char *expr)
{
	int	*neg;
	t_stree	*begin;
	int	neg_val;
	
	*i = *i + 1;	
	neg_val = 0;
	neg = &neg_val;
	begin = init_stree();
	while (expr[*i] != '\0')
	{
		if (if_ops(expr[*i], ops))
		{
			begin = push_ops(&expr[*i], begin, neg, ops, base);
		}
		else if (if_digits(expr[*i], base))
		{
			begin = push_digit(expr, base, i, neg, begin);
			*neg = 0;
		}
		else if(expr[*i] == ops[0])
		{
			begin = push_digit_brac(parser_brac(base, ops, i, expr), neg, begin);
			*neg = 0;
		}
		else if(expr[*i] == ops[1])
		{
			print_tree(begin);
			return (calc(begin, base));
		}
		*i = *i + 1;
	}
	return (NULL);
}

t_stree		*parser(char *base, char *ops, char *expr, t_stree *begin)
{
	int	*i;
	int	*neg;
	int	neg_val;
	int	value_i;

	value_i = 0;
	i = &value_i;	
	neg_val = 0;
	neg = &neg_val;
	*neg = first_neg(expr, i, ops);
	while (expr[*i] != '\0')
	{
		if (if_ops(expr[*i], ops))
		{
			begin = push_ops(&expr[*i], begin, neg, ops, base);
		}
		else if (if_digits(expr[*i], base))
		{
			begin = push_digit(expr, base, i, neg, begin);
			*neg = 0;
		}
		else if(expr[*i] == ops[0])
		{
			begin = push_digit_brac(parser_brac(base, ops, i, expr), neg, begin);
			*neg = 0;
		}
		else if(expr[*i] == ops[1])
		{
			return (NULL);
		}
		*i = *i + 1;
	}
	print_tree(begin);
	return (calc(begin, base));
}
int	eval_expr(char *base, char *ops, char *expr)
{
	t_stree	*begin;
	begin = init_stree();

	if (test_base_and_ops(base, ops) == 1 || (begin = parser(base, ops, expr, begin)) == NULL)
	{
		write(2, SYNTAX_ERROR_MSG, ft_strlen(SYNTAX_ERROR_MSG));
		return (1);
	}
	print_tree(begin);
	return (0);
}
