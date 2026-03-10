#include "execution_timer.h"

double ExecutionTimer::Measure(ExecutionContext& context, const Instance& instance) {
  using clock = std::chrono::high_resolution_clock;

  auto start = clock::now();
  Solution* solution = context.Solve(instance);
  auto end = clock::now();

  delete solution;

  std::chrono::duration<double, std::milli> time = end - start;
  return time.count();
}
