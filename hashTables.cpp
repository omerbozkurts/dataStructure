#include <stdio.h>
#include <string.h>

typedef struct Table{
	
	int unicId;
	char name[15];
	char surname[15];
	int age;
	
}table;

table array[27];

int hashing(int);
int put(table);
void get(int);
void freeArray(table [],int);
void printArray(table [],int);

int main(){
	int length=sizeof(array)/sizeof(array[0]);
	freeArray(array,length);
	table data;
	data.unicId=10;data.age=23;strcpy(data.name,"omer");strcpy(data.surname,"bozkurt");
	put(data);
	data.unicId=152;data.age=19;strcpy(data.name,"ali");strcpy(data.surname,"yilmaz");
	put(data);
	data.unicId=113;data.age=45;strcpy(data.name,"zeynep");strcpy(data.surname,"cetin");
	put(data);
	//collision
	data.unicId=2;data.age=46;strcpy(data.name,"ayse");strcpy(data.surname,"durmaz");
	put(data);
	data.unicId=29;data.age=37;strcpy(data.name,"coll");strcpy(data.surname,"ision");
	put(data);
	//overwrite
	data.unicId=2;data.age=25;strcpy(data.name,"over");strcpy(data.surname,"write");
	put(data);
	printArray(array,length);
	get(113);
	//fulled hash table
	for(int i=0;i<30;i++){
		data.unicId=i;data.age=i+18;strcpy(data.name,"fulled");strcpy(data.surname,"hash_table");
		put(data);
	}
	printArray(array,length);
	//invalid search or getting
	get(107);
	return 0;
}

int hashing(int number){
	return (number*8+5)%27;
}

int put(table data){
	if(array[hashing(data.unicId)].unicId==-1){
		array[hashing(data.unicId)]=data;
		return 1;
	}
	int counter=0;
	int index=hashing(data.unicId);
	int length=sizeof(array)/sizeof(array[0]);
	while(array[index].unicId!=-1&&array[index].unicId!=data.unicId){
		index++;
		if(index>=length){
			if(counter>=1){
				printf("hash table is full\n");
				return -1;
			}
			index%=length;
			counter++;
		}
	}
	
	array[index]=data;
	return 1;
}

void get(int key){
	table tempArray[1];
	if(array[hashing(key)].unicId==key){
		tempArray[0]=array[hashing(key)];
	}
	else{
		int counter=0;
		int index=hashing(key);
		int length=sizeof(array)/sizeof(array[0]);
		while(array[index].unicId!=-1&&array[index].unicId!=key){
			index++;
			if(index>=length){
				if(counter>=1){
					printf("invalid search\n");
					return;
				}
				index%=length;
				counter++;
			}
		}
		tempArray[0]=array[index];
	}
	printf("key:%d unicId:%d name:%s surname:%s age:%d \n",hashing(key),tempArray[0].unicId,tempArray[0].name,tempArray[0].surname,tempArray[0].age);
}

void freeArray(table array[],int length){
	for(int i=0;i<length;i++){
		array[i].unicId=-1;
	}
}

void printArray(table array[],int length){
	for(int i=0;i<length;i++){
		int key=-1;
		if(array[i].unicId!=-1)
			key=hashing(array[i].unicId);
		printf("%d)key:%d unicId:%d name:%s surname:%s age:%d \n",i+1,key,array[i].unicId,array[i].name,array[i].surname,array[i].age);
	}
}
