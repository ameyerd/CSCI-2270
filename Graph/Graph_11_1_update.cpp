#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct adjVertex;

struct Vertex {
	int key;
	bool visited = false;
	int distance = 0;
	vector<adjVertex> adjList;
};

struct adjVertex {
	Vertex* v;
	//int weight;
};

class Graph {
private:
	vector<Vertex*> vertices;
	Vertex* search(int k);
	Vertex* DFT_Helper(Vertex* start);
public:
	int insertVertex(int k); // create the vertex (NOT necessarily edges!)
 	int insertEdge(int start, int end);
	int BFT(int k); // Breadth First Traversal starting at node with key 'k'
	int DFT(int k); // Depth First Traversal
	bool fun();
};

int Graph::insertVertex(int k) {
	Vertex* newVertex = new Vertex;
	newVertex->key = k;
	vertices.push_back(newVertex);
	return 0;
}

int Graph::insertEdge(int start, int end) {
	adjVertex* newEdge = new adjVertex;
	for (int i=0; i<vertices.size(); i++) {
		if (vertices[i]->key == start) { // find start @ index 'i'
			for (int j=0; j<vertices.size(); j++) {
				if (vertices[j]->key == end) { // find end @ index 'j'
					newEdge->v = vertices[j];
					vertices[i]->adjList.push_back(*newEdge);
					return 0;
				}
			}
			cout << "End node not found :(\n";
			return -1;
		}
	}
	cout << "Start node not found :(\n";
	return -1;
	//newEdge->v = ??; // Vertex reference containing the 'end' value;
}

Vertex* Graph::search(int k) {
	for (int i=0; i<vertices.size(); i++) {
		if (vertices[i]->key == k) {
			cout << "Found it!\n";
			return vertices[i];
		}
	}
	cout << "Didn't find the key :(\n";
	return NULL;
}

int Graph::BFT(int k) {
	Vertex* start = search(k);
	if (start == NULL) return -1;

	start->visited = true;
	start->distance = 0;
	queue<Vertex*> q;
	q.push(start);

	while (!q.empty()) {
		Vertex* curr = q.front(); // get access to first element
		q.pop(); // actually remove that element
		//curr->visited = true;
		cout << "Dequeued: " << curr->key << " at d: " << curr->distance << endl;

		// add it's adjList!
		for (int i=0; i<curr->adjList.size(); i++) {
			if (!(curr->adjList[i].v)->visited) {
				(curr->adjList[i].v)->distance = curr->distance + 1;
				(curr->adjList[i].v)->visited = true;
				//(curr->adjList[i].v)->parent = curr;
				q.push(curr->adjList[i].v);

				cout << "\tEnqueuing: " << (curr->adjList[i].v)->key;
				cout << "\t @d: " << (curr->adjList[i].v)->distance << endl;
			}
		}
		curr->visited = true;
	}
}

Vertex* Graph::DFT_Helper(Vertex* start) {
	if (!start->visited) {
		cout << "Visiting: " << start->key << endl;
		start->visited = true;
		for (int i=0; i<start->adjList.size(); i++) {
			DFT_Helper(start->adjList[i].v);
		}
	}
}

bool recursivecheck(Vertex* n, Vertex* p)
{
	n->visited = true;
	for(int i = 0; i < n->adjList.size(); i++)
	{
		if (!n->adjList[i].v->visited)
		{
			if(recursivecheck(n->adjList[i].v, n))
			{
				return true;
			}
		}
		else if(n->adjList[i].v != p)
		{
			return true;
		}
	}

	return false;
}

bool Graph::fun()
{
	for(int u = 0; u < vertices.size(); u++)
	{
		if(!vertices[u]->visited)
		{
			if(recursivecheck(vertices[u], NULL))
			{
				return true;
			}
		}
	}
	return false;
}

int Graph::DFT(int k) {
	Vertex* start = search(k);
	DFT_Helper(start);
	return 0;
}

int main() {
	Graph g;
	g.insertVertex(0);
	g.insertVertex(1);
	g.insertVertex(2);
	g.insertVertex(3);
	g.insertVertex(4);
	g.insertVertex(5);
	g.insertVertex(6);

	g.insertEdge(0, 1);
	g.insertEdge(1, 2);
	g.insertEdge(2, 0);
	g.insertEdge(1, 3);
	g.insertEdge(1, 4);
	g.insertEdge(1, 6);
	g.insertEdge(3, 5);
	g.insertEdge(4, 5);
	g.fun()? cout << "True" << endl:cout << "False" << endl;
	//g.search(10);
	//g.insertEdge(10, 12);

	Graph g1;
	g1.insertVertex(0);
	g1.insertVertex(1);
	g1.insertVertex(2);
	g1.insertVertex(3);
	g1.insertVertex(4);

	g1.insertEdge(0, 1);
	g1.insertEdge(1, 2);
	g1.insertEdge(1, 3);
	g1.insertEdge(2, 4);
	g1.fun()? cout << "True" << endl:cout << "False" << endl;

	Graph g2;
	g1.insertVertex(0);
	g1.insertVertex(1);
	g1.insertVertex(2);
	g1.insertVertex(3);
	g1.insertVertex(4);

	g1.insertEdge(0, 1);
	g1.insertEdge(0, 2);
	g1.insertEdge(0, 3);
	g1.insertEdge(1, 2);
	g1.insertEdge(1, 3);
	g1.fun()? cout << "True" << endl:cout << "False" << endl;

	return 0;
}
