//  Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = nums.size();
        int majority = nums[0];
        int count = 1;
        
        for(int i=1;i<n;++i)
        {
            if(nums[i]==majority)
                count += 1;
            else
            {
                count -= 1;
                if(count==0)
                {
                    majority = nums[i];
                    count = 1;
                }
            }
        }
        return majority;
    }
};

// Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        //For fast I/O in C++
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        if(n==0)
            return 0;
        
        unordered_map<int,int> mymap;   //Key = PrefixSUM, Value = Count of PrefixSUM.
        int currSUM = 0;
        int i = 0;
        int count = 0;
        
        while(i<n)
        {
            currSUM += nums[i];
            
            if(currSUM == k)    //We found a new subArray with SUM = k
                count += 1;
            
            if(mymap.find(currSUM-k)!=mymap.end())
                count += mymap[currSUM-k];
            
            mymap[currSUM] += 1;
            i += 1;
        }
        return count;
    }
};