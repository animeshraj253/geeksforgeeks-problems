class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        
        int n = q.size();
        if( k > n){
            return q;
        }
        vector<int> data;
        stack<int> rev;
        
        while ( k != 0){
            rev.push(q.front());
            q.pop();
            k--;
        }
        
        while( !q.empty() ){
            data.push_back(q.front() );
            q.pop();
        }
        
        while( !rev.empty() ){
            q.push(rev.top());
            rev.pop();
        }
        
        for ( int i : data){
            q.push(i);
        }
        
        
        
       
        
        
        return q;
    }
};