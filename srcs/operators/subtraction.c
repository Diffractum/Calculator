/*************************************\
* C File
* AUTHOR:   p-tank
* FILE:     substraction.c
* CREATED:  18:05:00 05/09/2013
* MODIFIED: 18:05:00 05/09/2013
\*************************************/

#include <stdlib.h>
#include "../../includes/bistromathique.h"
#include "../../includes/operators.h"

char	*sub_res(int i, char *result, char *base)
{
	char *result_res;
	int	j;
	int	k;

	j = 0;
	k = 0;
	result_res = NULL;
	while (result[j] == base[0])
	{
		j++;
	}
	if (j > 0 && ft_strlen(result) != (size_t)j)
	{
		result_res = result_malloc((i - j), result_res);
		while (j != i)
		{
			result_res[k] = result[j];
			j++;
			k++;
		}
		result = result_res;
	}
	else if (ft_strlen(result) == (size_t)j)
	{
		result_res = result_malloc(2, result_res);
		result_res[0] = '0';
		result = result_res;
	}
	return (result);
}
char	*subtraction(char *num_l, char *num_s, char *base)
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
			if (base_nb(num_l[i - 1], base) < (base_nb(num_s[j - 1], base) + res))
			{
				tmp = (base_nb(num_l[i - 1], base) + ft_strlen(base)) - (base_nb(num_s[i - 1], base) + res);
				res = 1;
				result[i - 1] = base[tmp];
			}
			else
			{
				tmp = base_nb(num_l[i - 1], base) - (base_nb(num_s[j - 1], base) + res);
				res = 0;
				result[i - 1] = base[tmp];
			}
		}
		else
		{
			if (base_nb(num_l[i - 1], base) <  res)
			{
				tmp = (base_nb(num_l[i - 1], base) + ft_strlen(base)) - res;
				res = 1;
				result[i - 1] = base[tmp];
			}
			else
			{
				tmp = base_nb(num_l[i - 1], base) - res;
				res = 0;
				result[i - 1] = base[tmp];
			}
		}
		i--;
		j--;
	}
	result = sub_res(ft_strlen(num_l), result, base);
	return (result);
}
