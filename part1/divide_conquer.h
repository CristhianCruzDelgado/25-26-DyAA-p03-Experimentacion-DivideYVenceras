/**
 * Universidad de La Laguna
 * Degree: Ingeniería Informática
 * Signature: Diseño y Análisis de Algoritmos
 * Practice 03: Experimentación con Divide y Vencerás
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
  Solution* Solve(const Instance&) const override;

 protected:
  virtual bool Small(const Instance&) const = 0;
  virtual Solution* SolveSmall(const Instance&) const = 0;
  virtual InstanceHalves Divide(const Instance&) const = 0;
  virtual Solution* Combine(Solution*, Solution*) const = 0;
};

#endif