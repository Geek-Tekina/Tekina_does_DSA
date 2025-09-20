class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = INT_MIN;
        int n = colors.size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(colors[i] != colors[j]){
                    ans = max(ans, abs(i-j));
                }
            }
        }
        return ans;
    }
};