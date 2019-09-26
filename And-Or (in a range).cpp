#include <bits/stdc++.h>
using namespace std;
#define READ(f)         freopen(f, "r", stdin)
#define WRITE(f)        freopen(f, "w", stdout)

#define __              std::ios_base::sync_with_stdio(false); cin.tie(0);
#define ___             cerr << endl << "Execution Time : " << 1 * clock() / CLOCKS_PER_SEC << endl;
#define START           double start_s=clock();
#define STOP            double stop_s=clock();
#define _               cerr << "Time Elapsed : " << (stop_s-start_s)/double(CLOCKS_PER_SEC);

#define mem(x,y)        memset(x,y,sizeof(x))
#define DEBUG(x)        cout << #x << " = " << x << endl

#define TC(T)           int T;cin>>T;while(T--)
#define FTC(T)          int T;cin>>T;for(int TestCase=1;TestCase<=T;TestCase++)
#define CASE_OUT()      cout << "Case " << TestCase << ": ";

#define ERR             1e-9
#define pi              (2*acos(0))
#define PI              3.141592653589793
#define MOD             1000000009
#define el              cout << endl
#define bor             |
#define infinity        1e10

typedef long double LD;
typedef unsigned int UI;
typedef long long int LL;
typedef unsigned long long int ULL;
#define SS              stringstream
#define vi              vector<int>
#define vii             vector< vi >
#define pb              push_back

vi prime,primeFactor;bool flg=true;
bool flag = true;

