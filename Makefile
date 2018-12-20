# FILENAMES	=	ft_printf.c 				\
# 		ft_itoa_base.c 			\
# 		ft_atoi_base.c 			\
# 		ft_lowercase.c 			\
# 		ft_uppercase.c 			\
# 		ft_parse.c 				\
# 		ft_flag.c 				\
# 		ft_modificator.c 		\
# 		ft_size.c 				\
# 		ft_type.c 				\
# 		ft_itoamax.c 			\
# 		pf_lib_1.c 				\
# 		ft_makedot.c 			\
# 		ft_makewidth.c 			\
# 		ft_makedot_oxu.c 		\
# 		ft_makewidth_oxu.c 		\
# 		ft_join.c				\
# 		ft_float.c				\
# 		ft_float_2.c			\
# 		ft_float_check.c		\
# 		ft_float_round.c		\
# 		ft_ftoa.c				\
# 		ft_lib_additional.c		\
# 		ft_lib_additional_2.c	\
# 		ft_str_mul_div.c		\

# NAME = libftprintf.a

# LIBFT = libft/*.o

# CC		=	gcc
# GLAS		=	-Wall -Wextra -Werror -I includes *.h -I includes libft/libft.h
# AR		=	ar

# SOURCES		=	 $(FILENAMES)
# OBJECTS		=	 $(FILENAMES:.c=.o)
	
# all: $(NAME) 


# $(NAME): $(OBJECTS) $(LIBFT)
# 	@$(AR) crs $@ $(OBJECTS) $@ $(LIBFT)

# $(OBJECT):
# 	@$(CC) -o $(GLAS)

# $(LIBFT):
# 	@make -C libft/

# clean:
# 	@rm -rf *.o
# 	@make clean -C libft/

# fclean: clean
# 	@rm -f $(NAME)
# 	@make fclean -C libft/

# re: fclean all


NAME = a.out

SRC = ft_printf.c 				\
		ft_itoa_base.c 			\
		ft_atoi_base.c 			\
		ft_lowercase.c 			\
		ft_uppercase.c 			\
		ft_parse.c 				\
		ft_flag.c 				\
		ft_modificator.c 		\
		ft_size.c 				\
		ft_type.c 				\
		ft_itoamax.c 			\
		pf_lib_1.c 				\
		ft_makedot.c 			\
		ft_makewidth.c 			\
		ft_makedot_oxu.c 		\
		ft_makewidth_oxu.c 		\
		ft_join.c				\
		ft_float.c				\
		ft_float_2.c			\
		ft_float_check.c		\
		ft_float_round.c		\
		ft_ftoa.c				\
		ft_lib_additional.c		\
		ft_lib_additional_2.c	\
		ft_str_mul_div.c		\

CC = gcc

OBJ = $(SRC:.c=.o)

FLAGS = -I include/*.h -I libft/include/libft.h

FLAGS = -I include/*.h -I libft/include/libft.h

LIBFT = libft/libft.a


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	@$(CC) $(OBJ) $(FLAGS) $(LIBFT) -o $(NAME)
	@./a.out 

$(OBJ): $(SRC)
	@$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
	@make -C libft/

clean:
	@rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all