#include "employees-days-shifts.h" // instance
#include "plan-employees.h" // declaration
#include "schedule.h" // solution

bool PlanEmployees::small(Instance* I) const { 
  EmployeesDaysShifts* E = dynamic_cast<EmployeesDaysShifts*>(I);
  if (!E) throw std::runtime_error("Bad pointer: instance null. PlanEmployees::small");
  return E->getDays() == 1;
}

int assigemntsOfEmployee(int e, const std::vector<std::vector<std::vector<bool>>>& schedule) {
  int count = 0;
  int numD = schedule[0].size();
  int numS = schedule[0][0].size();
  for (int d = 0; d < numD; ++d)
    for (int s = 0; s < numS; ++s)
      count += schedule[e][d][s];
  return count;
}

Solution* PlanEmployees::solveSmall(Instance* I) const {
  EmployeesDaysShifts* E = dynamic_cast<EmployeesDaysShifts*>(I); 
  if (!E) throw std::runtime_error("Bad pointer: instance null. PlanEmployees::solveSmall");

  // void displayOnConsoleSolveSmall() const {
  std::cout << "[TRACE] solveSmall called for " << E->getDays() << " day(s)\n";
  E->displayOnConsole();
  // }

  int numD = EmployeesDaysShifts::getRealSize();
  int numE = E->getEmployees().size();
  int numS = E->getShifts().size();
  std::vector<std::vector<std::vector<bool>>> sch(numE, std::vector<std::vector<bool>>(1, std::vector<bool>(numS, false)));
  for (int s = 0; s < numS; ++s) {
    int required = E->getB()[0][s];

    std::vector<std::pair<int,int>> candidates;
    for (int e = 0; e < numE; ++e) {
      if (numD - assigemntsOfEmployee(e, sch) == E->getC()[e]) continue; 
      candidates.push_back({E->getA()[e][0][s], e});
    }

    // Sort by descending satisfaction
    std::sort(candidates.begin(), candidates.end(), std::greater<>());

    int assigned = 0;
    for (std::pair<int,int>& p : candidates) {
      if (assigned == required) break;
      int e = p.second;
      sch[e][0][s] = true;
      ++assigned;
    }
  }
  return new Schedule(sch);
}

InstanceHalves PlanEmployees::divide(Instance* I, int size) const { 
  EmployeesDaysShifts* E = dynamic_cast<EmployeesDaysShifts*>(I);
  if (!E) throw std::runtime_error("Bad pointer: instance null. PlanEmployees::divide");
  size = E->getDays();
  int mid = size / 2;

  // void displayOnConsoleDivide() const {
  std::cout << "[TRACE] divide called: mid=" << mid << "\n";
  E->displayOnConsole();
  // }

  EmployeesDaysShifts* left = new EmployeesDaysShifts(
      E->getEmployees(), mid, E->getShifts(),
      E->getFromToDaysFromA(0, mid), E->getFromToDaysFromB(0, mid), E->getC()
  );
  EmployeesDaysShifts* right = new EmployeesDaysShifts(
      E->getEmployees(), size - mid, E->getShifts(),
      E->getFromToDaysFromA(mid, size), E->getFromToDaysFromB(mid, size), E->getC()
  );
  return {left, right};
}

Solution* PlanEmployees::combine(Solution* S1, Solution* S2) const { 
  Schedule* SCH1 = dynamic_cast<Schedule*>(S1);
  Schedule* SCH2 = dynamic_cast<Schedule*>(S2);
  if (!SCH1 || !SCH2) throw std::runtime_error("Bad pointer: solution null. PlanEmployees::combine");
  const auto& sch1 = SCH1->getSchedule();
  const auto& sch2 = SCH2->getSchedule();
  int numE = sch1.size();
  int days1 = sch1[0].size();
  int days2 = sch2[0].size();
  int numS = sch1[0][0].size();
  std::vector<std::vector<std::vector<bool>>> combined(numE, std::vector<std::vector<bool>>(days1 + days2, std::vector<bool>(numS, false)));
  // Copy days of SCH1
  for (int e = 0; e < numE; ++e) {
    for (int d = 0; d < days1; ++d) {
      for (int s = 0; s < numS; ++s) {
        combined[e][d][s] = sch1[e][d][s];
      }
    }
  }
  // Copy days of SCH2
  for (int e = 0; e < numE; ++e) {
    for (int d = 0; d < days2; ++d) {
      for (int s = 0; s < numS; ++s) {
        combined[e][days1 + d][s] = sch2[e][d][s];
      }
    }
  }
  Schedule* CMB = new Schedule(combined);

  // void displayOnConsoleCombine() const {
  std::cout << "[TRACE] combined schedule (" << days1 + days2 << " days):\n";
  for (int e = 0; e < numE; ++e) {
    std::cout << " Employee " << e << ": ";
    for (int d = 0; d < days1 + days2; ++d) {
      std::cout << "[";
      for (int s = 0; s < numS; ++s) {
        std::cout << CMB->getSchedule()[e][d][s];
        if (s < numS - 1) std::cout << ",";
      }
      std::cout << "] ";
    }
    std::cout << "\n";
  }
  std::cout << "====================\n";
  // }

  return CMB;
}