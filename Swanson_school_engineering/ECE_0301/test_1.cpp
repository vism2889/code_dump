#include <iostream>

using namespace std;
float fnx(float x, int n){
	if (n==1){
		return 0;
	}
	if (n >1){
		return (x/n)*fxn(x,n-1);
	}
	else
	{
		break
	}
};

int main() {
	cout << fnx(5,5);
	return 0;
}
