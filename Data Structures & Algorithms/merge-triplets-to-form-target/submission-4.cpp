class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& arr, vector<int>& t) {
        // potential triplets <= target
        vector<int> ans(3, 0);
        for(vector<int> &ele : arr){
            bool valid = true;
            for(int i = 0; i < t.size(); i++){
                if(ele[i] > t[i]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                for(int i = 0; i < t.size(); i++){
                    ans[i] = max(ans[i], ele[i]);
                }
            }
        }

        for(int i = 0; i < t.size(); i++){
            if(ans[i] != t[i]){
                return false;
            }
        }   
        return true;
    }
};
