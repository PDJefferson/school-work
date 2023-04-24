#include <stdio.h>
#include <stdlib.h>

/* Define structures and global variables*/
/*Linked list of children processes*/
struct Node1 {

    int process;  //keep track of the index
    struct Node1* link;  //allow us to have a point to the next child of the sibling

};

typedef struct Node1 linkedListType; //allows you to name a structure as you want

/*PCB structure*/
struct Node2 {
    int parent;
    linkedListType* children;
} *pcb = NULL;

typedef struct Node2 pcbType;

int amountOfProcesses; //size of the PCB array


/***************************************************************/
void printHierarchyOfProcesses() {
	/* declare local vars */
	int i;
	linkedListType* next;
	/* for each PCB index i from 0 up to (but not including) maximum number*/
	for(i = 0; i < amountOfProcesses; i++){

		
		/* check if PCB[i] has a parent and children */
		if((pcb[i].parent != -1) && (pcb[i].children != NULL)){

			/* print message about children of the current PCB[i] */
			printf("PCB[%d] is the parent of: ", i);
			
			/* initilize variable to head of list of children */
			next = pcb[i].children;

			/* while the end of the linked list of children is not reached */ 
			while(next != NULL){				
				
				/* print message about current child process index */
				printf("PCB[%d]  ", next->process);
				
				/* move to next node in linked list */
				next = next->link;
			} /* while */

			/* print newline */
			printf("\n");
		}/* if */
	} /* for */
} /* end of procedure */

/***************************************************************/
void enterParameters() {
	/* declare local vars */
    int i;

	/* prompt for maximum number of processes */
	printf("Enter the maximun number of processes: ");
    scanf("%d",&amountOfProcesses);

	/* allocate memory for dynamic array of PCBs */
    pcb = (pcbType*) malloc(sizeof(pcbType)* amountOfProcesses);

	/* Define PCB[0] */
	pcb[0].parent= 0;
    pcb[0].children = NULL;

	/* for-loop to intitialize all other indices' parent to -1 */
	for(i = 1 ; i < amountOfProcesses; i++){
        pcb[i].parent = -1;
    }
	return;

} /* end of procedure */

	
/***************************************************************/
void createInstance() {
	
	/* define local vars */
	int parent,childq;
	childq = 0;
	linkedListType* newChild;
	linkedListType* next;

	/* prompt for parent process index p */
	printf("Enter the parent Process index: ");
	scanf("%d",&parent);

	/* search for first available index q without a parent in a while loop */
	while(pcb[childq].parent != -1){
			
		childq++;
	}

	/* allocate memory for new child process, initilize fields */
	newChild = (linkedListType*) malloc(sizeof(linkedListType));
	newChild->process = childq; 
	newChild->link = NULL; //pointer type so we need the arrow

	/* record the parent's index p in PCB[q] */
	pcb[childq].parent = parent;

	/* initialize the list of children of PCB[q] as empty */
	pcb[childq].children = NULL;

	/* create a new link containing the child's index q and append the link to the end of the linked list of PCB[p] */
	if(pcb[parent].children == NULL){
		pcb[parent].children = newChild;
	}
	else{
		next = pcb[parent].children;
		
		while(next->link !=NULL){
			next = next->link;
		}
		next->link = newChild;
	}

	/* call procedure to print current hierachy of processes */
   	printHierarchyOfProcesses();
	return;
} /* end of procedure */


/***************************************************************/
void  destroyChildrenProcesses(linkedListType* node) {
	/* declare local vars */
	int childrenq;
	/* check if end of linked list--if so return */
	if(node == NULL){
		return;
	}
	
	else{

		/* else call self on next node in linked list */
		destroyChildrenProcesses(node->link);
		/* set variable q to current node's process index field */
		childrenq = node->process;

		/* call self on children of PCB[q] */ 	
		destroyChildrenProcesses(pcb[childrenq].children);

		/* free memory of paramter */
		free(node);	

		/* reset parent of PCB[q] to -1 */
		pcb[childrenq].parent = -1;

		/* set parameter to NULL */
		node =NULL;

	} /* end of else */
	return;
} /* end of procedure */


/***************************************************************/
void destroy() {
	/* declare local vars */
	int parentP;

	/* prompt for process index p */
	printf("Enter the index of the process whose descendants are to be destroyed: ");
	scanf("%d", &parentP);

	/* call recursive procedure to destroy children of PCB[p] */
	destroyChildrenProcesses(pcb[parentP].children);

	/* reset children of PCB[p] to NULL */
	pcb[parentP].children = NULL;

	/* call procedure to print current hierarchy of processes */
	printHierarchyOfProcesses();
	return;
} /* end of procedure */


/***************************************************************/
void garbageCollection() {

	/* check if PCB is non null)*/
	if(pcb != NULL){

		
		/* check if children of PCB[0] is not null */
		if(pcb[0].children != NULL){

			printf("Destroying processes");
			/* call recursive procedure to destroy children of PCB[0] */
			destroyChildrenProcesses(pcb[0].children);

		} /* if */
	
	/* free memory of PCB */
	free(pcb);

	} /* if */
	return;
} /* end of procedure */


/***************************************************************/
int main() {
	/* declare local vars */
	int choice = 0;

	/* while user has not chosen to quit */
	while(choice != 4){

		/* print menu of options */
		printf("\nProcess creation and destruction\n");
		printf("--------------------------------\n");
		printf("1) Enter parameters\n");
		printf("2) Create a new child process\n");
		printf("3) Destroy all descendants of a process\n");
		printf("4) Quit program and free memory\n");

	
		/* prompt for menu selection */
		printf("\nEnter Selection: ");
		scanf("%d",&choice);

		/* call appropriate procedure based on choice--use switch statement or series of if, else if, else statements */
		switch (choice){
		case 1:
			enterParameters(); break;

		case 2:
			createInstance(); break;

		case 3:
			destroy(); break;
		
		case 4:
				garbageCollection();
				printf("Quitting program...\n"); break;
		
		default: 
				printf("Invalid Option\n");  break;
		}
	}
	return 1;
}