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
  json j;

  int E = assignment_.size();
  int D = assignment_[0].size();
  int S = assignment_[0][0].size();
  j["employees"] = E;
  j["days"] = D;
  j["shifts"] = S;

  j["assignment"] = json::array();
  for (int e = 0; e < E; ++e) {
    json days = json::array();
    for (int d = 0; d < D; ++d) {
      json shifts = json::array();
      for (int s = 0; s < S; ++s) {
        shifts.push_back(assignment_[e][d][s]);
      }
      days.push_back(shifts);
    }
    j["assignment"].push_back(days);
  }
  j["active_assignments"] = json::array();
  for (int e = 0; e < E; ++e) {
    for (int d = 0; d < D; ++d) {
      for (int s = 0; s < S; ++s) {
        if (assignment_[e][d][s]) {
          j["active_assignments"].push_back({
            {"employee", e},
            {"day", d},
            {"shift", s}
          });
        }
      }
    }
  }
  file << j.dump(2);
}

#endif
