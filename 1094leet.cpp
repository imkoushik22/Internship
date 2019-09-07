class Solution {
public:
    bool carPooling(vector<vector<int>>& a, int capacity) {
        vector<tuple<int,int,int>> help;
        int n = a.size();
        for(int i = 0; i < n; ++i){
            help.push_back({a[i][1],1,a[i][0]});
            help.push_back({a[i][2],-1,a[i][0]});
        }
        
        sort(help.begin(),help.end(),[&](auto a, auto b){
            auto [x,y,z] = a;
            auto [x1,y1,z1] = b;
            return (x < x1 || (x == x1 && y < y1));
        });
        
        int res = 0;
        
        for(auto &x : help){
            auto [a,b,c] = x;
            if(b == 1) res += c;
            else res -= c;
            if(res > capacity) return false;
        }
        return true;
    }
};