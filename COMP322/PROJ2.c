#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*using limits library to assign a variable to INT_MAX*/    

/* declare global variables including a table structure to hold scheduling information */
struct Node {

    int id;
    int arrival;
    int totalCPU;
    int totalRemaining;
	int done;
    int startTime;
    int endTime;
    int turnAroundTime;
	int alreadyStarted;

}*table = NULL;

typedef struct Node tableType;

/*More global Vars*/
int numberOfProcesses;
/* optional: define a function that finds the maximum of two integers */
#define max(a,b) (a > b ? a : b)

/***************************************************************/
void printContentofTable() {
	
	/* declare local variables */
    int i;
	
    /* print table header */	
    printf("\nID\tArrival\ttotal\tStart\tEnd\tTurnaround\n");
	printf("---------------------------------------------\n");
    
    /* for each process */
        for(i = 0; i < numberOfProcesses; i++){
           
		/* print the contents (id, arrival time, total_cycles) of each field of the table's index */
			 printf("%d\t%d\t%d", table[i].id, table[i].arrival, table[i].totalCPU);

        /* if process has been scheduled ("done" field is 1, print other contents (start time, end time, turnaround time) */
        	if(table[i].done == 1){
				printf("\t%d\t%d\t%d", table[i].startTime, table[i].endTime, table[i].turnAroundTime);
        	}
			 /* print a new line outside the if statement*/
        	printf("\n");
        }
	return;
}


/***************************************************************/
void createProcess() {
	
	/* declare local variables */
	int i;
	/* prompt for total number of processes */	
	printf("Enter total number of prrocesses: ");
	scanf("%d", &numberOfProcesses);
	
	/* allocate memory for table to hold process parameters */
	table = (tableType*) malloc(numberOfProcesses*sizeof(tableType));

	/* for each process */
		for(i = 0; i < numberOfProcesses; i++){

		/* prompt for process id, arrival time, and total cycle time */	
		printf("Enter process id: ");
		scanf("%d", &table[i].id);
		printf("Enter arrival cycle for process P[%d] : ", table[i].id);
		scanf("%d", &table[i].arrival);
		printf("Enter total cycles for process P[%d] : ", table[i].id);
		scanf("%d", &table[i].totalCPU);

		}

	/* print contents of table */
	printContentofTable();

	return;		
}	
		

/***************************************************************/
void fifoAlgorithm() {

	/* declare (and initilize when appropriate) local variables */
	int numberofDoneProcesses, earliestArrivalTime,earliestArrivalTimeIndex,currentCycle,i;
	numberofDoneProcesses =0;
	currentCycle=0;
	
	/* for each process, reset "done" field to 0 */
	for(i =0 ; i < numberOfProcesses; i++){

		table[i].done =0;
	}
	

	/* while there are still processes to schedule */
	while( numberofDoneProcesses < numberOfProcesses ){
		
		/* initilize the earliest arrival time to INT_MAX (largest integer value) */
		earliestArrivalTime = INT_MAX;
			
		/* for each process not yet scheduled */
		for(i = 0; i < numberOfProcesses;i++){
			
			if(table[i].done == 0){	
			/* check if process has earlier arrival time than current earliest and update */
			
				if(table[i].arrival < earliestArrivalTime){
					earliestArrivalTime = table[i].arrival;
					earliestArrivalTimeIndex = i;
				}
			}
		}
					
		/* set start time, end time, turnaround time, done fields for unscheduled process with earliest arrival time */       	
		table[earliestArrivalTimeIndex].startTime = max(table[earliestArrivalTimeIndex].arrival ,currentCycle);
		table[earliestArrivalTimeIndex].endTime = table[earliestArrivalTimeIndex].startTime + table[earliestArrivalTimeIndex].totalCPU;
		table[earliestArrivalTimeIndex].turnAroundTime = table[earliestArrivalTimeIndex].endTime - table[earliestArrivalTimeIndex].arrival;	//could be startTime. check	
		table[earliestArrivalTimeIndex].done =  1;
		
		/* update current cycle time and increment number of processes scheduled */
		currentCycle = table[earliestArrivalTimeIndex].endTime; 
		numberofDoneProcesses++;
	
	}

	/* print contents of table */
	printContentofTable();
	return;		
}	


