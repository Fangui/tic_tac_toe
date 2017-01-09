# include "tree.h"



void addChildren(struct tree *tree, struct vector *vect)
{
  tree->nbChildren = vect->size;
  tree->children = malloc(tree->nbChildren * sizeof(struct tree));

  for(size_t i = 0; i < vect->size; ++i)
  {
    tree->children[i] = malloc(sizeof(struct tree));
    struct Tuple *tup = malloc(sizeof(struct Tuple));
    tree->children[i]->Tuple = tup;
    tree->children[i]->value = 0;
    tree->children[i]->Tuple->t1 = vect->data[i]->t1;
    tree->children[i]->Tuple->t2 = vect->data[i]->t2;
  }
}

void printTree(struct tree *tree)
{
  for(size_t i = 0; i < tree->nbChildren; ++i)
  {
    printf("fils n %zu gain= %lf t1 = %zu t2 = %zu\n", i, 
    tree->children[i]->value, tree->children[i]->Tuple->t1, 
    tree->children[i]->Tuple->t2);

    printTree(tree->children[i]);
  }
}

void freeTree(struct tree *tree)
{
  for(size_t i = 0; i < tree->nbChildren; ++i)
    freeTree(tree->children[i]);

  if(tree->nbChildren)
    free(tree->children);
  free(tree->Tuple);
  free(tree);
}
