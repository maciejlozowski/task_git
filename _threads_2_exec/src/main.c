#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *myThread(void *arg){
	int i;
	/*Funckje z rodziny exec* podmieniają obraz bieżącego procesu (stos, sterta, instrukcje) obrazem nowego procesu.
	 Działanie sprowadza się do tego, że wszystkie informacje i stan bieżącego procesu są utracone i nowy program jest wykonywany.
	 */
	if (idPotomnego == 0) {
	    printf("Jesteś w procesie potomnym, jego ID = %d\n", getpid());
	} else {
	    printf("Jesteś w procesie macierzystym, jego ID = %d\n", getpid());
	}
	/*for(i = 0; i < 10; i++){
		printf("Inkrem numb: %d",i);
		sleep(1);
	} */
	return NULL;
}

int main(int argc, const char *argv[])
{
	printf("Jestem program i wykonuję różne instrukcje.\n");fflush(stdout);
		execl("/bin/sleep","Spioch","30",NULL); // w execu zastepowane jest wszystko
		printf("Czy to się wyświteli? Dlaczego nie? Jaki kod powrotu zwrócę?\n");
	exit(0);
	return 0;
}
