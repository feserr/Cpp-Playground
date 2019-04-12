/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#include <stdio.h>
#include <chrono>
#include <cstring>
#include "../crtp_performance/crtp_interface.h"
#include "../crtp_performance/dynamic_interface.h"

const double kIterations = 40000;
bool verbose = false;

void RunDynamic(DynamicInterface* obj) {
  if (verbose) printf("Do some work...\n");
  for (double i = 0; i < kIterations; ++i) {
    if (verbose) printf("\r%.2f%%", (i / kIterations) * 100);
    for (double j = 0; j < i; ++j) {
      obj->Tick(j);
    }
  }
  if (verbose) printf("\n");
}

void RunDynamicInline(DynamicInterface* obj) {
  if (verbose) printf("Do some work...\n");
  for (double i = 0; i < kIterations; ++i) {
    if (verbose) printf("\r%.2f%%", (i / kIterations) * 100);
    for (double j = 0; j < i; ++j) {
      obj->InlineTick(j);
    }
  }
  if (verbose) printf("\n");
}

template <typename Implementation>
void RunCrtp(CRTPInterface<Implementation>* obj) {
  if (verbose) printf("Do some work...\n");
  for (double i = 0; i < kIterations; ++i) {
    if (verbose) printf("\r%.2f%%", (i / kIterations) * 100);
    for (double j = 0; j < i; ++j) {
      obj->Tick(j);
    }
  }
  if (verbose) printf("\n");
}

template <typename Implementation>
void RunCrtpInline(CRTPInterface<Implementation>* obj) {
  if (verbose) printf("Do some work...\n");
  for (double i = 0; i < kIterations; ++i) {
    if (verbose) printf("\r%.2f%%", (i / kIterations) * 100);
    for (double j = 0; j < i; ++j) {
      obj->InlineTick(j);
    }
  }
  if (verbose) printf("\n");
}

inline void HelpOutput(const char* executable_name) {
  printf(
      "%s [TYPE] <INLINE> <verbose> \n\n\t-d\tDynamic interface performance "
      "test.\n\t-c\tCRTP "
      "interface performance test\n\t-i\tUse inlined functions\n\t-v\tVerbose "
      "mode\n",
      executable_name);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    HelpOutput(argv[0]);
    return -1;
  } else if (argc == 3) {
    if (strcmp(argv[2], "-v") == 0) {
      verbose = true;
    }
  } else if (argc == 4) {
    if (strcmp(argv[3], "-v") == 0) {
      verbose = true;
    }
  }

  auto start = std::chrono::steady_clock::now();
  if (strcmp(argv[1], "-d") == 0) {
    if (strcmp(argv[2], "-i") == 0) {
      printf("Dynamic interface inline performance test.\n");
      DynamicImplementation* pObj = new DynamicImplementation();
      RunDynamicInline(pObj);
      delete pObj;
    } else {
      printf("Dynamic interface performance test.\n");
      DynamicImplementation* pObj = new DynamicImplementation();
      RunDynamic(pObj);
      delete pObj;
    }
  } else if (strcmp(argv[1], "-c") == 0) {
    if (strcmp(argv[2], "-i") == 0) {
      printf("CRTP interface inline performance test.\n");
      CRTPImplementation* pObj = new CRTPImplementation();
      RunCrtpInline(pObj);
      delete pObj;
    } else {
      printf("CRTP interface performance test.\n");
      CRTPImplementation* pObj = new CRTPImplementation();
      RunCrtp(pObj);
      delete pObj;
    }
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
