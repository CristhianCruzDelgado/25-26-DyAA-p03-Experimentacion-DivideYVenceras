#include "sorting_instance_generator.h"

#include <vector>
#include <random>

SortingInstance SortingInstanceGenerator::Generate(int size, int max_value) {
  std::vector<int> data;
  data.reserve(size);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(-max_value, max_value);

  for (int i = 0; i < size; ++i) {
    data.push_back(dist(gen));
  }

  return SortingInstance(data);
}