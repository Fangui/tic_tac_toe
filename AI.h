# include "matrix.h"

double minimax(struct tree *tree, size_t depth, double alpha, double beta);

struct tree *getTuple(struct tree *tree);

struct vector *getFreePos(struct matrix *mat, size_t capacity);

