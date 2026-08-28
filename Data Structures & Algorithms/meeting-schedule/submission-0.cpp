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
    bool canAttendMeetings(vector<Interval>& arr) {
        int n = arr.size();
        if(n == 0) return true;
        auto comp = [](Interval &a, Interval &b){
            return a.start < b.start;
        };
        sort(arr.begin(), arr.end(), comp);

        int end = arr[0].end;
        for(int i = 1; i < n; i++){
            if(end > arr[i].start){
                return false;
            }
            end = arr[i].end;
        }
        return true;
    }
};
