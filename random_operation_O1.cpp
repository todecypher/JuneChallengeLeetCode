class RandomizedSet {
public:
    /** Initialize your data structure here. */
    
    unordered_map<int , int> mp;
    vector<int> v;
    RandomizedSet() {
        srand(time(0));
        v.clear();
       
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) !=mp.end())
            return false;
        v.push_back(val);
        mp[val] = v.size()-1;
        // for(auto i :  v)
        //     cout<<i<<" ";
        //  cout<<endl;
        return true;         
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) !=mp.end()){
            int last = v[v.size()-1];
            v[mp[val]] = last;
            v.pop_back();
             mp[last] = mp[val];
             mp.erase(val);
           
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
       
        int index = rand() % (int)v.size();
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */