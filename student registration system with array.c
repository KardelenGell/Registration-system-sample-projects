#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	char name[50];
	char surname[50];
	char major[50];
	int ID;
};

void SaveStudent(struct student[], int);
void SearchStudent(struct student[], int, int);
void SortStudent(struct student[], int);
void AllStudent(struct student[], int);
void Swap(struct student[], int, int);

int main()
{
	struct student array[100];
	int n, choose, IDno, a = -1;

	printf("Number of records you want to enter? : ");
	scanf("%d", &n);

	while (a = -1)
	{
		printf("\nMENU :\n");
		printf("Press 1 to add a new record of students.\n");
		printf("Press 2 to search for a student (using its ID number).\n");
		printf("Press 3 to sort the records of students according to their ID numbers in an ascending order.\n");
		printf("Press 4 to show the information of all students. \n");
		printf("Press 5 to exit\n");
		printf("\nEnter choice: ");
		scanf("%d", &choose);


		switch (choose)
		{
		case 1: { SaveStudent(array, n);
			break; }
		case 2: printf("Enter ID number to search : ");
			scanf("%d", &IDno);
			{SearchStudent(array, n, IDno);
			break; }
		case 3: { SortStudent(array, n);
			break; }
		case 4: { AllStudent(array, n);
			break; }
		case 5: { printf("The program has ended.");  exit(EXIT_FAILURE);
			break; }
		}
	}
	system("pause");
	return 0;
}

void SaveStudent(struct student array[100], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nEnter information for record: %d", i + 1);

		printf("\nEnter Name: ");
		scanf("%s", array[i].name);
		printf("Enter Surname: ");
		scanf("%s", array[i].surname);
		printf("Enter Major : ");
		scanf("%s", array[i].major);
		printf("Enter ID : ");
		scanf("%d", &array[i].ID);
	}
}

void SearchStudent(struct student array[100], int n, int number)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (array[i].ID == number)
		{
			printf("ID : %d\nName : %s\nSurname : %s\nMajor : %s\n", array[i].ID, array[i].name, array[i].surname, array[i].major);
			return;
		}
	}
	printf("ID not found.\n");
}

void SortStudent(struct student array[100], int Size)
{
	int i, j;
	printf("\nList Order\n");
	for (j = Size; j > 1; j--)
	{
		for (i = 0; i < j + 1; i++)
		{
			if (array[i].ID > array[i + 1].ID)
			{
				Swap(array, i, i + 1);
				break;
			}
			for (i = 0; i < j + 1; i++)
			{
				printf("%-10d %-20s %-30s %-40s\n", array[i].ID, array[i].name, array[i].surname, array[i].major);
				continue;
			}
		}

	}
}

void Swap(struct student array[], int x, int y)
{
	struct student temp;
	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

void AllStudent(struct student array[100], int s)
{
	int i;

	printf("\n\nName\t  Surname\t        Major\t                       ID\n");
	for (i = 0; i < s; i++)
	{
		printf("%-10s %-20s %-30s %-40d\n", array[i].name, array[i].surname, array[i].major, array[i].ID);
	}
}
