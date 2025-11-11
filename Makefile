# === Configuration ===

CC 		:= 	gcc
NAME	:=	hashmap-c

CFLAGS	:=	-Wall -Wextra -DNAME_EXEC=\"$(NAME)\" -Iinclude
DFLAGS	:=	-g3 -DDEBUG

SRC		:=	test/main.c	\
			src/hashmap.c	\
			src/SIPhash.c	\
			src/free_hashmap.c	\


OBJ		:=	$(SRC:.c=.o)


# === Rules ===


all: 	$(NAME)


debug: 	CFLAGS += $(DFLAGS)
debug: 	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re debug
