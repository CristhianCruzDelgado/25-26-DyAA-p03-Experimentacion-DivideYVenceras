#include "mergesort.h"

bool MergeSort::Small(const Instance& instance) const {
  const auto& vec = static_cast<const SortingInstance&>(instance).getData();
  return vec.size() < 2;
}

Solution* MergeSort::SolveSmall(const Instance& instance) const {
  const auto& vec = static_cast<const SortingInstance&>(instance).getData();
  return new SortingSolution(vec);
}

InstanceHalves MergeSort::Divide(const Instance& instance) const {
  const auto& vec = static_cast<const SortingInstance&>(instance).getData();

  int mid = vec.size() / 2;
  std::vector<int> left(vec.begin(), vec.begin() + mid);
  std::vector<int> right(vec.begin() + mid, vec.end());

  return {
    new SortingInstance(left), 
    new SortingInstance(right)
  };
}

Solution* MergeSort::Combine(Solution* S1, Solution* S2) const {
  const auto& vec1 = static_cast<const SortingSolution*>(S1)->getData();
  const auto& vec2 = static_cast<const SortingSolution*>(S2)->getData();

  std::vector<int> combined;
  size_t i{0}, j{0};
  while (i < vec1.size() && j < vec2.size()) {
    if (vec1[i] < vec2[j]) {
      combined.push_back(vec1[i++]);
    } else {
      combined.push_back(vec2[j++]);
    }
  }

  while (i < vec1.size()) combined.push_back(vec1[i++]);
  while (j < vec2.size()) combined.push_back(vec2[j++]);

  return new SortingSolution(combined);
}