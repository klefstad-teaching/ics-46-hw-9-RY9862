#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(Edit_Distance, Equal) {
  EXPECT_TRUE(edit_distance_within("test", "test", 1));
  EXPECT_TRUE(edit_distance_within("test2", "test2", 1));
}

TEST(Edit_Distance, Replacement) {
  EXPECT_TRUE(edit_distance_within("car", "cat", 1));
}

TEST(Edit_Distance, Add_Remove) {
  EXPECT_TRUE(edit_distance_within("chat", "cheat", 1));
  EXPECT_TRUE(edit_distance_within("date", "dater", 1));
  EXPECT_TRUE(edit_distance_within("dan", "dean", 1));
  EXPECT_TRUE(edit_distance_within("dater", "date", 1));
}


