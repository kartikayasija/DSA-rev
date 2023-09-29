/*Given N friends, who want to go to a party, they can go as single or as couple
Find number of ways in which they can go.
----------------------------------------------------------------------------------------------------------

ex - N=3, ways=4

for n=0 => 1 //no one is going that is also one way
	n=1 => 1 // can go only single
	n=2 => 2 // as single or as couple, 2 ways

f(n) = 1.f(n-1) as single + (n-1)!.f(n-2) as couple. we have (n-1)! choices for couple and remaining is n-2
------------------------------------------------------------------------------------------------------------
*/


#include <iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int f(int n){
	//base
	if(n<=1){
		return 1;
	}

	//recursive
	int ways=0;
	ways = f(n-1) + factorial(n-1)*f(n-2);
	return ways;
}

int main(){
	int ways = f(3);
	cout<<ways<<endl;
}