// i. Sort Colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;
        
        for(int &num : nums) {
            if(num == 0)
                count_0++;
            else if(num == 1)
                count_1++;
            else
                count_2++;
        }
        
        for(int i = 0; i<n; i++) {
            if(count_0 > 0) {
                nums[i] = 0;
                count_0--;
            } else if(count_1 > 0) {
                nums[i] = 1;
                count_1--;
            } else if(count_2 > 0) {
                nums[i] = 2;
                count_2--;
            }
        }
    }
};

//T.C : O(n+n)
//S.C : O(1)

/* **************************************************************************** */

// ii. Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int i = n-1;
        for(; i>0; i--) {
            if(nums[i] > nums[i-1]) {
                break;
            }
        }
        if(i != 0) {
            int index = i;
            for(int j = n-1; j>=i; j--) {
                if(nums[j] > nums[i-1]) {
                    index = j;
                    break;
                }
            }
            swap(nums[i-1], nums[index]);
        }
        reverse(nums.begin()+i, nums.end());
    }
};