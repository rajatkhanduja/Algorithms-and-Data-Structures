#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

using std::vector;
using std::list;
using std::priority_queue;
using std::pair;
using std::make_pair;
using std::set;

typedef vector<list<pair<int, int> > > Graph;   // Use this to represent graphsa

typedef pair<int,pair<int, int> > edgeWeight;
inline int weight(const edgeWeight& e)
{
  return e.first;
}

inline int fromVertex(const edgeWeight& e)
{
  return e.second.first;
}

inline int toVertex(const edgeWeight& e)
{
  return e.second.second;
}

void printDistances (const vector<int>& distances)
{
  for(int i = 0; i < distances.size(); i++)
  {
    std::cout << i << " -- " << distances[i] << std::endl;
  }
}

int minVertex (vector<int>& distances, vector<bool>& visited)
{
  int minVal = INT_MAX, minIndex = -1;
  for (int i = 0; i < distances.size(); i++)
  {
    if (visited[i])
      continue;
    
    if (minVal > distances[i])
    {
      minIndex = i;
      minVal = distances[i];
    }
  }
  return minIndex;
}

int dijkstraShortestDistance (const Graph& g, const int& source, const int& destination)
{
  int nVertices = g.size();
  vector<int> distances(nVertices, INT_MAX);
  vector<bool> visited(nVertices);
  vector<int> minDistance(nVertices, INT_MAX);

  int last = source - 1, v;
  distances[last] = minDistance[last] = 0;
  list<pair<int,int> >::const_iterator it = g[last].begin();
  
  while (it != g[last].end())
  {
    distances[it->first - 1] = it->second;
    it++;
  }

  while ( last != destination - 1)
  {
    // Pick next v such that distances[v] is minimized
    v = minVertex(distances, visited);  /* TODO : use a better DS here. */
    it = g[v].begin();
    while (it != g[v].end())
    {
      distances[it->first - 1] = std::min (distances[it->first - 1], 
                                  distances[v] + it->second);
      it++;                                  
    }
    last = v;
    visited[v] = true;
  }

  return distances[destination - 1];
}

int main (void)
{
  int nVertices, nEdges;

  /* Read the number of vertices */
  std::cin >> nVertices;

  /* Initialize Graph */
  Graph g(nVertices);

  /* Read the number of edges */
  std::cin >> nEdges;

  int vertex1, vertex2, weight;
  while (nEdges--)
  {
    /* Read edge given as "v1<space>v2<space>weight" (quotes for clarity only) */
    /* Input vertices go from 1 to n. */
    std::cin >> vertex1 >> vertex2 >> weight;
    g[vertex1 - 1].push_back(make_pair(vertex2, weight));    
  }

  /* Read source and destination. */
  std::cin >> vertex1 >> vertex2;
  int distance = dijkstraShortestDistance (g, vertex1, vertex2);
  std::cout << distance << std::endl;
  return 0;
}
