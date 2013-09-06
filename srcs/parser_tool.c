/*************************************\
* C File
* AUTHOR:   p-tank
* FILE:     ft_parser.c
* CREATED:  22:25:24 18/08/2013
* MODIFIED: 22:25:24 18/08/2013
\*************************************/

#include <stdlib.h>
#include "../header/bistromathique.h"

int	if_ops(char expr, char *ops)
{
	int	i;

	i = 2;
	while (ops[i] != '\0')
	{
		if (ops[i] == expr)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
int	if_digits(char expr, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == expr)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
