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
        auto comp1 = [](Interval &a, Interval &b){
            return a.end > b.end;
        };

        sort(arr.begin(), arr.end(), comp);

        int ans = 0;

        priority_queue<Interval, vector<Interval>, decltype(comp1) > pq(comp1);

        for(Interval i : arr){
            cout << i.start << " " << i.end << endl;
            while(!pq.empty() && pq.top().end <= i.start){
                pq.pop();
            }
            pq.push(i);
            // cout << pq.size() << endl;
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};
