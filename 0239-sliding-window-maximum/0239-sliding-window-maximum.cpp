class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Deque to store indices of elements in the current window

        for (int i = 0; i < k; ++i) {
            // Remove elements from the back of the deque which are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);
        }

        for(int i=k; i<nums.size(); i++) {
            // The front of the deque is the index of the maximum element for the previous window
            result.push_back(nums[dq.front()]);

            // Remove elements from the back of the deque which are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Remove elements from the front of the deque which are out of the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Add the current element's index to the deque
            dq.push_back(i);
        }

        result.push_back(nums[dq.front()]); // Add the maximum for the last window
        return result;
    }
};