/***************************************************************/
void sjfAlgorithm() {

	/* declare (and initilize when appropriate) local variables */
	int numberofDoneProcesses, earliestArrivalTime,earliestArrivalTimeIndex,currentCycle,i;
	numberofDoneProcesses = 0;
	currentCycle = 0;

	/* for each process, reset "done" field to 0 */
	for(i = 0 ; i < numberOfProcesses; i++){
		table[i].done = 0;
	}

	/* while there are still processes to schedule */
	while(numberofDoneProcesses < numberOfProcesses ){
		
		/* initilize the shortest total cpu time to INT_MAX (largest integer value) */
		earliestArrivalTime = INT_MAX;

		/* for each process not yet scheduled */
		for(i = 0; i < numberOfProcesses; i++){		
			if(table[i].done == 0){	
			/* check if process has lower total cpu  time than current lowest and the process has arrival time less than or equal current cycle and update */	
				if( (table[i].totalCPU < earliestArrivalTime) && (table[i].arrival <= currentCycle) ){
					earliestArrivalTime = table[i].totalCPU;
					earliestArrivalTimeIndex = i;
				}
			}
		}
		
		/* set start time, end time, turnaround time, done fields for unscheduled process with earliest arrival time */       	
		table[earliestArrivalTimeIndex].startTime = max(table[earliestArrivalTimeIndex].arrival, currentCycle);
		table[earliestArrivalTimeIndex].endTime = table[earliestArrivalTimeIndex].startTime + table[earliestArrivalTimeIndex].totalCPU;
		table[earliestArrivalTimeIndex].turnAroundTime = table[earliestArrivalTimeIndex].endTime - table[earliestArrivalTimeIndex].arrival;	
		table[earliestArrivalTimeIndex].done = 1;

		/* update current cycle time and increment number of processes scheduled */
		
		currentCycle = table[earliestArrivalTimeIndex].endTime; 
		numberofDoneProcesses++;
		
	}

	/* print contents of table */
	printContentofTable();
	

	return;		
}	
        	

/***************************************************************/
void srtAlgorithm() {

	/* declare (and initilize when appropriate) local variables */
	int numberofDoneProcesses, earliestArrivalTime,earliestArrivalTimeIndex,currentCycle,i;
	numberofDoneProcesses = 0;
	currentCycle = 0;

	/* for each process, set fields appropiately */
	for(i = 0 ; i < numberOfProcesses; i++){
		table[i].done = 0;
		table[i].alreadyStarted = 0;
		table[i].totalRemaining = table[i].totalCPU;
		
	}

	/* while there are still processes to schedule */
	while(numberofDoneProcesses < numberOfProcesses ){
		
		/* initilize the shortest total cpu time to INT_MAX (largest integer value) */
		earliestArrivalTime = INT_MAX;

		/* for each process */
			for(i = 0; i < numberOfProcesses; i++){

				if(table[i].done == 0){	
				/* check if process has shorter total cpu  time than current shortest and the process has arrive and update */	
					if( (table[i].totalRemaining < earliestArrivalTime) && (table[i].arrival <= currentCycle) ){
						earliestArrivalTime = table[i].totalRemaining;
						earliestArrivalTimeIndex = i;
					}
				}
			}
	
		/*check if the process was not partially scheduled for some reason he uses i*/
		if(table[earliestArrivalTimeIndex].alreadyStarted == 0){ 	

			/* set start time, end time, turnaround time, done fields for unscheduled process with smallest remaining time */  
			table[earliestArrivalTimeIndex].startTime = max(table[earliestArrivalTimeIndex].arrival ,currentCycle);	
			table[earliestArrivalTimeIndex].alreadyStarted = 1;
		}

		table[earliestArrivalTimeIndex].endTime = currentCycle + 1;
		table[earliestArrivalTimeIndex].turnAroundTime = table[earliestArrivalTimeIndex].endTime - table[earliestArrivalTimeIndex].arrival;	

		//decrement total remaining time of table
		table[earliestArrivalTimeIndex].totalRemaining--; //he uses i

		/*check if done and if so increment # of process scheduled,set done field*/
		if(table[earliestArrivalTimeIndex].totalRemaining == 0){
			table[earliestArrivalTimeIndex].done = 1;
			numberofDoneProcesses++;
		}

		

		/* update current cycle time and increment number of processes scheduled */
		
		currentCycle++; 
		
	}

	/* print contents of table */
	printContentofTable();
	

	return;	
}	
        	

/***************************************************************/
void garbageCollection() {

	/* free the schedule table if not NULL */
	if(table !=  NULL){
		free(table);
	}
	
	return;
}


/***************************************************************/
int main() {
	/* declare local vars */
	int choice;

	/* while user has not chosen to quit */
	while(choice != 5){

		/* print menu of options */
		printf("\nBatch scheduling\n");
		printf("--------------------------------\n");
		printf("1) Enter parameters\n");
		printf("2) Schedule processes with FIFO algorithm\n");
		printf("3) Schedule processes with SJF algorithm\n");
		printf("4) Schedule processes with SRT algorithm\n");
		printf("5) Quit program and free memory\n");

	
		/* prompt for menu selection */
		printf("\nEnter Selection: ");
		scanf("%d",&choice);

		/* call appropriate procedure based on choice--use switch statement or series of if, else if, else statements */
		switch (choice){
		case 1:
			createProcess(); break;

		case 2:
			fifoAlgorithm(); break;

		case 3:
			sjfAlgorithm(); break;

		case 4:
			srtAlgorithm(); break;
		
		case 5:
			garbageCollection();
			printf("Quitting program...\n"); break;
		
		default: 
			printf("Invalid Option\n");  break;
		}
	}

	 return 1; /* indicates success */
} /* end of procedure */