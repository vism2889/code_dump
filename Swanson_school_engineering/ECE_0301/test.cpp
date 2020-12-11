
#include <stdio.h>
int i;
void increment(int i){
	i++;
}

int main(){
	for (i=0; i<10;increment(i))
	{
		
	}
	printf("i=%d\n", i);
		return 0;
}
