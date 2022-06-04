#ifndef ADMIN_H
#define ADMIN_H

#define ADMIN 1
#define USER 2
#define END 3
#define PRINT() printf("\n----------------------------------------------------------------------------------------------------------------\n\n")

#define PASSWORD 1234
#define ADD_PATIENT 1
#define EDIT 2
#define RESERVE 3
#define CANCEL 4
#define EXIT_ADMIN 5

typedef struct patient
{
	uint8 u8name[50];
	uint32 u32age;
	uint8 u8gender[10];
	uint32 u32id;
	uint8 u8slot;
	struct patient *next;
}patient_t;

void Admin(void);
void AddPatient(void);
void Print(uint8 u8index);
void Edit(void);
void Reservation(void);
void Cancel_Reservation(void);

extern patient_t *head;
extern uint8 a, b, c, d, e;

#endif