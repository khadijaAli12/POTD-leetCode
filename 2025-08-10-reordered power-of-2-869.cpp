First Solution – Checking by Sorting for Each Power of 2
cpp
Copy
Edit
// Problem: 869 - Reordered Power of 2
// Concept: Sorting + String Comparison
// Approach: For a given number, sort its digits and compare with sorted digits of all powers of 2 (up to 2^29 for n ≤ 1e9).
// Time Complexity: O(30 * log10(n)) for sorting and comparison
// Space Complexity: O(1)

class Solution {
public:
    string getSortedString(int n) {
        string s = to_string(n);
        sort(begin(s), end(s));
        return s;
    }
    
    bool reorderedPowerOf2(int n) {
        string s = getSortedString(n);
        for (int i = 0; i <= 29; i++) {
            if (s == getSortedString(1 << i)) {
                return true;
            }
        }
        return false;
    }
};
Second Solution – Precompute All Possible Sorted Strings of Powers of 2
cpp
Copy
Edit
// Problem: 869 - Reordered Power of 2
// Concept: Precomputation + Unordered Set
// Approach: Store all sorted-digit strings of powers of 2 in a set once, then just check membership for the input number.
// Time Complexity: O(log10(n)) for sorting the input
// Space Complexity: O(1) extra after precomputation

unordered_set<string> st;

void BuildSet() {
    for (int p = 0; p <= 29; p++) {
        int power = 1 << p;
        string s = to_string(power);
        sort(begin(s), end(s));
        st.insert(s);
    }
}

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if (st.empty()) {
            BuildSet();
        }
        string s = to_string(n);
        sort(begin(s), end(s));
        return st.count(s);
    }
};
Tags
Hashing Sorting Precomputation String Manipulation Bit Manipulation

Concept
Sorting Digits: The main trick is that two numbers can be permutations of each other if their sorted digit strings are the same.

Precomputation: We store all possible sorted strings of powers of 2 up to 2^29 in a set for O(1) lookup.

Bit Shifts: (1 << i) efficiently computes 2^i.
