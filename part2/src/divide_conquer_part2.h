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

#include "combine_part2.h"
#include "divide_conquer.h"
#include "divide_part2.h"
#include "instance.h"
#include "small_part2.h"
#include "solve_small_part2.h"

class DivideConquerPart2 : public DivideConquer {
 public:
  DivideConquerPart2() = default;
  ~DivideConquerPart2() = default;
  
  Solution* solve(const Instance* I) override {
    Combine* a = new CombinePart2;
    Divide* b = new DividePart2;
    Small* c = new SmallPart2;
    SolveSmall* d = new SolveSmallPart2;
    this->setStrategy(a, b, c, d);
    return DivideConquer::solve(I, I->getSize());
  }
};

#endif
