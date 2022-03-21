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
//----------------------------Define The Functions Used
void AppendNode(void);
u8 IDSearch(u8 key1);
void DeleteTime(u8 timee);
u8 DeleteReservation(void);
u8 ViewPatientRecord(void);
void DisplayNodes(void);
//----------------------------Define The Variables

void main(void)
{	
u8 mode,i,MOOD1,h;
u8 MOOD,s;
u32 PW;
	printf("Please Enter You Mode A or U,[A:Admin] or [U:User]\n");
	scanf(" %c",&mode);
	printf("The State is %c\n",mode);
	printf("----------------------------------------\n");
	printf("----------------------------------------\n");
	switch(mode)
	{
		case 'A': //----------------------------Case 1 of Admin Mode 
				printf("Welcome To The Admin Mode :) \n");
				printf("Please Enter Your Password\n");
				for(i=0;i<=2;i++)
				{
					scanf("%d",&PW);
					if(PW==1234)
					{
						while(1)
						{
							printf("-------------------------------------------------\n");
							printf("-------------------------------------------------\n");	
							printf("Add Data : Press 1\n");
							printf("Delete Reservation : Press 2\n");
							printf("To Restart : Press 3\n");
							scanf("%d",&MOOD);
							switch (MOOD)
							{
								case 1:	AppendNode();
										break;
								case 2: s=DeleteReservation();
										if(s==100) //s=100 says that the iD inserted is not correct or doesn't exist
										{
											printf("Enter Your ID Correctly To Delete Reservation\n");
											break;
										}
								case 3: break;
							}
							if(MOOD==3)
							{
								main();
								i=2; //as when leaves whil it don't leave for , so to break system and break for i must enter the else condition , to enter it i must be >= 2 so make it equal 2 to leave the system 
								break; //as after returning from main it leave the while but stays in the for so it will check again about PW
							}
						printf("-------------------------------------------------\n");
						printf("-------------------------------------------------\n");
						}
					}
					else if (PW!=1234&&i<2)
					{
						printf("Wrong Number ,Please Enter Again Your Password");
					}
					else
					{
						printf("System Error");
						break;
					}
				}
			break;
		case 'U'://----------------------------Case 2 Of User Mode
				printf("Welcome To User Mode :) \n");
				printf("-------------------------------------------------\n");
				printf("-------------------------------------------------\n");		
				while(1)
				{		
					printf("View Pateint Record : Press 1\n");
					printf("View Today's Record : Press 2\n");
					printf("To Restart : Press 3\n");
					scanf("%d",&MOOD1);
					switch (MOOD1)
					{
						case 1:	h=ViewPatientRecord();
								if(h==200) //h=200 : says that ID doesn't exist 
								{
									printf("ID Doesn't Exist\n");
								}
								break;
						case 2: DisplayNodes();
								break;
						case 3: break;
					}
					if (MOOD1==3)
					{
						main();
						i=2;
						break;
					}
					printf("-------------------------------------------------\n");
					printf("-------------------------------------------------\n");		
				}		
	}		
}