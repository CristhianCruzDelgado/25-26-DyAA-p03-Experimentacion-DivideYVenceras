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

#include "algorithm.h"

#include <stdexcept>
#include <utility>

using InstanceHalves = std::pair<Instance*, Instance*>;

class Instance;
class Solution;

class DivideConquer : public Algorithm {
 public:
  Solution* solve(Instance*, int) const;

 protected:
  virtual bool small(Instance*) const = 0;
  virtual Solution* solveSmall(Instance*) const = 0;
  virtual InstanceHalves divide(Instance*, int) const = 0;
  virtual Solution* combine(Solution*, Solution*) const = 0;
};

#endif