//header file::
/* This is file containing function prototype, global declarations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"validation.h"




/*creating a structure 
In this structure we are storing one integer data which is for hospital id, one long interger for storing the phone number
and two strings for storing , hospital name , hospital address
*/
typedef struct hospitalDetails
{
    int hospital_id;           //taking integer input
    long int phone_no;       //taking long integer input
    char address[50], hospital_name[20];
}h_details;      //giving an alternative name to the ownerDetails structure
 





//struct Linkedlist to store hospital details in a node
typedef struct LinkedList
{
    int hospital_id;           //taking integer input
    long int phone_no;       //taking long integer input
    char address[50], hospital_name[20];   // taking string inputs
    struct LinkedList *next; 
}node;



#define ADD 1
#define MODIFY 2
#define DELETE 3
#define DISPLAY 4
#define BACK 5
#define EXIT 6



int generateid();


//This is a function for creating newnode for linkedlist
node* createNode(h_details);


//This is a function to add node to an linkedlist
node* addNode(node *,node *);


//This is a fuction that takes details that are needed to be modified by the user
void enterModifiedData(node *);






//This is fucntion to dispaly menu for the user
void hospital_menu();


//This is a fuction used for entering  hospital details data inside our database file
void addHospitalDetails(h_details);


//This is a function to write one record to file
void writeFile(FILE *, h_details);
            
 
//This is a function to delete hospital details inside our database file
void deleteHospitalDetails(h_details,node *);


//This is a function to modify hospital details inside our database file
void modifyHospitalDetails(h_details,node *);


//This is a function to display  hospital details using hospital_id;
void display(h_details);


//This is a function that is used to display the ID'S of all the owners
void displayID(node *);
