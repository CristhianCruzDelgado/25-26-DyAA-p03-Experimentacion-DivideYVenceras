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

#include "instance.h"

#include <stdexcept>
#include <string>
#include <vector>

using Employee = std::string;
using Shift = std::string;

class Algorithm;
class Solution;

class EmployeesDaysShifts : public Instance {
 public:
  EmployeesDaysShifts(std::vector<Employee>, int, std::vector<Shift>,
    std::vector<std::vector<std::vector<int>>>, std::vector<std::vector<int>>, std::vector<int>);

  void setAlgorithm(Algorithm*) override;
  Solution* execute() override;

 private:
  std::vector<Employee> E_; // Employess
  int D_;                   // Days
  std::vector<Shift> S_;    // Shifts
  // A[e][d][s]             // Satisfaction of employee [e] on day [d] for shift [s]
  // B[d][s]                // Employees on day [d] for shift [s]
  // C[e]                   // Rest days for employee [e]
  std::vector<std::vector<std::vector<int>>> A_;
  std::vector<std::vector<int>> B_;
  std::vector<int> C_;
  // Algorithm
  Algorithm* algorithm_;
};