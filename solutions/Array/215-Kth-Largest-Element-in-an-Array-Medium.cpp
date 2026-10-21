class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> v;

        for(int i=0; i<nums.size(); i++){
            if(v.size() < k){
                v.push(nums[i]);
            }else if(nums[i] > v.top()){
                v.pop();
                v.push(nums[i]);
            }
        }

        return v.top();
    }
};