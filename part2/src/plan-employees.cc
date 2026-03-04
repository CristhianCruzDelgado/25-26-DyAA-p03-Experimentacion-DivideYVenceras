#include "employees-days-shifts.h" // instance
#include "plan-employees.h" // declaration
#include "schedule.h" // solution

bool PlanEmployees::small(Instance* I) const { 
  if (!I) throw std::runtime_error("Bad pointer: instance null. PlanEmployees::small");
  return false;
}

Solution* PlanEmployees::solveSmall(Instance* I) const { 
  if (!I) throw std::runtime_error("Bad pointer: instance null. PlanEmployees::solveSmall");
  return nullptr;
}

InstanceHalves PlanEmployees::divide(Instance* I, int size) const { 
  if (!I) throw std::runtime_error("Bad pointer: instance null. PlanEmployees::divide");
  return {nullptr, nullptr};
}

Solution* PlanEmployees::combine(Solution* S1, Solution* S2) const { 
  if (!S1) throw std::runtime_error("Bad pointer: solution null. PlanEmployees::combine");
  if (!S2) throw std::runtime_error("Bad pointer: solution null. PlanEmployees::combine");
  return nullptr;
}