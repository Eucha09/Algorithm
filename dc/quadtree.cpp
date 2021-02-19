#include <stdio.h>
#include <string>
using namespace std;

string qt;
int index;

string solve(){
	string s[4];
	
	if(qt[index] != 'x')
		return string(1, qt[index]);
	
	for(int i = 0; i < 4; i++){
		index++;
		s[i] = solve();
	}
	
	return string("x") + s[2] + s[3] + s[0] + s[1];
}

int main(){
	int c;
	
	scanf(" %d", &c);
	while(c--){
		string ret;
		char input[1005];
		index = 0;
		
		scanf(" %s", input);
		qt = input;
		
		ret = solve();
		printf("%s\n", ret.c_str());
	}
	return 0;
}
