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

vector<int> dijkstraShortestDistance (const Graph& g, const int& source)
{
  priority_queue<edgeWeight, vector<edgeWeight>, std::greater<edgeWeight> > minHeap;
  vector<int> distances(g.size(), INT_MAX);
  set<int> known;

  int sourceIndex = source - 1;
  distances[sourceIndex] = 0;
    
  distances[sourceIndex] = 0;
  known.insert(sourceIndex + 1);
  edgeWeight nextEdge;
  list<pair<int, int> >::const_iterator it = g[sourceIndex].begin();
  while (it != g[sourceIndex].end())
  {
    distances[it->first] = it->second;
    edgeWeight tmp = edgeWeight(it->second, make_pair(sourceIndex + 1, it->first));
    minHeap.push(tmp);
    it++;
  }
  
  while (minHeap.size() > 0)
  {
    nextEdge = minHeap.top();
    minHeap.pop();
    distances[toVertex(nextEdge) - 1] = std::min (distances[fromVertex(nextEdge) - 1] 
                                            + weight(nextEdge), 
                                            distances[toVertex(nextEdge) - 1]);
    int curVertexIndex = toVertex(nextEdge) - 1;
    it = g[curVertexIndex].begin();
    while (it != g[curVertexIndex].end())
    {
      edgeWeight tmp = edgeWeight(it->second, make_pair(curVertexIndex + 1, it->first));
      minHeap.push(tmp);
      it++;
    }
    known.insert(curVertexIndex + 1);
  }

  /* This step shouldn't be required. */
  return distances;
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
  vector<int> distances = dijkstraShortestDistance (g, vertex1);
  
  for (int i = 0; i < distances.size(); i++)
  {
    std::cout << i + 1 << " -- " << distances[i] << std::endl;
  }
  return 0;
}
