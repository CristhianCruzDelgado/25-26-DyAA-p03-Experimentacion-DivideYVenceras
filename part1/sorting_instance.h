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

#ifndef SORTING_INSTANCE_H
#define SORTING_INSTANCE_H

#include <vector>

#include "instance.h"

class SortingInstance : public Instance {
 private:
  std::vector<int> data_;

 public:
  SortingInstance(const std::vector<int>& data) : data_(data) {}
  std::vector<int> getData() const { return data_; }
  void Print() const override {
    if (data_.empty()) {
      std::cout << "[]";
      return;
    }

    std::cout << "[" << data_[0];
    for (size_t i = 1; i < data_.size(); ++i) {
      std::cout << ", " << data_[i];
    }
    std::cout << "]" << std::endl;
  }
};

#endif