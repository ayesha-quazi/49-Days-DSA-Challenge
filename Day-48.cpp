// Partition Equal Subset Sum


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        // If the total sum is odd, it's impossible to partition into equal subsets
        if (sum % 2 != 0) return false;

        int target = sum / 2;

        // DP array: dp[j] is true if a subset with sum j can be formed
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Subset with sum 0 is always possible

        for (int num : nums) {
            // Traverse dp array from right to left to avoid overwriting values
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
