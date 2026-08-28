class Solution {
public:
    int trap(vector<int>& h){
        int n = h.size();

        int total = 0;

        int l = 0, r = 1;
        int startH = h[0];
        
        while(r < n-1){
            // cout << r << " Adding: " << max(0, (startH - h[r])) << endl;
            total += max(0, (startH - h[r]));

            if(h[r] >= startH){
                startH = h[r];
                l = r;
            }
            r++;
        }

        int rmax = h[n-1];
        r = n-2;
        while(rmax < startH && r > l){
            // cout << r << " removing: " << (startH - h[r]) << endl;
            total -= (startH - h[r]);

            // cout << r << " adding: " << (0, rmax - h[r]) << endl;
            total += max(0, rmax - h[r]);

            if(rmax < h[r]){
                rmax = h[r];
            }
            r--;
        }

        return total;
    }
};
