#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct flight
{
	char source;
	char destination;
	int number;
	struct flight* next;
};

struct flight* top = NULL;
typedef struct flight ListNode; 
typedef ListNode* ListNodePtr; 

void insert(ListNodePtr* sPtr, char source, char destination, int n);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void sortList(ListNodePtr currentPtr);
int delete(ListNodePtr* sPtr, int value);

struct flight* temp;
char flightsource;
char flightdestination;
int flightnumber;

void insert(ListNodePtr* sPtr, char source, char destination, int n)
{
	ListNodePtr newPtr; 
	ListNodePtr previousPtr; 
	ListNodePtr currentPtr; 

	newPtr = malloc(sizeof(ListNode)); 

	if (newPtr != NULL)
	{ 
		newPtr->number = n; 
		newPtr->next = NULL; 

		previousPtr = NULL;
		currentPtr = *sPtr;

		       
		while (currentPtr != NULL && n > currentPtr->number)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}

		
		if (previousPtr == NULL)
		{
			newPtr->next = *sPtr;
			*sPtr = newPtr;
		}
		else
		{ 
			previousPtr->next = newPtr;
			newPtr->next = currentPtr;
		}
	}
	else 
	{
		printf("%d not inserted. No memory available.\n", n);
	}
	top != NULL;
}

void printList(ListNodePtr currentPtr)
{
	int i = 1;
	
	if (isEmpty(currentPtr)) 
	{
		puts("List is empty.\n");
	}
	else
	{
		temp = top;
		while (currentPtr != NULL)
		{
			printf("%d-) %c %c %d \n", i, currentPtr->source, currentPtr->destination, currentPtr->number);  
			currentPtr = currentPtr->next;
			i++;
		}
		
	}
}

void sortList(ListNodePtr currentPtr)
{
	int i = 1;
	
	if (isEmpty(currentPtr))
	{
		puts("List is empty.\n");
	}
	else
	{
		temp = top;
		while (currentPtr != NULL)
		{
			printf("%d-) %d \n", i,  currentPtr->number);  
			currentPtr = currentPtr->next;
			i++;
		}	
	}
}

int delete(ListNodePtr* sPtr, int value)
{
	ListNodePtr previousPtr; 
	ListNodePtr currentPtr; 
	ListNodePtr tempPtr; 

	if (value == (*sPtr)->number)
	{
		tempPtr = *sPtr;
		*sPtr = (*sPtr)->next;
		free(tempPtr);
		return value;
	}
	else 
	{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->next;


		while (currentPtr != NULL && currentPtr->number != value)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}


		if (currentPtr != NULL)
		{
			tempPtr = currentPtr;
			previousPtr->next = currentPtr->next;
			free(tempPtr);
			return value;
		}
	}
	return '\0';
}

int isEmpty(ListNodePtr sPtr)
{
	return sPtr == NULL;
}

int main()
{
	int choise, a = -1;
	
	ListNodePtr startPtr = NULL;
	
	while (a = -1)
	{
		printf("\nMENU:\n");
		printf("\n1- Add flight to list.");
		printf("\n2- Delete flight from the list.");
		printf("\n3- Sort the flights in list according to their numbers.");
		printf("\n4- Show all flight information in the list.");
		printf("\n5- Exit the program.\n");
		printf("\nSelect your choise: ");
		scanf("%d", &choise);

		switch (choise)
		{
		
		    case 1:
		    {	
			    printf("\n Source: ");
		        scanf("%s", &flightsource);
		        printf("\n Destination: ");
		        scanf("%s", &flightdestination);
		        printf("\n Number: ");
		        scanf("%d", &flightnumber);
	    
		    	insert(&startPtr,flightsource, flightdestination, flightnumber); 
		
		        break;
	    	}
	       
			case 2:
		    {
		    	if (!isEmpty(startPtr))
			    {
				    printf("%s", "Enter flight number to be deleted: ");
				    scanf("\n%d", &flightnumber);

				   if (delete(&startPtr, flightnumber))
				   { 
					  printf("%d deleted.\n", flightnumber);
				   }
				   else
				   {
					  printf("%d not found.\n\n", flightnumber);
				   }
		        }
			    else
			    {
				    printf("List is empty.\n");
			    }
			    break;
		    }
	    	
			case 3:
	    	{
			    sortList(startPtr);
		    	break;
		    }

		    case 4: 
		    {
			    printList(startPtr);
			    break; 
		    }

	     	case 5: 
		    { 
			    system("cls");
			    printf("The program has ended."); exit(EXIT_FAILURE);
			    break; 
		    }
		}
	}
	return 0;
}



