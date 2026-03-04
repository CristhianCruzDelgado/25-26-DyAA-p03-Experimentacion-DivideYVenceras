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

#ifndef LOADER_EMPLOYEE_DAY_SHIFT_H_
#define LOADER_EMPLOYEE_DAT_SHIFT_H_

#include "loader.h"

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Instance;

class LoaderEmployeeDayShift : public Loader {
 public:
  Instance* load(const std::string&) const override;
};

#endif