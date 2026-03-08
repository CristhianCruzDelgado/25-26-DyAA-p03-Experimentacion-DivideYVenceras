#include "saver-schedule.h" // declaration
#include "schedule.h"       // solution
#include "employees-days-shifts.h" // para obtener E, D, S si hace falta
#include "instance.h"

void SaverSchedule::save(Instance* I, Solution* S, const std::string& path) const {
  EmployeesDaysShifts* E = dynamic_cast<EmployeesDaysShifts*>(I);
  Schedule* SCH = dynamic_cast<Schedule*>(S);
  if (!E) throw std::runtime_error("Bad pointer: instance null. SaverSchedule::save");
  if (!SCH) throw std::runtime_error("Bad pointer: solution null. SaverSchedule::save");

  std::ofstream file(path);
  if (!file) throw std::runtime_error("Bad output file: " + path);

  nlohmann::json j;

  const std::vector<std::vector<std::vector<bool>>>& schedule = SCH->getSchedule();
  int numE = schedule.size();
  int numD = schedule[0].size();
  int numS = schedule[0][0].size();

  j["employees"] = numE;
  j["days"] = numD;
  j["shifts"] = numS;
  j["schedule"] = nlohmann::json::array();
  for (int e = 0; e < numE; ++e) {
    nlohmann::json days = nlohmann::json::array();
    for (int d = 0; d < numD; ++d) {
      nlohmann::json shifts = nlohmann::json::array();
      for (int s = 0; s < numS; ++s) {
        shifts.push_back(schedule[e][d][s]);
      }
      days.push_back(shifts);
    }
    j["schedule"].push_back(days);
  }
  j["active"] = nlohmann::json::array();
  for (int e = 0; e < numE; ++e) {
    for (int d = 0; d < numD; ++d) {
      for (int s = 0; s < numS; ++s) {
        if (schedule[e][d][s]) {
          j["active"].push_back({ {"employee", e}, {"day", d}, {"shift", s} });
        }
      }
    }
  }
  double objValue = SCH->objectiveFunction(E);
  j["objective_function"] = objValue;
  file << j.dump(2);
}