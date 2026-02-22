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

#ifndef READER_H_
#define READER_H_

#include "instance.h"

#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Reader {
 public:
  Reader() {}
  ~Reader() {}
  
  Instance loadFile(const std::string& path) const {
    std::ifstream file(path);
    if (!file.is_open()) throw std::runtime_error("Bad input file: " + path);

    json j;
    file >> j;
    int numE = j["employees"].get<int>();
    int numD = j["planningHorizon"].get<int>();
    int numS = j["shifts"].get<int>();
    Instance I(numE, numD, numS);
    std::vector<Employee> employees(numE, "");
    std::vector<Shift> shifts(numS, "");

    const auto& empJson = j["employees"];
    for (int e = 0; e < numE; ++e) {
      int value = descJson[e]["freeDays"].get<int>();
      I.setC(e, value);
      Employee employee = empJson[s]["name"].get<Employee>();
      employees.push_back(employee);
    }
    I.setE(employees);
    const auto& shiJson = j["shifts"];
    for (int s = 0; s < numS; ++s) {
      Shift shift = shiJson[s].get<Shift>();
      shifts.push_back(shift);
    }
    I.setS(shifts);
    const auto& satJson = j["satisfaction"];
    for (int e = 0; e < numE; ++e) {
      for (int d = 0; d < numD; ++d) {
        for (int s = 0; s < numS; ++s) {
          int value = satJson[e][d][s].get<int>();
          I.setA(e, d, s, value);
        }
      }
    }
    const auto& reqJson = j["requiredEmployees"];
    for (int d = 0; d < numD; ++d) {
      for (int s = 0; s < numS; ++s) {
        int value = reqJson[d][s].get<int>();
        I.setB(d, s, value);
      }
    }
    
    return I;
  }

 private:
};

#endif