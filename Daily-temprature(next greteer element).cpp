class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        
        int n=temperatures.size();
        vector<int> ans(n,0);
        int prev_day;
        for(int i=0;i<n;i++){
            
            while(s.empty()==false && temperatures[s.top()]<temperatures[i]){
                prev_day=s.top();
                ans[prev_day]=i-s.top();
                s.pop();
            }
            
            s.push(i);
        }
        
       
         return ans;
        
    }
};