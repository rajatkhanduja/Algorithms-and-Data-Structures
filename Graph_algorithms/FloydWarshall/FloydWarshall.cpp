/* This algorithm works better with matrices.
 * Here, vector has been made use of instead of arrays
 */
#include <vector>
#include <iostream>
#include <climits>

using std::vector;

typedef vector<vector<int> > GraphMatrix;

GraphMatrix floyd (const GraphMatrix& g)
{
  GraphMatrix shortestDistances = g;
  int nPoints = shortestDistances.size();
  
  /* Set points that are not directly reachable to INT_MAX */
  for (int i = 0; i < nPoints; i++)
  {
    for (int j = 0; j < nPoints; j++)
      if (shortestDistances[i][j] == 0 && i != j)
        shortestDistances[i][j] = INT_MAX;
  }
  for (int k = 0; k < nPoints; k++)
  {
    for (int i = 0; i < nPoints; i++)
    {
      for (int j = 0; j < nPoints; j++)
      {
        /* If either of i->k or k->j is infinity (or INT_MAX), then continue to other i,j */
        if (shortestDistances[i][k] == INT_MAX || shortestDistances[k][j] == INT_MAX)
          continue;

        int throughK = shortestDistances[i][k] + shortestDistances[k][j];
        shortestDistances[i][j] = std::min (throughK, shortestDistances[i][j]);
      }
    }
  }

  return shortestDistances;
}

int main(void)
{
  int nPoints;
  /* Read the number of points */
  std::cin >> nPoints;
  
  GraphMatrix g(nPoints, vector<int>(nPoints));

  int nEdges;
  /* Read the number of edges */
  std::cin >> nEdges;

  /* Read the edges and the weight */
  int v1, v2, weight;
  while (nEdges--)
  {
    std::cin >> v1 >> v2 >> weight;
    g[v1 - 1][v2 - 1] = weight;
  }

  GraphMatrix shortestPaths = floyd(g);

  for (int i = 0; i < nPoints; i++)
  {
    for (int j = 0; j < nPoints; j++)
    {
      std::cout << shortestPaths[i][j] << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
