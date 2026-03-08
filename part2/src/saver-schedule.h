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

#ifndef SAVER_SCHEDULE_H_
#define SAVER_SCHEDULE_H_

#include "saver.h"

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

class Instance;
class Solution;

class SaverSchedule : public Saver {
 public:
  void save(Instance*, Solution*, const std::string&) const override;
};

#endif