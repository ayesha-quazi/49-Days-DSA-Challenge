// i. Simplify Path

class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        
        stringstream ss(path);
        stack<string> st;
        
        while(getline(ss, token, '/')) {

            if(token == "" || token == ".") continue;
            
            if (token != "..") 
                st.push(token);
            else if (!st.empty()) 
                st.pop();
        }
        
        string result = "";
        
        while(!st.empty()){ // add all the stack elements
            result="/"+st.top()+result;
            st.pop();
        }
        
        if(result.length()==0) // if no directory or file is present
            result="/"; // minimum root directory must be present in result
        
        return result;
    }
};

// ***************************************

// ii. Merge Intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
        int i=0;
        while(i<n) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            i+=1;
            while(i<n and end>=intervals[i][0]) {
                end = max(end,intervals[i][1]);
                i+=1;
            }
            vector<int> temp;
            temp.push_back(start);
            temp.push_back(end);
            ans.push_back(temp);
        }
        return ans;
    }
};

