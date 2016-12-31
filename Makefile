CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -g -o tic_tac_toe
LDFLAGS=
LDLIBS=
 
SRC= tic_tac_toe.c tree.c vector.c matrix.c AI.c

OBJ= ${SRC:.c=.o} 
all: tic_tac_toe

tic_tac_toe: ${OBJ} 
 
clean:
	rm -f ${OBJ}
	rm -f *.o
	rm tic_tac_toe
