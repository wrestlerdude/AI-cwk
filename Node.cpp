#include "Node.hpp"
#include "Edge.hpp"
#include <vector>

Node::~Node()
{
  for(unsigned int i = 0; i < edges.size(); i++)
  {
    delete edges[i];
    edges[i] = nullptr;
  }
  edges.clear();
}

void Node::add_Edge(Node* dest)
{
  edges.push_back(new Edge(this, dest));
}
