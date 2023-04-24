#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

intmain(){
    intid;    
    printf("Hello World from the master thread\n" );
    printf("We have a total of %d threads \n", omp_get_num_threads());
    #pragmaomp parallel private(id){
        if(omp_get_thread_num() == 0){
            printf("Hello World from thread number %d (AKA master thread), we have %d threads now\n", omp_get_thread_num(), omp_get_num_threads());
        }
        else
            {
             printf("Hello World from thread number %d \n", omp_get_thread_num());
             }
  }
    printf("Hello World  again from the master thread, we are done \n" );
}