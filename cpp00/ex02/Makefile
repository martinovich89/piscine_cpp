NAME			=	GlobalBanksters

INC				=	-I./

SRC_PATH		=	./

SRCS			=	Account.cpp tests.cpp

OBJS			=	$(SRCS:.cpp=.o)

CC				=	c++

CFLAGS			=	-Wall -Wextra -Werror -std=c++98

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
