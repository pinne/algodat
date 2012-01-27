#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void){
	int i,tal,*pek;

	InitStack(sizeof(int),1000);
	for(i=0;i<100;i++){
		tal=i;
		Push(&tal);
	}
	while(!IsEmpty()){
		pek=(int *)Pop();
		tal=*pek;
		printf("%4d",tal);
	}
	printf("\n");
	return 0;
}
