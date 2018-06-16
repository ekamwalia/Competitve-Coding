#include<bits/stdc++.h>
using namespace std;

int main() {

	int n,m;
	cin>>n>>m;

	int a[n][m];

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}


	int dp[n][m];

	dp[0][0] = a[0][0];

	for(int i=1;i<m;i++) {
		dp[0][i] = a[0][i] + dp[0][i-1];
	}

	for(int i=1;i<n;i++) {
		dp[i][0] = a[i][0] + dp[i-1][0];
	}


	for(int i=1;i<n;i++) {
		for(int j=1;j<m;j++) 
			dp[i][j] = a[i][j] + min(dp[i-1][j], dp[i][j-1]);
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) 
			cout<<dp[i][j]<<"  ";
		cout<<"\n";
	}

	return 0;
}