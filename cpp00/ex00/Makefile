NAME			=	megaphone

SRC_PATH		=	./

SRCS			=	./megaphone.cpp

OBJS			=	$(SRCS:.cpp=.o)

CC				=	c++

CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
