---
layout: default
title: Dynamic Programming 13C codeforces
categories: cp dp
---

For the next couple of weeks I will be mainly focusing on improving my dynamic programming skills so today
I was trying to solve 13C on codeforces.

<b><i>problem:-</i></b>

Little Petya likes to play very much. And most of all he likes to play the following game:

He is given a sequence of N integer numbers. At each step it is allowed to increase the value of any number by 1 or to decrease it by 1. The goal of the game is to make the sequence non-decreasing with the smallest number of steps. Petya is not good at math, so he asks for your help.

The sequence a is called non-decreasing if a1 ≤ a2 ≤ ... ≤ aN holds, where N is the length of the sequence.

<b><i>Input:-</i></b>

The first line of the input contains single integer N (1 ≤ N ≤ 5000) — the length of the initial sequence. The following N lines contain one integer each — elements of the sequence. These numbers do not exceed 109 by absolute value.

<b><i>Output:-</i></b>

Output one integer — minimum number of steps required to achieve the goal.

<b><i>My approach:-</i></b>

We need to make an observation first.

1) The element at nth position in the final array formed by the minimal number of moves is at most the maximum number in the initial array.

let's say an array b is a clone of a with the only diffrence that it is sorted and f(i,j) is the minimal number of moves required to make the first i numbers in the initial array non-decreasing with each of them at most b<sub>j</sub>.

base case: it is obvious that f(1,1)= |a<sub>1</sub>-b<sub>1</sub>|
when i=1: f(1,j)= min(f(1,j-1),|a<sub>j</sub>-b<sub>j</sub>|
when j=1: f(i,1)= |a<sub>i</sub>-b<sub>1</sub>|+f(i-1,1)
when i,j>1:f(i,j)= min(f(i,j-1),f(i-1,j)+|a<sub>i</sub>-b<sub>j</sub>|

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
 

ll dp[5000];
ll b[5000];
ll a[5000];
int main(){
	ios::sync_with_stdio(false);

	//int n;
	//int m;
	//
	//scanf("%d %d",&n,&m);
	//
	//int T;
	//scanf("%d %d",&T);
//	memset(dp, 0, sizeof dp);
//	memset(b, 0, sizeof b);
//	memset(a, 0, sizeof a);
	int n;
	cin>>n;
	REP(i,n){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	dp[0]=abs(a[0]-b[0]);
	for(int i=1;i<n;i++){
		dp[i]=MIN(abs(a[0]-b[i]),dp[i-1]);
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==0){
				dp[j]=((ll)abs(a[i]-b[1]))+(ll)(dp[1]);
			}else{
				dp[j]=((ll)MIN(dp[j-1],(ll)(dp[j])+(ll)(abs(a[i]-b[j]))));
			}
		}
	}
	cout<<dp[n-1];
	return 0;
}
{% endhighlight %}

