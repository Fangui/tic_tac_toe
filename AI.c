# include "AI.h"

double minimax(struct tree *tree, size_t depth, double alpha, double beta)
{
  if(tree->nbChildren == 0)
    return tree->value;

  double curr = minimax(tree->children[0], depth + 1, alpha, beta);
  double Child;
  tree->value = curr;
  if(depth % 2 == 0)
  {
    for(size_t i = 1; i < tree->nbChildren; ++i)
    {
      Child = minimax(tree->children[i], depth + 1, alpha, beta);
      if(curr < Child)
      {
        curr = Child;
        tree->value = curr;
      }
      if(curr > beta)
      {
        for(size_t j = i; j < tree->nbChildren; ++j)
          freeTree(tree->children[j]);
        tree->nbChildren = i;
      }
      if(tree->value == 10)
        return tree->value;
      if(alpha < curr)
        alpha = curr;
    }
  }

  else
  {
    for(size_t i = 1; i < tree->nbChildren; ++i)
    {
      Child = minimax(tree->children[i], depth + 1, alpha, beta);
      if(curr > Child)
      {
        curr = Child;
        tree->value = curr;
      }
      if(alpha >= curr)
      {
        for(size_t j = i; j < tree->nbChildren; ++j)
          freeTree(tree->children[j]);
        tree->nbChildren = i;
        return curr;
      }
      if(tree->value == -10)
        return tree->value;

      if(beta > curr)
        beta = curr;
    }
  }
  return curr;
}

struct vector *getFreePos(struct matrix *mat, size_t capacity)
{
  struct vector *freePos = vector_make(capacity);
  for(size_t i = 0; i < mat->lines; ++i)
  {
    for(size_t j = 0; j < mat->cols; ++j)
    {
      if(mat->data[i * mat->cols + j] == 0)
      {
        struct Tuple *Tuple = malloc(sizeof(struct Tuple));
        Tuple->t1 = i;
        Tuple->t2 = j;
        vector_push_back(freePos, Tuple);
      }
    }
  }
  return freePos;
}

struct tree *getTuple(struct tree *tree)
{
  if(tree->nbChildren == 0)
    return tree;
  struct tree *curr = tree->children[0];

  for(size_t i = 1; i < tree->nbChildren; ++i)
    if(curr->value < tree->children[i]->value)
      curr = tree->children[i];

  return curr;
}

