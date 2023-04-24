#include <stdio.h>
#include <stdlib.h>

/* Declare dynamic arrays/vectors and global variables*/
int* resource = NULL;
int* available = NULL;
int* maxClaim = NULL;
int* allocated = NULL;
int* need = NULL;
 
/*Dinamic variables*/
int totalNumberofProcesses;
int totalNumberOfResources;

/***********************************************************/
void printResourceVector() {
	/* declare local variables */
	int i;
    
    /*header of units total and available*/
    printf("\n\t Units\t Available\t\n");
    
    /* for loop: print each resource index */
    for(i = 0; i < totalNumberOfResources; i++){

        /*print number of total units and available units of each resource index */
        printf("r[%d]\t %d\t %d\t\n",i, resource[i], available[i]);
    }
	
	return;
}


/***************************************************************/
void printMatrix() { 
	/* declare local variables */
	int i, j;
    
    printf("\n\tMaximum\t\t\tCurrent\t\t\tPotential\t\n");
    
    /* for loop: print each resource index for header*/
    for(i = 0 ; i < totalNumberOfResources; i++){
        for(j =0 ; j < totalNumberOfResources; j++){
        printf("\tr%d", j);
        }
    }

	/* for each process: */
    for(i = 0; i < totalNumberofProcesses;i++){
        printf("\np%d\t" ,i);
		/* for each resource: */
        for(j =0 ; j < totalNumberOfResources;j++){
			
            /* print maximum number of units each process may request, is allocated, and needs from each resource */
            printf("%d\t", maxClaim[i*totalNumberOfResources+j]);
        }

        for(j = 0; j < totalNumberOfResources; j++){
            printf("%d\t ",  allocated[i*totalNumberOfResources+j]);
        }

        for(j = 0; j < totalNumberOfResources ;j++){
            printf("%d\t", need[i*totalNumberOfResources+j]);
        }
    
    } 
    printf("\n");     
	return;
}


/****************************************************************/
void enterParameters() {
	/* declare local variables */

	/* prompt for number of processes and number of resources */
    printf("Enter number of processes: ");
    scanf("%d", &totalNumberofProcesses);
    printf("Enter number of resources: ");
    scanf("%d", &totalNumberOfResources);
    

	/* allocate memory for vectors and arrays: resource, available, max_claim, allocated, need */
    resource = (int*) malloc(sizeof(int) * totalNumberOfResources);
    available = (int*) malloc(sizeof(int) * totalNumberOfResources);

    maxClaim = (int*) malloc(sizeof(int) * totalNumberOfResources * totalNumberofProcesses);
    allocated = (int*) malloc(sizeof(int) * totalNumberOfResources * totalNumberofProcesses);
    need = (int*) malloc(sizeof(int) * totalNumberOfResources * totalNumberofProcesses);

    printf("Enter number of units for resources(r0 to r%d): ",(totalNumberOfResources-1));

	/* for each resource, prompt for number of units, set resource and available vectors indices*/
    for(int i = 0 ; i < totalNumberOfResources; i++){

        scanf("%d", &resource[i]);
        available[i] = resource[i];
    }
	/* for each process, for each resource, prompt for maximum number of units requested by process, update max_claim and need arrays */
    for(int i =0 ; i < totalNumberofProcesses; i++){
        printf("Enter max units process p%d will request from each resource (r0 to r%d): ", i, (totalNumberOfResources-1));
        for(int j = 0; j < totalNumberOfResources;j++){
           
            scanf("%d", &maxClaim[i*totalNumberOfResources+j]);
            need[i* totalNumberOfResources+j] = maxClaim[i* totalNumberOfResources+j];
        }
    }

    for(int i = 0 ; i < totalNumberofProcesses; i++){
        printf("Enter number of units of each resource (r0 to r%d) allocated to process p%d: ", (totalNumberOfResources-1) ,i);
        for(int j = 0; j < totalNumberOfResources; j++){
            
            scanf("%d", &allocated[i* totalNumberOfResources+j]);
            /*update need array*/
            need[i* totalNumberOfResources+j] -= allocated[i* totalNumberOfResources+j];
            available[j] -= allocated[i* totalNumberOfResources+j];
      }
    }
	
	/* print resource vector, available vector, max_claim array, allocated array, need array */
    printResourceVector();
    printMatrix();

	return;
}


