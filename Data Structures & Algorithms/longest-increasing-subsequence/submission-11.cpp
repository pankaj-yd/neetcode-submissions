class SegmentTree {
public:
    SegmentTree(int n){
        this->n = n;
        v.resize(4*n, 0);
    }

    void build(){
        // no need
    }

    void update(int i, int val){
        // cout << "updating " << i << " with" << val << endl;
        pointUpdate(0, 0, n-1, i, val);
    }

    int query(int l, int r){
        // cout << "quering for: " << l << " " << r << endl;
        return query(0, 0, n-1, l, r);
    }

    void print(){
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int m = q.size();
            for(int i = 0; i < m; i++){
                int j = q.front();
                q.pop();
                cout << v[j] << " ";
                if (j*2 + 1 < 4*n){
                    q.push(j*2 + 1);
                }
                if (j*2 + 2 < 4*n){
                    q.push(j*2 + 2);
                }
            }
            cout << endl;
        }
        cout << endl;
    }
 
private:
    int n;
    vector<int> v;
    void pointUpdate(int treeIdx, int left, int right, int ansIdx, int val){
        // cout << treeIdx << " " << left << " " << right << " " << ansIdx << " " << val << endl;
        if(left == right){
            v[treeIdx] = val;
            return;
        }

        int mid = (left + right)>>1;
        if(ansIdx <= mid){
            pointUpdate(treeIdx*2 + 1, left, mid, ansIdx, val);
        } else {
            pointUpdate(treeIdx*2 + 2, mid+1, right, ansIdx, val);
        }

        v[treeIdx] = max(v[treeIdx*2 + 1], v[treeIdx*2 + 2]);
    }

    int query(int idx, int left, int right, int l, int r){
        // do not overlap
        if(right < l || r < left){
            return 0;
        }
        // cout << idx << " " << left << " " << right << " " << l << " " << r << endl;
        // current tree range lies inside ans range
        if(l <= left && right <= r){
            return v[idx];
        }

        // partial overlap
        // go both sides and return the value
        int mid = (left + right)>>1;

        return max(query( (idx<<1) + 1, left, mid, l, r), query( (idx<<1) + 2, mid + 1, right, l, r));
    }
    
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> valIdx;
        for(int i = 0; i < n; i++){
            valIdx.push_back({nums[i], i});
        }

        sort(valIdx.begin(), valIdx.end());

        unordered_map<int, int> idxMap;
        for(int i = 0; i < n; i++){
            idxMap[valIdx[i].second] = i;
        }

        SegmentTree s(n);

        for(int i = 0; i < n; i++){
            int lb = lower_bound(valIdx.begin(), valIdx.end(), make_pair(nums[i], -1)) - valIdx.begin();

            // cout << "lb "<< lb << endl;
            int val = 1 + (lb > 0? s.query(0, lb-1) : 0);

            int sortedIdx = idxMap[i];
            s.update(sortedIdx, val);
        }

        return s.query(0, n-1);
    }
};