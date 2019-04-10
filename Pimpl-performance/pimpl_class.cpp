/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#include "../Pimpl-performance/pimpl_class.h"

struct PimplClass::Impl {
  Impl(int first, int second) : first_(first), second_(second), result_(0) {}

  const int first_;
  const int second_;
  int result_;
};
PimplClass::PimplClass(const int first, const int second)
    : pImpl_(std::unique_ptr<Impl>(new Impl(first, second))) {}

PimplClass::~PimplClass() {}

void PimplClass::Add() { pImpl_->result_ = pImpl_->first_ + pImpl_->second_; }

int PimplClass::GetResult() const { return pImpl_->result_; }
