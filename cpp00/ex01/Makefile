NAME			=	phonebook

INC				=	-I./

SRC_PATH		=	./

SRCS			=	PhoneBook.cpp

OBJS			=	$(SRCS:.cpp=.o)

CC				=	c++

CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CXXFLAGS) $(SRCS) $(INC) -o $(NAME)

%.o : %.cpp
	$(CC) $(CXXFLAGS) $(INC) -o $@ -c $<

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
