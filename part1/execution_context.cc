#include "execution_context.h"
#include <stdexcept>

void ExecutionContext::SetAlgorithm(Algorithm* algorithm) {
  algorithm_ = algorithm;
}

Solution* ExecutionContext::Solve(const Instance& instance) const {
  if (!algorithm_) {
    throw std::runtime_error("Algorithm not set in ExecutionContext");
  }
  return algorithm_->Solve(instance);
}
