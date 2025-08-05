// LeetCode POTD – 2025/08/05
// Problem: Fruits Into Baskets II (3477)
// Link: https://leetcode.com/problems/fruits-into-baskets-ii/
// Tags: Greedy, Matching, Brute Force
// Approach: For each fruit, try to find the smallest available basket that can hold it.
//           Use a boolean array to mark used baskets.

class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int unplaced = 0;
            int n = fruits.size();
            vector<bool> used(n, false); // Tracks which baskets have been used
    
            for (int i = 0; i < n; i++) {
                bool placed = false;
                for (int j = 0; j < n; j++) {
                    if (!used[j] && fruits[i] <= baskets[j]) {
                        used[j] = true;  // Mark basket as used
                        placed = true;
                        break;
                    }
                }
                if (!placed) {
                    unplaced++; // Couldn't place this fruit
                }
            }
    
            return unplaced;
        }
    };
    