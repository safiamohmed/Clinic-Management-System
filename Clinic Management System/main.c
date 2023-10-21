#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_patients 100
#define max_reservations 10
#define pass 1234

int num_Patients = 0;
int num_Reserv = 0;

typedef struct
{
    char name[100];
    int age;
    char gender[10];
    int id;
} Patient;

typedef struct
{
    int slot;
    int patientId;
} Reservation;

Patient patients[max_patients];
Reservation reservations[max_reservations];
/*---------------------*/
void intro()
{
    printf("\n");
    printf("Clinic Management System\n");
    printf("------------------------\n");
    printf("1. Admin Mode\n");
    printf("2. User Mode\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}
/*---------------------*/
void admin_mode()
{
    printf("\n");
    printf("Admin Mode\n");
    printf("-----------\n");
    printf("1. Add new patient record\n");
    printf("2. Edit patient record\n");
    printf("3. Reserve a slot with the doctor\n");
    printf("4. Cancel reservation\n");
    printf("5. Logout\n");
    printf("Enter your choice: ");


}
/*---------------------*/
void user_admin()
{

    printf("\nUser Mode\n");
    printf("----------\n");
    printf("1. View patient record\n");
    printf("2. View today's reservations\n");
    printf("3. Logout\n");
    printf("Enter your choice: ");
}
/*---------------------*/
void addNewPatient()
{
    Patient patient;
    int Flag=0;

    printf("Enter name: ");
    scanf("%s", patient.name);
    //strcpy(patient.name,"safia");
    printf("Enter age: ");
    scanf("%d", &patient.age);

    printf("Enter gender: ");
    scanf("%s", patient.gender);

    printf("Enter ID: ");
    scanf("%d", &patient.id);


    for (int i = 0; i < num_Patients; i++)
    {
        if (patients[i].id == patient.id)
        {
            printf("ID already exists\n");
            Flag=1;

        }
    }
    if(Flag!=1)
    {

        patients[num_Patients] = patient;
        num_Patients++;
        printf("Patient record added successfully\n");
    }
    else
    {

    }
}
/*---------------------*/
void edit_PatientRecord()
{
    int id, Flag = 0;

    printf("Enter patient ID: ");
    scanf("%d", &id);

    for (int i = 0; i < num_Patients; i++)
    {
        if (patients[i].id == id)
        {
            printf("Enter new name: ");
            scanf("%s", patients[i].name);

            printf("Enter new age: ");
            scanf("%d", &patients[i].age);

            printf("Enter new gender: ");
            scanf("%s", patients[i].gender);

            Flag = 1;
            break;
        }
    }

    if (Flag!=1)
    {
        printf("Incorrect ID\n");
    }
    else
    {
        printf("Patient record edit successfully\n");
    }
}
/*---------------------*/
void reserve_Slot()
{
    int id, slot;

    printf("Enter patient ID: ");
    scanf("%d", &id);


    int Flag = 0;
    for (int i = 0; i < num_Patients; i++)
    {
        if (patients[i].id == id)
        {
            Flag = 1;
            break;
        }
    }

    if (Flag!=1)
    {
        printf("Incorrect ID\n");
    }
    else
    {
        Flag=0;
        static int choise=0;
        if(choise==0){
        printf("Available slots:\n");
        printf("1. 2pm to 2:30pm\n");
        printf("2. 2:30pm to 3pm\n");
        printf("3. 3pm to 3:30pm\n");
        printf("4. 4pm to 4:30pm\n");
        printf("5. 4:30pm to 5pm\n");
        printf("Enter slot number: ");
        }
         if(choise==1){
        printf("Available slots:\n");
        printf("1. reseve\n");
        printf("2. 2:30pm to 3pm\n");
        printf("3. 3pm to 3:30pm\n");
        printf("4. 4pm to 4:30pm\n");
        printf("5. 4:30pm to 5pm\n");
        printf("Enter slot number: ");

    }
    else if(choise==2){
        printf("Available slots:\n");
        printf("1. 2pm to 2:30pm\n");
        printf("2. reseve\n");
        printf("3. 3pm to 3:30pm\n");
        printf("4. 4pm to 4:30pm\n");
        printf("5. 4:30pm to 5pm\n");
        printf("Enter slot number: ");

    }else if(choise==3){
        printf("Available slots:\n");
        printf("1. 2pm to 2:30pm\n");
        printf("2. 2:30pm to 3pm\n");
        printf("3. reseve\n");
        printf("4. 4pm to 4:30pm\n");
        printf("5. 4:30pm to 5pm\n");
        printf("Enter slot number: ");

    } else if(choise==4){
        printf("Available slots:\n");
        printf("1. 2pm to 2:30pm\n");
        printf("2. 2:30pm to 3pm\n");
        printf("3. 3pm to 3:30pm\n");
        printf("4. reseve\n");
        printf("5. 4:30pm to 5pm\n");
        printf("Enter slot number: ");

    }else if(choise==5){
        printf("Available slots:\n");
        printf("1. 2pm to 2:30pm\n");
        printf("2. 2:30pm to 3pm\n");
        printf("3. 3pm to 3:30pm\n");
        printf("4. 4pm to 4:30pm\n");
        printf("5. reseve");
        printf("Enter slot number: ");

    }
         scanf("%d", &slot);
        if(slot>=1 &&slot<=5)
        {


            for (int i = 0; i < num_Reserv; i++)
            {
                if (reservations[i].slot == slot)
                {
                    printf("Slot already reserved\n");
                    Flag=1;

                }
            }
            if(Flag!=1)
            {
                reservations[num_Reserv].slot = slot;
                reservations[num_Reserv].patientId = id;
                num_Reserv++;

                printf("Slot reserved successfully\n");
                if(slot==1)
                {
                    choise=1;

                }
                else if(slot==2)
                {
                    choise=2;

                }else if(slot==3)
                {
                    choise=3;

                }else if(slot==4)
                {
                    choise=4;

                }else if(slot==5)
                {
                    choise=5;

                }


            }
            else {}
        }
        else
        {
            printf("\n-----WARNING-----\n");
            printf("Invalid slot");
        }
    }

}

void cancel_Reservation()
{
    int id;

    printf("Enter patient ID: ");
    scanf("%d", &id);

    int Flag = 0;
    for (int i = 0; i < num_Patients; i++)
    {
        if (patients[i].id == id)
        {
            Flag = 1;
            break;
        }
    }

    if (Flag!=1)
    {
        printf("\n-----WARNING-----\n");
        printf("Incorrect ID\n");

    }
    else
    {

        Flag = 0;
        for (int i = 0; i < num_Reserv; i++)
        {
            if (reservations[i].patientId == id)
            {
                reservations[i].patientId = 0;
                reservations[i].slot = 0;

                Flag = 1;
                break;
            }
        }

        if (Flag!=1)
        {
            printf("Not found for the patient\n");
        }
        else
        {
            printf("canceled successfully\n");
        }
    }
}

void view_PatientRecord()
{
    int id;

    printf("Enter patient ID: ");
    scanf("%d", &id);


    int Flag = 0;
    for (int i = 0; i < num_Patients; i++)
    {
        if (patients[i].id == id)
        {
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %s\n", patients[i].gender);
            Flag = 1;
            break;
        }
    }

    if (Flag!=1)
    {
        printf("Incorrect ID\n");
    }
}

void view_Reservations()
{
    printf("the reservations in today:\n");

    for (int i = 0; i < num_Reserv; i++)
    {
        if (reservations[i].patientId != 0)
        {
            printf("Slot: %d   Patient ID: %d\n", reservations[i].slot, reservations[i].patientId);
        }
    }
}
int main()
{
    int choice, password_repeat = 0;

    while (1)
    {
        intro();
        scanf("%d", &choice);
        if (choice == 1)
        {
            int password;
            printf("Enter password: ");
            scanf("%d", &password);

            if (password == pass)
            {
                int adminChoice;

                while (1)
                {
                    admin_mode();
                    scanf("%d", &adminChoice);

                    switch (adminChoice)
                    {
                    case 1:
                        addNewPatient();
                        break;
                    case 2:
                        edit_PatientRecord();
                        break;
                    case 3:
                        reserve_Slot();
                        break;
                    case 4:
                        cancel_Reservation();
                        break;
                    case 5:
                        break;
                    default:
                        printf("\n-----WARNING-----\n");
                        printf("Invalid choice\n");
                        break;
                    }

                    if (adminChoice == 5)
                    {
                        break;
                    }
                    else
                    {
                    }
                }
            }
           else
            {
                password_repeat++;

                if (password_repeat >= 3)
                {
                    printf("Sorry,your entered password was incorrect for 3 consecutive times.\n");
                    break;
                }
                else
                {
                    printf("\n-----WARNING-----\n");
                    printf("Incorrect password. Please try again.\n");
                }
            }
        }
        else if (choice == 2)
        {
            int userChoice;

            while (1)
            {
                user_admin();
                scanf("%d", &userChoice);

                switch (userChoice)
                {
                case 1:
                    view_PatientRecord();
                    break;
                case 2:
                    view_Reservations();
                    break;
                case 3:
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
                }

                if (userChoice == 3)
                {
                    break;
                }
            }
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("\n-----WARNING-----\n");
            printf("Invalid choice.\nplease enter another choice from 1 to 3\n");
        }
    }

    return 0;
}
