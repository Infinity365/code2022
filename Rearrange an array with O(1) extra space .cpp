//Very good problem 
//contain mathematical logic

// input arr=[4,0,2,1,3]
// output arr=[3,4,2,0,1]
// Explanation: 
// arr[arr[0]] = arr[4] = 3.
// arr[arr[1]] = arr[0] = 4.
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(1)

void arrang(long long arr[],int n){
    int x,y;
    for(int i=0;i<n;i++){
        x=arr[i];
        y=arr[x];
        arr[i]=x+(y%n)*n;
    }

    for(int i=0;i<n;i++){
        arr[i]=arr[i]/n;
    }
}