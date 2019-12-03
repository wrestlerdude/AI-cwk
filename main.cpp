#include "Graph.hpp"
#include "A_Star.hpp"
#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  
  if (argc != 2)
    return 1;

  std::string args = argv[1];

  Graph cave_graph(args);
  double total = 0;
  std::vector<uint32_t> path = path_find(cave_graph, total);

  if (args.find(".cav") != std::string::npos)
    args.resize(args.size() - 4);
  args += ".csn";

#ifdef DEBUG
  std::ostream out(std::cout.rdbuf());
#else
  std::ofstream out(args);  
#endif

  for (auto& p : path)
    out << p << " ";
  out << '\n';
  out << "Length is: " << total;

  return 0;
}