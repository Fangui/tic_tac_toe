# include "AI.h"

# include <time.h>

int check_lines(struct matrix *mat, size_t lines, int player);

int check_column(struct matrix *mat, size_t column, int player);

int check_diago(struct matrix *mat, int player);

int check_diago2(struct matrix *mat, int player);

int is_Finish(struct matrix *mat, int player, size_t lines, size_t column);

void addToken(struct matrix *mat, size_t lines, size_t cols, int player);

void treeScore(struct tree *tree,struct matrix *mat, int player, size_t cpt, int depth, int max_depth);

int game(size_t lines, size_t cols);

