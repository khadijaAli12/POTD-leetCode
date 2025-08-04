// LeetCode POTD - 2025/08/04
// Problem: Fruit Into Baskets
[Fruit Into Baskets – LeetCode](https://leetcode.com/problems/fruit-into-baskets/)
// Tags: Sliding Window, Hash Map
// Approach: Maintain a sliding window with at most 2 types of fruits.

class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int n = fruits.size();
            unordered_map<int, int> mp;
            int i = 0, j = 0;
            int count = 0;
    
            while (j < n) {
                mp[fruits[j]]++; // Add fruit to the basket
    
                if (mp.size() <= 2) {
                    count = max(count, j - i + 1); // Update max if valid
                } else {
                    // Shrink window from left
                    mp[fruits[i]]--;
                    if (mp[fruits[i]] == 0) {
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
    
                j++;
            }
    
            return count;
        }
    };
    
