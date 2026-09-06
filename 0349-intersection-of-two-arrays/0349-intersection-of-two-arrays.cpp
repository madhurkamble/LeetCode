class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> store;
        for(int num : nums1) {
            store.insert(num);
        }
        vector<int> ans;
        unordered_set<int> used;
        for(int num : nums2) {
            if(store.count(num) && !used.count(num)){
                ans.push_back(num);
                used.insert(num);
            }
        }
        return ans;
    }
};