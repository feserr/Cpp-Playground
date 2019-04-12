/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#include "../crtp_performance/dynamic_interface.h"

DynamicImplementation::DynamicImplementation() : counter_(0) {}

void DynamicImplementation::Tick(uint64_t n) { counter_ += n; }
