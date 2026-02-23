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

#ifndef SOLVE_SMALL_H_
#define SOLVE_SMALL_H_

#include "instance.h"
#include "solution.h"

class SolveSmall {
 public:
  virtual ~SolveSmall() = default;
  virtual Solution* solveSmall(const Instance*) const = 0;
};

#endif