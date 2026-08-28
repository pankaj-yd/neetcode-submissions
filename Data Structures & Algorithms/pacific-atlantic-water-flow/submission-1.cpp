class Solution {
private:
    void dfs(vector<vector<int>>& h, unordered_set<int> &uset, int i, int j, int prevH){
        int rows = h.size(), cols = h[0].size();
        int cord = i * cols + j;
        if(i >= rows || j >= cols || i < 0 || j < 0 || uset.find(cord) != uset.end() || h[i][j] < prevH){
            return;
        }
        // cout << "adding: h[i][j]: " << h[i][j] << "   i: " << i << " ,j: " << j << endl;
        uset.insert(cord);
        dfs(h, uset, i + 1, j, h[i][j]);
        dfs(h, uset, i - 1, j, h[i][j]);
        dfs(h, uset, i, j + 1, h[i][j]);
        dfs(h, uset, i, j - 1, h[i][j]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int rows = h.size(), cols = h[0].size();
        // int = row_idx * cols + cols;
        unordered_set<int> pacific;
        cout << "Pacific" << endl;
        for(int i = 0; i < rows; i++){
            dfs(h, pacific, i, 0, INT_MIN);
        }
        for(int j = 0; j < cols; j++){
            dfs(h, pacific, 0, j, INT_MIN);
        }

        cout << "Atlantic" << endl;
        unordered_set<int> atlantic;
        for(int i = 0; i < rows; i++){
            dfs(h, atlantic, i, cols-1, INT_MIN);
        }
        for(int j = 0; j < cols; j++){
            dfs(h, atlantic, rows-1, j, INT_MIN);
        }
        


        vector<vector<int>> ans;
        for(int p : pacific){
            if(atlantic.find(p) != atlantic.end()){
                ans.push_back({p/cols, p%cols});
            }
        }

        return ans;
    }
};
