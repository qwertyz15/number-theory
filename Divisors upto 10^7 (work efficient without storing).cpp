#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
vector <int> d[MAX];
int arr[MAX] = {0};


void Divisors()
{
   for(int i = 1; i <= MAX; i++) {
    for (int j = i; j <= MAX; j += i) {
         arr[j]++;
         if(arr[j] == 1) d[j].push_back(1);
         d[j].push_back(i);
        }
    }
}

int main()
{
    Divisors();
    for(int i = 0 ; i < 30; i++) {
            cout << "divisors of " << i << "\n";
        for(int j = 1; j < d[i].size() ; j++) {
            cout << d[i][j] << " ";
        }
    cout << endl;
    }
}
