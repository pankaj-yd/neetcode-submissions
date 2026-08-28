class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& arr, vector<int>& queries) {
        auto comp = [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        };

        sort(arr.begin(), arr.end(), comp);
        vector<int> qcopy = queries;
        sort(qcopy.begin(), qcopy.end());
        unordered_map<int, int> ans;
        
        
        auto comp2 = [](pair<int, int> &a, pair<int, int> &b){
            if(a.second - a.first == b.second - b.first) return a.second > b.second;
            return a.second - a.first > b.second - b.first;
            
        };

        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(comp2)> pq(comp2);
        int i = 0, j = 0;
        while(j < qcopy.size()){
            int query = qcopy[j];
            while(i < arr.size()){
                if((arr[i][0] <= query && query <= arr[i][1])){
                    // cout << "pushing: {" << arr[i][0] << "," << arr[i][1] << "}" << endl;
                    pq.push({arr[i][0], arr[i][1]});
                } else if(query < arr[i][0]){
                    break;
                }
                i++;
            }
            // remove smaller intervals
            while(!pq.empty() && pq.top().second < query) {
                // cout << "popping: {" << pq.top().first << "," << pq.top().second << "}" << endl;
                pq.pop();
            }
            int intSize = -1;
            // choose smallest interval
            if(!pq.empty()){
                // cout << "top: {" << pq.top().first << "," << pq.top().second << "}" << endl; 
                intSize = pq.top().second - pq.top().first + 1;
            }

            ans[query] = intSize;

            j++;
        }

        vector<int> res;
        for(int q : queries){
            res.push_back(ans[q]);
        }
        return res;
    }
};
