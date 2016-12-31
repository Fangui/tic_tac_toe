# include "matrix.h"

struct matrix *newMat(struct matrix *mat, size_t lines, size_t cols)
{
  mat->data = calloc(cols * lines, sizeof(int));
  mat->lines = lines;
  mat->cols = cols;

  return mat;
}

struct matrix *cloneMat(struct matrix *mat)
{
  struct matrix *Clone = malloc(sizeof(struct matrix));
  Clone = newMat(Clone, mat->lines, mat->cols);
  for(size_t i = 0; i < mat->lines; ++i)
    for(size_t j = 0; j < mat->cols; ++j)
      Clone->data[i * mat->cols + j] = mat->data[i * mat->cols + j];

  return Clone;
}


void freeMat(struct matrix *mat)
{
  free(mat->data);
  free(mat);
}

void printMat(struct matrix *mat)
{
  for(size_t i = 0; i < mat->lines; i++)
  {
    for(size_t j = 0; j < mat->cols; j++)
    {
      if(mat->data[i * mat->cols + j] == 0)
        printf("| ");
      else if(mat->data[i * mat->cols + j] == 1)
        printf("|O");
      else
        printf("|X");
    }
    printf("|\n");
  }
  printf("\n");
}
