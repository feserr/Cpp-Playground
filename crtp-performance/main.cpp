/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#include <cstring>
#include <stdio.h>
#include "../crtp-performance/crtp_interface.h"
#include "../crtp-performance/dynamic_interface.h"

const uint64_t kIterations = 40000;

void RunDynamic(DynamicInterface* obj) {
  for (uint64_t i = 0; i < kIterations; ++i) {
    for (uint64_t j = 0; j < i; ++j) {
      obj->Tick(j);
    }
  }
}

void RunDynamicInline(DynamicInterface* obj) {
  for (uint64_t i = 0; i < kIterations; ++i) {
    for (uint64_t j = 0; j < i; ++j) {
      obj->InlineTick(j);
    }
  }
}

template <typename Implementation>
void RunCrtp(CRTPInterface<Implementation>* obj) {
  for (uint64_t i = 0; i < kIterations; ++i) {
    for (uint64_t j = 0; j < i; ++j) {
      obj->Tick(j);
    }
  }
}

template <typename Implementation>
void RunCrtpInline(CRTPInterface<Implementation>* obj) {
  for (uint64_t i = 0; i < kIterations; ++i) {
    for (uint64_t j = 0; j < i; ++j) {
      obj->InlineTick(j);
    }
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Wrong arguments.\n");
  }

  if (strcmp(argv[1], "d") == 0) {
    printf("Dynamic interface performance test.");
    DynamicImplementation* pObj = new DynamicImplementation();
    RunDynamic(pObj);
    delete pObj;
  } else if (strcmp(argv[1], "di") == 0) {
    printf("Dynamic interface inline performance test.");
    DynamicImplementation* pObj = new DynamicImplementation();
    RunDynamicInline(pObj);
    delete pObj;
  } else if (strcmp(argv[1], "c") == 0) {
    printf("CRTP interface performance test.");
    CRTPImplementation* pObj = new CRTPImplementation();
    RunCrtp(pObj);
    delete pObj;
  } else {
    printf("CRTP interface inline performance test.");
    CRTPImplementation* pObj = new CRTPImplementation();
    RunCrtpInline(pObj);
    delete pObj;
  }

  return 0;
}
