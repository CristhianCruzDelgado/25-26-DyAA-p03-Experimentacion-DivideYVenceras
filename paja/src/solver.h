/**
 * Universidad de La Laguna
 * Degree: Ingeniería Informática
 * Signature: Diseño y Análisis de Algoritmos
 * Practice 03: Planifiación de empleados
 * Authors: 
 *   Cristhian Adoney Cruz Delgado
 *   Michelangelo Da Cruz Bochicchio
 * Emails: 
 *   alu0101648293@ull.edu.es
 *   alu0101651217@ull.edu.es
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include "instance.h"
#include "divide_conquer.h"

class Solution;

class Solver {
 public:
  Solver() = delete;
  Solver(Instance* I) : 
    instance_(I),
    strategy_(nullptr) {}
  ~Solver() {
    delete instance_;
    delete strategy_;
  }

  void setStrategy(DivideConquer* strategy) { strategy_ = strategy; } 
  Solution* executeStrategy() const { return strategy_->solve(instance_, instance_->getSize()); }

 private:
  Instance* instance_;
  DivideConquer* strategy_;
};

#endif
