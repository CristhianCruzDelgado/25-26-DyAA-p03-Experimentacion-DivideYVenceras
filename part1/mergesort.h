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

#ifndef MERGESORT_H
#define MERGESORT_H

#include "divide_conquer.h"
#include "sorting_instance.h"
#include "sorting_solution.h"

class MergeSort : public DivideConquer {
 private:
  bool Small(const Instance&) const override;
  Solution* SolveSmall(const Instance&) const override;
  InstanceHalves Divide(const Instance&) const override;
  Solution* Combine(Solution*, Solution*) const override;
};

#endif