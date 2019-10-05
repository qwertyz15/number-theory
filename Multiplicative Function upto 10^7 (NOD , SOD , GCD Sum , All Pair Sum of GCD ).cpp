/** In this program , we pre-calculate the number of divisor(NOD), sum of divisors(SOD) ,
    GCD sum  and all pairs of GCD sum upto 10^7 via multiplicative function

    Suppose n = p1^a1 * p2^a2 * ....... * pn^ak

    NOD     =   Π (a + 1)
    SOD     =   Π [((p^(a + 1)) - 1) / (p - 1)]
    GCD Sum =   Π [((a + 1) * p^a) - (a * p^(a - 1))]
    All Pair GCD Sum = Σ (gcdSum(i) - i)
    
**/

#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000

long long bigPrime[MAX + 7];

long long NOD[MAX + 7];
long long SOD[MAX + 7];

long long gcdSum[MAX + 7];
long long DP[MAX + 7];

void multiplicative() {

    NOD[1] = 1;
    SOD[1] = 1;

    gcdSum[1] = 1;
    DP[1] = 0;


    memset(bigPrime, 0, sizeof bigPrime);

    int root = (int)sqrt(MAX);

    for (int i = 2; i <= MAX; ++i) {
        if (bigPrime[i] == 0) {
            bigPrime[i] = i;
            // Only for primes up to root of MAX
            if (i > root) continue;
                for (int j = i*i; j <= MAX; j += i) bigPrime[j] = i;
        }
    }

    for (int i = 2; i <= MAX; ++i) {
        int p = bigPrime[i];
        int a = 0;
        int pa = 1;
        int tmp = i;

        while (tmp % p == 0) {
            a = a+1;
            tmp /= p;
            pa *= p;
        }

        NOD[i] = (a + 1) * NOD[tmp];
        SOD[i] = (pa*p - 1) / (p - 1) * SOD[tmp];

        gcdSum[i] = (((a+1) * pa) - (a * (pa / p))) * gcdSum[tmp];
        DP[i] = DP[i-1] + gcdSum[i] - i;

    }
}

int main()
{
    multiplicative();

     for (int i = 1; i <= 30; ++i) {
        cout << "NOD[" << i << "] = " << NOD[i] << endl;
        cout << "SOD[" << i << "] = " << SOD[i] << endl;
        cout << "gcdSum[" << i << "] = " << gcdSum[i] << endl;
        cout << "DP[" << i << "] = " << DP[i] << endl << endl;;
    }
    return 0;
}

