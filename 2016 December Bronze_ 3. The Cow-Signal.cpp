// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void cowsignal(){
	int m, n, k;
	cin>>m>>n>>k;
	vector<string> v(m*k);
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		string str="";
		int j=0;
		while(j<n){
			int count_dot=0;
			while(j<n&&s[j]=='.'){
				count_dot++;
				j++;
			}
			for(int l=0;l<count_dot*k;l++){
				str+=".";
			}
			int count_x=0;
			while(j<n&&s[j]=='X'){
				count_x++;
				j++;
			}
			for(int l=0;l<count_x*k;l++){
				str+="X";
			}
		}
		for(int a=0;a<k;a++){
			v.push_back(str);
		}
	}

	for(auto x: v){
		cout<<x<<"\n";
	}
}

int main() {
	
  cowsignal();
	

}
