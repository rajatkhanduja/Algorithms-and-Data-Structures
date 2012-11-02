#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>

using std::vector;
using std::list;
using std::priority_queue;
using std::pair;
using std::make_pair;
using std::set;

typedef vector<list<pair<int, int> > > Graph;   // Use this to represent graphsa

class edgeWeight
{
  public:
    int from, to, weight;
    edgeWeight(const int& v1 = -1, const int& v2 = -1, const int& w = 0) : from(v1), to(v2), weight(w){}
    
    bool operator< (const edgeWeight& rhs) const
    {
      return this->weight > rhs.weight;
    }
};

int dijkstraShortestDistance (const Graph& g, const int& source, const int& destination)
{
  priority_queue<edgeWeight> minHeap;
  vector<int> distances(g.size());
  set<int> coveredPoints;

  int sourceIndex = source - 1;
  distances[sourceIndex] = 0;
    
  int curVertexIndex = sourceIndex;
  distances[sourceIndex] = 0;
  coveredPoints.insert(curVertexIndex + 1);
  edgeWeight nextEdge;
  while (coveredPoints.size() != g.size())
  {
    list<pair<int, int> >::const_iterator it = g[curVertexIndex].begin();
    while (it != g[curVertexIndex].end())
    {
      edgeWeight tmp(curVertexIndex + 1, it->first, it->second);
      minHeap.push(tmp);
      it++;
    }
    nextEdge = minHeap.top();
    minHeap.pop();
    distances[nextEdge.to - 1] = distances[nextEdge.from - 1] + nextEdge.weight;
    /* If the inserted vertex itself is the destination, return. */
    if (nextEdge.to == destination)
    {
      return distances[nextEdge.to - 1];
    }

    curVertexIndex = nextEdge.to - 1;
    coveredPoints.insert(curVertexIndex + 1);
  }

  /* This step shouldn't be required. */
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

  std::cout << "Shortest distance : " << dijkstraShortestDistance (g, vertex1, vertex2) << std::endl;

  return 0;
}
