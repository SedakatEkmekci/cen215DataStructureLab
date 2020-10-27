#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void swapNumber(int *x,int *y)
{
    int temp= *x;
    *x=*y;
    *y=temp;
}
void swapName(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printArray(int array[],int size)
{
    for(int i=0;i<size;i++)
    	printf("%d",array[i]);
    
}

/*Insertion Sort*/

void insertionSortNum(int array[],int size)
{
	int x,prev;
	for(int i=1;i<size;i++)
	{
		x=array[i];
		prev= i-1;

		while(prev>=0 && array[prev]>x){
			array[prev+1] = array[prev];
			prev--;
        }
	array[prev+1]=x;
    }
}
void insertionSortName(char array[],int size)
{
    int prev;
    char name;

    for(int i=1;i<size;i++)
    {
        name=array[i];
        prev=i-1;
        while( prev >=0 && array[prev] > name)
        {
            array[prev+1]= array[prev];
            prev= prev-1;
        }
        array[prev+1]=name;
    }
}
/*Selection Sort*/

void selectionSortNum(int array[],int size)
{
	int minIndex;
	for(int i=0;i<size;i++)
	{
        minIndex= i;
		for(int j=i;j<size;j++)
		{
			if(array[j]<array[minIndex])
			{
				minIndex=j;
			}
		}
		swapNumber(&array[minIndex],&array[i]);
	}
}
void selectionSortName(char array[],int size)
{
	int minIndex;
	for(int i=0;i<size;i++)
	{
        minIndex= i;
		for(int j=i;j<size;j++)
		{
			if(array[j]<array[minIndex])
			{
				minIndex=j;
			}
		}
		swapName(&array[minIndex],&array[i]);
	}
}
/* Bubble Sort */
void bubbleSortNum(int array[], int size)
{

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swapNumber(&array[j], &array[j + 1]);
			}
		}
	}
}
void bubbleSortName(char array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapName(&array[j], &array[j + 1]);
			}
		}
	}
}
  /* Merge sort */

void mergeNum(int array[], int left, int middle, int right)
{
	int lsize;
	int rsize;
	lsize = middle - left + 1;
	rsize = right - middle;
	int Left[lsize];
	int Right[rsize];
	int i = 0;
	int j = 0;
	for (i = 0; i < lsize; ++i)
	{
		Left[i] = array[left + i];
	}
	for (j = 0; j < rsize; ++j)
	{
		Right[j] = array[middle + 1 + j];
	}
	i = 0; j = 0; int org = left;
	while (i < lsize && j < rsize)
	{
		if (Left[i] <= Right[j])
		{
			array[org] = Left[i];
			i++;
		}
		else
		{
			array[org] = Right[j];
			j++;
		}
		org++;
	}
	while (i < lsize)
	{
		array[org] = Left[i];
		org++;
		i++;
	}
	while (j < rsize)
	{
		array[org] = Right[j];
		org++;
		j++;
	}
}

void mergeSortNum(int array[], int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		mergeSortNum(array, left, middle);
		mergeSortNum(array, middle + 1, right);
		mergeNum(array, left, middle, right);
	}
}

void mergeName(char array[], int left, int middle, int right)
{
	int lsize;
	int rsize;
	lsize = middle - left + 1;
	rsize = right - middle;
	int Left[lsize];
	int Right[rsize];
	int i = 0;
	int j = 0;
	for (i = 0; i < lsize; ++i)
	{
		Left[i] = array[left + i];
	}
	for (j = 0; j < rsize; ++j)
	{
		Right[j] = array[middle + 1 + j];
	}
	i = 0; j = 0; int org = left;
	while (i < lsize && j < rsize)
	{
		if (Left[i] <= Right[j])
		{
			array[org] = Left[i];
			i++;
		}
		else
		{
			array[org] = Right[j];
			j++;
		}
		org++;
	}
	while (i < lsize)
	{
		array[org] = Left[i];
		org++;
		i++;
	}
	while (j < rsize)
	{
		array[org] = Right[j];
		org++;
		j++;
	}
}

void mergeSortName(char array[], int left, int right)
{
	if (left < right)
    {
		int middle = left + (right - left) / 2;
		mergeSortName(array, left, middle);
		mergeSortName(array, middle + 1, right);
		mergeName(array, left, middle, right);
	}
}


int main(){

     clock_t time;

    int num[]={2,0,1,7,5,5,6,0,2,5};
    char name[] = "sedakat ekmekci";
    int sizeOfNum = sizeof(num) /sizeof(num[0]);
    int sizeOfName = strlen(name);

    printf("Name: %s",name);
    printf("\nNumber : ");
    printArray(num,sizeOfNum);
    printf("\n\n");

    time=(double)clock();
    insertionSortNum(num,sizeOfNum);
    time=(double)clock()-time;
    printf("Insertion Sort For Number: ");
    printArray(num,sizeOfNum);
    printf("\nTime of Insertion Sort Performance for Number: %f\n", ((double)time) / CLOCKS_PER_SEC);

    time=(double)clock();
    insertionSortName(name,sizeOfName);
    time=(double)clock()-time;
    printf("Insertion Sort For Name: %s\n",name);
    printf("Time of Insertion  Sort Performance for Name:  %f\n\n", ((double)time) / CLOCKS_PER_SEC);

    time = (double)clock();
	selectionSortNum(num, sizeOfNum);
	time = (double)clock()-time;
	printf("Selection Sort for Number: ");
	printArray(num, sizeOfNum);
	printf("Time of Selection Sort Performance for Number: %f\n", ((double)time) / CLOCKS_PER_SEC);

	time = (double)clock();
	selectionSortName(name, sizeOfName);
	time = (double)clock()-time;
	printf("Selection Sort for Name: %s\n",name);
	printf("Time of Selection Sort Performance for Name: %f\n\n",((double)time) / CLOCKS_PER_SEC);

    time = (double)clock();
	bubbleSortNum(num, sizeOfNum);
	time = (double)clock()-time;
	printf("Bubble Sort for Number: ");
	printArray(num, sizeOfNum);
	printf("\nTime of Bubble Sort Performance for Number: %f\n", ((double)time) / CLOCKS_PER_SEC);

	time = (double)clock();
	bubbleSortName(name, sizeOfName);
	time = (double)clock()-time;
	printf("Bubble Sort for Name: %s\n",name);
	printf("Time of Bubble Sort Performance for Name: %f\n\n",((double)time) / CLOCKS_PER_SEC);

    time = (double)clock();
	mergeSortNum(num, 0, sizeOfNum - 1);
	time = (double)clock()-time;
	printf("Merge Sort for Number: ");
	printArray(num, sizeOfNum);
	printf("\nMerge Sort Performance for Number: %f\n", ((double)time) / CLOCKS_PER_SEC);

	time = (double)clock();
	mergeSortName(name, 0, sizeOfName - 1);
	time = (double)clock()-time;
	printf("Merge Sort for Name: %s\n",name);
	printf("Merge Sort Performance for Name: %f\n",((double)time) / CLOCKS_PER_SEC);

	return 0;

}



