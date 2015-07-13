#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *myThread(void *arg){
	int i;
	int idPotomnego = fork();
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
	pthread_t firstThread;
	pthread_create ( &firstThread, NULL, myThread, NULL);
	pthread_join(firstThread, NULL);
	exit(0);
	return 0;
}
