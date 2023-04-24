#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

//gcc main.c -lm
// Declare global variables, including dynamic array to store sequence of traversed tracks
int* sequence = NULL;
int sequenceSize;

/*********************************************************/
void enterParameters() {

	// prompt for the sequence size
    printf("Enter size of sequence: ");
    scanf("%d", &sequenceSize);
	// allocate memory for the sequence of traversed tracks
    sequence = (int*) malloc(sequenceSize * sizeof(int));
	// prompt for starting track, store in index 0
    printf("Enter starting track: ");
    scanf("%d",  &sequence[0]);
  
	// prompt for sequence of tracks to seek, store in index 1 to "sequence size-1"
    printf("Enter sequence of tracks to seek: ");
    for(int i = 1 ; i <= sequenceSize-1; i++) {
        scanf("%d", &sequence[i]);
    }
	return;

} // "OPTION #1"


/*********************************************************/
void fifoAlgo() {

	// declare local variables		
	int totalDistance = sequence[0];
    
    printf("\nTraversed sequence: %d" , sequence[0]);
	// calculate total distance of traversed tracks
    for(int i = 1; i <= sequenceSize -1 ;i++){
        totalDistance += abs(sequence[i] - sequence[i-1]);
        
        // print sequence of traversal
        printf(" %d", sequence[i]);
    }

	// print total distance of tracks traversed
    printf("\nThe distance of the traversed tracks is:  %d\n", totalDistance);
	return;

} // "OPTION #2"	


/*********************************************************/
void sstfAlgo() {

	// declare local variables
    int currentTrack,totalDistance, numberOfTracksTraversed,shortestDistance,shortestIndex;
	int* scheduledtracks = (int*) calloc(sizeof(int), sequenceSize);
   
    // initialize current track and distance traversed to starting track
    currentTrack = sequence[0];
    totalDistance = sequence[0];
	numberOfTracksTraversed = 1;
    shortestIndex = 0;
	// begin printing sequence of traversal ,add the value at 0 
    printf("\nTraversed sequence: %d", sequence[0]);
	
    // until every track is traversed
    while(numberOfTracksTraversed < sequenceSize){
		// initilize shortest distance to INT_MAX
        shortestDistance = INT_MAX;
		// for each track in sequence
        for(int i = 1; i <= sequenceSize-1; i++){
        
			// if not already traversed
            if(scheduledtracks[i] == 0){
                //totalDistance += abs(sequence[i] - sequence[i-1]); could be +=
				
                //if distance to traverse is shorter than current shortest distance
                if(abs(sequence[i] - currentTrack ) < shortestDistance ){
					// set current shortest distance and index of the track	w/ shortest distance
                    shortestDistance =  abs(sequence[i] -  currentTrack); //need to check this  
                    shortestIndex = i;
                }
            }
        }

		// set "done" value for track w/shortest distance to 1 (mark as traversed)
        scheduledtracks[shortestIndex] = 1;

		// increment number of tracks that have been traversed
        numberOfTracksTraversed++;
		
		// update total distance traversed
        totalDistance += shortestDistance;
		
		//set current track to new position, print position
        currentTrack = sequence[shortestIndex];
        printf(" %d", currentTrack);
    }							
  	// print total distance traversed
	printf("\nThe distance of the traversed tracks is: %d\n", totalDistance);
	return;

} // "OPTION #3" 


/*********************************************************/
void scanAlgo() {

	// declare local variables
    int currentTrack,totalDistance, numberOfTracksTraversed,shortestDistance,shortestIndex,direction,atLeastOne;
	int* scheduledtracks = (int*) calloc(sizeof(int), sequenceSize);
	
    //prompt for initial direction (0=descreasing, 1=increasing)
    printf("Enter initial direction (0=descreasing, 1=increasing): ");
    scanf("%d", &direction);
	

	// initialize current track and distance traversed to starting track
    currentTrack = sequence[0];
    totalDistance = sequence[0];
	shortestIndex = 0;
	numberOfTracksTraversed = 1;
	// begin printing sequence of traversal 
    printf("Traversed sequence: %d", sequence[0]);
	
    // until every track is traversed
    while(numberOfTracksTraversed < sequenceSize){

		// initilize shortest distance to INT_MAX
		atLeastOne =0;
        shortestDistance = INT_MAX;

		// for each track in sequence
        for(int i = 1; i <= sequenceSize-1; i++){
        
			// if not already traversed
            if(scheduledtracks[i] == 0){
               // totalDistance = abs(sequence[i] - sequence[i-1]);could be +=
				
                //if distance to traverse is shorter than current shortest distance in the current direction
                if((abs(sequence[i] - sequence[i-1])) < shortestDistance ){
                    if( (((sequence[i] - currentTrack) > 0 ) && (direction == 1)) 
						|| (((sequence[i] - currentTrack) < 0 ) && (direction == 0))) {
                        
                        // set current shortest distance and index of the track	w/ shortest distance
                        shortestDistance = abs(sequence[i] - currentTrack);  
                        shortestIndex = i;
                        
						// set flag that at least one track was traversed
						atLeastOne = 1;
                   }	
                }
            }
		}
        // if at least one track was traversed
		if(atLeastOne == 1){
    	    // set "done" value for track w/shortest distance to 1 (mark as traversed)
			scheduledtracks[shortestIndex] = 1;
			
			// increment number of traversed tracks
			numberOfTracksTraversed++;
			
			// update total distance traversed
			totalDistance += shortestDistance;
			
			//set current track to new position, print position
			currentTrack = sequence[shortestIndex];
        	printf(" %d", currentTrack);
		}
		// else change direction
		else {
			direction = 1 - direction;
		}
    
	} 

 	// print total distance traversed
	printf("\nThe distance of the traversed tracks is: %d\n", totalDistance);
	return;

}// "OPTION #4"


