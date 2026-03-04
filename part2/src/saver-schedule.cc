#include "saver-schedule.h" // declaration
#include "schedule.h" // solution

void SaverSchedule::save(Solution* s1, const std::string& path) const {
  if (!s1) throw std::runtime_error("Bad pointer: solution null. SaverSchedule::save");
  std::ofstream file(path);
  if (!file) { throw std::runtime_error("Bad output file: " + path); }

  json j;

  Schedule* s2 = dynamic_cast<Schedule*>(s1);
  std::vector<std::vector<std::vector<bool>>> schedule = s2->getSchedule();

  int E = schedule.size();
  int D = schedule[0].size();
  int S = schedule[0][0].size();
  j["employees"] = E;
  j["days"] = D;
  j["shifts"] = S;

  j["schedule"] = json::array();
  for (int e = 0; e < E; ++e) {
    json days = json::array();
    for (int d = 0; d < D; ++d) {
      json shifts = json::array();
      for (int s = 0; s < S; ++s) {
        shifts.push_back(schedule[e][d][s]);
      }
      days.push_back(shifts);
    }
    j["schedule"].push_back(days);
  }

  j["active"] = json::array();
  for (int e = 0; e < E; ++e) {
    for (int d = 0; d < D; ++d) {
      for (int s = 0; s < S; ++s) {
        if (schedule[e][d][s]) {
          j["active"].push_back({ 
            {"employee", e},
            {"day", d},
            {"shift", s}
          });
        }
      }
    }
  }

  file << j.dump(2);
}