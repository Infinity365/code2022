 bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n[1001]={0};
        for(vector<int> item: trips){
            n[item[1]]+=item[0];
            n[item[2]]-=item[0];
        }
        
        for(int i=0;i<=1000;i++){
            capacity=capacity-n[i];
if(capacity<0)
    return false;        
    }
        return true;
    }
};