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

#ifndef DIVIDE_CONQUER_PART2_H_
#define DIVIDE_CONQUER_PART2_H_

#include "divide_conquer.h"
#include "instance.h"
#include "solution.h"

class DivideConquerPart2 : public DivideConquer {
 public:
  DivideConquerPart2() = default;
  ~DivideConquerPart2() = default;
  
 private:
  bool small(const Instance* I) const override {

  }
  Solution* solveSmall(const Instance* I) const override {
    
  }
  InstanceHalves divide(const Instance* I, const int& size) const override {

  }
  Solution* combine(const Solution* I1, const Solution* I2) const override {

  }
};

#endif
