#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>

struct vertex;

struct adjVertex{
  vertex *v;
};

struct vertex{
  int key;
  bool visited = false;
  int distance = 0;
  std::vector<adjVertex> adj;
};

class GRAPH_H{
  public:
    void addEdge(int v1,int)
}
