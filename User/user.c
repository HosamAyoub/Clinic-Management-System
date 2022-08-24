#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../LIB/STD_TYPES.h"
#include "../Admin/admin.h"
#include "user.h"

void User()
{
	uint32 u32option;
	uint8 u8check;
	
	printf("\n||Welcome to user mode||\n\n");
	
	while(1)
	{
		printf("1.View Patient record.			2.View today's reservations.		3.Exit user mode.\n");
		printf("\nTo choose option write its number: ");
		if(scanf("%d%c", &u32option,&u8check) != 2 || u8check != '\n')
		{
			fgetc(stdin);
			PRINT();
			printf("\nInvalid choice, please enter your choice number\n");
			PRINT();
			return;
		}
		
		switch(u32option)
		{
			case PATIENT_RECORED:
			{
				PatientRecord();
				break;
			}
			case TODAY_RESERVATION:
			{
				TodayReservation();
				break;
			}
			case EXIT_USER:
			{
				PRINT();
				return;
			}
			default:
			{
				printf("\nInvalid input!\n");
				PRINT();
				break;
			}
		}
	}
}

void PatientRecord()
{
	uint32 u32ID;
	uint8 u8index = 0, u8counter = 0;
	patient_t *ptr = head;
	
	printf("ID: ");
	scanf("%d", &u32ID);
	
	while(ptr != NULL)
	{
		u8index++;
		if(u32ID == ptr->u32id)
		{
			printf("\n");
			Print(u8index);
			u8counter++;
			break;
		}
		ptr = ptr->next;
	}
	
	if(u8counter == 0)
	{
		printf("\nID not found!\nMake sure you have recorded this ID.\n");
		PRINT();
		return;
	}
}

void TodayReservation()
{
	patient_t *ptr = head;
	
	printf("\nReserved slots:\n\n");
	while(ptr != NULL)
	{
		if((a == 1) && ((ptr->u8slot == 'a') || (ptr->u8slot == 'A')))
		{
			printf("2pm to 2:30pm	||	ID: ");
			printf("%d\n", ptr->u32id);
			PRINT();
		}
		if((b == 1) && ((ptr->u8slot == 'b') || (ptr->u8slot == 'B')))
		{
			printf("2:30pm to 3pm	||	ID: ");
			printf("%d\n", ptr->u32id);
			PRINT();
		}
		if((c == 1) && ((ptr->u8slot == 'c') || (ptr->u8slot == 'C')))
		{
			printf("3pm to 3:30pm	||	ID: ");
			printf("%d\n", ptr->u32id);
			PRINT();
		}
		if((d == 1) && ((ptr->u8slot == 'd') || (ptr->u8slot == 'D')))
		{
			printf("4pm to 4:30pm	||	ID: ");
			printf("%d\n", ptr->u32id);
			PRINT();
		}
		if((e == 1) && ((ptr->u8slot == 'e') || (ptr->u8slot == 'E')))
		{
			printf("4:30pm to 5pm	||	ID: ");
			printf("%d\n", ptr->u32id);
			PRINT();
		}
		ptr = ptr->next;
	}
	if((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0))
	{
		printf("No Reserved slots.\n");
		PRINT();
	}
}