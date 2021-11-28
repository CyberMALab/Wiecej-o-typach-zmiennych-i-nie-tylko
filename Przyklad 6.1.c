#include <stdio.h>
#include <stdlib.h>
int zmienna_globalna=0;
int main() {
	int zmienna_lokalna=1;
	
	if(zmienna_lokalna==1)
	{
		int zmienna_lokalna=2; /* przysłania zmienną z main */
 		printf("%d ",zmienna_globalna);
 		printf("%d \n",zmienna_lokalna);
	}
	printf("%d ",zmienna_globalna);
 	printf("%d ",zmienna_lokalna);
}

