#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "admin.h"

patient_t *head = NULL;
uint8 a = 0, b = 0, c = 0, d = 0, e = 0;

void Admin()
{
	uint32 u32choice, u32password;
	uint8 u8check, u8pass = 0, u8counter = 0;
	
	while(1)
	{
		printf("Please Enter password: ");
		if(scanf("%d%c", &u32password,&u8check) != 2 || u8check != '\n')
		{
			fgetc(stdin);
			printf("Wrog Password.\n");
			u8counter++;
			if(u8counter >= 3)
			{
				PRINT();
				exit(0);
			}
			continue;
		}
		switch(u32password)
		{
			case PASSWORD:											//default password 1234
			{
				printf("\n||Welcome to admin mode||\n\n");
				u8pass = 1;
				break;
			}
			default:
			{
				printf("Wrong Password.\n");
				u8counter++;
				if(u8counter >= 3)
				{
					PRINT();
					exit(0);
				}
				u8pass = 0;
				break;
			}
		}
		
		if(u8pass == 1)
		{
			break;
		}
	}
	
	while(1)
	{
		printf("1.Add new patient record\n2.Edit patient record.\n3.Reserve a slot.\n4.Cancel reservation.\n5.Exit Admin mode\n");
		printf("\nEnter your choice: ");
		if(scanf("%d%c", &u32choice,&u8check) != 2 || u8check != '\n')
		{
			fgetc(stdin);
			printf("Invalid choice, please enter your choice number\n");
			PRINT();
			return;
		}
		else
		{
			PRINT();
		}
		switch(u32choice)
		{
			case ADD_PATIENT:
			{
				AddPatient();
				break;
			}
			case EDIT:
			{
				Edit();
				break;
			}
			case RESERVE:
			{
				Reservation();
				break;
			}
			case CANCEL:
			{
				Cancel_Reservation();
				break;
			}
			case EXIT_ADMIN:
			{
				return;
			}
			default:
			{
				printf("Invalid Input.\n");
				PRINT();
				break;
			}
		}
	}
}


void AddPatient()
{
	uint32 u32Age, u32ID;
	uint8 u8Name[50], u8Gender[10], u8check;
	patient_t *ptr = head;
	printf("Please Enter Patient informations\n\nName: ");
	fgets(u8Name, 256, stdin);
	u8Name[strlen(u8Name) - 1] = 0;
	printf("Age: ");
	if(scanf("%d%c", &u32Age, &u8check) != 2 || u8check != '\n')
	{
		fgetc(stdin);
		PRINT();
		printf("\nInvalid input, please enter age as number.\n");
		PRINT();
		return;
	}
	printf("Gender: ");
	fgets(u8Gender, 256, stdin);
	u8Gender[strlen(u8Gender) - 1] = 0;
	printf("ID: ");
	if(scanf("%d%c", &u32ID, &u8check) != 2 || u8check != '\n')
	{
		fgetc(stdin);
		PRINT();
		printf("\nInvalid input, please enter ID as number.\n");
		PRINT();
		return;
	}
	
	if(ptr != NULL)
	{
		while(ptr != NULL)
		{
			if(u32ID == ptr->u32id)
			{
				printf("\nThis ID already Exist, rejected entery!\n");
				PRINT();
				return;
			}
			ptr = ptr->next;
		}
	}
	
	patient_t *new_node = (patient_t *) malloc(sizeof(patient_t));
	
	for(uint8 u8iterator = 0; u8iterator < (sizeof(u8Name)/sizeof(uint8)); u8iterator++)
	{
		new_node->u8name[u8iterator] = u8Name[u8iterator];
	}
	
	new_node->u32age	= u32Age;
	
	for(uint8 u8iterator = 0; u8iterator < (sizeof(u8Gender)/sizeof(uint8)); u8iterator++)
	{
		new_node->u8gender[u8iterator] = u8Gender[u8iterator];
	}
	
	new_node->u32id		= u32ID;
	new_node->u8slot  	= ' ';
	new_node->next	 	= NULL;
	ptr = head;
	
	
	if(ptr == NULL)
	{
		head = new_node;
	}
	else
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
	}
	printf("\n**Patient has been added thank you**\n");
	PRINT();
}	


void Print(uint8 u8index)
{
	patient_t *ptr = head;
	
	if(ptr == NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		for(uint32 u32Iterator = 0; u32Iterator < u8index - 1; u32Iterator++)
		{
			ptr = ptr->next;
		}
		printf("Name: %s\n", ptr->u8name);
		printf("Age: %d\n", ptr->u32age);
		printf("Gender: %s\n", ptr->u8gender);
		PRINT();
		}
}

void Edit()
{
	uint32 u32ID, u32Age;
	uint8 u8Name[50], u8Gender[10], u8counter = 0, u8index = 0;
	patient_t *ptr = head;
	
	printf("ID: ");
	scanf("%d", &u32ID);
	
	while(ptr != NULL)
	{
		u8index++;
		if(u32ID == ptr->u32id)
		{
			printf("ID exist.\n\n");
			printf("Patient information.\n\n");
			Print(u8index);
			u8counter++;
			break;
		}
		ptr = ptr->next;
	}
	
	if(u8counter == 0)
	{
		printf("\nID not found!\n");
		PRINT();
		return;
	}
	
	printf("Please Enter Patient new informations\n\nName: ");
	fgetc(stdin);
	fgets(ptr->u8name, 256, stdin);
	ptr->u8name[strlen(ptr->u8name) - 1] = 0;
	printf("Age: ");
	scanf("%d", &ptr->u32age);
	printf("Gender: ");
	fgetc(stdin);
	fgets(ptr->u8gender, 256, stdin);
	ptr->u8gender[strlen(ptr->u8gender) - 1] = 0;
	printf("New patien information.\n");
	Print(u8index);
}

