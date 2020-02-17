#include <iostream>
#include <queue>


using namespace std;

struct Vertex {
  int key;
  bool visited;
  int distance;
  vector<adjVertex*> adjList;
};

struct adjVertix {
  Vertex* e;
  //int weight
}

class Graph {
  private:
    vector<vertex*> vertices;
    Vertex* search(int k);
  public:
    int insertVertex(int key); // create the vertex(NOT necessarily edges!)
    int insertEdge(int start, int end);
    int search(int key);
    int BFT(int k);
};

int Graph::insertVertex(int key)
{
  Vertex* newVertex = new Vertex;
  newVertex.key = k;
  vertices.insert(newVertex);
}

int Graph::insertEdge(int start, int end)
{
  adjVertex* newEdge = new adjVertex;
  newEdge->;//vertex reference containing end value;
}

Vertex* Graph::search(int k)
{
  for ( int i =; i <vertices.size(); i++)
  {
    if (vertices[i]->key == k)
    {
      cout << "Found it!" << endl;
      return vertices[i];
    }
    cout << "Didn't find the key" << endl;
    return NULL;
  }
}

int Graph::BFT(int k)
{
  Vertex* start = search(k);
  if(start == NULL) return -1;

  start->visited = true;
  start->distance = 0;
  queue<Vertex*> q;
  q.push(start);

  while(!q.empty())
  {
    Vertex* curr = q.front(); // get access to first element
    q.pop(); // actually remove that element
    //curr->visited = true;

    if(!curr->visited)
    {
      // add it's adjList;
      for(int i = 0; i < curr->adjList.size(); i++)
      {
        (cur->adjList.v)->distance = curr->distance + 1;
        q.push(curr->adjList[i].v);
      }
    }

    curr->visited = true;
  }
}

int main()
{

  Graph g;
  g.insertVertex(10);
  g.insertVertex(12);
  g.insertEdge(10,12);


  return 0;
}
