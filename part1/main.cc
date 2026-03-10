/**
 * Universidad de La Laguna
 * Degree: Ingeniería Informática
 * Signature: Diseño y Análisis de Algoritmos
 * Practice 03: Experimentación con Divide y Vencerás
 * Authors: 
 *   Cristhian Adoney Cruz Delgado
 *   Michelangelo Da Cruz Bochicchio
 * Emails: 
 *   alu0101648293@ull.edu.es
 *   alu0101651217@ull.edu.es
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "divide_conquer_library.h"

void PrintUsage() {
  std::cout << "Usage:\n"
            << "  ./main                -> compare MergeSort vs QuickSort\n"
            << "  ./main -n [-a m|q]    -> normal mode (algorithm, time test)\n"
            << "  ./main -d [-a m|q] [-s size] -> debug mode\n\n"
            << "Options:\n"
            << "  -n        normal mode\n"
            << "  -d        debug mode\n"
            << "  -a m|q    algorithm (m=mergesort, q=quicksort)\n"
            << "  -s size   instance size\n";
}

Algorithm* SelectAlgorithm(char alg_flag) {
  if (alg_flag == 'q') return new QuickSort();
  return new MergeSort();
}

void DebugMode(char alg_flag, int size) {
  ExecutionContext context;
  Algorithm* algorithm = SelectAlgorithm(alg_flag);

  auto instance = SortingInstanceGenerator::Generate(size);

  std::cout << "Instance: ";
  instance.Print();
  std::cout << "\n";

  context.SetAlgorithm(algorithm);

  Solution* solution = context.Solve(instance);

  if (alg_flag == 'q') std::cout << "QuickSort ";
  else std::cout << "MergeSort ";
  std::cout << " solution: ";
  solution->Print();
  std::cout << "\n";

  delete solution;
  delete algorithm;
}

void NormalMode(char alg_flag) {
  ExecutionContext context;
  ExecutionTimer timer;

  Algorithm* algorithm = SelectAlgorithm(alg_flag);

  std::vector<int> sizes = {100, 500, 1000, 5000, 10000, 50000, 100000};

  context.SetAlgorithm(algorithm);

  if (alg_flag == 'q') std::cout << "QuickSort\n" << std::endl;
  else std::cout << "MergeSort\n" << std::endl;
  std::cout << std::left << std::setw(10) << "Size"
            << std::setw(15) << "Time(ms)" << "\n";

  for (int size : sizes) {
    auto instance = SortingInstanceGenerator::Generate(size);

    double time = timer.Measure(context, instance);

    std::cout << std::setw(10) << size
              << std::setw(15) << time << "\n";
  }

  delete algorithm;
}

void CompareMode() {
  ExecutionContext context;
  ExecutionTimer timer;

  Algorithm* mergesort = new MergeSort();
  Algorithm* quicksort = new QuickSort();

  std::vector<int> sizes = {100, 500, 1000, 5000, 10000, 50000, 100000};

  std::cout << std::left << std::setw(10) << "Size"
            << std::setw(15) << "MergeSort(ms)"
            << std::setw(15) << "QuickSort(ms)"
            << "\n";

  for (int size : sizes) {

    auto instance = SortingInstanceGenerator::Generate(size);

    context.SetAlgorithm(mergesort);
    double merge_time = timer.Measure(context, instance);

    context.SetAlgorithm(quicksort);
    double quick_time = timer.Measure(context, instance);

    std::cout << std::setw(10) << size
              << std::setw(15) << merge_time
              << std::setw(15) << quick_time
              << "\n";
  }

  delete mergesort;
  delete quicksort;
}

int main(int argc, char* argv[]) {

  bool normal = false;
  bool debug = false;

  char algorithm = 'm';
  int size = 10;

  for (int i = 1; i < argc; ++i) {

    std::string arg = argv[i];

    if (arg == "-n") normal = true;
    else if (arg == "-d") debug = true;

    else if (arg == "-a") {
      if (i + 1 >= argc) {
        PrintUsage();
        return 1;
      }
      algorithm = argv[++i][0];
      if (algorithm != 'q' && algorithm != 'm') {
        PrintUsage();
        return 1;
      }
    }

    else if (arg == "-s") {
      if (i + 1 >= argc) {
        PrintUsage();
        return 1;
      }
      size = std::stoi(argv[++i]);
    }

    else {
      PrintUsage();
      return 1;
    }
  }

  if (normal && debug) {
    std::cerr << "Error: cannot use -n and -d together\n";
    return 1;
  }

  if (debug) {
    DebugMode(algorithm, size);
  }

  else if (normal) {
    NormalMode(algorithm);
  }

  else {
    CompareMode();
  }

  return 0;
}