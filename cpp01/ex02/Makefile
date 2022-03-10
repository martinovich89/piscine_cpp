NAME			=	HiThisIsBrain

SRC_PATH		=	./

SRCS			=	main.cpp

OBJS			=	$(SRCS:.cpp=.o)

CC				=	clang++

CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re