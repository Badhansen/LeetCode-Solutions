class Solution {
public:
    int binary(vector<int>& nums, int low, int high, int target){
        while(low<=high){
            
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            } 
        }
        return -1;
    }
    int pivot(vector<int>& nums, int lo, int hi){

        while(lo<hi){
            int mid=(lo+hi)/2;
            if(nums[mid]>nums[hi]) lo=mid+1;
            else if(nums[mid]<=nums[hi]) hi=mid;
        }
        return lo;
    }
    int search(vector<int>& nums, int target) {
        
        int index=pivot(nums,0,nums.size()-1);
        int first=binary(nums,0,index-1,target);
        int second=binary(nums,index,nums.size()-1,target);
    
        if(first!=-1){
            return first;
        }
        else
            return second;
    }
};