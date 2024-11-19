// First Missing Positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool contains_one = false;
        for(int x: nums){
            if(x == 1){
                contains_one = true;
                break;
            }
        }
        if(!contains_one) return 1;
        
        int n = nums.size();
        if(n == 1) return 2;
        
        for(int i = 0; i < n; ++i)
            if(nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        
        for(int i = 0; i < n; ++i){
            int x = abs(nums[i]);
            if(nums[x-1] > 0) nums[x-1] *= -1;
        }
        
        for(int i = 0; i < n; ++i)
            if(nums[i] > 0) return i+1;
        
        return n+1;
    }
};

// Count of Smaller Numbers After Self

class Solution {
public:
    
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right){
        vector<pair<int,int>> temp(right - left + 1);
        int i=left;
        int j=mid+1;
        int k=0;
        
        while(i<=mid && j<=right){
            
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            
            else{
                
                count[v[i].second] += right-j+1;
                temp[k++] = v[i++];
                
            }
            
        }
        
        
        while(i<=mid){
            temp[k++] = v[i++];
        }
        
        while(j<=right){
            temp[k++] = v[j++];
        }
        
        for(int i=left;i<=right;i++){
            v[i] = temp[i-left]; 
        }
        
    }
    
    void mergeSort(vector<int> &count, vector<pair<int,int>> &v, int left, int right){
        
        
        if(left<right){
            int mid = left + (right-left)/2;
            mergeSort(count, v, left, mid);
            mergeSort(count, v, mid+1, right);
            merge(count, v, left, mid, right);
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            v[i] = p;
        }
        
        
        vector<int> count(n, 0);
        mergeSort(count, v, 0, n-1);
        return count;
        
    }
};

