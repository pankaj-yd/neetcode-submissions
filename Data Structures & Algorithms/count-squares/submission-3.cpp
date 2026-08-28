class CountSquares {
    
    vector<vector<int>> pts;
    unordered_map<long, int> freq;
public:
    CountSquares() {

    }

    long getKey(int x, int y) {
        return (static_cast<long>(x) << 32) | static_cast<long>(y);
    }
    
    void add(vector<int> pt) {
        pts.push_back(pt);
        freq[getKey(pt[0], pt[1])]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int count = 0;
        
        for(vector<int> pt : pts){
            if( abs(x - pt[0]) != abs(y - pt[1]) || x == pt[0] || y == pt[1])
                continue;
            
            count += freq[getKey(x, pt[1])] * freq[getKey(pt[0], y)];
        }


        return count;
    }
};
