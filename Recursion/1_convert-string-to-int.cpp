#include <iostream>
#include <string>
using namespace std;

/*
	Given a String, convert it into integer recursively 
*/

int convertToInt(string &str, int n){

	//base
	if(n==0){
		return 0;
	}

	//extract last number
	int last = str[n-1]-'0';
	
	//rec
	int small_ans = convertToInt(str, n-1);

	return small_ans*10+last;
}

int main(){
	string a = "123";
	int ans = convertToInt(a,a.size());
	cout<<endl<<ans<<endl;
}
