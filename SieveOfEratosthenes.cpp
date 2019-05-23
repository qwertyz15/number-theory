#include <bits/stdc++.h>
using namespace std;
#define MAX 1e5 + 7

vector <int> v;
void SieveOfEratosthenes() {
    bool prime[100007];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= MAX; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= MAX; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= MAX; p++) {
        if (prime[p]) {
            v.push_back(p);
        }
    }
}


int main()
{
    SieveOfEratosthenes();
    return 0;
}
