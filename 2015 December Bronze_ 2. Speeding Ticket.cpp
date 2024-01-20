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

int main() {

	setIO("speeding");
	int m, n;
	cin>>n>>m;
	vector<pair<int,int>> road;
	vector<pair<int,int>> bessie;
	for(int i=0;i<n;i++){
		int segment, speed;
		cin>>segment>>speed;
		road.push_back(make_pair(segment,speed));
	}

	for(int i=0;i<m;i++){
		int segment, speed;
		cin>>segment>>speed;
		bessie.push_back(make_pair(segment,speed));
	}

	int i=0,j=0;
	int len=0,cov=0;
	int overlimit=0;
	bool addl=true, addc=true;
	while(i<n&&j<m){
		overlimit=max(overlimit, bessie[j].second-road[i].second);
		len+=addl?road[i].first: 0;
		cov+=addc?bessie[j].first:0;
		// cout<< len/ <<" "<<cov<<"\n";
		if(cov<len){
			addl=false;
			addc=true;
			j++;
		}else if(cov==len){
			addc=true, addl=true;
			j++;i++;
		}else{
			addc=false;
			addl=true;
			i++;
		}
	}

	cout<<overlimit;


}
