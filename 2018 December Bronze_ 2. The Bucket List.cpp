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
	vector<pair<char,int>> cows(1001);
	for(int i=0;i<n;i++){
		int si,ti,bi;
		cin>>si>>ti>>bi;
		cows[si]=make_pair('s',bi);
		cows[ti]=make_pair('t',bi);
	}
	int max_bucket=0;
	int buckets=0;
	for(int i=0;i<1001;i++){
		if(cows[i].first){
			buckets+= cows[i].first=='s'?cows[i].second:-1*cows[i].second;
		}
		max_bucket=max(max_bucket,buckets);
	}
	

	cout<<max_bucket;
}
