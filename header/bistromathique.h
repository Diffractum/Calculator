/*************************************\
* H File
* AUTHOR:   p-tank
* FILE:     bistromathique.h
* CREATED:  01:09:17 17/08/2013
* MODIFIED: 01:09:17 17/08/2013
\*************************************/

#ifndef BISTROMATHIQUE_H
# define BISTROMATHIQUE_H

# define SYNTAX_ERROR_MSG	"syntax error\n"

/* main.c */
size_t	ft_strlen(char *str);
unsigned int	ft_uatoi(char *nbr);

/* ft_eval_expr.c */
int	eval_expr(char *base, char *ops, char *expr);

typedef struct		s_stree
{
	char		op_id;
	char	 	*number;
	int		neg; /* 0 = pos, 1 = neg */
	struct s_stree	*right;
	struct s_stree	*left;
}			t_stree;

/* ft_stack.c */
t_stree		*init_stree(void);
t_stree		*push(char op_id, char *number, int *neg);
t_stree		*read_stree(t_stree *begin);
t_stree		*read_stree_left(t_stree *begin);

/* parser_tool.c */
int	if_ops(char expr, char *ops);
int	if_digits(char expr, char *base);

/* push_ops */
t_stree		*push_ops(char *expr, t_stree *begin, int *neg, char *ops, char *base);
int		first_neg(char *expr, int *i, char *ops);

/* push_digit.c */
t_stree		*push_digit(char *expr,char *base, int *i, int *neg, t_stree *begin);
t_stree		*push_digit_brac(t_stree *expr, int *neg, t_stree *begin);

/* str_tool.c */
int	ft_strcmp_repeat(char *str1, char *str2);
void	ft_putchar(char c);
void	ft_putstr(char *str);

/* calc.c */
void		print_tree(t_stree *begin);
t_stree		*calc(t_stree *begin, char *base);

#endif
