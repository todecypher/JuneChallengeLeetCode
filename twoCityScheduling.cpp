bool cmp(vector<int>& a, vector<int>& b){
    return (a[0]-a[1] < b[0]-b[1]);
}
class Solution {
public:
    int ans = INT_MAX;
        
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin() , costs.end() , cmp);
        
        int n = costs.size();
        n /=2 ;
        
        int total = 0;
        for(int i=0;i<n;i++){
            total += costs[i][0] + costs[i+n][1];
        }
        return total;
    }
};