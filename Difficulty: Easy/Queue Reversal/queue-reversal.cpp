class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int> s;
        
        while(!q.empty()){
            int data = q.front();
            s.push(data);
            q.pop();
        }
        
        while( !s.empty()){
            int data = s.top();
            q.push(data);
            s.pop();
        }
        
        
    }
};