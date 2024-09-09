#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <vector>

#define MAX_NTH_DIGIT (2147483647U)
#define MAX_NUM_NUMBER_SET (31271)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

typedef unsigned int uint;

class Number {
private:
    uint n_;

public:
    Number(uint n)
        : n_(n)
    {
    }
    uint digit_count() const;
    uint nth_digit(uint nth) const;
};

uint Number::digit_count() const
{
    assert(n_ < 100000);
    if (n_ >= 10000)
        return 5;
    else if (n_ >= 1000)
        return 4;
    else if (n_ >= 100)
        return 3;
    else if (n_ >= 10)
        return 2;
    else
        return 1;
}

uint Number::nth_digit(uint nth) const
{
    // If n_ = 2345, then return 2 for nth=1, 3 for nth=2, etc.
    uint digits[10];
    uint k = 0;
    uint temp = n_;
    assert(nth >= 1);
    do {
        digits[k++] = temp % 10;
        temp /= 10;
    } while (temp > 0);
    assert(nth <= k);
    for (uint i = 0, j = k - 1; i < j; ++i, --j) {
        std::swap(digits[i], digits[j]);
    }
    return digits[nth - 1];
}

class NumberSet {
private:
    std::vector<uint> number_set_size_prefix_sum;
    std::vector<uint> number_set_size;
    std::vector<uint> num_digits;

public:
    NumberSet()
    {
        number_set_size_prefix_sum.reserve(MAX_NUM_NUMBER_SET);
        num_digits.reserve(MAX_NUM_NUMBER_SET);
        number_set_size.reserve(MAX_NUM_NUMBER_SET);
        build();
    }
    uint locate_at(const uint nth_digit) const
    {
        // Decide which digit is at the position nth_digit in the sequence
        auto preceding_digits = preceding_number_set_in_digits(nth_digit);
        auto nth_digit_in_si = nth_digit - preceding_digits;
        auto at_number = nth_number(nth_digit_in_si);
        auto digits_prefix_sum = number_set_size[at_number - 1];

        auto at_nth_digit_at_number = nth_digit_in_si - digits_prefix_sum;
        return Number(at_number).nth_digit(at_nth_digit_at_number);
    }

private:
    void build()
    {
        number_set_size_prefix_sum.push_back(0);
        number_set_size.push_back(0);
        num_digits.push_back(0);

        uint count = 1;
        Number number = count;
        do {
            uint digits = number.digit_count();
            num_digits.push_back(digits);
            number_set_size.push_back(number_set_size.back() + digits);
            number = ++count;
            number_set_size_prefix_sum.push_back(
                number_set_size.back() + number_set_size_prefix_sum.back());
        } while (count <= MAX_NUM_NUMBER_SET);
        assert(number_set_size_prefix_sum.back() > MAX_NTH_DIGIT);
    }
    uint preceding_number_set_in_digits(const uint nth_digit) const
    {
        // In the sequence 1 12 123 1234 ..., decide the number of digits in
        // the preceding full number sets, excluding the number set where
        // nth_digit locates in.
        // For example, if nth_digit = 5, then return 3.
        const auto up = std::lower_bound(number_set_size_prefix_sum.begin(),
            number_set_size_prefix_sum.end(), nth_digit);
        return *(up - 1);
    }
    uint preceding_number_set(const uint nth_digit) const
    {
        // In the sequence 1 12 123 1234 ..., decide the number of preceding
        // full Si for the given nth_digit, excluding the number set where
        // nth_digit locates in.
        // For example, if nth_digit = 5, then return 2.
        const auto up = std::lower_bound(number_set_size_prefix_sum.begin(),
            number_set_size_prefix_sum.end(), nth_digit);
        return up - number_set_size_prefix_sum.begin() - 1;
    }
    uint nth_number(const uint nth_digit_in_si) const
    {
        // In a number set 1234567891011..., decide the natural number where
        // the nth_digit locates in.

        auto low = std::lower_bound(number_set_size.begin(),
            number_set_size.end(), nth_digit_in_si);

        return low - number_set_size.begin();
    }
};

#if !defined(ENABLE_UNITTEST) && !defined(ENABLE_BENCHMARK)
int main(int argc, char* argv[])
{
    int nCases = 0;
    uint nth = 0;
    NumberSet ns;
#ifndef ONLINE_JUDGE
    std::ifstream input_file("../in.txt");
    std::cin.rdbuf(input_file.rdbuf());
#endif

    std::cin >> nCases;
    while (nCases--) {
        std::cin >> nth;
        std::cout << ns.locate_at(nth) << "\n";
    }

#ifndef ONLINE_JUDGE
    input_file.close();
#endif
    return 0;
}
#endif
