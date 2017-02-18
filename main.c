# include "tic_tac_toe.h"

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
