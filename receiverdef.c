//Definition file::
//This file contains all function definitions
#include"receiver.h" //header file



//this function is responsible for generating a unique consecutive receiverId
int generateid(){

  int receiver_id= 1000;
  FILE *fptr = fopen("receiver_details.txt", "r");
  char c;
  
  c = getc(fptr);
  while(c!= EOF){

    if(c == '\n'){
      receiver_id++;
    }
    
    c=getc(fptr);
  }
  receiver_id++;

  return receiver_id;
 
}//generateid()

//receiver menu function which calls every other functions according to user choice
//return type is void
void receiver_menu()
{
printf("\n\n");
      int choice=0;
      receiver rec;
      node *head = NULL;
     
      //system("clear");
      printf("<--:MENU:-->\n");
      printf("1 : ADD receiver DETAILS\n");
      printf("2 : MODIFY receiver DETAILS\n");
      printf("3 : DISPLAY receiver DETAILS\n");
      printf("4 : BACK TO MAIN MENU\n");
      printf("5 : EXIT\n");
      
      printf("ENTER YOUR CHOICE.\n");
      scanf("%d",&choice);
      switch(choice)
      {
      case ADD:
           addreceiverDetails(rec);
           break;
      case MODIFY:
           modifyreceiverDetails(rec,head);
           break;
      case DISPLAY:
           display(rec);
           break;           
      case BACK:
           receiver_menu(); 
           break;      
      case EXIT:
           exit(0);     
      default:
           printf("INVALID CHOICE");     
          
      }
  
}//receiver_menu()



//creating a newnode for linkedlist with data(values) fetched from parameter rec
node* createNode(receiver rec)
{
      
      node *newnode = (node*)malloc(sizeof(node));
      
      strcpy(newnode->receiver_name, rec.receiver_name);
      newnode->receiver_id = rec.receiver_id;
      strcpy(newnode->receiver_gender, rec.receiver_gender);
      strcpy(newnode->receiver_bloodgroup, rec.receiver_bloodgroup);
      newnode->phone_no = rec.phone_no;
      strcpy(newnode->receiver_address, rec.receiver_address);
      newnode->receiver_age = rec.receiver_age;
      newnode->adhaar_no = rec.adhaar_no;
      newnode->next = NULL;
      
      return newnode;    

}//createNode()



/*adding node to linkedlist containing receiver_details
parameters: *head pointing to the first node of linkedlist , *newnode containing new record fetched from file*/
node* addNode(node *head,node *newnode)
{
      node *temp = head;
      
      //check if linked list is empty
      if(head==NULL)
            head = newnode;
      else
      {
            while(temp->next!=NULL)
                  temp = temp->next;
                  
            temp->next = newnode;      
      }
      return head;
}//addNode



/*
This is a fuction that take structure as an input and its return type is void,
The main use of this fucntion is to add details to an database file "receiver_detail.txt" by taking all the inputs from the user.
*/
void addreceiverDetails(receiver rec)
{
      int i,ch;
      FILE *fptr;    
   
      fptr = fopen("receiver_details.txt","a");    //opens the file in append mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
           printf("\nCannot open file: ");
                exit(0);
      }
      
      int tempreceiverid=0;
      do  //if file succesfully opened then the program start taking input     
      {
      
           printf("\nEnter all required details:\n");    //display statement
                 
           while(getchar()!= '\n');                  
           printf("receiver's Name : ");          //display statement
           scanf("%[^\n]%*c",rec.receiver_name);     //taking user input for receiver name 
           if(nameToValidate(rec.receiver_name)==0){
             receiver_menu();
           }
           //printf("receiver's Id : ");           //display statement
           //scanf("%d",&rec.receiver_id);            //taking user input for receiver id
           
           rec.receiver_id = generateid()+tempreceiverid;
           tempreceiverid++;
           
           
           while(getchar()!= '\n');          
           printf("receiver's gender : ");      //display statement
           scanf("%s",rec.receiver_gender);          //taking user input for receiver gender
                    
           while(getchar()!= '\n');                  
           printf("receiver's bloodgroup  : ");      //display statement
           scanf("%s",rec.receiver_bloodgroup);           //taking user input for receiver bloodgroup
                    
           printf("receiver's Phone No : ");     //display statement
           scanf("%ld",&rec.phone_no);      //taking user input for phone no          
           if(phoneNoToValidate(rec.phone_no)==0){
             receiver_menu();
           }
           
           while(getchar()!= '\n');                  
           printf("receiver's address  : ");      //display statement
           scanf("%s",rec.receiver_address);  
           
           printf("receiver's age : ");     //display statement
           scanf("%d",&rec.receiver_age);      //taking user input for receiver age
           
           printf("receiver's adhaar No : ");     //display statement
           scanf("%ld",&rec.adhaar_no);      //taking user input for adhaar no 
           if(adhaarToValidate(rec.adhaar_no)==0){
             receiver_menu();
           }
           
           //apending new data into the file in next line
           writeFile(fptr,rec);  
          
           printf("if you want to enter more data select\n1=yes\n0=no\n(1/0): ");   //display statement
           scanf("%d",&ch); 
                      //taking user input for yes or no          
          
      }while(ch != 0);  //do while loop ended     
   
      fclose(fptr); //closes the file opened in append mode after work is complete      
      receiver_menu();
     
          
}//addreceiverDetails();



