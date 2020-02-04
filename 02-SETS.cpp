#include<iostream>
using namespace std;
void printarr(int a[],int b[],int m,int n)
{
	int i,j,temp;
	for (i=0;i<m;i++) 
    {
		for (j=i+1;j<m;j++)
        {
			if (a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for (i=0;i<n;i++) 
    {
		for (j=i+1;j<n;j++)
        {
			if (b[i]>b[j])
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	cout << "\n\nSet A : ";
	for(i=0;i<m;i++)
	{
		cout << a[i] << " ";
	}
	cout << "\nSet B : ";
	for(i=0;i<n;i++)
	{
		cout << b[i] << " ";
	}
}
void printUnion(int a[],int b[],int m, int n)
{
	int i,j,flag;
	for(i=0;i<m;i++)
	{
		cout<<a[i]<<" ";
	}
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<m;j++)
		{
			if(b[i]==a[j])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			cout<<b[i]<<" ";
		}
	}
}

void printIntersection(int a[],int b[], int m, int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
			{
				cout<<"Intersection: "<<a[i]<<" ";
			}
		}
	}
}

void printComplement(int a[], int b[], int m, int n) 
{ 
  int i = 0, j = 0; 
  while (i<m||j<n) { 
    if(a[i]<b[j])
	{ 
      cout <<a[i]<< " "; 
      i++; 
    } 
	else if(a[i]>b[j]) 
	{ 
      j++; 
    } 
	else if(a[i]==b[j]) 
	{ 
      i++; 
      j++; 
    } 
  }
  while (i<m)  
    cout <<a[i]<<" ";   
}

void choices()
{
	cout << "\n[A] Union" << endl;
	cout << "[B] Intersection" << endl;
	cout << "[C] Complement" << endl;
	cout << "[D] Exit" << endl;
}

int main()
{
	int set1[100],set2[100];
	int size1,size2,i;
	char choice;	

	cout << "Size of the 1st set : ";
	cin >> size1;
	for(i=0;i < size1; i++)
	{
		cin >> set1[i];
	}
	cout << "\nSize of the 1st set : ";
	cin >> size2;
	for(i=0;i < size2; i++)
	{
		cin >> set2[i];
	}
	ch:
	system("cls");
	printarr(set1,set2,size1,size2);
	choices();
	cout << "\nEnter choice : ";
	cin >> choice;
	switch(choice)
	{
		case 'A':
		case 'a': printUnion(set1,set2,size1,size2);
			break;
		case 'B':
		case 'b': printIntersection(set1, set2,size1, size2);
			break;
		case 'C':
		case 'c': printComplement(set1, set2,size1,size2);
			break;
		case 'D':
		case 'd': exit(0);
			break;
		default : cout << "\nInvalid Input" << endl;
			system("pause");
			system("cls");
			goto ch;
	}
	return 0;
}
