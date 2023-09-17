#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define arrSize 5

void createArray(int []);
void printArray(int []);
void selectionSort(int []);
void insertionSort(int []);
void bubbleSort(int []);
void mergeSort(int [],int,int);
void merge(int [],int,int,int);
void quickSort(int [],int,int);
int partition(int [],int,int);

int main(){
	int arr[arrSize];
	createArray(arr); 
	printArray(arr);
	//selectionSort(arr);
	//insertionSort(arr);
	//bubbleSort(arr);
	//mergeSort(arr,0,arrSize-1);
	quickSort(arr,0,arrSize-1);
	printArray(arr);
	return 0;
}

void createArray(int arr[]){
	srand(time(NULL));
	int i=0;
	while(i<arrSize){
		arr[i]=rand()%100;
		i++;
	}
}

void printArray(int arr[]){
	int i=0;
	while(i<arrSize){
		printf("%d ",arr[i]);
		i++;
	}
	printf("\n");
}

void selectionSort(int arr[]){
	int minNumber=arr[0];
	int i=0,temp;
	for(;i<arrSize;){
		for(int j=i;j<arrSize;j++){
			if(minNumber>arr[j]){
				minNumber=arr[j];
				arr[j]=arr[i];
				arr[i]=minNumber;	
			}
		}
		i++;
		minNumber=arr[i];
	}
}

void insertionSort(int arr[]){
	for(int i=1;i<arrSize;i++){
		int j=i;
		while(arr[j]<arr[j-1]){
			int temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			j--;
		}
	}
}

void bubbleSort(int arr[]){
	for(int i=0;i<arrSize;i++){
		int compCount=arrSize-i;
		int j=0;
		while(compCount>1){
			if(arr[j]>arr[j+1]){
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
			compCount--;
			j++;
			printArray(arr);
		}
	}
}

void mergeSort(int arr[],int left,int right){
	if(left<right){
		int middle=(left+right)/2;
		mergeSort(arr,left,middle);
		mergeSort(arr,middle+1,right);
		merge(arr,left,middle,right);
	}
}

void merge(int arr[], int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int leftArray[leftSize];
    int rightArray[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArray[i] = arr[middle + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void quickSort(int arr[],int left,int right){
	int pivot;
	if(left<right){
		pivot=partition(arr,left,right);
		quickSort(arr,left,pivot-1);
		quickSort(arr,pivot+1,right);
	}
}

int partition(int arr[],int left,int right){
	int temp;
	int x=arr[right];
	int i=left-1;
	for(int j=left;j<=right-1;j++){
		if(arr[j]<=x){
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[right];
	arr[right]=temp;
	return i+1;
}

