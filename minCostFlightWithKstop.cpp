struct h{
            int u ,  k  ,  dist;
            
        };

 struct node{
            int u,w;
        };

 bool operator < ( const h &a , const h &b){
                if(a.dist == b.dist)
                    return a.k > b.k;
                return a.dist > b.dist;
            }

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
       
        
      
        vector<vector<node>> adj(n);
        node x ;
        
        for(int i =0;i<flights.size();i++){
            x.u = flights[i][1];
            x.w = flights[i][2];
            // cout<<flights[i][0]<<endl;
            adj[flights[i][0]].push_back(x);
        }
        h temp ;
        temp.u = src;
        temp.k = 0;
        temp.dist = 0;
        
        priority_queue<h> q;
        q.push(temp);
        // cout<<adj[src].size()<<endl;
        
        while(!q.empty()){
            auto t  = q.top();
            q.pop();
            // cout<<t.u<<" " <<t.dist<<endl;
            if(t.u == dst )
                return t.dist;

            for(auto i : adj[t.u]){
                temp.u = i.u;
                temp.k = t.k+1;
                // cout<<i.u<<" ";
                temp.dist = t.dist+i.w;
                if(t.k <= K)
                    q.push(temp);
            }
            
        }
        return  -1;
    }
};