/**
 * Universidad de La Laguna
 * Degree: Ingeniería Informática
 * Signature: Diseño y Análisis de Algoritmos
 * Practice 03: Experimentación con Divide y Vencerás
 * Authors: 
 *   Cristhian Adoney Cruz Delgado
 *   Michelangelo Da Cruz Bochicchio
 * Emails: 
 *   alu0101648293@ull.edu.es
 *   alu0101651217@ull.edu.es
 */

#ifndef SORTING_INSTANCE_GENERATOR_H
#define SORTING_INSTANCE_GENERATOR_H

#include "sorting_instance.h"

class SortingInstanceGenerator {
 public:
  static SortingInstance Generate(int size, int max_value = 100);
};

#endif