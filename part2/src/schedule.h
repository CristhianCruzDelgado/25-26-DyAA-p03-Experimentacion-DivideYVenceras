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

#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "solution.h"

#include <vector>

class EmployeesDaysShifts;
class Instance;

class Schedule : public Solution {
 public:
  Schedule(std::vector<std::vector<std::vector<bool>>>);

  const std::vector<std::vector<std::vector<bool>>>& getSchedule() const;

  double calculateSatisfaction(EmployeesDaysShifts*) const;
  int countCoveredShifts(EmployeesDaysShifts*) const;
  double objectiveFunction(Instance*) const override;

 private:
  // x[e][d][s] = 1 if employee e works on day d for shift s, 0 otherwise
  std::vector<std::vector<std::vector<bool>>> schedule_;  
};

#endif