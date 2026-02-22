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

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include "instance.h"

#include <vector>

class Solution {
 public:
  Solution(const Instance& I) {
    assignment_.resize(I.getNumE(), std::vector<std::vector<bool>>(I.getNumD(), std::vector<bool>(I.getNumS(), false)));
    objectiveValue_ = 0.0;
  }
  ~Solution() {}

  bool getAssignment(int e, int d, int s) const { return assignment_[e][d][s]; }
  const double getObjectiveValue() const { return objectiveValue_; }

  double calculateSatisfaction(const Instance& I) const {
    double total = 0.0;
    int E = I.getNumE();
    int D = I.getNumD();
    int S = I.getNumS();
    for (int e = 0; e < E; ++e) {
      for (int d = 0; d < D; ++d) {
        for (int s = 0; s < S; ++s) {
          if (assignment_[e][d][s]) {
            total += I.getA(e, d, s);
          }
        }
      }
    }
    return total;
  }
    

  int countCoveredShifts(const Instance& I) const {
    int count_s = 0;
    int D = I.getNumD();
    int S = I.getNumS();
    int E = I.getNumE();
    for (int d = 0; d < D; ++d) {
      for (int s = 0; s < S; ++s) {
        int count_e = 1;
        for (int e = 0; e < E; ++e) {
          if (assignment_[e][d][s]) ++count_e;
        }
        if (count_e > I.getB(d, s)) ++count_s;
      }
    }
    return count_s;
  }

  void objectiveFunction(const Instance& I) {
    objectiveValue_ = calculateSatisfaction(I) + countCoveredShifts(I) * 100.0;
  }

 private:
  // x[e][d][s] = 1 if employee e works on day d for shift s, 0 otherwise
  std::vector<std::vector<std::vector<bool>>> assignment_;  
  double objectiveValue_;
};

#endif