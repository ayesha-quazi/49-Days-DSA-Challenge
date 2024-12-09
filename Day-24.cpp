// i. Reduce Array Size to The Half

#include<bits/stdc++.h>
class Solution {
public:
   
    
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i = 0; i< arr.size(); i++){
            m[arr[i]] += 1;
        }
        
        multiset<int, greater<int>> s;
        
        for(auto n : m){
            s.insert(n.second);
        }
        
        int size = arr.size();
        int count = 0;
        int ans = 0;
        
        for(auto it = s.begin(); count * 2 < size ; it++){
            ans++;
            count += *it;
        }
        
        return ans;
        
    }
};

// ***************************************************************

// ii. Relative Sort Array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;

        for(int &num : arr1) {
            mp[num]++;
        }

        int i = 0;
        for(int &num : arr2) {
            while(mp[num]-- > 0) {
                arr1[i++] = num;
            }
        }

        for(auto &it : mp) {
            int freq = it.second;
            while(freq > 0) {
                arr1[i++] = it.first;
                freq--;
            }
        }

        return arr1;
    }
};

// ***************************************************************

// iii. Maximum Ice Cream Bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        
        int count = 0;
        
        for(int &cost : costs) {
            if(cost > coins)
                return count;
            else {
                count++;
                coins -= cost;
            }
        }
        
        return count;
    }
};

// ***************************************************************