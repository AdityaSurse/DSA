#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        // Step 1: Sort both the greed factors and cookie sizes
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int child = 0;   // Points to the least greedy child currently unsatisfied
        int cookie = 0;  // Points to the smallest available cookie

        // Step 2: Try to satisfy children with the smallest valid cookie
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                // The cookie is big enough; child is satisfied
                child++;
            }
            // Move to the next cookie regardless:
            // - If used, we need a new cookie.
            // - If not used, it's too small for this child (and all subsequent children).
            cookie++;
        }

        // 'child' index equals the total number of content children
        return child;
    }
};