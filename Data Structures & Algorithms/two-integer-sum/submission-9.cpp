/* -19, -18, -10, -1
4
i = 0, j = 4
m = 2

i = 2, j = 4
m = 3

i = 3, j = 4
m = 3

*/
bool comp(pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
}

int binarySearch(vector<pair<int,int>> a, int num, int start) {
    int i = start;
    int j = a.size() - 1;
    
    while (i <= j){
        int mid = i + (j-i)/2;
        if (a[mid].first == num){
            return mid;
        }
        if(a[mid].first < num){
            i = mid + 1;
        }
        if(a[mid].first > num){
            j = mid - 1;
        }

    }
    return -1;
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> numsIndex;
        for (int i = 0; i < nums.size(); i++){
            numsIndex.push_back({nums[i], i});
        }
        sort(numsIndex.begin(), numsIndex.end(), comp);
        for(int i = 0; i < nums.size(); i++){
            pair<int,int> p = numsIndex[i];
            int otherIndex = binarySearch(numsIndex, target - p.first, i + 1);
            if(otherIndex != -1) {
                vector<int> ans;
                ans.push_back(p.second);
                ans.push_back(numsIndex[otherIndex].second);
                sort(ans.begin(), ans.end());
                return ans;
            }
        }
    }
};
