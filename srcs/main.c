/*************************************\
* C File
* AUTHOR:   p-tank
* FILE:     main.c
* CREATED:  01:07:14 17/08/2013
* MODIFIED: 01:07:14 17/08/2013
\*************************************/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../header/bistromathique.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

unsigned int	ft_uatoi(char *nbr)
{
	unsigned int	res;
	res = 0;
	while (*nbr)
	{
		res = *nbr - '0' + res * 10;
		nbr = nbr + 1;
	}
	return(res);
}

int	ft_fill_buff(char *buf,size_t size)
{
	size_t	size_read;
	ssize_t	ret;

	size_read = 0;
	ret = read(0, buf, size);
	if (ret == -1)
	{
		write(2, SYNTAX_ERROR_MSG, ft_strlen(SYNTAX_ERROR_MSG));
			return (1);
	}
	while (ret != 0)
	{
		size_read += ret;
		ret = read(0, buf, size - size_read);
		if (ret == -1)
		{
			write(2, SYNTAX_ERROR_MSG, ft_strlen(SYNTAX_ERROR_MSG));
			return (1);
		}
	}
	buf[size_read] = 0;
	return (0);
}

int	ft_check_args_n_malloc_buf(int argc, char **argv, char **buf)
{
	size_t size;

	if (argc != 4)
	{
		write(2, SYNTAX_ERROR_MSG, ft_strlen(SYNTAX_ERROR_MSG));	
		return (1);
	}
	size = ft_uatoi(argv[3]);
	*buf = malloc(sizeof(**buf) * (size + 1));
	if (*buf == 0)
	{
		write(2, SYNTAX_ERROR_MSG, ft_strlen(SYNTAX_ERROR_MSG));
		return (1);
	}
	return (ft_fill_buff(*buf, size));
}

int	main(int argc, char **argv)
{
	char	*buf;

	if (ft_check_args_n_malloc_buf(argc, argv, &buf))
	{
		return (1);
	}
	return (eval_expr(argv[1], argv[2], buf));
}
