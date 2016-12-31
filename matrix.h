# ifndef MATRIX_H_
# define MATRIX_H_

# include "tree.h"

struct matrix
{
  int *data;
  size_t lines;
  size_t cols;
};

struct matrix *newMat(struct matrix *mat, size_t lines, size_t cols);

struct matrix *cloneMat(struct matrix *mat);

void freeMat(struct matrix *mat);

void printMat(struct matrix *mat);


# endif
