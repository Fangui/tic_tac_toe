# include <time.h>
# include "AI.h"

int check_lines(struct matrix *mat, size_t lines, int player)
{
  for(size_t i = 0; i < mat->lines; ++i)
    if(mat->data[lines * mat->lines + i] != player)
      return 0;
  
  return 1;
}

int check_column(struct matrix *mat, size_t column, int player)
{
  for(size_t i = 0; i < mat->cols; ++i)
    if(mat->data[i * mat->cols + column] != player)
      return 0;

  return 1;
}

int check_diago(struct matrix *mat, int player)
{
  for(size_t i = 0; i < mat->lines; ++i)
    if(mat->data[i * mat->cols + i] != player)
      return 0;

  return 1;
}

int check_diago2(struct matrix *mat, int player)
{
  for(size_t i = 0; i < mat->lines; ++i)
    if(mat->data[i * mat->cols + mat->lines - i - 1] != player)
      return 0;

  return 1;
}

int is_Finish(struct matrix *mat, int player, size_t lines, size_t column)
{
  return check_lines(mat, lines, player) || check_column(mat, column, player)
         || check_diago(mat, player) || check_diago2(mat, player);
}

void addToken(struct matrix *mat, size_t lines, size_t cols, int player)
{
  mat->data[lines * mat->lines + cols] = player;
}

void treeScore(struct tree *tree,struct matrix *mat, int player, size_t cpt)
{
  if(player == 3)
    player = 1;

  struct vector *freePos = getFreePos(mat, cpt);
  addChildren(tree, freePos);

  for(size_t i = 0; i < tree->nbChildren; ++i)
  {
    struct matrix *clone = cloneMat(mat);
    clone->data[tree->children[i]->t1 * clone->cols + tree->children[i]->t2] = player;
    if(is_Finish(clone, player, tree->children[i]->t1, tree->children[i]->t2))
    {
      if(player == 1)
        tree->children[i]->value = -10;
      else
        tree->children[i]->value = 10;
      tree->children[i]->nbChildren = 0;
    }
    else
    {
      if(cpt == 1)
      {
        tree->children[i]->value = 0;
        tree->children[i]->nbChildren = 0;
      }
      else if(cpt > 1)
         treeScore(tree->children[i], clone, player + 1, cpt - 1);
         
     
    }
    freeMat(clone);
  }
  freeVect(freePos);
}

int game(size_t lines, size_t cols)
{
  int player = 0, valid = 0, win = 0;
  printf("Player first?(1 or 2) : ");
  scanf("%d", &player);
  
  struct matrix *mat = malloc(sizeof(struct matrix));
  mat = newMat(mat, lines, cols);
  size_t cpt =  mat->lines * mat->cols;
  
  if(player == 2)
  {
    --cpt;
    srand(time(NULL));
    int r = rand() % 2;
    if(r == 0)
      addToken(mat, 1, 1, player);
    else
      addToken(mat, 0, 0, player);
  }
  else
    player = 0;

  printMat(mat);

  for(; cpt > 0; --cpt)
  {
    ++player;
    valid = 0;
    if(player == 3)
      player = 1;

    while(valid == 0)
    {
      if(player == 1)
      {
        printf("lines : ");
        scanf("%zu", &lines);
        printf("cols : ");
        scanf("%zu", &cols);
        if(lines >= mat->lines || cols >= mat->cols)
          printf("Position impossible\n");
        else if (mat->data[lines * mat->cols + cols] != 0)
          printf("Position occupé\n");
        else
          valid = 1;
      }
      else
      {
        valid = 1;
        struct tree *tree = malloc(sizeof(struct tree));
        tree->value = 0;

        treeScore(tree, mat, player, cpt);

        minimax(tree, 0, -150, 150);
        struct tree *treePos = getTuple(tree);

        if(treePos->value == 10)
          printf("It is my win :P \n");
        lines = treePos->t1;
        cols = treePos->t2;
        printf("%zu |", lines);
        printf("%zu\n", cols);

        freeTree(tree);
      }
      if(valid)
      {
        addToken(mat, lines, cols, player);
        printf("\n");
        printMat(mat);
        win = is_Finish(mat, player, lines, cols);
        if(win != 0)
        {
          freeMat(mat);
          return player;
        }
      }
    }
  }
  freeMat(mat);
  return win;
}
int main()
{
  size_t lines = 3, cols = lines;
  int win = game(lines, cols);
  if(win == 0)
    printf("It is a draw\n");
  else
    printf("Joueur %d win\n", win);
  return 0;
}



