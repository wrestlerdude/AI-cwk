#include "Graph.hpp"
#include "Node.hpp"
#include "Edge.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Graph::Graph() {}

Graph::~Graph()
{
  for(unsigned int i = 0; i < nodes.size(); i++)
  {
    delete nodes[i];
    nodes[i] = nullptr;
  }
  nodes.clear();
}

Graph::Graph(std::string filename)
{
  if (filename.find(".cav") == std::string::npos)
    filename += ".cav";

  std::fstream fin;
  fin.open(filename, std::ios::in);

  std::string line;
  getline(fin, line);

  std::stringstream ss(line);

  //Get number of caverns
  std::string str;
  getline(ss, str, ',');
  size = std::stoi(str);
  //Read in cavern locations
  for(int i = 1; i <= size; i++)
  {
    getline(ss, str, ',');
    unsigned int x = std::stoi(str);
    getline(ss, str, ',');
    unsigned int y = std::stoi(str);

    nodes.push_back(new Node(i, x, y));
  }
  
  //Read in connections and calculate edges
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      getline(ss, str, ',');
      bool connection = std::stoi(str);
      if (connection)
        nodes[j]->add_Edge(nodes[i]);
    }
  }

  for(auto& n : nodes)
  {
    std::cout << "Node " << n->idx << " is connected to Nodes: ";
    for (auto& e : n->edges)
    {
      std::cout << e->dest->idx << " ";
    }
    std::cout << '\n';
  }
}