/**                                     Prime Check        ----------------->     isPrime(n)                                                                           **/         template<typename T>inline bool isPrime(T n){if(n<=1)return false;if(n<=3)return true;if(n%2==0 bor n%3==0)return false;for(int i=5;i*i<=n;i+=6)if(n%i==0||n%(i+2)==0)return false;return true;}
/**                                     Sieve Method       ----------------->     sieve(n)                                                                             **/         template<typename T>inline void sieve(T N){int status[(N>>5)+2];memset(status,0,((N>>5)+2)<<2);for(int i=3;i*i<=N;i+=2)if(!(status[i>>5]&(1<<(i & 31))))for(int j=i*i;j<=N;j+=(i<<1))status[j>>5]|=(1<<(j&31));prime.pb(2);for(int i=3;i<=N;i+=2){if(!(status[i>>5]&(1<<(i&31))))prime.pb(i);if(!(N%i))flg=false;}}
/**                                     Factorization      ----------------->     factorization(n)                                                                     **/         template<typename T>inline void factorization(T N){if(flg){primeFactor.pb(N);return;}int Size=0;int sqrtN=int(sqrt(N));while(N>=1&&Size!=prime.size()&&prime[Size]<=sqrtN){while(N%prime[Size]==0){primeFactor.pb(prime[Size]);N/=prime[Size];}Size++;}if(N>1)primeFactor.pb(N);}
/**                                     GCD                ----------------->     gcd(a,b)                                                                             **/         template<typename T>inline T gcd(T a,T b){while(b)b ^= a ^= b ^= a %= b;return a;}
/**                                     LCM                ----------------->     lcm(a,b)                                                                             **/         template<typename T>inline T lcm(T a, T b){return (a / gcd(a,b)) * b;}
/**                                     Big Mod            ----------------->     bigMod(b,p,m)                                                                        **/         template<typename T>inline T mmul(T a, T b, T m) { T result = 0; a %= m; while (b) { if (b % 2) result = (result + a) % m; a = (a + a) % m; b /= 2; } return result; }template<typename T>inline T bigMod(T a, T b, T m) { T result = 1; a %= m; while (b) { if (b % 2) result = mmul(result, a, m); a = mmul(a, a, m); b /= 2; } return result; }
/**                                     Negative Mod       ----------------->     negMod(-a,b)                                                                         **/         template<typename T>inline T negMod(T n,T m){return (n%m+m)%m;}
/**                                     ((a * b) % m)      ----------------->     big(a,b,m)                                                                           **/         template<typename T>inline T bigMul(T a,T b,T m){if(b==0)return 0;T x=bigMul(a,b>>1,m);x=((x%m)+(x%m))%m;if(b&1)x=(x+(a%m))%m;return x;}
/**                                     String to integer  ----------------->     StoI(string s,int x(any integer))                                                    **/         template<typename T>inline T StoI(string s, T ret){SS ss(s);ss >> ret;return ret;}/// extract words or numbers from a line
/**                                     integer to string  ----------------->     ItoS(n)                                                                              **/         template<typename T>inline string ItoS(T n){SS ss;ss << n; return ss.str();}/// convert a number to string
/**                                     min. of 3 numbers  ----------------->     MIN3(x,y,z)                                                                          **/         template<typename T>inline T MIN3(T x,T y,T z){T Min=y^((x^y)& -(x<y));Min=z^((Min^z)& -(Min<z));return Min;}
/**                                     max. of 3 numbers  ----------------->     MAX3(x,y,z)                                                                          **/         template<typename T>inline T MAX3(T x,T y,T z){T Max=x^((x^y)& -(x<y));Max=Max^((Max^z)& -(Max<z));return Max;}
/**                                     Binary to Decimal  ----------------->     BtoD(x)                                                                              **/         template<typename T>inline T BtoI(T x){T two=1,intn=0;while(x){if(x%10)intn+=two;x/=10;two<<=1;}return intn;}
/**                                     Binary to Dec(ULL) ----------------->     BtoI(string s)                                                                       **/         inline ULL BtoD(string str){ULL intS=0,two=1;int len=str.length();for(int i=len-1;i>=0;i--){if(str.at(i)=='1')intS+=two;two<<=1;}return intS;}
/**                                     Binary to Dec(ULL) ----------------->     to_bin()                                                                             **/       inline string to_bin(long long x) { string ret = ""; while(x) { ret += (x%2) + '0'; x /= 2; } reverse(ret.begin(), ret.end()); return ret; }
/**                                     Binary to Dec(ULL) ----------------->     to_Int()                                                                             **/       inline long long to_Int(string x) { long long ret = 0, mul = 1; for(int i=x.size()-1; i>=0; i--) { if(x[i] == '1') ret += mul; mul *= 2; } return ret; }
/**                                     Dec to Binary(ULL) ----------------->     DtoB(n) [store it in a string]                                                       **/         inline string DtoB(ULL n) { int count = 0; string s = ""; for (int i = 31; i >= 0; i--) { int k = n >> i; if (k & 1) { count  = 1; s += '1'; } else { if(count  == 1) s += '0'; }} return s; }
/**                                     STL all elements   ----------------->     printStl(v)                                                                          **/         //template<typename T>inline void printStl(T &v){int sz=v.size()-1;int k=0;for(auto i=v.begin();i!=v.end();i++,k++){if(k==sz)cout<<*i<<E;else cout<<*i<<" ";}}
/**                                     intput 1 integer   ----------------->     in(x)                                                                                **/         template<typename T>inline void in(T &x){x=0;bool neg=false;register char c=getchar();while((c<48||c>57)&&c!=EOF&&c!='-')c=getchar();if(c=='-'){neg=true;c=getchar();}while(c>=48&&c<=57){x=(x<<3)+(x<<1)+c-48;c=getchar();}if(neg)x=~(x-1);}
/**                                     intput 2 integer   ----------------->     in2(x,y)                                                                             **/         template<typename T>inline T in2(T &a,T &b){in(a);in(b);}
/**                                     intput 3 integer   ----------------->     in3(x,y,z)                                                                           **/         template<typename T>inline T in3(T &a,T &b,T &c){in(a);in(b);in(c);}
/**                                     print  1 integer   ----------------->     out(x)                                                                               **/         template<typename T>inline void out(T x){char a[21];T i=1,j;if(x<0){putchar('-');x=~(x-1);}if(x==0)putchar('0');while(x){a[i++]=x%10+48;x/=10;}for(j=i-1;j>=1;j--)putchar(a[j]);}
/**                                     Remainder          ----------------->     Rem(string divident,LL divisor)                                                      **/         inline LL Rem(string q,LL r) { LL l = q.size(); LL remainder = 0; for(int i=0; i<l; i++) remainder = ((remainder*10) + (q.at(i)-'0') )% r; }
/**                                     Quotient           ----------------->     quotient(string divident,LL divisor)                                                 **/         inline LL quotient(string num,LL number) { long long l,x = 0,mod=0; l= num.size(); int print_done = 0; for(int i=0; i<l; i++) { mod=(mod*10+num.at(i)-'0'); if(mod<number && !print_done) continue; x = (x * 10) + (mod / number); print_done = 1; mod = mod % number; } return x; }
/**                                     Vowel              ----------------->     isVowel(char c)                                                                      **/         bool isVowel(char ch){ch=toupper(ch);return(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E');return false;}
/**                                     Consonant          ----------------->     isConsonant(char c)                                                                  **/         bool isConsonant(char ch){return(isalpha(ch) && !isVowel(ch));return false;}


long long bitOr(string a, string b) {
    string str = "";
    bool f = true;
    if(a.size() != b.size()) {
        int len = max(a.size(), b.size());
        for(int i = 1; i <= len; i++) str += '1';
        return to_Int(str);
    }

    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) f = false;
        if(f) str += a[i];
        else str += '1';
    }


    return to_Int(str);
}

long long bitAnd(string a, string b) {
    if(a.size() != b.size()) return 0;
    string str = "";
    bool f = true;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) f = false;
        if(f) str += a[i];
        else str += '0';
    }


    return to_Int(str);
}

int main() {

       long long A , B;
       cin >> A >> B;
       string strA = to_bin(A), strB = to_bin(B);
       cout << bitOr(strA, strB)<<" "<< bitAnd(strA, strB) << endl;
}
