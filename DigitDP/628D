#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long  m,d,dp[2005][2005][5];
string a,b;
vector <long long > digits;
long long  DP (long long  id,long long  mod,long long  tight){
    if (id == -1){
        if (mod == 0) return 1;
        return 0;
    }
    if (dp[id][mod][tight] > -1 && tight == 0){
        return dp[id][mod][tight];
    }
    long long  zz = 9, res = 0;
    if (tight == 1) zz = digits[id];
    if ((digits.size() - id) % 2 == 0){
        if (digits[id] < d && tight == 1){
            return 0;
        }
        long long  newTight = 0;
        if (d == digits[id]) newTight = tight;
        res += DP(id - 1,(mod*10 + d) % m,newTight);
        if (res >= MOD) res -= MOD;
    }
    else {
        for (long long  i = 0; i <= zz; i++){
            if (i == d) continue;
            long long  newTight = 0;
            if (i == digits[id]) newTight = tight;
            res += DP(id - 1,(mod*10 + i) % m,newTight);
            if (res >= MOD) res -= MOD;
        }
    }
    if (tight == 0) dp[id][mod][tight] = res;
    return res;
}
main(){
    freopen ("inp","r",stdin);
    freopen ("out","w",stdout);
    cin >> m >> d;
    cin >> a >> b;
    memset (dp,-1,sizeof(dp));
    long long  check = 1,checkmod = 0;
    for (long long  i = a.size()-1; i >= 0; i--){
        digits.push_back(a[i] - '0');
    }
    for (long long  i = 0;i < a.size(); i++){
        checkmod = (checkmod*10 + (a[i] - 48)) % m;
        if(i % 2 == 0 && a[i] - '0' == d) {
            check = 0;
            break;
        }
        if (i % 2 == 1 && a[i] - '0' != d){
            check = 0;
            break;
        }
    }
    long long  ans1 = 0,ans2 = 0;
    ans1 = DP(digits.size() - 1,0,1);
    digits.clear();
    for (long long  i = b.size()-1; i >= 0; i--){
        digits.push_back(b[i] - '0');
    }
    ans2 = DP (digits.size() - 1,0,1);
    cout << (ans2 - ans1 + ((check == 1) && (checkmod == 0)) + MOD) % MOD;
}
