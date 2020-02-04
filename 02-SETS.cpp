#include<iostream>
using namespace std;
int seta[100],setb[100],set3[100];
int size1,size2,size3;

void universal()
{
	
}
void printset(int set[],int size){
	int i,j,temp=0;
	for(i=0;i<size;i++){
		for (j=i+1;j<size;j++){
			if(set[i]>set[j])
			{
				temp=set[i];
				set[i]=set[j];
				set[j]=temp;
			}
		}
	}
	for(i=0;i<size;i++)
	{
		cout << set[i] << " ";
	}
}
void printcompliment(int set1[], int set2[],int size1,int size2){
  int i = 0, j = 0; 
  while (i<size1||j<size2) { 
    if(set1[i]<set2[j])
	{ 
      cout <<set1[i]<< " "; 
      i++; 
    } 
	else if(set1[i]>set2[j]) 
	{ 
      j++; 
    } 
	else if(set1[i]==set2[j]) 
	{ 
      i++; 
      j++; 
    } 
  }
  while (i<size2)  
    cout <<set1[i]<<" "; 
}

void printunion(int set1[], int set2[], int size1, int size2)
{
	int i=0, j=0;
	while (i < size1 && j < size2)
	{
		if (set1[i] < set2[j])
			cout << set1[i++] << " ";
		else if (set2[j] < set1[i])
			cout << set2[j++] << " ";
    	else
		{
			cout << set2[j++] << " ";
			i++;
		}
	}
	while(i < size1)
		cout << set1[i++] << " ";
	while(j < size2)
    	cout << set2[j++] << " ";	
}
void intersection()
{
	int i=0, j=0;
	while (i < size1 && j < size2)
	{
		if(seta[i]==setb[j]){
			set3[size3]=seta[i];
			size3++;
			j++;
		}
		i++;
	}
}
int main()
{
	int i,j,temp=0,size;
	menu:
	cout << "Enter size of Set A : ";
	cin >> size1;
	cout << "\nEnter Elements : " << endl;
	for(i=0;i<size1;i++)
	{
		cin >> seta[i];
	}
	cout << "\nEnter size of Set B : ";
	cin >> size2;
	for(i=0;i<size2;i++)
	{
		cin >> setb[i];
	}
	system("cls");
	cout << "Set A : ";
	printset(seta, size1);
	cout << "\nSet B : ";
	printset(setb, size2);
	cout << "\n\n\t\tSet Operation : " << endl;
	cout << "\nIntersection of the sets : ";
	intersection();
	printset(set3, size3);
	cout << "\nUnion of the sets : ";
	printunion(seta, setb, size1, size2);
	cout << "\nCompliment of set A to set B : ";
	printcompliment(seta,set3,size1,size3);
	cout << "\nCompliment of set B to set A : ";
	printcompliment(setb,set3,size2,size3);
	system("pause");
}