/********************************************************************/
void bankersAlgorithm() {

	/* declare local variables, including vector to indicate if process is safely sequenced and "num_sequenced" count*/
    int i,j;
    
    /*counter for number of proce. that have been sucessfully sequenced*/
    int finished = 0;
    int lessthanorEqual = 1;

    /*set sequenced[i] to 0 if not sequenced, 1 if already sequenced*/
    int* sequenced = (int*) calloc(totalNumberofProcesses,sizeof(int));
    int atLeastOne = 1;

	/* while not all processed are sequenced */
    while((finished < totalNumberofProcesses) && (atLeastOne == 1)){
        
        atLeastOne = 0;
        
		/* for each process */
        for(i = 0; i < totalNumberofProcesses; i++){ 
           lessthanorEqual = 1;
			/* if process has not been safely sequenced yet 8?*/
            if(sequenced[i] == 0){
                printf("Checking: < ");
                
				/* for each resource */
                for(j = 0; j < totalNumberOfResources; j++){
                    printf("%d " , need[i*totalNumberOfResources+j]);  
                }

                printf("> <= < ");
                
                for(j =0 ; j < totalNumberOfResources; j++){    
                    printf("%d " , available[j]);
                }
                printf("> :");

                for(j = 0; j < totalNumberOfResources;j++){
                    
                    /* check for safe sequencing by comparing process' need vector to available vector */
                    lessthanorEqual &= (need[i*totalNumberOfResources+j] <= available[j]);
                   
                }
                

                if(lessthanorEqual == 1 ){
                        atLeastOne = 1;
                        sequenced[i] = 1;
                        /* print message that process had been safely sequenced */
                         printf("p%d safely sequenced\n" , i);

					/* update number of available units of resource */
					/* for each resource */
                    for(j =0 ; j < totalNumberOfResources ; j++){

						/*free all resources allocated to process */
                        available[j] += allocated[i*totalNumberOfResources+j];
                         allocated[i*totalNumberOfResources+j] = 0;
	
                    }
                    
                    /* increment number of sequenced processes */
                    finished++;

                }else {
                    printf("p%d could not be sequenced\n" , i);
                }
                    
            }  
            
        }
        
    }
        if(atLeastOne == 0){
            printf("Deadlock has been reached!\n");
        }
    return;
}


/********************************************************************/
void garbageCollection() {
	/* check if vectors/array are not NULL--if so, free each vector/array */
    if((resource != NULL) || (available != NULL) || (maxClaim != NULL) || (allocated != NULL) || (need != NULL)){
        free(resource);
        free(available);
        free(maxClaim);
        free(allocated);
        free(need);
    }
	return;
}


/***************************************************************/
int main() {

	/* declare local vars */
	int choice = 0;

	/* while user has not chosen to quit */
	while(choice != 3){

		/* print menu of options */
		printf("\nProcess creation and destruction\n");
		printf("--------------------------------\n");
		printf("1) Enter parameters\n");
		printf("2) Determine Safe Sequence\n");
		printf("3) Quit program and free memory\n");

	
		/* prompt for menu selection */
		printf("\nEnter Selection: ");
		scanf("%d",&choice);

		/* call appropriate procedure based on choice--use switch statement or series of if, else if, else statements */
		switch (choice){
		case 1:
			enterParameters(); break;

		case 2:
			bankersAlgorithm(); break;
	
		case 3:
			garbageCollection();
			printf("Quitting program...\n"); break;
		
		default: 
			printf("Invalid Option\n");  break;
		}
	}
  return 1;
}