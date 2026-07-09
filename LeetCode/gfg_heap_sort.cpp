// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
    // Function to sort an array using Heap Sort.
    
    void heapify(vector<int>& arr,int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n&&arr[largest]<arr[left]){
            largest=left;
        }
        if(right<n&&arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
        else return;
        
    }
    void heapSort(vector<int>& arr) {
        // code here
        int n=arr.size();
    // step-1  make heap first
     for(int i=(n/2)-1;i>=0;i--){
         heapify(arr,n,i);
     }
     
    //  step 2 heap sort
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);  //always swap with top element means arr[0] then call heapify from 0 idex always
        // and i in the place of n because maintain max heap order from i position to down
        
        
    }
     
    }
};