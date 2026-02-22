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
#include <vector>

using Employee = std::string;
using Shift = std::string;

class Instance {
 public:
  Instance() {}
  Instance(const int& numE, const int& numD, const int& numS) : E_(std::vector<Employee>(numE, ""))
                                                              , D_(numD)
                                                              , S_(std::vector<Employee>(numS, "")) {
    resize();
  }
  ~Instance() {}

  void resize() {
    A_.resize(E_.size(), std::vector<std::vector<int>>(D_, std::vector<int>(S_.size(), 0)));
    B_.resize(D_, std::vector<int>(S_.size(), 0));
    C_.resize(E_.size(), 0);
  }

  const Employee& getE(int e) const { return E_[e]; }
  const int getNumE() const { return E_.size(); }
  const int getNumD() const { return D_; }
  const Shift& getS(int s) const { return S_[s]; }
  const int getNumS() const { return S_.size(); }

  const int getA(int e, int d, int s) const { return A_[e][d][s]; }
  const int getB(int d, int s) const { return B_[d][s]; }
  const int getC(int e) const { return C_[e]; }

  void setE(const std::vector<Employee>& E) { E_ = E; }
  void setD(const int& D) { D_ = D; }
  void setS(const std::vector<Shift>& S) { S_ = S; }

  void setA(int e, int d, int s, int value) { A_[e][d][s] = value; }
  void setB(int d, int s, int value) { B_[d][s] = value; }
  void setC(int e, int value) { C_[e] = value; }

 private:
  std::vector<Employee> E_; /* Employess */
  int D_; /* Days */
  std::vector<Shift> S_; /* Shifts */

  // A[e][d][t] - Satisfaction of employee e on day d for shift s
  std::vector<std::vector<std::vector<int>>> A_;
  // B[d][t] - Employees on day d for shift t
  std::vector<std::vector<int>> B_;
  // C[e] - Rest days for employee e
  std::vector<int> C_;
};

#endif