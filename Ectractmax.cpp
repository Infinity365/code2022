#include<bits/stdc++.h>
using namespace std;
void heapify(int ar[],int i,int n){
  int largest=i;
  int left=2*i+1;
  int right=2*i+2;
  if(left<n && ar[largest]<ar[left])
    largest=left;
  if(right<n && ar[largest]<ar[right])
    largest= right;
  if(largest !=i){
    swap(ar[largest],ar[i]);
    heapify(ar,largest,n);
  }
}
void heapSort(int ar[],int n){
  for(int i=n/2-1;i>=0;i--){
    heapify(ar,i,n);
  }

  for(int i=0;i<n;i++){
    cout<<ar[i]<<" ";

    
  }
  cout<<endl;
}
void extractMax(int ar[],int n){
  
  for(int i=n-1;i>=0;i--){
    cout<<ar[0]<<" ";
    swap(ar[0],ar[i]);
    heapify(ar,0,i);
  }
}
int main(){
  int n;
  cin>>n;
  int ar[n];
  for(int i=0;i<n;i++){
    cin>>ar[i];
  }
  heapSort(ar,n);
  extractMax(ar,n);
}