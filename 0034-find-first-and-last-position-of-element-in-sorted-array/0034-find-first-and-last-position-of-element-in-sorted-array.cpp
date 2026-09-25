class Solution {
public:

    int FirstPos(vector<int>& nums, int target){
        int st=0;
        int end=nums.size()-1;
        int first=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                first=mid;
                end=mid-1;
            }

            else if(target<nums[mid]){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return first;
    }

    int LastPos(vector<int>& nums, int target){
        int st=0;
        int end=nums.size()-1;
        int last=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                last=mid;
                st=mid+1;
            }

            else if(target<nums[mid]){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=FirstPos(nums,target);
        int last=LastPos(nums,target);
        return{first,last};
    }
};