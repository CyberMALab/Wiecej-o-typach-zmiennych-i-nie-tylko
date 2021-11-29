#include <stdio.h>
#include <stdlib.h>
int zmienna_globalna=0;
int main() {
	int zmienna_lokalna_main=1;
	
	if(zmienna_lokalna_main==1)
	{
		int zmienna_lokalna_if=2;
 		printf("%d ",zmienna_globalna); /* dostęp OK */
 		printf("%d ",zmienna_lokalna_main); /* dostęp OK */
 		printf("%d ",zmienna_lokalna_if); /* dostęp OK */
	}
}
