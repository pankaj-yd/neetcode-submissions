class Solution {
private:
    bool check(vector<int>& gas, vector<int>& cost, int curr, int dest, int tank){
        if(tank < 0) return false;
        if(curr >= gas.size()) curr %= gas.size();
        if(curr == dest) return true;
        return check(gas, cost, curr+1, dest, tank + gas[curr] - cost[curr]);

    }

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for(int i = 0; i < n; i++){
            if(check(gas, cost, i+1, i, gas[i] - cost[i])){
                return i;
            }
        }

        return -1;
    }
};
