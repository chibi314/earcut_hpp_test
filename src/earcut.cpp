#include "earcut.hpp"
#include <iostream>
int main()
{
  using Coord = double;
  using N = uint32_t;
  using Point = std::array<Coord, 2>;
  std::vector<std::vector<Point>> polygon;
  polygon.push_back({{100, 0}, {100, 100}, {0, 100}, {0, 0}});

  std::vector<N> indices = mapbox::earcut<N>(polygon);

  for (const auto &i : indices) {
    std::cout << i << std::endl;
  }
  return 0;
}
