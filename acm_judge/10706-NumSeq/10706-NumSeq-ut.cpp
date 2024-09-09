#include "gtest/gtest.h"
#include "10706-NumSeq.cpp"

TEST(Number, Digit_Count)
{
    Number n {10017};
    EXPECT_EQ(5, n.digit_count());
    for(int i=0; i<10; i++) {
        n = i;
        EXPECT_EQ(1, n.digit_count());
    }
    for(int i=100; i<1000; ++i) {
        n = i;
        EXPECT_EQ(3, n.digit_count());
    }
}

TEST(Number, Nth_Digit)
{
    Number n { 76543 };
    EXPECT_EQ(7, n.nth_digit(1));
    EXPECT_EQ(6, n.nth_digit(2));
    EXPECT_EQ(5, n.nth_digit(3));
    EXPECT_EQ(4, n.nth_digit(4));
    EXPECT_EQ(3, n.nth_digit(5));
    n  = 1;
    EXPECT_EQ(1, n.nth_digit(1));
}

TEST(NumberSet, Preceding_digits)
{
// 11212312341234512345612345671234567812345678912345678910123456789101112345678910
    NumberSet ns;
    EXPECT_EQ(3, ns.preceding_number_set_in_digits(5));
    EXPECT_EQ(3, ns.preceding_number_set_in_digits(6));
    EXPECT_EQ(6, ns.preceding_number_set_in_digits(7));
    EXPECT_EQ(6, ns.preceding_number_set_in_digits(8));
    EXPECT_EQ(6, ns.preceding_number_set_in_digits(9));
    EXPECT_EQ(6, ns.preceding_number_set_in_digits(10));
    EXPECT_EQ(10, ns.preceding_number_set_in_digits(11));
    EXPECT_EQ(10, ns.preceding_number_set_in_digits(12));
    EXPECT_EQ(10, ns.preceding_number_set_in_digits(13));
}

TEST(NumberSet, Preceding_Sets)
{
    NumberSet ns;
    EXPECT_EQ(2, ns.preceding_number_set(5));
    EXPECT_EQ(2, ns.preceding_number_set(6));
    EXPECT_EQ(3, ns.preceding_number_set(7));
    EXPECT_EQ(3, ns.preceding_number_set(8));

}
TEST(NumberSet, Nth_Number)
{
    NumberSet ns;
    EXPECT_EQ(9, ns.nth_number(9));
    EXPECT_EQ(10, ns.nth_number(10));
    EXPECT_EQ(10, ns.nth_number(11));
}
TEST(NumberSet, Locate_At)
{
    NumberSet ns;
#if 0
    for(uint i=1; i<=2147483647U; ++i) {
        ns.locate_at(i);
    }
#endif
    EXPECT_EQ(1, ns.locate_at(1));
    EXPECT_EQ(1, ns.locate_at(2));
    EXPECT_EQ(2, ns.locate_at(3));
    EXPECT_EQ(1, ns.locate_at(4));
    EXPECT_EQ(2, ns.locate_at(5));
    EXPECT_EQ(3, ns.locate_at(6));
    EXPECT_EQ(1, ns.locate_at(7));
    EXPECT_EQ(2, ns.locate_at(8));
    EXPECT_EQ(3, ns.locate_at(9));
    EXPECT_EQ(4, ns.locate_at(10));
    EXPECT_EQ(1, ns.locate_at(11));
    EXPECT_EQ(1, ns.locate_at(55));
    EXPECT_EQ(2, ns.locate_at(2147483647U));
}
