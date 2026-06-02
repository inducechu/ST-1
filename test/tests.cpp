// Copyright 2025 UNN-CS
#include "alg.h"
#include <cstdint>
#include <gtest/gtest.h>

TEST(PrimeTask, sumPrime_LargeBound) {
  const uint64_t out_res = sumPrime(2000000);
  const uint64_t out_exp = 142913828922ULL;
  EXPECT_EQ(out_exp, out_res);
}

TEST(PrimeTask, sumPrime_SmallBound) {
  const uint64_t out_res = sumPrime(15);
  const uint64_t out_exp = 41;
  EXPECT_EQ(out_exp, out_res);
}

TEST(PrimeTask, checkPrime_CornerCases) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_TRUE(checkPrime(2));
}

TEST(PrimeTask, checkPrime_PrimeNumbers) {
  EXPECT_TRUE(checkPrime(7));
  EXPECT_TRUE(checkPrime(13));
  EXPECT_TRUE(checkPrime(89));
}

TEST(PrimeTask, checkPrime_CompositeNumbers) {
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(15));
  EXPECT_FALSE(checkPrime(121));
}

TEST(PrimeTask, nPrime_FirstPrimes) {
  EXPECT_EQ(2, nPrime(1));
  EXPECT_EQ(3, nPrime(2));
  EXPECT_EQ(13, nPrime(6));
  EXPECT_EQ(17, nPrime(7));
}

TEST(PrimeTask, nPrime_ZeroCase) { EXPECT_EQ(0, nPrime(0)); }

TEST(PrimeTask, nextPrime_FromZeroAndOne) {
  EXPECT_EQ(2, nextPrime(0));
  EXPECT_EQ(2, nextPrime(1));
}

TEST(PrimeTask, nextPrime_FromPrimes) {
  EXPECT_EQ(3, nextPrime(2));
  EXPECT_EQ(7, nextPrime(5));
  EXPECT_EQ(13, nextPrime(11));
}

TEST(PrimeTask, nextPrime_FromComposites) {
  EXPECT_EQ(11, nextPrime(8));
  EXPECT_EQ(17, nextPrime(14));
}
