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

#ifndef PLAN_EMPLOYEES_H_
#define PLAN_EMPLOYEES_H_

#include "divide-conquer.h" // algorithm

#include <stdexcept>

class Instance;
class Solution;

class PlanEmployees : public DivideConquer {
 private:
  bool small(Instance*) const override;
  Solution* solveSmall(Instance*) const override;
  InstanceHalves divide(Instance*, int) const override;
  Solution* combine(Solution*, Solution*) const override;
};

#endif