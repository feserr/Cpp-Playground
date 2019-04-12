/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#ifndef CRTP_PERFORMANCE_CRTP_INTERFACE_H_
#define CRTP_PERFORMANCE_CRTP_INTERFACE_H_

#include <inttypes.h>

template <typename Implementation>
class CRTPInterface {
 public:
  void Tick(uint64_t n) { impl().Tick(n); }
  void InlineTick(uint64_t n) { impl().InlineTick(n); }

  uint64_t GetValue() { return impl().GetValue(); }

 private:
  Implementation& impl() { return *static_cast<Implementation*>(this); }
};

class CRTPImplementation : public CRTPInterface<CRTPImplementation> {
 public:
  CRTPImplementation();

  void Tick(uint64_t n);
  void InlineTick(uint64_t n) { counter_ += n; }

  uint64_t GetValue() { return counter_; }

 private:
  uint64_t counter_;
};

#endif  // CRTP_PERFORMANCE_CRTP_INTERFACE_H_