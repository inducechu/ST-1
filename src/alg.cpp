// Copyright 2025 UNN-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t num) {
  if (num <= 1)
    return false;
  if (num <= 3)
    return true;
  if (num % 2 == 0 || num % 3 == 0)
    return false;

  for (uint64_t step = 5; (step * step) <= num; step += 6) {
    if (num % step == 0 || num % (step + 2) == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t target_n) {
  if (target_n == 0)
    return 0;

  uint64_t counter = 0;
  uint64_t current_val = 1;

  while (counter < target_n) {
    current_val++;
    if (checkPrime(current_val)) {
      counter++;
    }
  }
  return current_val;
}

uint64_t nextPrime(uint64_t start_val) {
  if (start_val < 2)
    return 2;

  uint64_t next_val = start_val;
  do {
    next_val++;
  } while (!checkPrime(next_val));

  return next_val;
}

uint64_t sumPrime(uint64_t limit) {
  uint64_t total_sum = 0;
  for (uint64_t index = 2; index < limit; index++) {
    if (checkPrime(index)) {
      total_sum += index;
    }
  }
  return total_sum;
}
