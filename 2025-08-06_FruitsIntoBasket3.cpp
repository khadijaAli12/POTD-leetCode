/*
LeetCode Problem: 3479 - Fruits Into Baskets III
Link: https://leetcode.com/problems/fruits-into-baskets-iii/

🧠 Data Structure Used:
- Segment Tree: Used to efficiently find and update the leftmost basket with sufficient capacity.

🏷️ Tags:
- Segment Tree
- Greedy
- Array
- Binary Search on Tree
- Range Queries

⏱️ Time Complexity:
- Build Segment Tree: O(n)
- Each Fruit Placement: O(log n)
- Total: O(n log n)
*/

class Solution {
    public:
        // Function to build segment tree from basket capacities.
        // Each node stores the maximum capacity in its segment.
        void build(int i, int l, int r, vector<int>& baskets, vector<int>& segmentTree) {
            if (l == r) {
                segmentTree[i] = baskets[l];  // Leaf node = single basket
                return;
            }
    
            int m = (l + r) / 2;
            build(2*i + 1, l, m, baskets, segmentTree);        // Left child
            build(2*i + 2, m + 1, r, baskets, segmentTree);    // Right child
    
            segmentTree[i] = max(segmentTree[2*i + 1], segmentTree[2*i + 2]); // Store max capacity
        }
    
        // Function to find and mark the leftmost basket with capacity >= val
        bool querySegmentTree(int i, int l, int r, vector<int>& segmentTree, int val) {
            // No basket in this segment can hold the fruit
            if (segmentTree[i] < val)
                return false;
    
            // Leaf node found with enough capacity, mark it as used
            if (l == r) {
                segmentTree[i] = -1;
                return true;
            }
    
            int mid = (l + r) / 2;
            bool placed;
    
            // Try left child first (leftmost basket rule)
            if (segmentTree[2*i + 1] >= val)
                placed = querySegmentTree(2*i + 1, l, mid, segmentTree, val);
            else
                placed = querySegmentTree(2*i + 2, mid + 1, r, segmentTree, val);
    
            // Update the current node after placing
            segmentTree[i] = max(segmentTree[2*i + 1], segmentTree[2*i + 2]);
            return placed;
        }
    
        // Main function to return number of unplaced fruits
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int n = fruits.size();
            vector<int> segmentTree(4 * n, -1);
    
            // Build segment tree from basket capacities
            build(0, 0, n - 1, baskets, segmentTree);
    
            int unplaced = 0;
    
            // Try placing each fruit
            for (int &fruit : fruits) {
                if (!querySegmentTree(0, 0, n - 1, segmentTree, fruit)) {
                    unplaced++;  // Fruit couldn't be placed
                }
            }
    
            return unplaced;
        }
    };
    