//header file::
/* This is file containing function prototype, global declarations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"validation.h"

/*creating a structure 
In this structure we are storing two integer data which is for receiver id and receiver age, two long integer for storing the phone number and adhaar number
and four strings for storing receiver bloodgroup, receiver name ,receiver gender,receiver address
*/
typedef struct Receiver_Details
{
    int receiver_id, receiver_age;           //taking integer input
    long int phone_no, adhaar_no;       //taking long integer input
    char receiver_bloodgroup[20], receiver_name[20], receiver_gender[20], receiver_address[20];   // taking string inputs
    
}receiver;      //giving an alternative name to the receiverDetails structure
 





//struct Linkedlist to store receiver details in a node
typedef struct LinkedList
{
    int receiver_id, receiver_age;           //taking integer input
    long int phone_no, adhaar_no;       //taking long integer input
    char receiver_bloodgroup[20], receiver_name[20], receiver_gender[20], receiver_address[20];   // taking string inputs
    struct LinkedList *next; 
}node;


#define ADD 1
#define MODIFY 2
#define DISPLAY 3
#define BACK 4
#define EXIT 5


//This is a function for creating newnode for linkedlist
node* createNode(receiver);


//This is a function to add node to an linkedlist
node* addNode(node *,node *);

//this is a function to generate unique receiver id
int generateid();

//This is a fuction that takes details that are needed to be modified by the user
void enterModifiedData(node *);



//This is function to dispaly menu for the user
void receiver_menu();


//This is a fuction used for entering receiver details data inside our database file
void addreceiverDetails(receiver);


//This is a function to write one record to file
void writeFile(FILE *, receiver);
            


//This is a function to modify receiver details inside our database file
void modifyreceiverDetails(receiver,node *);


//This is a function to display receiver details using receiver_id;
void display(receiver);


//This is a function that is used to display the ID'S of all the receiver
void displayID(node *);

/*

int nameToValidate(char*);*/

