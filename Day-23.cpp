// i. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int i = 0, j = 1;
        
        while(j < n) {
            if(nums[i] != nums[j]) nums[++i] = nums[j];
            j++;
        }
        
        return i+1;
    }
};

//T.C : O(n)
//S.C : O(1)


// ***********************************************************

// ii. Remove Element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> :: iterator it;
        it = nums.begin();
        for(int i=0;i<nums.size();i++){
            if(nums[i] == val){
                nums.erase(it);
                it--;
                i--;
            }
            it++;
        }
        return nums.size();
    }
};

// ***********************************************************

// iii. Partition Array According to Given Pivot

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;

        // Partition the array into three groups: less than, equal to, and greater than the pivot.
        for (int num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } else if (num == pivot) {
                equal.push_back(num);
            } else {
                greater.push_back(num);
            }
        }

        // Combine the three groups to form the result.
        vector<int> result;
        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }
};
