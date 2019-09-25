#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 7;
vector < pair <long long , long long> > factor[MAX];



void sieveOfEratothenese() {
    bool prime[MAX];
    memset(prime , true , sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for(int i = 2 ; i < MAX; i++) {
        if(prime[i]) {
            for(int j = i; j < MAX; j += i) {
                prime[j] = false;
                int cnt = 0 , p;

                int n = j;
                while(n % i == 0) {
                    cnt++;
                    n /= i;
                }

                factor[j].push_back(make_pair(i , cnt));
            }

        }
    }
}
long long numofDivisors(int n) {
    long long total = 1;
    for(int i = 0; i < factor[n].size() ; i++) {
        total *= factor[n][i].second + 1;
    }
    return total;
}

long long sumOfDivisors(int n) {
    int total = 1;
    for(int i = 0; i < factor[n].size() ; i++) {
        total *= ((pow(factor[n][i].first, factor[n][i].second + 1) - 1) / (factor[n][i].first - 1) );
    }
    return total;
}
double relativePrime(long long n) {
    double total = 1.0;
    for(int i = 0; i < factor[n].size() ; i++) {
        total *= ( 1 - (1.0 / factor[n][i].first) );
    }
    return total * n;
}

int main()
{

	sieveOfEratothenese();

	return 0;
}
