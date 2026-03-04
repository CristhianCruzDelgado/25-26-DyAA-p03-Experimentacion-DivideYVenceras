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

#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <string>

class Instance {
 public:
  virtual ~Instance() = default;
  virtual const int getSize() const = 0;
  virtual void loadFile(const std::string&) = 0;
};

#endif
