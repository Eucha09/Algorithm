#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string w;
string file[50];
vector<string> result;
int dp[105][105];

int solve(string& w, string& s, int a, int b){
	int& ret = dp[a][b];
	
	if(ret != -1)
		return ret;
	if(a == w.size())
		return b == s.size() ? 1 : 0;
	if(b == s.size())
		return (w.size() == a + 1 && w[a] == '*') ? 1 : 0;
	
	if(w[a] == '?' || w[a] == s[b])
		ret = solve(w, s, a + 1, b + 1);
	else if(w[a] == '*')
		ret = solve(w, s, a, b + 1) || solve(w, s, a + 1, b);
	else
		ret = 0;
	return ret;
}

int main(){
	int c;
	
	scanf(" %d", &c);
	while(c--){
		int n;
		char s[105];
		result.clear();
		
		scanf(" %s", s);
		w = s;
		scanf(" %d", &n);
		for(int i = 0; i < n; i++){
			scanf(" %s", s);
			file[i] = s;
		}
		
		for(int i = 0; i < n; i++){
			memset(dp, -1, sizeof(dp));
			if(solve(w, file[i], 0, 0))
				result.push_back(file[i]);
		}
		sort(result.begin(), result.end());
		for(int i = 0; i < result.size(); i++)
			printf("%s\n", result[i].c_str());
	}
	return 0;
}
