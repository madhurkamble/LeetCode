class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = 0;
        int maxIndex = 0;
        int n=nums.size();

        for(int i = 1; i < n; i++){

            if(nums[i] < nums[minIndex]){
                minIndex = i;
            }

            if(nums[i] > nums[maxIndex]){
                maxIndex = i;
            }
        }

        if(minIndex > maxIndex){
            swap(minIndex, maxIndex);
        }
        
        int fromFront = maxIndex + 1;
        int fromBack = n - minIndex;
        int bothSides = (minIndex + 1) + (n - maxIndex);
        return min({fromFront, fromBack, bothSides});
    }
};