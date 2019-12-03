#pragma once

#include "Node.hpp"
#include "Edge.hpp"
#include <vector>
#include <string>

struct Graph
{
  int size;
  std::vector<Node*> nodes;

  Graph();
  Graph(std::string filename);
  ~Graph();
};