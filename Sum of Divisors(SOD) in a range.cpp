#include <bits/stdc++.h>
using namespace std;
const int maxi = 20000009;
long long  divisors[maxi];


inline void sum_of_divisors() {
    int lim = 20000009;

    for(int i=1; i<=lim; i++) {
        for(int j=i; j<=lim; j += i) {
            divisors[j] += i;
        }
    }

 }
int main()
{
    sum_of_divisors();
}
