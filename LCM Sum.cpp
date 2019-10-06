/** In this program , we pre-calculate the  LCM Sum

    LCM Sum =  n/2 * (Σ(Φ(d) * d) + 1)

**/

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000007
long long phi[MAX + 7], result[MAX + 7];
long long answer[MAX + 7] = {0};

void computeTotient()
{
    phi[1] = 1;
    for (int i=2; i<MAX; i++)
    {
        if (!phi[i])
        {
            phi[i] = i-1;
            for (int j = (i<<1); j<MAX; j+=i)
            {
                if (!phi[j])
                    phi[j] = j;

                phi[j] = (phi[j]/i)*(i-1);
            }
        }
    }
}

void Divisors_x_phi()
{
   for(int i = 1; i <= MAX; i++) {
    for (int j = i; j <= MAX; j += i) {
         answer[j] += (phi[i] * i);

        }
    }
}

int main()
{
    computeTotient();
    Divisors_x_phi();
    int t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;
        cout << (answer[n] + 1) * n / 2 << endl;

    }
}
