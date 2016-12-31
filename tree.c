# include "tree.h"

struct tree *buildTree(size_t height)
{
  struct tree *tree = malloc(sizeof(struct tree));
  struct Tuple *tup = malloc(sizeof(struct Tuple));
  tree->children = malloc(height * sizeof(struct tree));
  tree->Tuple = tup;
  tree->value = 0;
  tree->nbChildren = height;

  for(size_t i = 0; i < height; ++i)
    tree->children[i] = buildTree(height -1);
 
  return tree;
}

void addChildren(struct tree *tree, struct vector *vect)
{
  for(size_t i = 0; i < vect->size; ++i)
  {
    tree->children[i]->Tuple->t1 = vect->data[i]->t1;
    tree->children[i]->Tuple->t2 = vect->data[i]->t2;
  }
}

void printTree(struct tree *tree)
{
  for(size_t i = 0; i < tree->nbChildren; ++i)
  {
    printf("fils n %zu gain= %lf t1 = %zu t2 = %zu\n",i, tree->children[i]->value, tree->children[i]->Tuple->t1, tree->children[i]->Tuple->t2);
    printTree(tree->children[i]);
  }
}

void freeTree(struct tree *tree)
{
  for(size_t i = 0; i < tree->nbChildren; ++i)
    freeTree(tree->children[i]);

  free(tree->children);
  free(tree->Tuple);
  free(tree);
}
