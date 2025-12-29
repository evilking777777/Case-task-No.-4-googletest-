#include <gtest/gtest.h>
#include "bst.hpp"
TEST(BST, Search){ BinarySearchTree<int> t; t.push(10); t.push(5); EXPECT_TRUE(t.search(10)); EXPECT_TRUE(t.search(5));}