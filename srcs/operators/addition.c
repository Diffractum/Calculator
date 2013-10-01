/*************************************\
* C File
* AUTHOR:   p-tank
* FILE:     addition.c
* CREATED:  14:11:08 04/09/2013
* MODIFIED: 14:11:08 04/09/2013
\*************************************/

#include <stdlib.h>
#include "../../includes/bistromathique.h"
#include "../../includes/operators.h"

char	*add_res(int i, int res, char *result, char *base)
{
	char	*result_res;

	result_res = NULL;
	if (res != 0)
	{
		result_res = result_malloc(i, result_res);
		while (i != 0)
		{	
			result_res[i - 1] = result[i - 2];
			i--;
		}
		result_res[i] = base[res];
		result = result_res;
	}
	return (result);
}
char	*addition(char *num_l,char *num_s, char *base)
{
	int	i;
	int	j;
	int	res;
	int	tmp;
	char	*result;

	result = NULL;
	i = ft_strlen(num_l);
	j = ft_strlen(num_s);
	result = result_malloc(i, result);
	res = 0;
	while (i != 0)
	{
		if (j > 0)
		{
			tmp = base_nb(num_l[i - 1], base) + base_nb(num_s[j - 1], base) + res;
			result[i - 1] = base[tmp % ft_strlen(base)];
			res = tmp / ft_strlen(base);
		}
		else
		{
			tmp = base_nb(num_l[i - 1], base) + res;
			result[i - 1] = base[tmp % ft_strlen(base)];
			res = tmp / ft_strlen(base);
		}
		i--;
		j--;
	}
	result = add_res((ft_strlen(num_l) + 1), res, result, base);
	return (result);
}

