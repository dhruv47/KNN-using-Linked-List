#include<iostream>
#include<cstdlib>
#include <cmath>
using namespace std;

//Dimention of coordinates
int const k =3;

struct Node
{
    int data[k];
    struct Node* next;
    char label;
} ;

// Function to calculate distance
float dist(int *point, int *target)
{
    // Calculating distance
	float dis=0;
	for(int q=0;q<k;q++)
	{dis = dis + pow(point[q] - target[q],2);}
    return sqrt(dis);
}

int main(){
	int n;
	cout<<"Enter number of nodes in LL:";
	cin>>n;
	int a[k];
	cout<<"Enter the point to be Classified: ";
	for(int i=0 ; i<k ;i++)
	{cin>>a[i];}
	struct Node *head = NULL, *p =NULL ;
	cout<<"Enter the value of points and their label in order :\n";
	for(int i=0;i<n;i++)
	{
		struct Node *ptr;
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		for(int l=0 ; l<k ;l++)
	    {cin>>temp->data[l];}
		cin>>temp->label;
		temp->next = NULL;
		
		if(!head){
			// this section runs if linked list is empty
			// we set head to temp
			head = temp;	
		}
		else if(dist(temp->data, a) <= dist(head->data , a)){
			// this section runs if the new val is smaller then the first value in the linked list
			// we simple insert temp at the beginning of the linked list
			temp->next = head;
			head = temp;
		}
		else
		{
			// we are iterating each element of the linked list
			// to find the node whose value is just smaller than val
			ptr = head;
			while(ptr->next!= NULL && dist(ptr->next->data,a) < dist(temp->data, a))
			{
				ptr = ptr->next;
			}
			// ptr now points to the node whose value is just less than val
			// we simply insert temp between ptr and ptr->next
			temp->next = ptr->next;
			ptr->next = temp;

		}
	}
	int knn, t=0;
	char c[10];
	cout<<"Enter the number of nearest neighbour :";
	cin>>knn;
	p=head;
	while(knn)
	{
		c[t]= p->label;
		cout<<p->label<<endl;
		knn--;
		t++;
		p=p->next; 	
	}
    return 0;
}