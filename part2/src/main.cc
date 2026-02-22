/**
 ** Universidad de La Laguna
 * Degree: Ingeniería Informática
 * Signature: Diseño y Análisis de Algoritmos
 * Practice 03: Planifiación de empleados
 * Authors: 
 *   Cristhian Adoney Cruz Delgado
 *   Michelangelo Da Cruz Bochicchio
 * Emails: 
 *   alu0101648293@ull.edu.es
 *   alu0101651217@ull.edu.es
 * Description: plans employee schedules
 */

#include "instance.h"
#include "reader.h"
#include "solution.h"
#include "writer.h"

#include <exception>
#include <fstream>
#include <iostream>

const char* HELP_MESSAGE = "Help: This program plans employee schedules. \
                            \nTry: ./planificar-empleados ~ Executable \
                            \ntest/instance_horizonX_employeesX_shifX_00[0|1].json ~ Input File \
                            \nsltn/solution_horizonX_employeesX_shifX_00[0|1].json ~ Output file\n";

int main(int argc, char* argv[]) {
  try {
    if (argc == 2 && std::string(argv[1]) == "--help") {
      std::cout << HELP_MESSAGE; 
      return 0;
    }
    if (argc != 3) throw std::invalid_argument("Missing arguments");

    Reader reader;
    Instance instance = reader.loadFile(std::string(argv[1]));
    DivideYVenceras solver;
    Solution solution = solver.solve(instance);
    Writer writer;
    writer.saveFile(solution, instance, std::string(argv[2]));
    std::cout << "x = " << solution.getObjectiveValue() << std::endl;

  } catch (const std::exception& e) {
    std::cerr << "\nerror: " << e.what() << "\n";
    return -1;
  } catch (...) {
    std::cerr << "\nerror: ...\n";
    return -1;
  }
  return 0;
}