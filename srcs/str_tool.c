/*************************************\
* C File
* AUTHOR:   p-tank
* FILE:     ft_str_tool.c
* CREATED:  16:27:40 18/08/2013
* MODIFIED: 16:27:40 18/08/2013
\*************************************/

#include <stdlib.h>
#include <unistd.h>
#include "../header/bistromathique.h"

int	ft_strcmp_repeat(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] != '\0')
		{
			j++;
			if (i == j - 1)
			{
				j++;
			}
			if (str1[i] == str2[j - 1])
			{
				return (1);
			}
		}
		i++;
	}
	return (0);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}
