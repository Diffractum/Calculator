#*************************************
# Makefile
# AUTHOR:   p-tank
# FILE:     Makefile
# CREATED:  21:10:48 05/09/2013
# MODIFIED: 21:10:48 05/09/2013
#*************************************

NAME=calc

CFLAGS=-Wall -Wextra -Werror

SRCS=srcs/main.c\
     srcs/calc.c\
     srcs/ft_eval_expr.c\
     srcs/ft_stack.c\
     srcs/parser_tool.c\
     srcs/push_digit.c\
     srcs/push_ops.c\
     srcs/str_tool.c\
     srcs/operators/addition.c\
     srcs/operators/subtraction.c\
     srcs/operators/operators_tool.c

HEADERS=header/bistromathique.h header/operators.h
	
OBJET=main.o\
      addition.o\
      subtraction.o\
      operators_tool.o\
      calc.o\
      ft_eval_expr.o\
      ft_stack.o\
      parser_tool.o\
      push_digit.o\
      push_ops.o\
      str_tool.o

all: $(NAME)

$(NAME): $(OBJET)
	@gcc -o $(NAME) $(OBJET); echo "Compilation success"	

$(OBJET): $(SRCS) $(HEADERS) 
	@gcc -c $(CFLAGS) $(SRCS)

clean:
	@rm -rf $(OBJET)

fclean: clean
	@rm -rf $(NAME)

test:
	echo "hzkte+zzgu" | ./calc "azertyuiopqsdfghjklmwxcvbn" "()+-*/%" 10
