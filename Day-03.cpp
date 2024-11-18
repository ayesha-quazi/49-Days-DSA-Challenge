// i. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
 
        int n=nums.size();
        vector<int> ans(n);
        ans[0]=1;
 
        for(int i=1;i<n;i++) ans[i]=ans[i-1]*nums[i-1];// left prod
 
        int r=1;
        for(int i=n-1;i>=0;i--){// right prod
            ans[i]=ans[i]*r;
            r*=nums[i];
        }
         return ans;   
    }
};

// ii. Increment Submatrices by One

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        
        // Process each query
        for (int i = 0; i < queries.size(); i++) {
            int r1 = queries[i][0], c1 = queries[i][1];
            int r2 = queries[i][2], c2 = queries[i][3];

            for (int row = r1; row <= r2; row++) {
                v[row][c1]++; // Increment start of the range
                if (c2 + 1 < n) v[row][c2 + 1]--; // Decrement after the range
            }
        }

        // Apply prefix sum on each row
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                v[i][j] += v[i][j - 1];
            }
        }

        return v;
    }
};
