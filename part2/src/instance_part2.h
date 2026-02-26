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

#ifndef INSTANCE_PART2_H_
#define INSTANCE_PART2_H_

#include "instance.h"

#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using Employee = std::string;
using Shift = std::string;

class InstancePart2 : public Instance {
 public:
  InstancePart2() = default;
  ~InstancePart2() = default;
  
  const int getSize() const { return D_; }
  const Employee& getE(int e) const { return E_[e]; }
  const int getNumE() const { return E_.size(); }
  const int getNumD() const { return D_; }
  const Shift& getS(int s) const { return S_[s]; }
  const int getNumS() const { return S_.size(); }
  const int getA(int e, int d, int s) const { return A_[e][d][s]; }
  const int getB(int d, int s) const { return B_[d][s]; }
  const int getC(int e) const { return C_[e]; }
  void setA(int e, int d, int s, int value) { A_[e][d][s] = value; }
  void setB(int d, int s, int value) { B_[d][s] = value; }
  void setC(int e, int value) { C_[e] = value; }
  void loadFile(const std::string&) override;

 private:
  std::vector<Employee> E_; // Employess
  int D_;                   // Days
  std::vector<Shift> S_;    // Shifts
  // A[e][d][s]             // Satisfaction of employee e on day d for shift s
  // B[d][s]                // Employees on day d for shift s
  // C[e]                   // Rest days for employee e
  std::vector<std::vector<std::vector<int>>> A_;
  std::vector<std::vector<int>> B_;
  std::vector<int> C_;
};

void InstancePart2::loadFile(const std::string& path) { 
  std::ifstream file(path);
  if (!file.is_open()) {
    throw std::runtime_error("Bad input file: " + path);
  }
  json j;
  file >> j;

  int numE = j["employees"].size();
  int numD = j["planningHorizon"].get<int>();
  int numS = j["shifts"].size();
  E_.resize(numE);
  D_ = numD;
  S_.resize(numS);
  A_.assign(numE, std::vector<std::vector<int>>(numD, std::vector<int>(numS)));
  B_.assign(numD, std::vector<int>(numS));
  C_.assign(numE, 0);

  for (int e = 0; e < numE; ++e) {
    E_[e] = j["employees"][e]["name"];
    C_[e] = j["employees"][e]["freeDays"];
  }
  for (int s = 0; s < numS; ++s) {
    S_[s] = j["shifts"][s];
  }
  for(const auto& entry : j["satisfaction"]){
    int e = entry["employee"];
    int d = entry["day"];
    int s = entry["shift"];
    int v = entry["value"];
    A_[e][d][s] = v;
  }
  for(const auto& entry : j["requiredEmployees"]){
    int d = entry["day"];
    int s = entry["shift"];
    int v = entry["value"];
    B_[d][s] = v;
  }
}

#endif
