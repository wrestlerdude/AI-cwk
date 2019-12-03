#include "Edge.hpp"
#include "Node.hpp"
#include <cmath>
#include <iostream>

Edge::Edge(Node* src, Node* dest)
{
    distance = calc_distance(src, dest);
    this->dest = dest;
}

double Edge::calc_distance(Node* a, Node* b)
{
  double xs = (double)b->x - a->x;
  double ys = (double)b->y - a->y;

  double result = std::sqrt((double)(xs * xs) + (ys * ys));
  return result;
}