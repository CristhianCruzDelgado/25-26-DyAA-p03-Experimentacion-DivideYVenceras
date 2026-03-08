#include "algorithm.h" // algorithm
#include "employees-days-shifts.h" // declaration

int EmployeesDaysShifts::realSize_ = -1;

EmployeesDaysShifts::EmployeesDaysShifts(
  std::vector<Employee> E, int D, std::vector<Shift> S,
  std::vector<std::vector<std::vector<int>>> A, std::vector<std::vector<int>> B, std::vector<int> C    
) : E_(std::move(E)), D_(D), S_(std::move(S)), 
    A_(std::move(A)), B_(std::move(B)), C_(std::move(C)), algorithm_(nullptr) {
  if (realSize_ == -1) realSize_ = D;
}

void EmployeesDaysShifts::setAlgorithm(Algorithm* a) { 
  if(!a) throw std::invalid_argument("Bad pointer: algorithm null. EmployeesDaysShifts::setAlgorithm");
  algorithm_ = a; 
}

Solution* EmployeesDaysShifts::execute() { 
  if (!algorithm_) { throw std::runtime_error("Bad pointer: algorithm null. EmployeesDaysShifts::execute"); }
  return algorithm_->solve(this, D_); 
}

const std::vector<Employee>& EmployeesDaysShifts::getEmployees() const { return E_; }
int EmployeesDaysShifts::getDays() const { return D_; }
const std::vector<Shift>& EmployeesDaysShifts::getShifts() const { return S_; }
std::vector<std::vector<std::vector<int>>> EmployeesDaysShifts::getFromToDaysFromA(int f, int l) const { 
  std::vector<std::vector<std::vector<int>>> splicedA;
  int employees = A_.size();
  splicedA.resize(employees);
  for (int e = 0; e < employees; ++e) {
    for (int d = f; d < l; ++d) {
      splicedA[e].push_back(A_[e][d]);
    }
  }
  return splicedA;
}
std::vector<std::vector<int>> EmployeesDaysShifts::getFromToDaysFromB(int f, int l) const { 
  std::vector<std::vector<int>> splicedB;
  for (int d = f; d < l; ++d) {
    splicedB.push_back(B_[d]);
  }
  return splicedB;
}
const std::vector<std::vector<std::vector<int>>>& EmployeesDaysShifts::getA() const { return A_; };
const std::vector<std::vector<int>>& EmployeesDaysShifts::getB() const { return B_; };
const std::vector<int>& EmployeesDaysShifts::getC() const { return C_; }

void EmployeesDaysShifts::displayOnConsole() const {
  std::cout << "=== EmployeesDaysShifts ===\n";
  std::cout << "Employees (" << E_.size() << "): ";
  for (const auto& e : E_) std::cout << e << " ";
  std::cout << "\n";
  std::cout << "Days: " << D_ << "\n";
  std::cout << "Shifts (" << S_.size() << "): ";
  for (const auto& s : S_) std::cout << s << " ";
  std::cout << "\n";
  std::cout << "Matrix A_ (satisfaction):\n";
  for (size_t e = 0; e < A_.size(); ++e) {
    std::cout << "Employee " << E_[e] << ":\n";
    for (size_t d = 0; d < A_[e].size(); ++d) {
      std::cout << "  Day " << d << ": ";
      for (size_t s = 0; s < A_[e][d].size(); ++s) {
        std::cout << A_[e][d][s] << " ";
      }
      std::cout << "\n";
    }
  }
  std::cout << "Matrix B_ (employees needed per day/shift):\n";
  for (size_t d = 0; d < B_.size(); ++d) {
    std::cout << "Day " << d << ": ";
    for (size_t s = 0; s < B_[d].size(); ++s) {
      std::cout << B_[d][s] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "Vector C_ (rest days per employee):\n";
  for (size_t e = 0; e < C_.size(); ++e) {
    std::cout << E_[e] << ": " << C_[e] << "\n";
  }
  std::cout << "===========================\n";
}