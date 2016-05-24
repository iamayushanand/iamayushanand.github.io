---
title: problem 300C on codeforces
layout: post
categories: cp exponentiation modularArithmetic
---

<i><b>problem:-</b></i>
Vitaly is a very weird man. He's got two favorite digits a and b. Vitaly calls a positive integer good, if the decimal representation of this integer only contains digits a and b. Vitaly calls a good number excellent, if the sum of its digits is a good number.

For example, let's say that Vitaly's favourite digits are 1 and 3, then number 12 isn't good and numbers 13 or 311 are. Also, number 111 is excellent and number 11 isn't.

Now Vitaly is wondering, how many excellent numbers of length exactly n are there. As this number can be rather large, he asks you to count the remainder after dividing it by 1000000007 (109 + 7).

A number's length is the number of digits in its decimal representation without leading zeroes.


<i><b>input:-</b></i>
The first line contains three integers: a, b, n (1 ≤ a < b ≤ 9, 1 ≤ n ≤ 10<sup>6</sup>).

<i><b>output:-</b></i>
Print a single integer — the answer to the problem modulo 1000000007 (10<sup>9</sup> + 7).

<i><b>My solution:-</b></i>

We have to make some observations about the problem first:-

1) any permutation of an excellent number is also an excellent number.
2) the excellent number consits of only 2 digits.
3) the sum of an good number is (# of a's)xa+(# of b's)xb

The 3 observations above are enough to come up with a good enough solution
use them as hints.I strongly suggest that users should first try to solve the problem
using those 3 problems.



[Spoiler alert: before continuing make sure you have at least tried to solve the problem.]




>! Suppose we knew how many digits of a and b we have in a good number then we can easily check weather the sum is also a good number(by using the formula inobservation 3).
>! if the sum is a good number then any all the distinct permutations of that number will also be an excellent number we can figure that out by C(n,# of a digts). However the problem is that we cannot generate C(n,k) by using pascal's triangle as that would be too inefficient so we can use modular inverse and fast exponentiation.
>! how?
>! well since MOD is a prime number we can use the fact that a<sup>-1</sup> = a<sup>MOD-2</sup> (the formula can be found [here](http://https://en.wikipedia.org/wiki/Modular_multiplicative_inverse "multiplicative inverse")).
>! now the formula for C(n,k) is fact(n)fact(n-k)<sup>-1</sup>fack(k)<sup>-1</sup>
>! now we can precompute factorials and use fast exponentiation to find the ans.

<b><i>My code:-</i></b>
{% highlight cpp %}
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
const int INF= 2147483647;

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define REP(i,a) for(int i=0;i<(a);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define pb(x) push_back(x)
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007
#define DEBUG(x) cout<<">>>> "<<x<<endl
 

ll C[1000001];
ll fact[1000001];
bool check(ll n,ll a, ll b){
	while(n!=0){
		if(n%10!=a && n%10!=b){
			return false;
		}
		n=n/10;
		
	}
	return true;
}

ll fast_pow(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
int main(){
	ios::sync_with_stdio(false);

	//int n;
	//int m;
	//
	//scanf("%d %d",&n,&m);
	//
	//int T;
	//scanf("%d %d",&T);	
	fact[1]=1;
	ll a,b;
	ll n;
	cin>>a>>b>>n;
	
	for(int i=2;i<=n;i++){
		fact[i]=(fact[i-1]*i)%MOD;
		fact[i]%=MOD;
	}

	for(int i=0;i<=n;i++){
		if(i==n || i==0){
			C[i]=1;
			continue;
		}
		C[i]=fact[n]*fast_pow(((fact[n-i]%MOD)*(fact[i]%MOD))%MOD,MOD-2,MOD);
	}	

//	cout<<<<endl;
	int ans=0;
	for(int x=0;x<=n;x++){
		if(check((x*a)+((n-x)*b),a,b)){
			ans+=C[x]%MOD;
//			cout<<C[x]<<" ";
			ans%=MOD;
		}
	}
	cout<<ans%MOD;
	return 0;
}
{% endhighlight %}  
