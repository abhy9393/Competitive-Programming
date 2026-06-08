
/*
CF Round 1102 Div2
Problem B - Palindrome, Twelve and Two Terms

Observation:
a ≡ n (mod 12)

r=0..9 -> a=r
r=10 -> a=22  if r=10 then chek that number greater than 22 because 22mod12=10 where we write 22 as palindrome and 0 as 12 divissior
r=11 -> a=11
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        long long r = n % 12;

        if(r <= 9){
            cout << r << " " << n - r << "\n";
        }
        else if(r == 10){
            if(n >= 22)
                cout << 22 << " " << n - 22 << "\n";
            else
                cout << -1 << "\n";
        }
        else{ // r == 11
            if(n >= 11)
                cout << 11 << " " << n - 11 << "\n";
            else
                cout << -1 << "\n";
        }
    }

    return 0;
}