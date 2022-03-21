#include<stdio.h>
#include<stdlib.h>
//----------------------------Define The Datatypes
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;
//---------------------------- Define The Structure 
typedef struct mystruct
{
	u8 id;
	u8 name[20];
	u8 gender;
	u8 age;
	u8 mytime;
	struct mystruct *next;
}patient;
//-----------------------------Define two objects of the structure Head , Tail for the LinkedList Structure
patient * head=NULL;
patient * tail=NULL;
//-----------------------------Define The Global variables Used
u8 size,key,g=0;
patient * ptr,*ptt;
u8 time[6]={1,2,3,4,5,6};
u8 time1[6]={0,0,0,0,0,0};
//------------------------------Define The Functions Used
patient * SearchByID(u8 key);
u8 SearchByTime(u8 NT);
//------------------------------Append Node Function Implementation to Add new Patient Record
void AppendNode(void)
{
	u8 t,i,x;
	printf("-------------------------------------------------\n");
	printf("-------------------------------------------------\n");
	printf("\n");
	//---------------------------------------------------------------------Getting the ID and check if it's unique
	printf("Enter the Id :");
	scanf("%d",&key);
	ptt=SearchByID(key);
	while(ptt!=NULL)
	{
		printf("ID is Taken,Enter Another ID\n");
		scanf("%d",&key);
		ptt=SearchByID(key);
	}
	ptr=(patient *)malloc(sizeof(patient));
	ptr->id=key;
	//-----------------------------------------------------------------------Continue filling the data of LinkedList
	printf("Enter Your Name's Size : ");
	scanf("%d",&size);
	printf("Enter the name :");
	for(i=0;i<size;i++)
	{
		scanf(" %c",&(ptr->name[i]));

	}
	printf("Enter The Gender [M:Male] or[F:Female]:");
	scanf(" %c",&(ptr->gender));
	printf("Enter the Age  : ");
	scanf("%d",&(ptr->age));	
	//------------------------------------------------------------------------Done getting all the data in the LinkedList
	printf("-------------------------------------------------\n");
	printf("-------------------------------------------------\n");
	printf("\n");
	//-----------------------------------------------------------------------See The Available Slots
	printf("Available Slots Are :\n");
	for(t=0;t<6;t++)
	{
		printf("time is: %d\t",time[t]);
	}
	printf("\n");
	printf("\n");
	printf("-------------------------------------------------\n");
	printf("-------------------------------------------------\n");
	//-----------------------------------------------------------------------See The Reserved Slots
	printf("Reserved Slots Are :\n");
	for(t=0;t<6;t++)
	{
		printf("time is: %d\t",time1[t]);
	}
	printf("\n");
	//-----------------------------------------------------------------------Getting The time of the User in the Reserved slots and Make sure it's reserved and cleared from the Available slots
	printf("Please Enter Your Time\n");
	scanf("%d",&(ptr->mytime));
	x=SearchByTime(ptr->mytime);
	//-----------------------------------------------------------------------says that the time i want to reserve already exist so , i didn't reserve the time at the x==20
	while(x==20)
	{
		printf("Time Is Not Reserved,Enter Another ID \n");
		scanf("%d",&(ptr->mytime));
		x=SearchByTime(ptr->mytime);
	}
	if(head == NULL)	
	{
		head = ptr;
		tail = ptr;
		ptr->next=NULL;
	}
	else
	{
		tail->next=ptr;
		tail=ptr;
		tail->next=NULL;
	}
	//--------------------------------------------------------------Done Getting All The Data 
	printf("\n");
	printf("-------------------------------------------------\n");
	printf("Data Is Reserved Successfully :) \n");
	printf("-------------------------------------------------\n");
}
//--------------------------------------------------------------Search the time taken from user is in reserved slots or not
u8 SearchByTime(u8 NT)
{	
	u8 i=0;
	for(i=0;i<6;i++)
	{
		if(NT==time1[i])
		{
			return 20; // says that the time i want to reserve already exist so i didn't reserve the time
		}
	}	
	//after finishing and find that the time i want to reserve is not reserved , will reserve it now and increment to reserve the next one 
	time1[g]=NT;
	g++;
	for(i=0;i<6;i++)
	{
		if(NT==time[i])
		{
			time[i]=0;
			break;
		}
	}
}
//-------------------------------------------------------------------Make Sure That the ID is Unique
 patient * SearchByID(u8 key)
{	
    patient * ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->id==key)
        {
            return ptr;
        }	
		ptr=ptr->next;
    }
    return NULL;
}
//-------------------------------------------------------------------Getting The Time of The ID Taken From The User
 u8 IDSearch(u8 key)
{	
    u8 y;
	patient * ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->id==key)
        {
            y=ptr->mytime;
			ptr->mytime=0;
			return y;  //the Time i want to delete 
        }	
		ptr=ptr->next;
    }
    return 40 ; //40 here says that the ID doesn't exist 
}
//--------------------------------------------------Delete the time from the reserved slots and put it again in the available slots
void DeleteTime(u8 timee)
{	
	u8 i;
	for(i=0;i<6;i++)
	{
		if(timee==time1[i])
		{
			time1[i]=0;
			break;
		}
	}	
	for(i=0;i<6;i++)
	{
		if(time[i]==0)
		{
			time[i]=timee;
			break;
		}
	}	
}
//-------------------------------------------------Delete the time of the ID entered by user 
u8 DeleteReservation(void)
{
	u8 IDD,u;
	printf("Enter Your ID To Delete Reservation\n");
	scanf("%d",&IDD);
	u=IDSearch(IDD);
	if(u==40)
	{
		return 100; //100 here says that the ID doesn't exist 
	}
	DeleteTime(u);
	printf("\n");
	printf("-------------------------------------------------\n");
	printf("Done Deleting\n");
	printf("-------------------------------------------------\n");
	return 0;// says nothing , but in order to make the whole function u8 instead of void to use this property in line 197
}
//--------------------------------------------------------View all the data of a patient by using his ID
u8 ViewPatientRecord(void)
{
	u8 i,IDD;	
    patient * ptr;
	printf("Enter Your ID To Get Your Data\n");
	scanf("%d",&IDD);
	ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->id==IDD)
        {
			printf("-------------------------------------------------\n");
			printf("-------------------------------------------------\n");		
            printf("Patient ID is : %d\n",ptr->id);
			printf("Patient Name is\n");
			for(i=0;i<5;i++)
			{
				printf("%c",ptr->name[i]);
			}
			printf("\n");
			printf("Patient Gender is : %c\n",ptr->gender);
			printf("Patient Age is : %d\n",ptr->age);
			printf("Patient Time is : %d\n",ptr->mytime);
			printf("-------------------------------------------------\n");
			printf("-------------------------------------------------\n");		
			return 199; // says nothing , but in order to make the whole function u8 instead of void to use this property in line 236
        }	
		ptr=ptr->next;
    }
	return 200;  //200 here says that the ID doesn't exist 
}
//------------------------------------------------------------------Display all the reservations for today 
void DisplayNodes(void)
{
	patient * ptr;
	u8 i=0;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("Patient ID is : %d\n",ptr->id);
		printf("Patient Time is : %d\n",ptr->mytime);
		printf("-------------------------------------------------\n");
		printf("-------------------------------------------------\n");
		printf("\n");
		ptr=ptr->next;
    }
}
//---------------------------------------------------------