#include "Graph.hpp"
#include "A_Star.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
  if (argc != 2)
    return 1;

  std::string args = argv[1];

  Graph cave_graph(args);
  vector<int> path = path_find(cave_graph);

#ifdef DEBUG
  for (auto& p : path)
    cout << p << " ";
  cout << endl;
#else
  if (args.find(".cav") != std::string::npos)
    args.resize(args.size() - 4);
  args += ".csn";
  std::ofstream outfile(args);
  for (auto& p : path)
    outfile << p << " ";
#endif

  return 0;
}