/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/cpp-playground#license
 */

#include "../crtp_performance/crtp_interface.h"

CRTPImplementation::CRTPImplementation() : counter_(0) {}

void CRTPImplementation::Tick(uint64_t n) { counter_ += n; }
