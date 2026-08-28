class CountSquares {
    unordered_map<int, set<pair<int,int>> > X;

    unordered_map<long, int> freq;
public:
    CountSquares() {

    }

    long getKey(int x, int y) {
        return (static_cast<long>(x) << 32) | static_cast<long>(y);
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        X[x].insert({x, y});

        freq[getKey(x, y)]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int count = 0;
        pair<int, int> p1 = {x, y};
        for(pair<int,int> p2 : X[x]){
            int len = abs(p2.second - y);
            if(len == 0){
                long nos = freq[getKey(x, y)];
                if(nos < 4){
                    continue;
                }
                count +=  (int) (nos * (nos - 1) * (nos - 2)) / 6;
                continue;
            }

            int fp2 = freq[getKey(p2.first, p2.second)];

            pair<int, int> p3 = { p1.first + len, p2.second};
            pair<int, int> p4 = { p1.first + len, p1.second};

            if(X[p3.first].find(p3) != X[p3.first].end() && X[p3.first].find(p4) != X[p3.first].end() ){
                int fp3 = freq[getKey(p3.first, p3.second)];
                int fp4 = freq[getKey(p4.first, p4.second)];
                count += fp2 * fp3 * fp4;
            }

            p3 = { p1.first - len, p2.second};
            p4 = { p1.first - len, p1.second};
            if(X[p3.first].find(p3) != X[p3.first].end() && X[p3.first].find(p4) != X[p3.first].end() ){
                int fp3 = freq[getKey(p3.first, p3.second)];
                int fp4 = freq[getKey(p4.first, p4.second)];
                count += fp2 * fp3 * fp4;
                
            }
        }
        return count;
    }
};
