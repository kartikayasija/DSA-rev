#include <iostream>
#include <cstring>
using namespace std;

/*
	Given a String, replace pi with 3.14

	abcpidepif -> abc3.14de3.14f

*/

void replacePi(char str[], int i){

	//base
	if(str[i]=='\0' or str[i+1]=='\0'){
		return;
	}

	if(str[i]=='p' and str[i+1]=='i'){
		//shift
		for(int j=strlen(str)-1; j>=i+2 ;j--){
			str[j+2]=str[j];
		}
		str[i]='3';
		str[i+1]='.';
		str[i+2]='1';
		str[i+3]='4';

		replacePi(str,i+4);
	}else{
		replacePi(str, i+1);
	}

	return;
}

int main(){
	char a[] = "abcpi";
	replacePi(a,0);	
	cout<<a;
}