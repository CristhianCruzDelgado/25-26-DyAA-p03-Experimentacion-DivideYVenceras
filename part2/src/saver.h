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

#ifndef SAVER_H_
#define SAVER_H_

#include <string>

class Instance;
class Solution;

class Saver {
 public:
  virtual ~Saver() = default;
  virtual void save(Instance*, Solution*, const std::string&) const = 0;
};

#endif