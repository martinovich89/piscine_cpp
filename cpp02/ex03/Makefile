NAME			=	fixed

INC				=	-I./

SRC_PATH		=	./

SRCS			=	main.cpp Fixed.cpp Point.cpp Bsp.cpp

OBJS			=	$(SRCS:.cpp=.o)

CC				=	c++

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