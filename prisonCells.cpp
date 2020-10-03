class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        vector<int>res(8,0);
        int r,q,i;
        
        for(int i=1;i<7;i++)
            res[i] = cells[i];
        
        if(N==0)
            return cells;
        
        r=N%7;
        
        if(r)
        {
        
            while(r--)
            {
                for(i=1;i<7;i++)
                {
                    if(cells[i-1]==cells[i+1])
                        res[i]=1;
                    else
                        res[i]=0;
                }
                
                cells=res;
            }
            
            q=N/7;
            
            if(q%2!=0)
                reverse(res.begin(),res.end());
            
            return res;
                
        }
        
        else
        {
            r=7;
            while(r--)
            {
                for(i=1;i<7;i++)
                {
                    if(cells[i-1]==cells[i+1])
                        res[i]=1;
                    else
                        res[i]=0;
                }
                
                cells=res;
            }
            
            q=N/7;
            
            if(q%2==0)
                reverse(res.begin(),res.end());
            
            return res;
        }
        
    }
};