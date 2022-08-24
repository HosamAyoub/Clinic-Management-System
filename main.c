#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LIB/STD_TYPES.h"
#include "Admin/admin.h"
#include "User/user.h"

void main(void)
{
	uint32 u32mode;
	uint8 u8check;
	
	while(1)
	{
		printf("\nModes:\n1.Admin.			2.User.			3.Close Program.\n\nEnter your choice: ");
		
		if(scanf("%d%c", &u32mode,&u8check) != 2 || u8check != '\n')
		{
			fgetc(stdin);
			PRINT();
			printf("\nInvalid choice, please enter your mode number\n");
			PRINT();
			continue;
		}
		PRINT();
		switch(u32mode)
		{
			case ADMIN:
			{
				Admin();
				break;
			}
			case USER:
			{
				User();
				break;
			}
			case END:
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