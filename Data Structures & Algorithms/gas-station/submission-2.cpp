class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int n = gas.size();
        vector<int> diff;
        for(int i = 0; i < n; i++){
            diff.push_back(gas[i] - cost[i]);
            // cout << cost[i] - gas[i] << " ";
        }
        int sum = 0;
        int start = 0;
        for(int i = 0; i < n; i++){
            sum += diff[i];
            if(sum < 0){
                sum = 0;
                start = i+1;
            }
        }

        sum = 0;
        for(int i = 0; i < n; i++){
            sum += diff[(start + i) % n];
            if(sum < 0){
                return -1;
            }
        }
        return start;
    }
};
