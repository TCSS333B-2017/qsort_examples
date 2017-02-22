#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpInt(const void *a, const void *b ){
	int *aptr = (int*) a;
	int *bptr = (int*) b;
	return (*aptr-*bptr);
}	
int cmpChar(const void *a, const void *b ){
	char *aptr = (char*) a;
	char *bptr = (char*) b;
	return (*aptr-*bptr);
}	
int cmpStr(const void *a, const void *b ){
	char **aptr = (char**) a;
	char **bptr = (char**) b;
	return (strcmp(*aptr,*bptr));
}	
void* genMax(void *base, int nMemb, int size, int(*cmp)(const void*,const void*) ){
	void *max=base;
	for(char *ptr=(char*)base + size; ptr < (char*) base + nMemb*size; ptr+=size){
		if(cmp((void*) ptr, max) >0){
			max=(void*) ptr;
		}	
	}
	return max;		
}	
	


int main(){
	int a[]={1,3,5,2,4};
	char b[]={1,3,5,2,4};
	char *c[]={"one","two","three","four","five"};
	
	qsort(a,sizeof(a)/sizeof(int),sizeof(int),cmpInt);
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		printf("%d\n",a[i]);
	}
	
	qsort(b,sizeof(b)/sizeof(char),sizeof(char),cmpChar);
	for(int i=0;i<sizeof(b)/sizeof(char);i++){
		printf("%d\n",b[i]);
	}
		qsort(c,sizeof(c)/sizeof(char*),sizeof(char*),cmpStr);
	for(int i=0;i<sizeof(c)/sizeof(char*);i++){
		printf("%s\n",c[i]);
	}	
 int *intMax=genMax(a,sizeof(a)/sizeof(int),sizeof(int),cmpInt);
	char *charMax=genMax(b,sizeof(b)/sizeof(char),sizeof(char),cmpChar);
	char **strMax=genMax(c,sizeof(c)/sizeof(char*),sizeof(char*),cmpStr);

	printf("%d %d %s\n",*intMax,*charMax,*strMax);
		
	
			
	return 0;
}
