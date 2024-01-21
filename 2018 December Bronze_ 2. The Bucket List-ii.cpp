// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

bool comparator(vector<int>v1, vector<int>v2){
	return v1[0]<v2[0];
}

int main() {
	setIO("blist");
	int n;
	cin>>n;
	vector<vector<int>> cows(n, vector<int>(3));
	for(int i=0;i<n;i++){
		cin>>cows[i][0]>>cows[i][1]>>cows[i][2];
	}
	sort(cows.begin(),cows.end(), comparator);
	int l=cows[0][0], r=cows[0][1];
	int max_bucket=0;
	vector<int>bucket(1001,0);
	
	for(int i=0;i<n;i++){
		for(int j=cows[i][0];j<=cows[i][1];j++){
			bucket[j]+=cows[i][2];
		}
	}
	for(int i=0;i<1001;i++){
		max_bucket=max(max_bucket,bucket[i]);
	}

	cout<<max_bucket;
}
