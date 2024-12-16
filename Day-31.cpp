// i. Shortest Unsorted Continuous Subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while (low+1 < nums.size() && nums[low] <= nums[low+1]) low++;
        while (high-1 >= 0 && nums[high-1] <= nums[high]) high--;

        if (low == nums.size()-1) return 0;

        int wMin = INT_MAX, wMax = INT_MIN;
        for (int i = low; i <= high; i++) {
            wMin = min(wMin, nums[i]);
            wMax = max(wMax, nums[i]);
        }

        while (low-1 >= 0 && nums[low-1] > wMin) low--;
        while (high+1 <= nums.size()-1 && nums[high+1] < wMax) high++;

        return high - low + 1;
    }
};


// **********************************************************************

// ii. The Number of Weak Characters in the Game

class Solution {
public:
    bool static sorted(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1]; //[7,10],[7,9],[7,5]
        }
      return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
      sort(properties.begin(),properties.end(),sorted);
      int ans = 0,maxDefVal=INT_MIN;
        int n = properties.size();
        for(int i=n-1;i>=0;i--)
        {
            if(properties[i][1]<maxDefVal)
            {
                ans++;
            }
            if(properties[i][1]>maxDefVal)
            {
              maxDefVal = properties[i][1];  
            }
        }
        return ans;
    }
};

// **********************************************************************

// iii. Remove Duplicate Letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        stack<char> st;
        
        vector<bool> taken(26, false);
        vector<int> lastIndex(26);
        
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            
            lastIndex[ch-'a'] = i;
        }
        
        
        for(int i = 0; i < n; i++) {
            
            int idx = s[i] - 'a';
            
            if(taken[idx] == true) continue;
            
            while(!st.empty()  && s[i] < st.top() && lastIndex[st.top() - 'a'] > i) {
                taken[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(s[i]);
            taken[idx] = true;
            
        }
        
        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(result), end(result));
        
        return result;
    }
};



// ***********************************************************************