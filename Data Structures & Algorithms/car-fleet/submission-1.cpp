class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> ps(n);
        for(int i = 0; i < n; i++){
            ps[i] = {position[i], speed[i]};
        }

        sort(ps.begin(), ps.end());

        int groups = 1;
        int catchUpIdx = n-1;

        for(int i = n-2; i >= 0; i--){
            // can i catch up to next group
            int v1 = ps[catchUpIdx].second;
            int p1 = ps[catchUpIdx].first;
            int v2 = ps[i].second;
            int p2 = ps[i].first;
            if( v1 * (p1 - p2) > (v2 - v1) * (target - p1) ){
                catchUpIdx = i;
                groups++;
            }
        }
        return groups;
    }
};
