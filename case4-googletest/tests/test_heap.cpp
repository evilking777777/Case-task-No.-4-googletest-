#include <gtest/gtest.h>
#include "heap.hpp"
TEST(Heap, Max){ Heap<int> h; h.push(3); h.push(7); EXPECT_EQ(h.pop(),7);}