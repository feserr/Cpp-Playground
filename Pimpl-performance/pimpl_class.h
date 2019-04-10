/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#ifndef PIMPL_PERFORMANCE_PIMPL_CLASS_H_
#define PIMPL_PERFORMANCE_PIMPL_CLASS_H_

#include <memory>

class PimplClass final {
 public:
  PimplClass(const int first, const int second);
  ~PimplClass();

  void Add();
  int GetResult() const;

 private:
  struct Impl;
  std::unique_ptr<Impl> pImpl_;
};

#endif  // PIMPL_PERFORMANCE_PIMPL_CLASS_H_
