class Solution {
public:
    int candy(vector<int>& ratings) {

        // optimal T.C=O(N) S.C=O(1)
      int n=ratings.size();
      int i=1;
      int sum=1;
      while(i<n){
        // if flat surface comming then add only 1 means equal element
        while(i<n&&ratings[i]==ratings[i-1]){
            sum+=1;
            i++;
        }

        // when increasing surface comming then always add previous value+1 and update peak til last increasing value
 int peak=1;
   while(i<n&&ratings[i-1]<ratings[i]){
     peak++;
     sum+=peak;
     i++;
   }

// when down slope comming then according only for sum we add from 1 to last and at last we compare peak and from down peak which is greater
int down=1;
while(i<n&&ratings[i-1]>ratings[i]){
    sum+=down;
    down++;
    i++;
}

// compare both peak jo bada hoga whi add mana jaega knuki wo dono side satisfy krega sum me add hum (down-peak ) agar down bada hua to knuki peak already add hi to agar down bada ho gya to jitna difference hoga whi add kr denge knuki down++ last wala wo add nhi kiya hu
if(down>peak){
    sum+=(down-peak);
}

      }
      return sum;
    }
};