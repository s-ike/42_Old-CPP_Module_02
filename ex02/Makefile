NAME		:= a.out
SRCS		:= Fixed.cpp
ifdef TEST2
SRCS		+= test2.cpp
else
SRCS		+= main.cpp
endif
OBJDIR		:= ./objs/
OBJS		:= $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))
DEPENDS		:= $(addprefix $(OBJDIR), $(SRCS:.cpp=.d))

CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP

RM			:= rm -f
C_GREEN		:= "\033[32m"
C_DEFAULT	:= "\033[39m"
C_RESET		:= "\033[m"

$(OBJDIR)%.o:	%.cpp
			@if [ ! -d $(OBJDIR) ]; then \
				echo ";; mkdir $(OBJDIR)"; mkdir $(OBJDIR); \
			fi
			$(CXX) $(CXXFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $@
			@echo $(C_GREEN)"=== Make Done ==="$(C_DEFAULT)$(C_REST)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

test:
			$(MAKE) CXXFLAGS="$(CXXFLAGS) -D TEST=1"

test2:
			$(MAKE) CXXFLAGS="$(CXXFLAGS) -D TEST=1" TEST2=TRUE

-include	$(DEPENDS)

.PHONY:		all clean fclean re
.PHONY:		test
