#include <gtest/gtest.h>
#include "queue.hpp"
TEST(Queue, FIFO){ Queue<int> q; q.push(1); q.push(2); EXPECT_EQ(q.pop(),1); EXPECT_EQ(q.pop(),2);}