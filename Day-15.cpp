// 1. Koko Eating Bananas

class Solution {
public:
    
    bool canEatAll(vector<int>& piles, int givenHour, int h) {
        int actualHour = 0;
        
        for(int &x : piles) {
            actualHour += x/givenHour;
            
            if(x%givenHour != 0)
                actualHour++;
            
        }
        
        return actualHour <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int l = 1, r = *max_element(begin(piles), end(piles));
        
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(canEatAll(piles, mid, h)) {
                r = mid;
            } else {
                l = mid+1;
            }
            
        }
        
        return l;
    }
};

// *********************************************************


// 2. Median of Two Sorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int> temp(m+n);
        int i = 0, j = 0, k = 0;
        
        while(i < m && j < n) {
            if(nums1[i] < nums2[j])
                temp[k++] = nums1[i++];
            else
                temp[k++] = nums2[j++];
        }
        
        while(i < m) temp[k++] = nums1[i++];
        while(j < n) temp[k++] = nums2[j++];
        
        int size = m+n;
        
        if(size%2 != 0)
            return temp[size/2];
        
        return (temp[size/2]+temp[(size/2)-1])/2.0;
        
    }
};
