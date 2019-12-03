#pragma once
#include "Node.hpp"

struct Node;

struct Edge
{
  double distance;
  Node* dest;

  Edge(Node* src, Node* dest);

  static double calc_distance(Node* a, Node* b);
};