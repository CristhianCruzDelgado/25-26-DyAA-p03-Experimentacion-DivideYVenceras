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

#ifndef DIVIDE_H_
#define DIVIDE_H_

#include "instance.h"

#include <utility>

using InstanceHalves = std::pair<Instance*, Instance*>;

class Divide {
 public:
  virtual ~Divide() = default;
  virtual InstanceHalves& divide(const Instance*, const int&) const = 0;
};

#endif