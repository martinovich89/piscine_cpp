NAME			=	animal

INC				=	-I./

SRC_PATH		=	./

SRCS			=	main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS			=	$(SRCS:.cpp=.o)

CC				=	clang++

CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) $(INC) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re