NAME			=	iter

HEADERS			=	iter.hpp number.hpp print.hpp printeven.hpp

INC				=	-I./

SRC_PATH		=	./

SRCS			=	main.cpp number.cpp

OBJS			=	$(SRCS:.cpp=.o)

CXX				=	c++

CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 #-sanitize=address -g3

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
