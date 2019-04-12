/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#include <inttypes.h>
#include <chrono>
#include <cstring>
#include <memory>
#include <vector>
#include "../pimpl_performance/abstract_class.h"
#include "../pimpl_performance/inline_class.h"
#include "../pimpl_performance/pimpl_class.h"

const double repeats = 100000;
bool verbose = false;

int PimplRun(double count) {
  double temp_count = count;
  std::vector<std::shared_ptr<PimplClass> > vInstances;
  vInstances.reserve(count);
  if (verbose) printf("Generating data...\n");
  while (--count) {
    if (verbose) printf("\r%.2f%%", ((temp_count - count) / temp_count) * 100);
    vInstances.emplace_back(std::make_shared<PimplClass>(4711, 4711));
  }
  int result(0);
  count = vInstances.size();
  if (verbose) printf("\nDo some work...\n");
  while (--count) {
    if (verbose) printf("\r%.2f%%", ((temp_count - count) / temp_count) * 100);
    for (auto& pInstance : vInstances) {
      pInstance->Add();
      result += pInstance->GetResult();
    }
  }
  if (verbose) printf("\n");
  return result;
}

int AbstractRun(double count) {
  double temp_count = count;
  std::vector<std::shared_ptr<AbstractClass> > vInstances;
  vInstances.reserve(count);
  if (verbose) printf("Generating data...\n");
  while (--count) {
    if (verbose) printf("\r%.2f%%", ((temp_count - count) / temp_count) * 100);
    vInstances.emplace_back(AbstractClass::Create(4711, 4711));
  }
  int result(0);
  count = vInstances.size();
  if (verbose) printf("\nDo some work...\n");
  while (--count) {
    if (verbose) printf("\r%.2f%%", ((temp_count - count) / temp_count) * 100);
    for (auto& pInstance : vInstances) {
      pInstance->Add();
      result += pInstance->GetResult();
    }
  }
  if (verbose) printf("\n");
  return result;
}

int InlineRun(double count) {
  double temp_count = count;
  std::vector<std::shared_ptr<InlineClass> > vInstances;
  vInstances.reserve(count);
  if (verbose) printf("Generating data...\n");
  while (--count) {
    if (verbose) printf("\r%.2f%%", ((temp_count - count) / temp_count) * 100);
    vInstances.emplace_back(std::make_shared<InlineClass>(4711, 4711));
  }
  int result(0);
  count = vInstances.size();
  if (verbose) printf("\nDo some work...\n");
  while (--count) {
    if (verbose) printf("\r%.2f%%", ((temp_count - count) / temp_count) * 100);
    for (auto& pInstance : vInstances) {
      pInstance->Add();
      result += pInstance->GetResult();
    }
  }
  if (verbose) printf("\n");
  return result;
}

inline void HelpOutput(const char* executable_name) {
  printf(
      "%s [TYPE] <verbose> \n\n\t-p\tPimpl class performance "
      "test.\n\t-a\tAbstract class "
      "performance test\n\t-i\tInline performance test\n\t-v\tVerbose mode\n",
      executable_name);
}

int main(const int argc, char** argv) {
  if (argc < 2) {
    HelpOutput(argv[0]);
    return -1;
  } else if (argc == 3) {
    if (strcmp(argv[2], "-v") == 0) {
      verbose = true;
    }
  }

  auto start = std::chrono::steady_clock::now();
  if (strcmp(argv[1], "-p") == 0) {
    printf("Pimpl class performance test.\n");
    PimplRun(repeats);
  } else if (strcmp(argv[1], "-a") == 0) {
    printf("Abstract class performance test.\n");
    AbstractRun(repeats);
  } else if (strcmp(argv[1], "-i") == 0) {
    printf("Inline class performance test.\n");
    InlineRun(repeats);
  } else {
    HelpOutput(argv[0]);
    return -1;
  }
  auto end = std::chrono::steady_clock::now();
  printf("Test duration: %llu ms\n",
         std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
             .count());

  return 0;
}
