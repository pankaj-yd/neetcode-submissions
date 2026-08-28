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
    int minMeetingRooms(vector<Interval>& arr){
        auto cmp = [&](Interval a, Interval b){
            return a.start < b.start;
        };
        sort(arr.begin(), arr.end(), cmp);

        auto cmp2 = [&](vector<int> a, vector<int> b){
            return a[1] > b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp2) > pq(cmp2);

        int days = 0;
        for(Interval i : arr){
            if(pq.empty()){
                pq.push({i.start, i.end, days++});
            } else {
                vector<int> top = pq.top();
                if(i.start >= top[1]){
                    pq.pop();
                    pq.push({i.start, i.end, top[2]});
                } else {
                    pq.push({i.start, i.end, days++});
                }
            }
        }


        return days;
    }
};
