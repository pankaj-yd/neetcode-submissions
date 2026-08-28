/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        
        vector<int> start, end;
        for(const auto &i : arr){
            start.emplace_back(i.start);
            end.emplace_back(i.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int ans = 0;
        int curr = 0;

        int i = 0, j = 0;
        while(i < n && j < n){
            if(start[i] < end[j]){
                curr++;
                i++;
            } else{
                curr--;
                j++;
            }
            ans = max(ans, curr);
        }

        return ans;
    }
};
