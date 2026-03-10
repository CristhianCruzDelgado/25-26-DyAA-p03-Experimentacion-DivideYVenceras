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
#ifndef EXECUTION_CONTEXT_H
#define EXECUTION_CONTEXT_H

#include "algorithm.h"

class ExecutionContext {
 private:
  Algorithm* algorithm_;

 public:
  ExecutionContext() : algorithm_(nullptr) {}

  void SetAlgorithm(Algorithm* algorithm);
  Solution* Solve(const Instance& instance) const;
};

#endif