/*This is a function that writes data(values) inside a file,
parameters:It take a FILE pointer and receiver variable */
void writeFile(FILE *fptr,receiver rec)
{
      //apending new data into the file in next line  
      fprintf(fptr,"%s,%d,%s,%s,%ld,%s,%d,%ld\n", rec.receiver_name, rec.receiver_id,rec.receiver_gender,rec.receiver_bloodgroup, rec.phone_no, rec.receiver_address, rec.receiver_age, rec.adhaar_no);   

}//writeFile() 



/*  This is a display function to display all the receiver details in the database file.
This function first opens the file the display all the content line by line present inside the file   */
void display(receiver rec)
{

      FILE *fptr;
     
      fptr = fopen("receiver_details.txt","r");    //opens the file in append mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
             printf("\nCannot open file: ");
                  exit(0);
      }
     
      while(fscanf(fptr,"%[^,],%d,%[^,],%[^,],%ld,%[^,],%d,%ld\n",rec.receiver_name, &rec.receiver_id, rec.receiver_gender, rec.receiver_bloodgroup, &rec.phone_no, rec.receiver_address, &rec.receiver_age, &rec.adhaar_no)  != -1 ) //EOF = -1
      {  
             printf("%s,%d,%s,%s,%ld,%s,%d,%ld\n", rec.receiver_name, rec.receiver_id, rec.receiver_gender, rec.receiver_bloodgroup, rec.phone_no, rec.receiver_address, rec.receiver_age, rec.adhaar_no);
      }
      
     
     
      fclose(fptr);
      receiver_menu();
}//display()



/*This is the function we will be using to modify our data in the list*/
void modifyreceiverDetails(receiver rec,node* head)
{
      FILE *fptr;
      //node *head = NULL;
      node *temp = NULL;
      node *newnode = NULL;
      int id;
      
      fptr = fopen("receiver_details.txt","r");    //opens the file in read mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
             printf("\nCannot open file: ");
                  exit(0);
      }
     
      while(fscanf(fptr,"%[^,],%d,%[^,],%[^,],%ld,%[^,],%d,%ld\n",rec.receiver_name, &rec.receiver_id, rec.receiver_gender, rec.receiver_bloodgroup, &rec.phone_no, rec.receiver_address, &rec.receiver_age, &rec.adhaar_no)  != -1 ) //EOF = -1
      {  
             newnode = createNode(rec);
             head = addNode(head,newnode);
      }
      
      fclose(fptr);
      
      printf("<------ receiver'S ID LIST ------> \n");
      displayID(head);
      printf("CHOOSE WHOSE VALUE YOU WANT TO UPDATE: ");
      scanf("%d",&id);
      
      temp = head;
      if(temp == NULL)
      {
            printf("\n\n\tLinked list is empty.........!!!!!\n");
                 exit(0);
      }           
      else
      {
            while(temp != NULL)
            {
                  if(id == temp->receiver_id)
                  {
                         enterModifiedData(temp);
                         break;
                  }
                  else
                  {
                  temp = temp->next;
                  }
            }
       }
       
       
       
       fptr = fopen("receiver_details.txt","w");
       if(fptr == NULL)                // if no such file exist the this loop enters
       {
            printf("\nCannot open file: ");
                 exit(0);
       }
       temp = head;
      
       if(temp == NULL)
       {
             printf("\n\n\tLinked list is empty.........!!!!!\n");
                  exit(0);
       }
       
       else
       {
             while(temp != NULL)
             {
                   fprintf(fptr,"%s,%d,%s,%s,%ld,%s,%d,%ld\n", temp->receiver_name, temp->receiver_id, temp->receiver_gender, temp->receiver_bloodgroup, temp->phone_no, temp->receiver_address, temp->receiver_age, 
                  temp->adhaar_no);
                   temp=temp->next;  
                   
             }
       }      
       fclose(fptr);
       receiver_menu(); 
}//modifyreceiverDetails()