/*********************************************************/
void cScanAlgo() {

	// declare local variables
	int currentTrack,totalDistance, numberOfTracksTraversed,shortestDistance,shortestIndex,atLeastOne,endReached;
	int* scheduledtracks = (int*) calloc(sizeof(int), sequenceSize);

	// initialize current track and number traversed to starting track
	totalDistance = sequence[0];
	currentTrack = sequence[0];
	numberOfTracksTraversed = 1;
	endReached = 0;
	// begin printing sequence of traversal 
	printf("\nTraversed sequence: %d", sequence[0]);
	
	// until every track is traversed
	while(numberOfTracksTraversed < sequenceSize){
		
		// initilize shortest distance to INT_MAX
		atLeastOne = 0;
		shortestDistance = INT_MAX;
		
		// for each track in sequence
		for(int i = 1; i <= sequenceSize-1; i++){
			// if not already traversed
			if(scheduledtracks[i] == 0){
				//if distance to traverse is shorter than current shortest distance and a positive value (only increasing direction)
				if( (((sequence[i] - currentTrack) < shortestDistance ) && ((sequence[i] - currentTrack) > 0))) {
					
					// set current shortest distance and index of the track	w/ shortest distance
					shortestDistance = (sequence[i]-currentTrack);
					shortestIndex = i;
					
     				// set flag that at least one track was traversed
					atLeastOne = 1; 
				}
			}
		}
		// if at least one track was traversed
		if(atLeastOne == 1){
    		// set "done" value for track w/shortest distance to 1 (mark as traversed)
			scheduledtracks[shortestIndex] = 1;

			// increment number of tracks that have been traversed
			numberOfTracksTraversed++;

			// if largest track was reached (recover lost tracks)
			if(endReached == 1){

				// update total distance traversed by decrementing by distance to track (subtracts distance from 0 to track)
				totalDistance -= shortestDistance;
				
				// reset "largest track" flag
				endReached = 0;
				currentTrack = sequence[shortestIndex];
				printf(" %d" , currentTrack);

			}else{ // else
				
				// update total distance traversed by distance to track
				totalDistance += shortestDistance;

				//set current track to new position, print position
				currentTrack = sequence[shortestIndex];
				printf(" %d", currentTrack);
			}		
		}else{
		// else (no track was traversed)

			// update total distance by current track (adds remaining distance before going back to 0)
			totalDistance += currentTrack;

			// reset current track to 0 (loop back around)
			currentTrack = 0;
			// set "end reached" flag to 1
			endReached = 1;
		}
	}
 	// print total distance traversed
	printf("\nThe distance of the traversed tracks is: %d\n", totalDistance);
	return;    

} // "OPTION #5


/***************************************************************/
void garbageCollection() {

	// if sequence is not NULL, free sequence
	if(sequence != NULL){
		free(sequence);
	}
	return;

} // "OPTION #6


/***************************************************************/
int main() {

	/* declare local vars */
	int choice = 0;
	
	/* while user has not chosen to quit */
	while(choice != 6) {

		/* print menu of options */
		printf("\nMemory allocation\n");
		printf("------------------------------\n");
		printf("1) Enter parameters\n");
		printf("2) Calculate distance to traverse tracks using FIFO \n");
		printf("3) Calculate distance to traverse tracks using SSTF\n");
		printf("4) Calculate distance to traverse tracks using Scan \n");
		printf("5) Calculate distance to traverse tracks using C-Scan \n");
		printf("6) Quit program and free memory\n");
		
		/* prompt for menu selection */
		printf("\nEnter Selection: ");
		scanf("%d", &choice);

		/* call appropriate procedure based on choice--use switch statement or series of if, else if, else statements */	
				/* call appropriate procedure based on choice--use switch statement or series of if, else if, else statements */
		switch (choice){
		case 1:
			enterParameters(); break;

		case 2:
			fifoAlgo(); break;

		case 3:
			sstfAlgo(); break;
		
		case 4:
			scanAlgo(); break;

		case 5:
			cScanAlgo(); break;
		
		case 6:
			garbageCollection();
			printf("Quitting program...\n"); break;
		
		default: 
			printf("Invalid Option\n");  break;
		}
	} /* while loop */

	 return 1; /* indicates success */

} // main	