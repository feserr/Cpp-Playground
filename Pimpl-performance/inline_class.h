/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#ifndef PIMPL_PERFORMANCE_INLINE_CLASS_H_
#define PIMPL_PERFORMANCE_INLINE_CLASS_H_

class InlineClass final {
 public:
  InlineClass(const int first, const int second)
      : first_(first), second_(second), result_(0) {}

  void Add() { result_ = first_ + second_; }
  int GetResult() const { return result_; }

 private:
  const int first_;
  const int second_;
  int result_;
};

#endif  // PIMPL_PERFORMANCE_INLINE_CLASS_H_
