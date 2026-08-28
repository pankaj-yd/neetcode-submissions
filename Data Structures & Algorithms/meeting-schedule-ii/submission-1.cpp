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
        auto comp = [](Interval &a, Interval &b){
            return a.start < b.start;
        };
        sort(arr.begin(), arr.end(), comp);
        int days = 0;
        while(arr.size() > 0){

            vector<Interval> remaining;
            int start = arr[0].start;
            int end = arr[0].end;
            int currIdx = 0;
            // cout << "{" << start << "," << end << "}, ";
            for(int i = 1; i < arr.size(); i++){
                // cout << "{" << arr[i].start << "," << arr[i].end << "}, ";
                if(arr[currIdx].end > arr[i].start){
                    remaining.push_back(arr[i]);
                } else {
                    currIdx = i;
                }
            }
            days++;
            arr = remaining;
            // cout << endl;
        }
        return days;
    }
};
