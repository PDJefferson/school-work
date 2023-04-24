#include <stdio.h>
#include <stdlib.h>

// declare structure to store block information (id, starting address, ending address, link to next block)
struct Node{
    struct Node *link;
    int start;
    int end;
    int id;
}*blockList = NULL;

typedef struct Node blockType;

// declare linked list to connect allocation blocks

// declare global variables
int pmSize;
int holeAlgo;
int remaining;

/********************************************************************/
void enterParameters() {
	
	// declare local variables (if any)

	// prompt for size of physical memory and choice of hole-fitting algorithm (0=first-fit, 1=best-fit), initialize remaining memory 
    printf("Enter size of physical memory: ");
    scanf("%d", &pmSize);
    printf("Enter hole-fitting algorithm (0=first_fit, 1=best_fit): ");
    scanf("%d", &holeAlgo);

    remaining = pmSize;
	
    // initilize linked list with "dummy" block of size 0
    blockList = (blockType*) malloc(sizeof(blockType));
    blockList->id = -1;
    blockList->start = 0;
    blockList->end = 0;
    blockList->link = NULL;

	return;
}


/********************************************************************/
void printTable() {
	
	// declare local variables 
	blockType* currentBlock = blockList;
	
	// print table containing block id, starting address, ending address
	printf("\nID\tStart\tEnd\n");
	printf("-----------------------\n");
	
	while(currentBlock != NULL)
	{
		if(currentBlock->id == -1){
			currentBlock = currentBlock->link;
		}
		printf("%d\t%d\t%d\n", currentBlock->id, currentBlock->start, currentBlock->end);
		currentBlock = currentBlock->link;
	}

	return;
}


/********************************************************************/
void allocateMemory() {
	
	// declare local variables
	int id,blockSize,holeStart,holeEnd,holeSize,bestStart,bestEnd;
	blockType* currentBlock;
	blockType* bestBlock;
	int atLeastOne;
	// initialize best hole so far to size of physical memory
	int bestHole = pmSize; 

	// prompt for block id & block size
	printf("Enter block id: ");
	scanf("%d", &id);
	printf("Enter block size: ");
	scanf("%d",&blockSize );

	// check if size of block is larger than remaining unallocated space, if so, print message and return	
	if(blockSize > remaining){
		printf("Out of Memory!");
		return;
	}

	// allocate space for new block and set id
	blockType* newBlock = (blockType*) malloc(sizeof(blockType));
	newBlock->id = id;

	// if only "dummy" block exists, insert block at end of linked list, set fields, return
	if(blockList->link == NULL){
		newBlock->start = 0; //can be 0
		newBlock->end = blockSize;
		newBlock->link = NULL;
		blockList->link = newBlock;
		remaining -= blockSize;
		printTable();
		return;
		
	}
	// else traverse list until either appropriate hole is found or the end of the list is reached
	currentBlock = blockList;

	while(currentBlock != NULL){

		// if id already exists, reject request and return
		if(currentBlock->id == id){
			printf("Block id already exists");
			return;
		}
		
		// set values for start and end of currently found hole
		holeStart = currentBlock->end;
		holeEnd = (currentBlock->link != NULL) ? currentBlock->link->start : pmSize;
		holeSize = holeEnd - holeStart;
		
		// if hole is large enough for block
		if(holeSize >= blockSize){
			atLeastOne = 1;

			// if first-fit algorithm
			if(holeAlgo == 0){

				// set start & end fields of new block & add block into linked list
				newBlock->start = holeStart;
				newBlock->end = holeStart + blockSize;
				newBlock->link = currentBlock->link;
				currentBlock->link = newBlock;
				
				// reduce remaining available memory and return
				remaining -= blockSize;
				return;

			}else{ // else--best-fit algorithm
		
				// if hole is smaller than best so far
				if(holeSize < bestHole){
					
					// set values of best start & best end & best hole size so far
					bestHole = pmSize;
					bestStart = holeStart; 
					bestEnd = holeEnd;
					bestBlock = currentBlock;
					
					
				}
		   }
		}
		// update best block & advance next block 
		currentBlock = currentBlock->link;
	}

	if(atLeastOne == 0){ //no hole big enough for block request
		printf("Could not find a hole big enough");
		free(newBlock);
		return;
	}
	

	// set start & end fields of new block & add block into linked list 	   
	newBlock->start = bestStart;
	newBlock->end = bestStart + blockSize;
	newBlock->link = bestBlock->link;
	bestBlock->link = newBlock;

	// reduce remaining available memory and return
	remaining -= blockSize;
	printTable();
	return;	
}


/********************************************************************/
void destroyBlock() {
	
	// declare local variables
	int blockId;
	blockType* prevBlock;
	// prompt for block id
	printf("Enter block id: ");
	scanf("%d", &blockId);
	blockType* currentBlock = blockList;
	// until end of linked list is reached or block id is found 
	while ((currentBlock != NULL) && (currentBlock->id != blockId)){
		prevBlock = currentBlock;
		// traverse list
		currentBlock = currentBlock->link;
	}
	// if end of linked list reached, print block id not found
	if(currentBlock == NULL){
		printf("Block id not found!");
		return;
	}
	// else remove block and deallocate memory
	prevBlock->link = currentBlock->link;
	remaining += currentBlock->end - currentBlock->start;
	free(currentBlock);
	printTable();
	return;
}


/********************************************************************/
void defragMemory() {
	// declare local variables 	   
	int blockSize,prevEnd;
	blockType* currentBlock;
	prevEnd = 0;

	currentBlock = blockList;
	// until end of list is reached
	while((currentBlock != NULL)){

		// calculate current hole size
		blockSize = currentBlock->end - currentBlock->start;
		
		// adjust start & end fields of current block to eliminate hole
		currentBlock->start = prevEnd;
		currentBlock->end = currentBlock->start + blockSize;
		prevEnd = currentBlock->end;

		currentBlock = currentBlock->link;
	}
	printTable();
	return;
}


/********************************************************************/
void garbageCollection(blockType* node) {
	
	// if node is NULL, return
	if(node == NULL){
		return;
	}else{
	// else

		//recursively call procedure on node->link
		garbageCollection(node->link);
		// deallocate memory from node
		free(node);
	}
	return;
}


/***************************************************************/
int main() {
	/* declare local vars */
	int choice = 0;

	/* while user has not chosen to quit */
	while(choice != 5){

		/* print menu of options */
		printf("\nMemory allocation\n");
		printf("--------------------------------\n");
		printf("1) Enter parameters\n");
		printf("2) Allocate memory for block\n");
		printf("3) Deallocate memory for block\n");
		printf("4) Defragment memory\n");
		printf("5) Quit program\n");

	
		/* prompt for menu selection */
		printf("\nEnter Selection: ");
		scanf("%d",&choice);

		/* call appropriate procedure based on choice--use switch statement or series of if, else if, else statements */
		switch (choice){
		case 1:
			enterParameters(); break;

		case 2:
			allocateMemory(); break;

		case 3:
			destroyBlock(); break;
		
		case 4:
			defragMemory(); break;

		case 5:
			garbageCollection(blockList);
			printf("Quitting program...\n"); break;
		
		default: 
			printf("Invalid Option\n");  break;
		}
	}
  return 1;
} /* end of procedure */