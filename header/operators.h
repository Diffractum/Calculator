/*************************************\
* H File
* AUTHOR:   p-tank
* FILE:     /home/p-tank/42/Bistromathique/header/operators.h
* CREATED:  13:42:07 04/09/2013
* MODIFIED: 13:42:07 04/09/2013
\*************************************/

#ifndef OPERATORS_H
# define OPERATORS_H

# define NUM_L longer_nb(begin->left->number, begin->right->number, base)
# define NUM_S smaller_nb (begin->left->number, begin->right->number, base)

/* operators_tool.c */
int	base_nb(char c, char *base);
char	*longer_nb(char *numb_1, char *numb_2, char *base);
char	*smaller_nb(char *numb_1, char *numb_2, char *base);
char	*result_malloc(int i, char *result);

/* addition.c */
char	*addition(char *numb_1, char *numb_2, char *base);

/* subtraction.c */
char	*subtraction(char *numb_1, char *numb_2, char *base);

#endif
