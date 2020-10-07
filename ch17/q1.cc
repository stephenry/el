//========================================================================== //
// Copyright (c) 2020, Stephen Henry
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//========================================================================== //

#include "gtest/gtest.h"
#include <vector>

class CombinationsRecursive {
 public:
  CombinationsRecursive() = default;
  std::size_t operator()(std::uint64_t score) {
    if (score == 0) return 1;

    return recurse(score);
  }

 private:
  std::size_t recurse(std::int64_t score) {
    if (score < 0) return 0;
    
    std::size_t count = 0;
    if (score == 2 || score == 3 || score == 7) ++count;

    return count + recurse(score - 2) + recurse(score - 3) + recurse(score - 7);
  }
};


TEST(Ch17Q1, Recursive) {
  CombinationsRecursive recur;
  EXPECT_EQ(recur(-1), 0);
  EXPECT_EQ(recur(0), 1);
  EXPECT_EQ(recur(1), 0);
  EXPECT_EQ(recur(2), 1);
  EXPECT_EQ(recur(3), 1);
  EXPECT_EQ(recur(4), 1);
  EXPECT_EQ(recur(5), 2);
  EXPECT_EQ(recur(6), 2);
  EXPECT_EQ(recur(12), 4);
}

int main(int argc, char**argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

