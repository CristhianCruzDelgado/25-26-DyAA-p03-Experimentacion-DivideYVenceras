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

#ifndef DIVIDE_CONQUER_H_
#define DIVIDE_CONQUER_H_

#include "combine.h"
#include "divide.h"
#include "instance.h"
#include "small.h"
#include "solution.h"
#include "solve_small.h"

class DivideConquer {
 public:
  DivideConquer() : 
    combine_(nullptr),
    divide_(nullptr),
    small_(nullptr),
    solve_small_(nullptr) {}
  virtual ~DivideConquer() {
    delete combine_;
    delete divide_;
    delete small_;
    delete solve_small_;
  }
  virtual Solution* solve(const Instance* I) = 0;
  Solution* solve(const Instance*, const int&) const;
  void setStrategy(Combine* a, 
                   Divide* b, 
                   Small* c, 
                   SolveSmall* d) {
    combine_ = a;
    divide_ = b;
    small_ = c;
    solve_small_ = d;
  }

 private:
  Combine* combine_;
  Divide* divide_;
  Small* small_;
  SolveSmall* solve_small_;
};

Solution* DivideConquer::solve(const Instance* I, const int& size) const {
  if (small_->small(I)) 
    return solve_small_->solveSmall(I);
  else {
    InstanceHalves m = divide_->divide(I, size);
    Solution* S1 = solve(m.first, size / 2);
    Solution* S2 = solve(m.second, size / 2);
    Solution* S = combine_->combine(S1, S2);
    delete S1;
    delete S2;
    return S;
  }
}

#endif
