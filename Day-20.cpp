// i. Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& list1, int len1, vector<int>& list2, int len2) {
        int idx1 = len1 - 1, idx2 = len2 - 1, mergeIdx = len1 + len2 - 1;
        while (idx1 >= 0 && idx2 >= 0) {
            if (list1[idx1] > list2[idx2]) {
                list1[mergeIdx] = list1[idx1];
                idx1--;
                mergeIdx--;
            } else {
                list1[mergeIdx] = list2[idx2];
                idx2--;
                mergeIdx--;
            }
        }
        while (idx1 >= 0)
            list1[mergeIdx--] = list1[idx1--];
        while (idx2 >= 0)
            list1[mergeIdx--] = list2[idx2--];
    }
};


// *************************************************************************


// ii. Merge Two 2D Arrays by Summing Values

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        int i=0,j=0;
        while(i < n && j < m){
            if(nums1[i][0]==nums2[j][0]){
                ans.push_back({nums1[i][0],nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else if(nums1[i][0]<nums2[j][0]){
                ans.push_back({nums1[i][0],nums1[i][1]});
                i++;
            }
            else {
                ans.push_back({nums2[j][0],nums2[j][1]});
                j++;
            }
        }
        while(i<n){
            ans.push_back({nums1[i][0],nums1[i][1]});
            i++;
        }
        while(j<m){
            ans.push_back({nums2[j][0],nums2[j][1]});
            j++;
        }
        return ans;
    }
};