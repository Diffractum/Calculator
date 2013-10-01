/*************************************\
* C File
* AUTHOR:   p-tank
* FILE:     operators_tool.c
* CREATED:  13:48:44 04/09/2013
* MODIFIED: 13:48:44 04/09/2013
\*************************************/

#include <stdlib.h>
#include "../../includes/bistromathique.h"
#include "../../includes/operators.h"

int	base_nb(char c, char *base)
{
	int	i;

	i = 0;
	while (c != base[i])
	{
		i++;
	}
	return (i);
}
char	*longer_nb(char *numb_1, char *numb_2,char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(numb_1) > ft_strlen(numb_2))
	{
		return (numb_1);
	}
	else if (ft_strlen(numb_1) == ft_strlen(numb_2))
	{
		while (numb_1[i] == numb_2[i])
		{

			i++;
		}
		if (base_nb(numb_1[i], base) > base_nb(numb_2[i], base))
		{
			return (numb_1);
		}
		else if (base_nb(numb_1[i], base) < base_nb(numb_2[i], base))
		{
			return (numb_2);
		}
	}
	return (numb_2);
}
char	*smaller_nb(char *numb_1, char *numb_2, char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(numb_1) > ft_strlen(numb_2))
	{
		return (numb_2);
	}
	else if (ft_strlen(numb_1) == ft_strlen(numb_2))
	{
		while (numb_1[i] == numb_2[i])
		{
			i++;
		}
		if (base_nb(numb_1[i], base) > base_nb(numb_2[i],  base))
		{
			return (numb_2);
		}
		else if (base_nb(numb_1[i], base) < base_nb(numb_2[i], base))
		{
			return (numb_1);
		}

	}
	return (numb_1);
}
char	*result_malloc(int i, char *result)
{
	result = malloc(sizeof(char) * i);
	if (!result)
	{
		return (NULL);
	}
	result[i] = '\0';
	return (result);
}
