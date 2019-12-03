#pragma once
#include "Node.hpp"

struct Node;

struct Edge
{
  unsigned int distance;
  Node* dest;

  Edge(Node* src, Node* dest);
  ~Edge();


  static double calc_distance(Node* a, Node* b);
}