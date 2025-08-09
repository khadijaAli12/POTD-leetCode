// Problem: 231. Power of Two
// Link: https://leetcode.com/problems/power-of-two/
// Tags: Bit Manipulation, Math
// Difficulty: Easy
// Concept:
// A number is a power of two if it has exactly one bit set in binary form.
// Example: 1 (0001), 2 (0010), 4 (0100), 8 (1000)...
// Trick: n > 0 && (n & (n - 1)) == 0 → true if n is a power of 2.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

