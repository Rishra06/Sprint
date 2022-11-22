//Blood Bank Management System (Sprint)
//Header-file

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//This is the structure to store AdminDetails.
typedef struct Admin_Details
{   
    char admin_emailId[50];
    char admin_password[20];
    
}Admin;



//This is the structure to store DonorDetails.
typedef struct Donor_Details
{
    char donor_emailId[50];
    char donor_password[20];
    
}Donor;



//struct LinkedList to store donor details in a node
typedef struct Donor_DetailsLL
{
    char donor_emailId[50];
    char donor_password[20];
    struct Donor_DetailsLL *next;
    
}Dnode;



//This is the structure to store ReceiverDetails.
typedef struct Receiver_Details
{
    char receiver_emailId[50];
    char receiver_password[20];
    
}Receiver;



//struct LinkedList to store receiver details in a node
typedef struct Receiver_DetailsLL
{
    char receiver_emailId[50];
    char receiver_password[20];
    struct Receiver_DetailsLL *next;
    
}Rnode;



//This is the structure to store HospitalDetails.
typedef struct Hospital_Details
{
    char hospital_emailId[50];
    char hospital_password[20];
    
}Hospital;



//struct LinkedList to store hospital details in a node
typedef struct Hospital_DetailsLL
{
    char hospital_emailId[50];
    char hospital_password[20];
    struct Hospital_DetailsLL *next;
    
}Hnode;



//defining MACROS

#define ADMIN 1
#define DONOR 2
#define RECEIVER 3
#define HOSPITAL 4
#define EXIT 0
#define REGISTER 5
#define LOGIN 6
#define BACK 7
#define ADD_DONOR 11
#define DELETE_DONOR 12
#define UPDATE_DONOR 13
#define ADD_RECEIVER 14
#define DELETE_RECEIVER 15
#define UPDATE_RECEIVER 16
#define ADD_HOSPITAL 17
#define DELETE_HOSPITAL 18
#define UPDATE_HOSPITAL 19



//This function is used for registration purpose for Donor.
void donor_registration(Donor);    

//This function is used to for registration purpose for Beneficiary.
void receiver_registration(Receiver);
    
//This function is used for registration purpose for Hospital.
void hospital_registration(Hospital);     


//This function is used for login purpose for Admin.
void admin_login(Admin);    

//This function is used for login purpose for Donor.
void donor_login(Donor); 

//This function is used for login purpose for Beneficiary.
void receiver_login(Receiver);  

//This function is used for login purpose for Hospital.
void hospital_login(Hospital);

//This function is used for displaying the Main Menu.
int displayMainMenu();

//This function is used for displaying the Sub Menu.
int displaySubMenu();

//This function is used for selecting the choice.
void getChoice(int);

//This function is used for displaying the Admin Menu.
void adminMenu();

//This is a function for creating newnode for Donor linkedlist.
Dnode* D_createNode(Donor);

//This is a function to add node to the Donor linkedlist.
Dnode* D_addNode(Dnode*,Dnode*);

//This is a function for creating newnode for Receiver linkedlist.
Rnode* R_createNode(Receiver);

//This is a function to add node to the Receiver linkedlist.
Rnode* R_addNode(Rnode*,Rnode*);

//This is a function for creating newnode for Hospital linkedlist.
Hnode* H_createNode(Hospital);

//This is a function to add node to the Hospital linkedlist.
Hnode* H_addNode(Hnode*,Hnode*);
