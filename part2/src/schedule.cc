#include "schedule.h" // declaration
#include "employees-days-shifts.h" // instance

Schedule::Schedule(std::vector<std::vector<std::vector<bool>>> schedule) : schedule_(std::move(schedule)) {}

const std::vector<std::vector<std::vector<bool>>>& Schedule::getSchedule() const { return schedule_; }

double Schedule::calculateSatisfaction(EmployeesDaysShifts* E) const {
  double sumSatisfaction = 0.0;
  int numE = E->getEmployees().size();
  int numD = E->getDays();
  int numS = E->getShifts().size();
  const auto& A = E->getA();
  for (int e = 0; e < numE; ++e) 
    for (int d = 0; d < numD; ++d) 
      for (int s = 0; s < numS; ++s) 
        if (schedule_[e][d][s]) sumSatisfaction += A[e][d][s];
  return sumSatisfaction;
}

int Schedule::countCoveredShifts(EmployeesDaysShifts* E) const {
  int countShifts = 0;
  int numE = E->getEmployees().size();
  int numD = E->getDays();
  int numS = E->getShifts().size();
  const std::vector<std::vector<int>>& B = E->getB();
  for (int d = 0; d < numD; ++d) {
    for (int s = 0; s < numS; ++s) {
      int assigned = 1;
      for (int e = 0; e < numE; ++e)
        if (schedule_[e][d][s]) ++assigned;
      if (assigned > B[d][s]) ++countShifts;
    }
  }
  return countShifts;
}

double Schedule::objectiveFunction(Instance* I) const {
  EmployeesDaysShifts* E = dynamic_cast<EmployeesDaysShifts*>(I);
  if (!E) throw std::runtime_error("Bad pointer: instance null. Schedule::objectiveFunction");
  return calculateSatisfaction(E) + 100.0 * countCoveredShifts(E);
}