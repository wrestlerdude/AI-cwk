#pragma once

#include "Edge.hpp"
#include <vector>

struct Edge;

struct Node
{
  unsigned int count = 0;
  bool expanded = false;
  unsigned int idx;
  unsigned int x;
  unsigned int y;
  std::vector<Edge*> edges;

  Node(int idx, int x, int y) { this->idx = idx; this->x = x; this->y = y; }
  ~Node();

  void add_Edge(Node* dest);
};