void enterModifiedData(node *temp)
{
       receiver rec;
       int choice;
       
            printf("PLEASE CHOOSE FROM THE LIST WHICH DATA YOU WANT TO UPDATE\n");
   
       	    printf("1 : NAME\n");
       	    printf("2 : receiver GENDER\n");
            printf("3 : receiver BLOODGROUP\n");
            printf("4 : PHONE NUMBER\n");
            printf("5 : receiver ADDRESS\n");
            printf("6 : receiver AGE\n");
            printf("7 : ADHAAR NUMBER\n");
            printf("8 : BACK TO PREVIOUS MENU\n");
            printf("9 : EXIT\n");
       
            printf("ENTER YOUR CHOICE : ");
            scanf("%d",&choice);
            switch(choice)
            {
            	case 1:
                 	while(getchar()!= '\n');
                 	printf("Current receiver's Name : %s\n",temp->receiver_name);                  
       		 	printf("Update receiver's Name To : ");          //display statement
       		 	scanf("%[^\n]%*c",rec.receiver_name);     //taking user input for receiver name 
       		 	strcpy(temp->receiver_name, rec.receiver_name);
       		 	printf("\n\n\treceiver DATA HAS BEEN UPDATED......\n");
                 	break;
            	case 2:
            	        printf("Current receiver's gender : %s\n",temp->receiver_gender);       
                 	printf("Update receiver's gender To : ");      //display statement
                 	scanf("%s",rec.receiver_gender);          //taking user input for receiver gender
                 	strcpy(temp->receiver_gender, rec.receiver_gender);
                 	printf("\n\n\treceiver DATA HAS BEEN UPDATED......\n");
                	break;
            	case 3: 
            	        printf("Current receiver bloodgroup : %s\n",temp->receiver_bloodgroup);       
                 	while(getchar()!= '\n');                  
                 	printf("Update receiver bloodgroup To : ");      //display statement
                 	scanf("%s",rec.receiver_bloodgroup);           //taking user input for receiver bloodgroup
                 	strcpy(temp->receiver_bloodgroup, rec.receiver_bloodgroup);
                 	printf("\n\n\treceiver DATA HAS BEEN UPDATED......\n");
                 	break;
            	case 4:
            	        printf("Current receiver's Phone Number : %ld\n",temp->phone_no);       
                 	printf("Update receiver's Phone Number To : ");     //display statement
                 	scanf("%ld",&rec.phone_no);      //taking user input for phone no  
                 	temp->phone_no = rec.phone_no;
                 	printf("\n\n\treceiver DATA HAS BEEN UPDATED......\n");
                 	break;
                case 5:
                 	while(getchar()!= '\n');
                 	printf("Old receiver's address  : %s\n",temp->receiver_address);                  
       		 	printf("Update receiver's address To : ");          //display statement
       		 	scanf("%[^\n]%*c",rec.receiver_address);     //taking user input for receiver address
       		 	strcpy(temp->receiver_address, rec.receiver_address);
       		 	printf("\n\n\treceiver DATA HAS BEEN UPDATED......\n");
                 	break; 
                case 6:
            	        printf("Current receiver's age : %d\n",temp->receiver_age);       
                 	printf("Update receiver's age To : ");      //display statement
                 	scanf("%d",&rec.receiver_age);          //taking user input for receiver age
                 	temp->receiver_age = rec.receiver_age;
                 	printf("\n\n\treceiver DATA HAS BEEN UPDATED......\n");
                	break;
                case 7:
            	        printf("Current receiver's Adhaar Number : %ld\n",temp->adhaar_no);       
                 	printf("Update receiver's Adhaar Number To : ");     //display statement
                 	scanf("%ld",&rec.adhaar_no);      //taking user input for adhaar no  
                 	temp->adhaar_no = rec.adhaar_no;
                 	printf("\n\n\treceiver DATA HAS BEEN UPDATED......\n");
                 	break;
            	case 8:
                 	receiver_menu();
                 	break;          
            	case 9:
                	exit(0);              
            	default:
                 	printf("INVALID CHOICE"); 
       		}   
                           
}//enterModifiedData()



//This function will list all the receiver id registered in the database.
void displayID(node *head)
{ 
      node *temp = head;
      if(temp == NULL)
      {
            printf("\n\n\tNO DATA TO DISPLAY\n");
                 exit(0);
      }
      else
      {
            while(temp != NULL)
            {
                  printf("%d\n",temp->receiver_id);
                  temp = temp->next;
            }
      }
                        
}
//displayID()




