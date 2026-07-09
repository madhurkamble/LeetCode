class Solution {
public:

    int gcd(int a, int b) {
        while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
        }
        return a;
    }
    bool isGoodArray(vector<int>& nums) {
       int ans=nums[0];
       for(int i=0;i<nums.size();i++){
            ans=gcd(ans,nums[i]);
        } 
       return ans==1;
    }
};