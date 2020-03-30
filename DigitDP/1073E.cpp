#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
long long  a,b,k;
long long  bitCnt[(1 << 10) + 5],pw[20];
pair <long long ,long long > dp[20][2][(1 << 10) + 5];
vector <long long > digits;
long long  add (long long  a,long long  b){
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
    return a;
}
long long  mul (long long  a,long long  b){
    return (a * b) % MOD;
}
pair <long long ,long long > DP (long long  id,long long  tight,long long  mask,long long  f){
    if (bitCnt[mask] > k)
        return {0,0};
    if (id == -1)
        return {0,1};
    if (dp[id][tight][mask].first > -1 && tight == 0)
        return dp[id][tight][mask];
    long long  zz = 9;
    if (tight == 1) zz = digits[id];
    pair <long long ,long long > res;
    for (long long  i = 0; i <= zz; i++){
        long long  newTight = 0;
        if (i == digits[id]) newTight = tight;
        long long  newf = f;
        if (i > 0) newf = 1;
        long long  newMask = (mask | (1 << i));
        if (newf == 0) newMask = 0;
        pair <long long ,long long > after = DP (id-1,newTight,newMask,newf);
        res.first = add(res.first,add(mul(mul(i,pw[id]),after.second),after.first));
        res.second = add(res.second,after.second);
    }
    if (tight == 0) dp[id][tight][mask] = res;
    return res;
}
long long  calc (long long  n){
    digits.clear();
    while (n > 0){
        digits.push_back(n % 10);
        n /= 10;
    }
    if (digits.size()) return DP (digits.size()-1,1,0,0).first;
    return 0;
}
 main (){
     //freopen ("inp","r",stdin);
     //freopen ("out","w",stdout);
     cin >> a >> b >> k;
     memset (dp,-1,sizeof(dp));
     for (long long  i = 1; i < (1 << 10); i++){
        bitCnt[i] = bitCnt[i & (i-1)] + 1;
     }
     pw[0] = 1;
     for (long long  i = 1; i < 20; i++){
        pw[i] = mul(pw[i-1],10);
     }
     cout << add(calc(b),-calc(a-1));
 }
