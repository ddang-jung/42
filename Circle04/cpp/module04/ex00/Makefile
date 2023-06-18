NAME = ex00_

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

OBJS = ${SRCS:.cpp=.o}

RED = \033[31m
GREEN = \033[32m
BOLD = \033[1m

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) is ready 💫"

all : $(NAME)

clean :
	@$(RM) $(OBJS)
	@echo "$(RED)deleted object files"

fclean :
	@$(MAKE) clean
	@$(RM) $(NAME)
	@echo "$(RED)deleted $(NAME)"

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re