class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) { 

        vector<int> ans;
        int n = arr.size();
        
        deque<int> de;
            
        
        int l = 0;
        int r = 0 ;
        
        while( r < n){
            if( arr[r] < 0 ){
                de.push_back(arr[r]);
            }
            
            if( r - l + 1 == k){
                if(!de.empty()){
                    ans.push_back(de.front());
                }else{
                    ans.push_back(0);
                }
                
                if( !de.empty() && arr[l] == de.front()){
                    de.pop_front();
                }
                
                l++;
            }
            r++;
            
            
        }
        
        return ans;        
        
    }
};