#include "quicksort.h"

bool QuickSort::Small(const Instance& instance) const {
  const auto& vec = static_cast<const SortingInstance&>(instance).getData();
  return vec.size() < 2;
}

Solution* QuickSort::SolveSmall(const Instance& instance) const {
  const auto& vec = static_cast<const SortingInstance&>(instance).getData();
  return new SortingSolution(vec);
}

InstanceHalves QuickSort::Divide(const Instance& instance) const {
  const auto& vec = static_cast<const SortingInstance&>(instance).getData();
  int pivot_index = vec.size() / 2;
  int pivot = vec[pivot_index];

  std::vector<int> left;
  std::vector<int> right;

  for (size_t i = 0; i < vec.size(); ++i) {
    if (static_cast<int>(i) == pivot_index) continue;

    if (vec[i] < pivot) {
      left.push_back(vec[i]);
    } else {
      right.push_back(vec[i]);
    }
  }

  // Metemos el pivot en una pila para poder recuperarlo al combinar soluciones
  pivot_stack_.push_back(pivot);

  return {
    new SortingInstance(left),
    new SortingInstance(right)
  };
}

Solution* QuickSort::Combine(Solution* S1, Solution* S2) const {
  const auto& vec1 = static_cast<const SortingSolution*>(S1)->getData();
  const auto& vec2 = static_cast<const SortingSolution*>(S2)->getData();

  int pivot = pivot_stack_.back();
  pivot_stack_.pop_back();

  std::vector<int> result(vec1);
  result.push_back(pivot);
  result.insert(result.end(), vec2.begin(), vec2.end());

  return new SortingSolution(result);
}