// i. XOR Queries of a Subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> cumXor(n, 0); //space : O(n)

        cumXor[0] = arr[0];
        for(int i = 1; i < n; i++) { //O(n)
            cumXor[i] = cumXor[i-1] ^ arr[i];
        }

        vector<int> result;
        for(vector<int>& query : queries) { //O(q)
            int L = query[0];
            int R = query[1];

            int xor_val = cumXor[R] ^ (L == 0 ? 0 : cumXor[L-1]);

            result.push_back(xor_val);
        }

        return result;
    }
};


// **********************************************************************


// ii. Gray Code

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string> garyString = generate(n);
        vector<int> ans;
        for(auto i:garyString)
        {
            ans.push_back(stoi(i,0,2));
        }
        return ans;
    }
    
    vector<string> generate(int n)
    {
        if(n==1)
        {
            return {"0","1"};
        }
        vector<string> ans;
        vector<string> temp = generate(n-1);
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back("0"+temp[i]);
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            ans.push_back("1"+temp[i]);
        }
        return ans;
    }
    
};


// **********************************************************************


// iii. Kth Smallest Number in Multiplication Table

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            int capacity = count(mid, m, n);
            if (capacity >= k) 
                high = mid;
            else 
                low = mid + 1;
        }

        return high;
    }

private:
    int count(int mid, int m, int n) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += std::min(mid / i, n);
        }
        return count;
    }
};
