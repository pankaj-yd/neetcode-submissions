class CountSquares {
private:
    set<pair<int,int>> points;
    unordered_map<int, int> freq;

    auto getKey(int x, int y){
        return (x << 14) | y;
    }
public:
    CountSquares() {

    }
    
    void add(vector<int> pt) {
        int key = getKey(pt[0], pt[1]);
        
        freq[key]++;
        points.insert({pt[0], pt[1]});
        
    }
    
    int count(vector<int> point) {
        int total = 0;
        for(pair<int, int> pt : points){
            if(pt.first == point[0] || pt.second == point[1] || ( abs(pt.first - point[0]) != abs(pt.second - point[1]) ) ){
                
                continue;
            }

            int key = getKey(pt.first, pt.second);
            int key1 = getKey(pt.first, point[1]);
            int key2 = getKey(point[0], pt.second);

            
            
            total += freq[key] * freq[key1] * freq[key2];
        }
        return total;
    }
};
