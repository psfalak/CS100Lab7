#include "base.hpp"
#include "factory.hpp"
#include "gtest/gtest.h"


TEST(Parse, Operators){
  char* ar[5]; ar[0] = "3"; ar[1] = "+"; ar[2] = "5"; ar[3] = "-"; ar[4] = "6";
  Factory fact = Factory();
  Base* base = fact.parse(ar, 5);
  std::cout << base->evaluate();
  EXPECT_EQ(2, base->evaluate());
  EXPECT_EQ("3.000000 + 5.000000 - 6.000000", base->stringify());
  ASSERT_NE(base, nullptr);
}


TEST(Parse, Mult){
  char* ar[5]; ar[0] = "3"; ar[1] = "+"; ar[2] = "5"; ar[3] = "*"; ar[4] = "6";
  Factory fact = Factory();
  Base* base = fact.parse(ar, 5);
  std::cout << base->evaluate();
  EXPECT_EQ(48, base->evaluate());
  EXPECT_EQ("3.000000 + 5.000000 * 6.000000", base->stringify());
  ASSERT_NE(base, nullptr);
}


TEST(Parse, Pow){
  char* ar[6]; ar[0] = "3"; ar[1] = "*"; ar[2] = "*"; ar[3] = "2"; ar[4] = "-"; ar[5] = "6";
  Factory fact = Factory();
  Base* base = fact.parse(ar, 6);
  std::cout << base->evaluate();
  EXPECT_EQ(3, base->evaluate());
  EXPECT_EQ("3.000000 ** 2.000000 - 6.000000", base->stringify());
  ASSERT_NE(base, nullptr);
}


TEST(Parse, PowEnd){
  char* ar[6]; ar[0] = "3"; ar[1] = "+"; ar[2] = "1"; ar[3] = "*"; ar[4] = "*"; ar[5] = "1";
  Factory fact = Factory();
  Base* base = fact.parse(ar, 6);
  std::cout << base->evaluate();
  EXPECT_EQ(4, base->evaluate());
  EXPECT_EQ("3.000000 + 2.000000 ** 1.000000", base->stringify());
  ASSERT_NE(base, nullptr);
}



TEST(Parse, ZeroTestPow){
  char* ar[6]; ar[0] = "0"; ar[1] = "+"; ar[2] = "1"; ar[3] = "*"; ar[4] = "*"; ar[5] = "0";
  Factory fact = Factory();
  Base* base = fact.parse(ar, 6);
  std::cout << base->evaluate();
  EXPECT_EQ(1, base->evaluate());
  EXPECT_EQ("0.000000 + 1.000000 ** 0.000000", base->stringify());
  ASSERT_NE(base, nullptr);

}



TEST(Parse, ZeroTestDiv){
  char* ar[5]; ar[0] = "0"; ar[1] = "+"; ar[2] = "0"; ar[3] = "/"; ar[4] = "3";
  Factory fact = Factory();
  Base* base = fact.parse(ar, 5);
  std::cout << base->evaluate();
  EXPECT_EQ(0, base->evaluate());
  EXPECT_EQ("0.000000 + 0.000000 / 3.000000", base->stringify());
  ASSERT_NE(base, nullptr);
}


int main(int argc, char **argv) {
 ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}
