#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/* funkcija je void* sto zanci da moze da vrati bilo koji tip podatka */
void* routine() 
{
    printf("Hello from threads\n");
    sleep(3);
    printf("Ending thread\n");
    printf("\n");
}

int main(int argc, char* argv[]) 
{
    /* Definisemo dve promenjive tipa pthread_t */
    pthread_t p1, p2;

    /* Poziv funkcije koja kreira novi tread i uzima argumente (adresu od promenjive p1, NULL se obicno koristi za dodatne postavke,
    ovde koristimo podrazumevane postavke, adresu od funkcije koja ce se izvrsiti, NULL tu bi trebao da stoji argument
    koji se prosledjuje funkciji routine ali u nasem slucaju nema argumenta) */
    pthread_create(&p1, NULL, &routine, NULL);
    pthread_create(&p2, NULL, &routine, NULL); 
    
    /* Funkcija koja ceka na zavrsetak funkcije treda generisanog funkcijom pthread_create. Ova funkcija ceka da se prvi argument
    koji joj je prosledjen zavrsi pa nastavlja dalje sa nekim drugim elementom ako je prosedjen */
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
   
    return 0;
}