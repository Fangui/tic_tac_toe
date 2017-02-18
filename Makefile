CC=gcc
 
CPPFLAGS= 

CFLAGS= -Wall -Wextra -Werror -std=c99 -pedantic -o -O2 
LDFLAGS=
LDLIBS= -lm

SRC= matrix.c vector.c AI.c tree.c tic_tac_toe.c

OBJ= ${SRC:.c=.o}
 
all: main
 
main: ${OBJ}
 
clean:
	rm -f ${OBJ}
	rm -f main
	rm -f .*.swp
	clear

# END
