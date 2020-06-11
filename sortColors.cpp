class Solution {
public:
    void sortColors(vector<int>& a) {
      int i = 0 , j = a.size()-1;
      int curr =0 ;
        
      while(i<=j and curr<=j){
         if(a[curr] == 0 ){
             swap(a[curr] , a[i]);
             curr++ , i++;
         }else if(a[curr] == 2){
             swap(a[curr] , a[j]);
             j--;
         }else
             curr++;
      }
    
    }
};

