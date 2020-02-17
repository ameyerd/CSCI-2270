#include GRAPH_H
#include<vector>
#include<iostream>
#include <climits>
using namespace std;


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

void Graph::addEdge(string v1, string v2, int num)
{
  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i]->name == v1)
    {
      for(unsigned int j = 0; j < vertices.size(); j++)
      {
        if(vertices[j]->name == v2 && i != j)
        {
          adjVertex av;
          av.v = vertices[j];
          av.weight = num;
          vertices[i]->adj.push_back(av);

          adjVertex av2;
          av2.v = vertices[i];
          av2.weight = num;
          vertices[j]->adj.push_back(av2);

        }
      }
    }
  }
}

void DFTraversal(vertex *n)
{
    n->visited = true;

    for(unsigned int x = 0; x < n->adj.size(); x++ )
    {
        if(!n->adj[x].v->visited)
        {
          cout << n->adj[x]->name << " --> ";
          DFTraversal(n->adj[x].v);
        }
    }

}

void Graph::depthFirstTraversal(string sourceVertex)
{

  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    vertices[i]->visited = false;
  }

  for(unsigned int j = 0; j < vertices.size(); j++)
  {
    if(vertices[j]->name == sourceVertex)
    {
      cout << vertices[j]->name << " --> ";
      DFTraversal(vertices[j]);
    }
  }

  cout << "Done";

}


vertex* Graph::DijkstraAlgorithm(string start, string end)
{
  vertex* startV;
  vertex* endV;
  vertex* parent;

  for(unsigned int j = 0; j < vertices.size(); j++)
  {
      if(vertices[j]->name == start)
      {
          startV = vertices[j];
      }
  }

  for(unsigned int j = 0; j < vertices.size(); j++)
  {
      if(vertices[j]->name == end)
      {
          endV = vertices[j];
      }
  }

  startV->visited = true;
  startV->distance = 0;

  vector<vertex*>solved;

  solved.push_back(startV);

  while(!endV->visited)
  {
    int minDistance = INT_MAX;

    vertex *solvedV = NULL;

    for(unsigned int x = 0; x < solved.size(); x++) // here
    {
      vertex* s = solved[x]; // here

      for(unsigned int y = 0; y < s->adj.size(); y++)
      {
        if(!s->adj[y].v->visited)
        {
          int dist = s->distance + s->adj[y].weight;

          if(dist < minDistance)
          {
            solvedV = s->adj[y].v;
            minDistance = dist;
            parent = s;
          }
        }
      }
    }

    solvedV->distance = minDistance;
    solvedV->pred = parent; // here
    solvedV->visited = true;
    solved.push_back(solvedV); // here
  }

  return endV;
}


void Graph::shortestpath(string s1, string s2)
{
  vertex *temp;

  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i]->name == s2)
    {
      temp = vertices[i];
    }
  }

  vector<vertex*> list;

  while(temp->pred != NULL)
  {
      list.push_back(temp);
      temp = temp->pred;
  }

  cout << temp->name << " ";

  for(unsigned int i = list.size() - 1; i > 0; i--)
  {
      cout << list[i]->name << " ";
  }

  cout << list[0]->name;


}
