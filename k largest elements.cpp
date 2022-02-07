//firstly we need to implement the code of heap sort
// after heapifying hte array we can extract the first element and then again heapify the array

class Solution{
public:	

void heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    
    if(r<n&& arr[r]>arr[largest]){
        largest=r;
    }
    
    if(largest!=i){
        swap(arr[largest],arr[i]);
        
        heapify(arr,n,largest);
    }
}
	vector<int> kLargest(int arr[], int n, int k) {
	    vector<int> ans;
	    for(int i=n/2-1;i>=0;i--){
	        heapify(arr,n,i);
	    }
	    
	    int j=n-1;
	    while(k>0 && j>=0){
	        ans.push_back(arr[0]);
	        swap(arr[0],arr[j]);
	        heapify(arr,j,0);
	        j--;
	        k--;
	    }
	    
	    return ans;
	}

};