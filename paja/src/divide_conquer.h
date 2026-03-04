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

#include <utility>

using InstanceHalves = std::pair<Instance*, Instance*>;

class Instance;
class Solution;

class DivideConquer {
 public:
  virtual ~DivideConquer() = default;
  
  Solution* solve(Instance*, const int&) const;

 protected:
  virtual bool small(Instance*) const = 0;
  virtual Solution* solveSmall(Instance* I) const = 0;
  virtual InstanceHalves divide(Instance*, const int&) const = 0;
  virtual Solution* combine(Solution* I1, Solution* I2) const = 0;
};

Solution* DivideConquer::solve(Instance* I, const int& size) const {
  if (small(I)) 
    return solveSmall(I);
  else {
    InstanceHalves m = divide(I, size);
    Solution* S1 = solve(m.first, size / 2);
    Solution* S2 = solve(m.second, size / 2);
    Solution* S = combine(S1, S2);
    delete m.first;
    delete m.second;
    delete S1;
    delete S2;
    return S;
  }
}

#endif
