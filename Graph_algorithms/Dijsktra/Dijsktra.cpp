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

class edgeWeight
{
  public:
    int from, to, weight;
    edgeWeight(const int& v1 = -1, const int& v2 = -1, const int& w = 0) : from(v1), to(v2), weight(w){}
    
    bool operator< (const edgeWeight& rhs) const
    {
      if (this->weight == rhs.weight)
      {
        if (this->from == rhs.from)
        {
          return this->to > rhs.to;
        }
        else
        {
          return this->from > rhs.from;
        }
      }
      else
      {
        return this->weight > rhs.weight;
      }
    }
};

vector<int> dijkstraShortestDistance (const Graph& g, const int& source)
{
  priority_queue<edgeWeight> minHeap;
  vector<int> distances(g.size(), INT_MAX);
  set<int> coveredPoints;

  int sourceIndex = source - 1;
  distances[sourceIndex] = 0;
    
  int curVertexIndex = sourceIndex;
  distances[sourceIndex] = 0;
  coveredPoints.insert(curVertexIndex + 1);
  edgeWeight nextEdge;
  while (curVertexIndex == sourceIndex || minHeap.size() > 0)
  {
    list<pair<int, int> >::const_iterator it = g[curVertexIndex].begin();
    while (it != g[curVertexIndex].end())
    {
      edgeWeight tmp(curVertexIndex + 1, it->first, it->second);
      minHeap.push(tmp);
      it++;
    }
    nextEdge = minHeap.top();
    std::cout << nextEdge.weight << std::endl;
    minHeap.pop();
    distances[nextEdge.to - 1] = std::min (distances[nextEdge.from - 1] 
                                            + nextEdge.weight, 
                                           distances[nextEdge.to - 1]);
    curVertexIndex = nextEdge.to - 1;
    coveredPoints.insert(curVertexIndex + 1);
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
    std::cout << vertex1 << "-" << vertex2 << "(" << weight << ")" <<std::endl;
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
