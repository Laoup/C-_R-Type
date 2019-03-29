RM      = rm -f

CXX     = g++

NAME        = r_type

SRCDIR      = src
INCDIR      = include

CXXFLAGS    += -Wall -Wextra -g3
CXXFLAGS    += -I./ -I./$(INCDIR)/
##CXXFLAGS    += -std=c++11

SRCS        = $(SRCDIR)/main.cpp \
          $(SRCDIR)/element.cpp \
          $(SRCDIR)/ennemy.cpp \
          $(SRCDIR)/game.cpp \
          $(SRCDIR)/handlerKeyMapping.cpp \
          $(SRCDIR)/handlerSprite.cpp \
					$(SRCDIR)/handlerWindow.cpp \
					$(SRCDIR)/physiqueManager.cpp \
					$(SRCDIR)/player.cpp \
					$(SRCDIR)/ship.cpp \
					$(SRCDIR)/object.cpp \
					$(SRCDIR)/background.cpp \
					$(SRCDIR)/view.cpp \
					$(SRCDIR)/musicManager.cpp \
					$(SRCDIR)/drawableClass.cpp \
					$(SRCDIR)/IGame.cpp \
					$(SRCDIR)/IPhysiqueManager.cpp

##        $(SRCDIR)/

OBJS        = $(SRCS:.cpp=.o)

##<VISUAL CMD>

ECHO        =   echo -e

YELLOW      =   "\033[0;33m"
GREEN       =   "\033[0;32m"
RED     =   "\033[0;31m"
RESET       =   "\033[0;0m"

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -o $(NAME) $(OBJS)
		@$(ECHO) $(GREEN)">Project \""$(NAME)"\" compiled" $(RESET)

clean:
		$(RM) $(OBJS)
		@$(ECHO) $(YELLOW) "Directories  clean" $(RESET)

fclean: clean
		$(RM) $(NAME)
		@$(ECHO) $(RED) "Directories full clean" $(RESET)

re:	fclean all

.PHONY: all clean fclean re test
