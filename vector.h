# ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>
# include <stdio.h>

struct Tuple
{
  size_t t1, t2;
};

struct vector
{
  size_t capacity, size;
  struct Tuple **data;
};

void print_vect(struct vector *vect);

struct vector *vector_make(size_t capacity);

void vector_push_back(struct vector *vect, struct Tuple *x);

void vector_extract_at(struct vector *vect, size_t pos);

void freeVect(struct vector *vect);

//struct vector *getFreePos(struct matrix *mat, size_t capacity);

# endif
