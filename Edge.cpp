#include "Edge.hpp"
#include "Node.hpp"
#include <cmath>

Edge::Edge(Node* src, Node* dest)
{
  if (src->idx == dest->idx)
  {
    distance = 0;
    this->dest = nullptr;
  }
  else
  {
    distance = calc_distance(src, dest);
    this->dest = dest;
  }
}

double Edge::calc_distance(Node* a, Node* b)
{
  double xs = b->x - a->x;
  double ys = b->y - a->y;

  return std::sqrt((xs * xs) + (ys * ys));
}