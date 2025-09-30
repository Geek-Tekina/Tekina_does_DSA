class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> temp = nums;
        vector<int> ans;
        int n = nums.size();
        while(n--){
            ans.clear();  
            for(int i = 0; i < temp.size() - 1; ++i){
                ans.push_back((temp[i] + temp[i+1] )%10);
            }
            temp = ans;
        }
        return ans[0];
    }
};
