

class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        vector<int> freq(26, 0);
        for(char c : tasks){
            freq[c - 'A']++;
        }
        

        priority_queue<pair<int,int>, vector<pair<int,int>> > pq;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                pq.push({freq[i], 0});
            }
        }

        int count = 0;
        while( !pq.empty() ){
            cout << "_________________________" << endl;
            
            bool foundVal = false;
            vector<pair<int,int>> popped;
            while(!pq.empty() && !foundVal){
                cout << "pq size: " << pq.size() << endl;
                pair<int,int> v = pq.top();
                cout << v.first << " " << v.second << endl;
                pq.pop();
                if( count >= v.second ){
                    foundVal = true;
                    v.first--;
                    v.second += k + 1;
                    count++;
                }

                if(v.first > 0){
                    popped.push_back(v);
                }
            }

            if(!foundVal){
                count ++;
            }

            for(pair<int, int> p : popped){
                pq.push(p);
            }
            cout << count;
        }

        return count;
    }
};
