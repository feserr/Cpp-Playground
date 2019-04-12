/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#ifndef CRTP_PERFORMANCE_DYNAMIC_INTERFACE_H_
#define CRTP_PERFORMANCE_DYNAMIC_INTERFACE_H_

#include <inttypes.h>

class DynamicInterface {
 public:
  virtual ~DynamicInterface() {}

  virtual void Tick(uint64_t n) = 0;
  virtual void InlineTick(uint64_t n) = 0;
  virtual uint64_t GetValue() const = 0;
};

class DynamicImplementation : public DynamicInterface {
 public:
  DynamicImplementation();

  virtual void Tick(uint64_t n);
  virtual void InlineTick(uint64_t n) { counter_ += n; }
  virtual uint64_t GetValue() const { return counter_; }

 private:
  uint64_t counter_;
};

#endif  // CRTP_PERFORMANCE_DYNAMIC_INTERFACE_H_
