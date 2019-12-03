#include "Graph.hpp"
#include <iostream>
#include <cstdint>
#include <limits>
#include <algorithm>

std::vector<uint32_t> path_find(Graph& caves, double& total) 
{
  uint32_t goal = caves.nodes.back()->idx;
  Node* current_node = caves.nodes.front();
  std::vector<Node*> previous_nodes{ caves.nodes.front() };

  do
  {
    double min_heuristic = std::numeric_limits<double>::max();

    auto routes = current_node->edges;
    Edge* candidate = nullptr;
    for(auto& option : routes)
    {
      if (std::find(previous_nodes.begin(), previous_nodes.end(), option->dest) != previous_nodes.end() || option->dest->expanded)
        continue;

      double heuristic_dist = Edge::calc_distance(option->dest, caves.nodes.back());
      //Basic crow's flight heuristic
      double heuristic_function = (double)(current_node->count + option->distance + heuristic_dist);
      if (heuristic_function <= min_heuristic)
      {
        candidate = option;
        min_heuristic = heuristic_function;
      }
    }

    if (!candidate)
    {
      current_node->expanded = true;
      for(int i = previous_nodes.size() - 1; i > 0; i--)
      {
        if (previous_nodes[i]->expanded == false && previous_nodes[i]->edges.size() > 1)
        {
          current_node = previous_nodes[i];
          previous_nodes.resize(i + 1);
          break;
        }
        else if(i == 1)
          return { 0 };
      }
      continue;
    }
    candidate->dest->count = (double)(current_node->count + candidate->distance);
    current_node = candidate->dest;

    previous_nodes.push_back(current_node);

  } while(previous_nodes.back()->idx != goal);

  std::vector<uint32_t> path;
  for(auto& n : previous_nodes)
    path.push_back(n->idx);

  total = current_node->count;

  return path;
}