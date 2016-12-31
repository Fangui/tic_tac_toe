# ifndef TREE_H
# define TREE_H

# include "vector.h"

struct tree
{
  struct Tuple *Tuple;
  double value;
  size_t nbChildren;
  struct tree **children;
};


struct tree *buildTree(size_t height);

void addChildren(struct tree *tree, struct vector *vect);

void freeTree(struct tree *tree);

void printTree(struct tree *tree);
#endif
