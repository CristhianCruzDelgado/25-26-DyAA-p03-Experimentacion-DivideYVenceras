#include "algorithm.h" // algorithm
#include "employees-days-shifts.h" // declaration

EmployeesDaysShifts::EmployeesDaysShifts(
  std::vector<Employee> E, int D, std::vector<Shift> S,
  std::vector<std::vector<std::vector<int>>> A, std::vector<std::vector<int>> B, std::vector<int> C    
) : E_(std::move(E)), D_(D), S_(std::move(S)), 
    A_(std::move(A)), B_(std::move(B)), C_(std::move(C)), algorithm_(nullptr) {}

void EmployeesDaysShifts::setAlgorithm(Algorithm* a) { algorithm_ = a; }

Solution* EmployeesDaysShifts::execute() { 
  if (!algorithm_) { throw std::runtime_error("Bad pointer: algorithm null. EmployeesDaysShifts::execute"); }

  return algorithm_->solve(dynamic_cast<Instance*>(this), D_); 
}