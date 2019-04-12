/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#include "../pimpl_performance/abstract_class.h"
#include <memory>

struct AbstractClassImpl final : public AbstractClass {
  AbstractClassImpl(int first, int second) : first_(first), second_(second) {}

  virtual void Add() { result_ = first_ + second_; }

  virtual int GetResult() const { return result_; }

  const int first_;
  const int second_;
  int result_;
};

std::shared_ptr<AbstractClass> AbstractClass::Create(const int first,
                                                     const int second) {
  return std::make_shared<AbstractClassImpl>(first, second);
}
