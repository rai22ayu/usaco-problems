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
	setIO("traffic");
	int n;
	cin>>n;
	vector<string> type(n);
	vector<int> mini(n);
	vector<int> maxi(n);
	for(int i=0;i<n;i++){
		// cout<<"*";
		cin>>type[i]>>mini[i]>>maxi[i];
	}

	int start=0, end=100000000;
	int j=n-1;
	while(j>=0){
		if(type[j]=="none"){
			start=max(mini[j], start);
			end=min(maxi[j],end);
			j--;
		}else if(type[j]=="on"){
			start-=maxi[j];end-=mini[j];
			if(start<0){start=0;}
			j--;
		}else{
			start+=mini[j];end+=maxi[j];
			j--;
		}
	}
	cout<< start <<" "<< end <<"\n";
	int i=0;
	start=0, end=100000000;
	while(i<n){
		if(type[i]=="none"){
			start=max(mini[i], start);
			end=min(maxi[i],end);
			i++;			
		}else if(type[i]=="on"){
			start+=mini[i];end+=maxi[i];
			i++;
		}else{
			start-=maxi[i];end-= mini[i];
			if(start<0)start=0;
		
			i++;
		}
	}
	cout<<start<<" "<<end<<"\n";

}

