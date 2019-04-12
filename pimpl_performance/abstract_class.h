/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#ifndef PIMPL_PERFORMANCE_ABSTRACT_CLASS_H_
#define PIMPL_PERFORMANCE_ABSTRACT_CLASS_H_

#include <memory>
struct AbstractClass {
  static std::shared_ptr<AbstractClass> Create(const int first,
                                               const int second);
  virtual ~AbstractClass() {}

  virtual void Add() = 0;
  virtual int GetResult() const = 0;
};

#endif  // PIMPL_PERFORMANCE_ABSTRACT_CLASS_H_
