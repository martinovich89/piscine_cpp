NAME			=	animal

HEADERS			=	Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

INC				=	-I./

SRC_PATH		=	./

SRCS			=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

OBJS			=	$(SRCS:.cpp=.o)

CXX				=	c++

CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAGS) $(SRCS) $(INC) -o $(NAME)

%.o : %.cpp $(HEADERS) Makefile
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $<

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
