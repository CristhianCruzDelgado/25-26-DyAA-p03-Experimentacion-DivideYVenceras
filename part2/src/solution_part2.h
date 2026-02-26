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

#ifndef SOLUTION_PART2_H_
#define SOLUTION_PART2_H_

#include "instance_part2.h"
#include "solution.h"

#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class SolutionPart2 : public Solution {
 public:
  SolutionPart2() = default;
  ~SolutionPart2() = default;

  double calculateSatisfaction(const InstancePart2& I) const {
    double sum_s = 0.0;
    int E = I.getNumE();
    int D = I.getNumD();
    int S = I.getNumS();
    for (int e = 0; e < E; ++e) {
      for (int d = 0; d < D; ++d) {
        for (int s = 0; s < S; ++s) {
          if (assignment_[e][d][s]) {
            sum_s += I.getA(e, d, s);
          }
        }
      }
    }
    return sum_s;
  }
  int countCoveredShifts(const InstancePart2& I) const {
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
  double objectiveFunction(const InstancePart2& I) const {
    return calculateSatisfaction(I) + countCoveredShifts(I) * 100.0;
  }
  void saveFile(const std::string&) const override;

 private:
  // x[e][d][s] = 1 if employee e works on day d for shift s, 0 otherwise
  std::vector<std::vector<std::vector<bool>>> assignment_;  
};

void SolutionPart2::saveFile(const std::string& path) const {
  std::ofstream file(path);
  if (!file.is_open()) {
    throw std::runtime_error("Bad output file: " + path);
  }

  // Por acabar
}

#endif
