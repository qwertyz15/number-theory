
#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void sieve()
{
    const int RT = 1e7 + 3;

    bitset<RT> status;
    int rt = sqrt(RT);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < RT; j+=(i<<1))
                status[j] = true;

    primes.push_back(2);

    for(int i = 3; i < RT; i+=2)
        if(!status[i])
            primes.push_back(i);
}


int main()
{
    sieve();
    return 0;
}
