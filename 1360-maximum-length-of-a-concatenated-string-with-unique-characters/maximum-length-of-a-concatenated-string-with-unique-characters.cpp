class Solution {
public:
    bool canAdd(string s1, string s2){
        unordered_set<char> st(s1.begin(), s1.end());
        for(auto it : s2){
            if(st.find(it) != st.end()) return false;
            st.insert(it);
        }
        return true;
    }

    int helper(vector<string>& arr, int index, string& temp){
        if(index < 0) return temp.size();  

        int take = 0, notTake = 0;

        // take case
        if(canAdd(temp, arr[index])){
            temp += arr[index];  
            take = helper(arr, index - 1, temp);
            temp.erase(temp.size() - arr[index].size());  
        }

        // not take case
        notTake = helper(arr, index - 1, temp);

        return max(take, notTake);  
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        return helper(arr, n - 1, temp);
    }
};
