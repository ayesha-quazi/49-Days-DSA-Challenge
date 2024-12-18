// i. Count Submatrices With All Ones

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> hist(m, vector<int>(n, 0));

        // Build histogram for consecutive 1s in columns
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    hist[i][j] = (i == 0) ? 1 : hist[i-1][j] + 1;
                }
            }
        }

        // Count rectangles
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int min_height = hist[i][j];
                for (int k = j; k >= 0 && min_height > 0; --k) {
                    min_height = min(min_height, hist[i][k]);
                    result += min_height;
                }
            }
        }
        return result;
    }
};


// **************************************************


// ii. Smallest Subsequence of Distinct Characters


class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        vector<int>lastindex(26,0);
        vector<bool>seen(26,false);
        for(int i = 0 ;i<s.size();i++)
        {
            lastindex[s[i] - 'a'] = i; 
        }
        for(int i = 0 ;i<s.size();i++)
        {
            int curr = s[i] - 'a'; 
            if(seen[curr])
            {
                continue;
            }
            while(st.size() > 0 && st.top() > s[i] && i < lastindex[st.top()-'a'])
            {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[curr] = true;  
        }
        string res= "";
        while(st.size() > 0)
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};