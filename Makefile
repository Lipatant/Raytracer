##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile de NanoTekSpice
##

SRC	=	Generate.cpp														\
		Generate/Add.cpp													\
		Loop.cpp															\
		Loop/Display.cpp													\
		Loop/Exit.cpp														\
		Loop/Input.cpp														\
		Loop/Loop.cpp														\
		Loop/Simulate.cpp													\
		Main.cpp															\
		Setup.cpp															\
		Setup/GetFilename.cpp												\
		Setup/GetFileStream.cpp												\
		Setup/Parse.cpp														\
		nts/Component/AComponent.cpp										\
		nts/Component/Complex.cpp											\
		nts/Component/Input.cpp												\
		nts/Component/Logic.cpp												\
		nts/ComponentFactory.cpp											\
		nts/ComponentMap.cpp												\
		nts/Exception.cpp													\
		nts/Instruction.cpp													\
		nts/Instruction/Parsing.cpp											\
		nts/Tristate.cpp													\
		Utility/Regex.cpp													\

BUILDDIR = build

OBJ = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o: 	src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

NAME	=	nanotekspice

LDFLAGS	=

IDIR	=	include

CPPFLAGS	=	-I$(IDIR) -I./include

CFLAGS	=	-W -Wextra

GCCFLAG	=	g++ -o

FDEBUG	=	-g3

LOGSFILE	=	logs.txt

SRC_UT		=	src/Module/Module.cpp		\
				src/Module/CpuModule.cpp	\

SRC_TU		=	tests/tests.cpp	\

CC			=	g++

UT 			=	unit_tests

CFLAGS_UT		=	-std=c++17  -Wall -Wextra -Werror

CPPFLAGS_UT	+=	-I./include

LCRITERION	=	-lcriterion --coverage

all:	$(NAME)

$(NAME):	$(OBJ)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) > $(LOGSFILE)

debug:	$(OBJ)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) $(FDEBUG) > $(LOGSFILE)

debug_play:	fclean debug
	clear
	valgrind --track-origins=yes ./$(NAME)

clean:
	$(RM) -f $(OBJ) > $(LOGSFILE)

fclean: clean
	$(RM) -f $(NAME) >> $(LOGSFILE)
	@$(RM) -f $(NAME)
	@$(RM) -f $(UT)
	@$(RM) -f unit_tests
	@$(RM) -f vgcore*
	@$(RM) -f *.gcda
	@$(RM) -f *.gcno
	@$(RM) -f *~
	@$(RM) -f *.a
	@$(RM) -f *.o
	@$(RM) -f *.gch
	@$(RM) -f a.out
	@$(RM) -f coding-style-reports.log

play:	$(NAME)
	./$(NAME)

re:	fclean all

play_re: re
	./$(NAME)

tests_run: fclean
		$(CC) -o $(UT) $(CFLAGS_UT) $(CPPFLAGS_UT) $(SRC_UT) $(SRC_TU) \
			$(LCRITERION) $(CPPFLAGS_UT)
		./$(UT)

.PHONY: all debug debug_play fclean clean play re play_re tests_run
