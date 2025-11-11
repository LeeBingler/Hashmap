# === Configuration ===

CC 		:= 	gcc
NAME	:=	hashmap-c
LIB_NAME := hashmap

CFLAGS	:=	-Wall -Wextra -fPIC -DNAME_EXEC=\"$(NAME)\" -Iinclude
DFLAGS	:=	-g3 -DDEBUG

SRC		:=	test/main.c	\
			src/hashmap.c	\
			src/SIPhash.c	\
			src/free_hashmap.c	\


OBJ		:=	$(SRC:.c=.o)

LIB_DIR  := lib

LIB_STATIC := $(LIB_DIR)/lib$(LIB_NAME).a
LIB_SHARED := $(LIB_DIR)/lib$(LIB_NAME).so

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

lclean:
	rm -fr $(LIB_DIR)

fclean: clean lclean
	rm -f $(NAME)

re:	fclean all


LIB_SRC := $(filter-out test/%.c, $(SRC))
LIB_OBJ := $(LIB_SRC:.c=.o)

build-lib: $(LIB_STATIC) $(LIB_SHARED)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(LIB_STATIC): $(LIB_OBJ) | $(LIB_DIR)
	ar rcs $@ $^

$(LIB_SHARED): $(LIB_OBJ) | $(LIB_DIR)
	$(CC) -shared -o $@ $^

.PHONY: all clean lclean fclean re debug build-lib lib
