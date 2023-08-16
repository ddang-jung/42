NAME = ScalarConverter

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRCS = main.cpp ScalarConverter.cpp

OBJ_DIR = obj

OBJS = ${addprefix $(OBJ_DIR)/, ${SRCS:.cpp=.o}}


RED = \033[31m
GREEN = \033[32m
BOLD = \033[1m

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) is ready 💫"

all : $(NAME)

clean :
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)deleted object files"

fclean :
	@$(MAKE) clean
	@$(RM) $(NAME)
	@echo "$(RED)deleted $(NAME)"

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re