NAME			=	megaphone

SRC_PATH		=	./

SRCS			=	./megaphone.cpp

OBJS			=	$(SRCS:.cpp=.o)

CC				=	c++

CXXFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
