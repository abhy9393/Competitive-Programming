class maxHeap {
private:
    vector<int> arr;
    int len;

public:
   maxHeap(){
       arr.push_back(-1);
       len=0;
   }

    void push(int x) {
      arr.push_back(x);
      len++;
      int idx=len;
      while(idx>1){
      int parent=idx/2;
          if(arr[parent]<arr[idx]){
              swap(arr[parent],arr[idx]);
              idx=parent;
          }
          else{
              break;
          }
      }
      
    }

    void pop() {
        swap(arr[1],arr[len]);
    arr.pop_back();
    len--;
    
    int i=1;
    while(i<len){
        int leftidx=2*i;
        int rightidx=2*i+1;
        int largest=i;
        if(leftidx<=len&&arr[largest]<arr[leftidx]){

            largest=leftidx;
        }
         if(rightidx<=len&&arr[largest]<arr[rightidx]){
              
                largest=rightidx;
        }
        if(largest==i) break;
        swap(arr[largest],arr[i]);
        i=largest;
    }
    }

    int peek() {
       if(len==0) return -1;
       return arr[1];
    }

    int size() {
        return len;
    }
};