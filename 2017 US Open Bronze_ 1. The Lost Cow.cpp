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
	setIO("lostcow");
	int x, y;
	cin>>x>>y;
	int val=1;
	int multiplier=false;
	int distance=0;
	int pos=x;
	int pos_prev=x;
	if(x<y){
		while(pos<y){
			pos=x+val;
			if(pos>y){pos=y;}
			distance+=abs(pos-pos_prev);
			pos_prev=pos;
			val*=-2;
		}
	}else if(x>y){
		while(pos>y){
			pos=x+val;
			if(pos<y){pos=y;}
			distance+=abs(pos-pos_prev);
			pos_prev=pos;
			val*=-2;
		}
	}
	

	cout<<distance;


}
