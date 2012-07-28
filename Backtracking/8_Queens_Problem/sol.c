#include <stdio.h>

#define N_QUEENS 8

/* Checks if it is allowed to place a queen at (r,c)
 * in the matrix, where any other 1 symbolizes another queen.
 */
int isallowed (int matrix[][N_QUEENS], int r, int c)
{
  int tmp;
  fprintf (stderr, "%s : %d %d\n", __func__, r, c);

  // Check that place (r,c)
  if (matrix[r][c])
  {
    return 0;
  }
  
  // Check horizontally.
  for (tmp = 0; tmp < N_QUEENS; tmp++)
  {
    if (matrix[r][tmp])
    {
      return 0;
    }
  }
  fprintf (stderr, "%s : %d %d -- Checked horizontal.\n", __func__, r, c);
  
  // Check vertically.
  for (tmp = 0; tmp < N_QUEENS; tmp++)
  {
    if (matrix[tmp][c])
    {
      return 0;
    }
  }
  fprintf (stderr, "%s : %d %d -- Checked vertical\n", __func__, r, c);

  // Check diagonally.
  for (tmp = 1; r + tmp < N_QUEENS && c + tmp < N_QUEENS; tmp++)
  {
    if (matrix[r + tmp][c + tmp])
    {
      fprintf (stderr, "Already a queen at %d,%d\n", r + tmp, c + tmp);
      return 0;
    }
  }
  for (tmp = 1; r - tmp >= 0 && c - tmp >= 0; tmp++)
  {
    if (matrix[r - tmp][c - tmp])
    {
      fprintf (stderr, "Already a queen at %d,%d\n", r - tmp, c - tmp);
      return 0;
    }
  }
  for (tmp = 1; r - tmp >= 0 && c + tmp < N_QUEENS; tmp++)
  {
    if (matrix[r - tmp][c + tmp])
    {
      return 0;
    }
  }
  for (tmp = 1; c - tmp >= 0 && r + tmp < N_QUEENS; tmp++)
  {
    if (matrix[r + tmp][c - tmp])
    {
      return 0;
    }
  }
  fprintf (stderr, "%s : %d %d -- Checked diagonal\n", __func__, r, c);

  return 1;
}

/* Return 1 if successful, 0 if not */
int queen8_solve (int matrix[][N_QUEENS], int n_queens_fixed)
{ 
  int i;
  if (n_queens_fixed >= N_QUEENS)
  {
    return 1;
  }

  fprintf (stderr, "%d\n", n_queens_fixed);
  for (i = 0; i < N_QUEENS; i++)
  {
    if (n_queens_fixed == 0 || isallowed (matrix, i, n_queens_fixed))
    {
      matrix[i][n_queens_fixed] = 1;

      if (!queen8_solve (matrix, n_queens_fixed + 1))
      {
        matrix[i][n_queens_fixed] = 0;
      }
      else
      {
        return 1;
      }
    }
  }

  return 0;
}

int main (void)
{
  int matrix[N_QUEENS][N_QUEENS] = {0};

  if (! queen8_solve (matrix, 0))
  {
    printf ("No solution found.\n");
    return 0;
  }

  int i, j;
  for (i = 0; i < N_QUEENS; i++)
  {
    for (j = 0; j < N_QUEENS && !matrix[j][i]; j++)
      ;
    
    printf ("%d\t", j);
  }

  return 0;
}
