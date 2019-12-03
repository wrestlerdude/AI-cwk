#include <iostream>
#include <string>
#include <vector>
#include "Graph.hpp"


using namespace std;

int main(int argc, char **argv)
{
  if (argc != 2)
    return 1;

  Graph cave_graph(argv[1]);

  return 0;
}