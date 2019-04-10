/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#include <inttypes.h>
#include <cstring>
#include <memory>
#include <vector>
#include "../Pimpl-performance/abstract_class.h"
#include "../Pimpl-performance/inline_class.h"
#include "../Pimpl-performance/pimpl_class.h"

const uint64_t repeats = 100000;

int PimplRun(uint64_t count) {
  std::vector<std::shared_ptr<PimplClass> > vInstances;
  vInstances.reserve(count);
  while (--count)
    vInstances.emplace_back(std::make_shared<PimplClass>(4711, 4711));
  int result(0);
  count = vInstances.size();
  while (--count)
    for (auto& pInstance : vInstances) {
      pInstance->Add();
      result += pInstance->GetResult();
    }
  return result;
}

int AbstractRun(uint64_t count) {
  std::vector<std::shared_ptr<AbstractClass> > vInstances;
  vInstances.reserve(count);
  while (--count) vInstances.emplace_back(AbstractClass::Create(4711, 4711));
  int result(0);
  count = vInstances.size();
  while (--count)
    for (auto& pInstance : vInstances) {
      pInstance->Add();
      result += pInstance->GetResult();
    }
  return result;
}

int InlineRun(uint64_t count) {
  std::vector<std::shared_ptr<InlineClass> > vInstances;
  vInstances.reserve(count);
  while (--count)
    vInstances.emplace_back(std::make_shared<InlineClass>(4711, 4711));
  int result(0);
  count = vInstances.size();
  while (--count)
    for (auto& pInstance : vInstances) {
      pInstance->Add();
      result += pInstance->GetResult();
    }
  return result;
}

int main(const int argc, char** argv) {
  if (argc < 2) {
    printf("Wrong arguments\n");
    return -1;
  }

  if (strcmp(argv[1], "p") == 0) {
    printf("Pimpl class performance test.");
    PimplRun(repeats);
  } else if (strcmp(argv[1], "a") == 0) {
    printf("Abstract class performance test.");
    AbstractRun(repeats);
  } else {
    printf("Inline class performance test.");
    InlineRun(repeats);
  }

  return 0;
}
