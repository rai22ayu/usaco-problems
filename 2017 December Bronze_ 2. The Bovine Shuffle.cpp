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

	setIO("shuffle");

	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<string> ids(n);
	for(int i=0;i<n;i++){
		cin>>ids[i];
	}
	vector<string>res(n);
	int k=3;
	while(k--){
		for(int i=0;i<n;i++){
			int index=-1;
			for(int j=0;j<n;j++){
				if(v[j]==i+1){
					index=j;
					break;
				}
			}
			res[index]=ids[i];
		}
		// for(int i=0;i<n;i++){
		// 	cout<<res[i]<<" ";
		// }
		// cout<<"\n";
		ids=res;
	}
	for(int i=0;i<n;i++){
		cout<<res[i]<<"\n";
	}

}
// 5
// 1 3 4 5 2 i
// 1234567 2222222 3333333 4444444 5555555 j
// 1       2       3       4       5
// 1234567 5555555 2222222 3333333 4444444 - initial position k
// 1234567 4444444 5555555 2222222 3333333 - 1st shuffle
// 1234567 3333333 4444444 5555555 2222222 - 2nd shuffle
// 1234567 2222222 3333333 4444444 5555555 - 3rd shuffle
// find where j+1 exists in v , get that i and res[i]=ids[j]