void Reservation()
{
	uint8 u8counter = 0, u8reservation = ' ', u8check;
	uint32 u32ID;
	patient_t *ptr = head;
	
	printf("Slots:\n");
	if(a == 0)
	{
		printf("a. 2pm to 2:30pm\n");
	}
	if(b == 0)
	{
		printf("b. 2:30pm to 3pm\n");
	}
	if(c == 0)
	{
		printf("c. 3pm to 3:30pm\n");
	}
	if(d == 0)
	{
		printf("d. 4pm to 4:30pm\n");
	}
	if(e == 0)
	{
		printf("e. 4:30pm to 5pm\n");
	}
	if((a == 1) && (b == 1) && (c == 1) && (d == 1) && (e == 1))
	{
		printf("No availabe slots!\n");
		PRINT();
		return;
	}
	PRINT();
	printf("Enter Patient ID: ");
	if(scanf("%d%c", &u32ID, &u8check) != 2 || u8check != '\n')
	{
		fgetc(stdin);
		PRINT();
		printf("\nInvalid input, please enter ID as number.\n");
		PRINT();
		return;
	}
	while(ptr != NULL)
	{
		if(u32ID == ptr->u32id)
		{
			switch(ptr->u8slot)
			{
				case 'A':
				case 'a':
				case 'B':
				case 'b':
				case 'C':
				case 'c':
				case 'D':
				case 'd':
				case 'E':
				case 'e':
				{
					printf("\nThis patient has already a reservation!\n");
					PRINT();
					return;
				}
			}
			
			printf("Enter The character of reservation slot: ");
			scanf("%c", &u8reservation);
			if(((u8reservation == 'a'|| u8reservation == 'A') && (a == 1)) || ((u8reservation == 'b'|| u8reservation == 'B') && (b == 1))
			|| ((u8reservation == 'c'|| u8reservation == 'C') && (c == 1)) || ((u8reservation == 'd'|| u8reservation == 'D') && (d == 1))
			|| ((u8reservation == 'e'|| u8reservation == 'E') && (e == 1)))
			{
				printf("\nUnavailable slot, please choose one from the availabe slots.\n");
				PRINT();
				return;
			}
			else if(((u8reservation == 'a'|| u8reservation == 'A') && (a == 0)) || ((u8reservation == 'b'|| u8reservation == 'B') &&
			(b == 0)) || ((u8reservation == 'c'|| u8reservation == 'C') && (c == 0)) || ((u8reservation == 'd'|| u8reservation == 'D')
			&& (d == 0)) || ((u8reservation == 'e'|| u8reservation == 'E') && (e == 0)))
			{
				printf("\n**Slot has been reserved**\n");
				ptr->u8slot = u8reservation;
				PRINT();
			}

			u8counter++;
			break;
		}
		ptr = ptr->next;
	}
	if(u8counter == 0)
	{
		printf("\nIncorrect ID.\n");
		PRINT();
		return;
	}
	
	switch(ptr->u8slot)
	{
		case 'A':
		case 'a':
		{
			a = 1;
			break;
		}
		case 'B':
		case 'b':
		{
			b = 1;
			break;
		}
		case 'C':
		case 'c':
		{
			c = 1;
			break;
		}
		case 'D':
		case 'd':
		{
			d = 1;
			break;
		}
		case 'E':
		case 'e':
		{
			e = 1;
			break;
		}
		default:
		{
			printf("\nInvalid Input!\n");
			PRINT();
			break;
		}
	}
	
}

void Cancel_Reservation()
{
	uint32 u32ID;
	uint8 u8counter = 0;
	patient_t *ptr = head;
	printf("To cancel reservation enter:\n");
	printf("ID: ");
	scanf("%d", &u32ID);
	
	while(ptr != NULL)
		{
			if(u32ID == ptr->u32id)
			{
				if(((ptr->u8slot == 'a'|| ptr->u8slot == 'A') && (a == 1)) || ((ptr->u8slot == 'b'|| ptr->u8slot == 'B') && (b == 1))
					|| ((ptr->u8slot == 'c'|| ptr->u8slot == 'C') && (c == 1)) || ((ptr->u8slot == 'd'|| ptr->u8slot == 'D') &&
					(d == 1))|| ((ptr->u8slot == 'e'|| ptr->u8slot == 'E') && (e == 1)))
				{
					switch(ptr->u8slot)
					{
						case 'A':
						case 'a':
						{
							a = 0;
							ptr->u8slot = ' ';
							printf("\nReservation has been canceled.\n");
							PRINT();
							break;
						}
						case 'B':
						case 'b':
						{
							b = 0;
							ptr->u8slot = ' ';
							printf("\nReservation has been canceled.\n");
							PRINT();
							break;
						}
						case 'C':
						case 'c':
						{
							c = 0;
							ptr->u8slot = ' ';
							printf("\nReservation has been canceled.\n");
							PRINT();
							break;
						}
						case 'D':
						case 'd':
						{
							d = 0;
							ptr->u8slot = ' ';
							printf("\nReservation has been canceled.\n");
							PRINT();
							break;
						}
						case 'E':
						case 'e':
						{
							e = 0;
							ptr->u8slot = ' ';
							printf("\nReservation has been canceled.\n");
							PRINT();
							break;
						}
						default:
						{
							printf("\nInvalid Input!\n");
							PRINT();
							break;
						}
					}	
				}
				else
				{
					printf("\nThis patient doesn't have reservation.\n");
					PRINT();
					return;
				}
				u8counter++;
				break;
			}
			ptr = ptr->next;
		}
		if(u8counter == 0)
		{
			printf("\nIncorrect ID.\n");
			PRINT();
			return;
		}
}
