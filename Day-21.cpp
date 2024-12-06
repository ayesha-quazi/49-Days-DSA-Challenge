// i. Sort Array By Parity: 

//Approach (Using simple iteration)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;
        
        for(int i = 0; i<nums.size(); i++) {
            
            if(nums[i]%2 == 0) {//even
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
        return nums;
    }
};

//T.C : O(n)


// ************************************************************

// ii. Sort Array By Parity II

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();

        while (i < n && j < n) {
            // Find the next even index with an odd number
            while (i < n && (nums[i] & 1) == 0) {
                i += 2;
            }
            // Find the next odd index with an even number
            while (j < n && (nums[j] & 1) == 1) {
                j += 2;
            }
            // If both indices are valid, swap the elements
            if (i < n && j < n) {
                swap(i, j, nums);
            }
        }
        return nums;
    }

private:
    void swap(int i, int j, vector<int>& nums) {
        if (nums[i] != nums[j]) {  // Only perform swap if the indices are different
            nums[i] = nums[i] ^ nums[j];  // Step 1: nums[i] holds the XOR of nums[i] and nums[j]
            nums[j] = nums[i] ^ nums[j];  // Step 2: nums[j] now holds the original value of nums[i]
            nums[i] = nums[i] ^ nums[j];  // Step 3: nums[i] now holds the original value of nums[j]
        }
    }
};

// ************************************************************

// iii. Rearrange Array Elements by Sign:

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pi = 0; //positive index
        int ni = 1; //negative index
        
        
        vector<int> result(n);
        
        for(int &num : nums) {
            if(num > 0) {
                result[pi] = num;
                pi +=2;
            } else {
                result[ni] = num;
                ni += 2;
            }
        }
        
        return result;   
    }
};