#include "employees-days-shifts.h" // instance
#include "loader-employee-day-shift.h" // declaration

Instance* LoaderEmployeeDayShift::load(const std::string& path) const {
  std::ifstream file(path);
  if (!file) { throw std::runtime_error("Bad input file: " + path); }

  nlohmann::json j;
  file >> j;

  int numS = j["shifts"].size();
  int numE = j["employees"].size();
  int numD = j["planningHorizon"].get<int>();

  std::vector<Employee> E(numE, "");
  std::vector<Shift> S(numS, "");
  std::vector<std::vector<std::vector<int>>> A(numE, std::vector<std::vector<int>>(numD, std::vector<int>(numS, 0)));
  std::vector<std::vector<int>> B(numD, std::vector<int>(numS, 0));
  std::vector<int> C(numE, 0);

  for (int s = 0; s < numS; ++s) {
    S[s] = j["shifts"][s];
  }

  for (int e = 0; e < numE; ++e) {
    E[e] = j["employees"][e]["name"];
    C[e] = j["employees"][e]["freeDays"];
  }

  for(const auto& entry : j["satisfaction"]){
    int e = entry["employee"];
    int d = entry["day"];
    int s = entry["shift"];
    int v = entry["value"];
    A[e][d][s] = v;
  }

  for(const auto& entry : j["requiredEmployees"]){
    int d = entry["day"];
    int s = entry["shift"];
    int v = entry["value"];
    B[d][s] = v;
  }  

  return new EmployeesDaysShifts(E, numD, S, A, B, C);
}