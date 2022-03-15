NAME			=	fragtrap

INC				=	-I./

SRC_PATH		=	./

SRCS			=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJS			=	$(SRCS:.cpp=.o)

CXX				=	c++

CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAGS) $(SRCS) $(INC) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $<

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re