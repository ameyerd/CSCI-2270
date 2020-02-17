#include GRAPH_H
#include<vector>
#include<iostream>
using namespace std;

Graph::Graph()
{

}


void Graph::addVertex(string name)
{
  bool found = false;
  for(int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i]->name == name)
    {
      found = true;
    }
  }
  if(found == false)
  {
    vertex * v = new vertex;
    v->name = name;
    vertices.push_back(v);
  }
}

void Graph::addEdge(string v1, string v2)
{
  for(int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i]->name == v1)
    {
      for(int j = 0; j < vertices.size(); j++)
      {
        if(vertices[j]->name == v2 && i != j)
        {
          adjVertex av;
          av.v = vertices[j];
          vertices[i]->adj.push_back(av);
          //another vertiex for edge in other direction
          adjVertex av2;
          av2.v = vertices[i];
          vertices[j]->adj.push_back(av2);
        }
      }
    }
  }
}

void Graph::displayEdges()
{
  for(unsigned int x = 0; x < vertices.size(); x++)
  {
    cout << vertices[x]->name << " --> ";
    for(unsigned int y = 0; y < vertices[x]->adj.size(); y++)
    {
      cout << vertices[x]->adj[y].v->name << " ";
    }
    cout << endl;
  }
}

void Graph::breadthFirstTraverse(string sourceVertex)
{

  vertex* vStart;

  for(unsigned int j = 0; j < vertices.size(); j++)
  {
      if(vertices[j]->name == sourceVertex)
      {
          vStart = vertices[j];
      }
  }

  vStart->visited = true;
  vStart->distance = 0;

  queue<vertex*> q;
  q.push(vStart);

  cout << "Starting vertex (root): " << vStart->name << "-> ";

  while(!q.empty())
  {
    vertex *n = q.front();
    q.pop();

    for(unsigned int i = 0; i < n->adj.size(); i++)
    {
      //cout << "not visited" << endl;
      if(!n->adj[i].v->visited)
      {
        n->adj[i].v->distance = n->distance + 1;
        cout << n->adj[i].v->name << "(" << n->adj[i].v->distance << ")" << " ";

        q.push(n->adj[i].v);
      }

    }

    //cout << "visited" << endl;

    n->visited = true;

  }
}

void DFTraversal(vertex *n)
{
    n->visited = true;

    for(unsigned int x = 0; x < n->adj.size(); x++ )
    {
        if(!n->adj[x].v->visited)
        {
          DFTraversal(n->adj[x].v);
        }
    }

}

int Graph::getConnectedComponents()
{

  int connected_components = 0;

  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    vertices[i]->visited = false;
  }

  for(unsigned int j = 0; j < vertices.size(); j++)
  {
    if(!vertices[j]->visited)
    {
      DFTraversal(vertices[j]);
      connected_components += 1;
    }
  }

  return connected_components;
 }

bool Graph::checkBipartite()
{

  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i]->color == "")
    {
      vertices[i]->color = "red";
    }
    for(unsigned int j = 0; j < vertices[i]->adj.size(); j++)
    {
      if(vertices[i]->adj[j].v->color == "" && vertices[i]->color == "red")
      {
        vertices[i]->adj[j].v->color = "blue";
      }
      else if(vertices[i]->adj[j].v->color == "" && vertices[i]->color == "blue")
      {
        vertices[i]->adj[j].v->color = "red";
      }
      else if(vertices[i]->adj[j].v->color == vertices[i]->color)
      {
        return false;
      }
    }

  }

  return true;

}
