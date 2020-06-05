class Solution {
public:
    double sum =0;
    vector<int> v;
    Solution(vector<int>& w) {
        srand((unsigned)time(0));
        for(auto i : w){
            sum += i;
            v.push_back(sum);
        }
    }
    
    int pickIndex() {
        double x = (double) rand() / RAND_MAX;
        double target = x * sum;
        int l = 0 , h = v.size()-1;
        
        while(l <= h){
            int mid = l + (h-l)/2;
            if(target  == v[mid])
                return mid;
            if(target > v[mid])
                l = mid+1;
            else
                h = mid-1; 
        }
        
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */