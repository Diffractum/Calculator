/*************************************\
* C File
* AUTHOR:   p-tank
* FILE:     calc.c
* CREATED:  18:37:39 27/08/2013
* MODIFIED: 18:37:39 27/08/2013
\*************************************/

#include <stdlib.h>
#include <unistd.h>
#include "../includes/bistromathique.h"
#include "../includes/operators.h"

void	print_tree(t_stree *begin,char *base)
{
	if (begin->number == NULL)
	{
		if (begin->left->number != NULL)
		{
			if (begin->left->neg == 1)
				if (begin->left->number[0] != base[0])
					ft_putstr("-");
			ft_putstr(begin->left->number);
		}
		ft_putchar(begin->op_id);
	}
	else if (begin->op_id == '0')
	{
		if (begin->neg == 1)
			if (begin->number[0] != base[0])	
				ft_putstr("-");
		ft_putstr(begin->number);
	}
	if (begin->right != NULL)
	{
		print_tree(begin->right, base);
	}
	else
	ft_putchar('\n');
}
int	who_neg(t_stree *begin,char *base)
{
	char	*test;
	int	i;

	i = 0;
	test = longer_nb(begin->left->number, begin->right->number, base);
	while (test[i] != '\0')
	{
		if (test[i] != begin->left->number[i])
		{
			return (begin->right->neg);
		}
		i++;
	}	
	return (begin->left->neg);
}
t_stree		*calc(t_stree *begin, char *base)
{
	if (begin->right != NULL)
	{
		begin->right = calc(begin->right, base);
	}
	if (begin->op_id == '+')
	{
		if ((begin->left->neg + begin->right->neg) != 1)
		{
			begin->neg = (begin->left->neg + begin->right->neg) / 2;
			begin->number = addition(NUM_L, NUM_S , base);
		}
		else
		{
			begin->number = subtraction(NUM_L, NUM_S, base);
			begin->neg = who_neg(begin, base);
		}
	}
	if (begin->op_id == '-' || begin->op_id == '*'|| begin->op_id == '/' || begin->op_id == '%')
	{
		ft_putstr("Operator not yet included\n");
		return (NULL);
	}	
	begin->right = NULL;
	begin->op_id = '0'; 
	return(begin);
}
