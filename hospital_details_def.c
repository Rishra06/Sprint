//Definition file::
//This file contains all function definitions


#include"hospital_details.h"     //header file
#include"validation.h"

int generateid()
{

	int hospital_id = 4000;
	FILE *fptr = fopen("hospital_details.txt","r");
	char c;
	
	c=getc(fptr);
	while(c!=EOF)
	{
	   if(c == '\n')
	   {
	      hospital_id++;
	    }
	    
	   c = getc(fptr);
	   
	 }
	 
	 hospital_id++;
	 
	 return hospital_id;
	 
}

/*hospital menu function which display different types of menu and then choose 
one menu as per required and after that call any function as per required and perform
some operation
*/


void hospital_menu()
{
  
      int choice=0;
      h_details hd;
      node *head = NULL;
     
      
      printf("<----------:MENU:--------->\n");
      printf("1 : ADD HOSPITAL DETAILS\n");
      printf("2 : MODIFY HOSPITAL DETAILS\n");
      printf("3 : DELETE HOSPITAL DETAILS\n");
      printf("4 : DISPLAY HOSPITAL DETAILS\n");
      printf("5 : BACK TO MAIN MENU\n");
      printf("6 : EXIT\n");
      
      printf("ENTER YOUR CHOICE.\n");
      scanf("%d",&choice);
      switch(choice)
      {
      case ADD:
           addHospitalDetails(hd);
           break;
      case MODIFY:
           modifyHospitalDetails(hd,head);
           break;
      case DELETE:
           deleteHospitalDetails(hd,head);
           break;           
      case DISPLAY:
           display(hd);
           break;
      case BACK:
           hospital_menu();           
      case EXIT:
            exit(0);   
      default:
           printf("INVALID CHOICE");     
          
      }
  
}//hospital_menu()







//creating a newnode for linkedlist with data(values) fetched from parameter hd
node* createNode(h_details hd)
{
      
      node *newnode = (node*)malloc(sizeof(node));
      
      strcpy(newnode->hospital_name, hd.hospital_name);
      newnode->hospital_id = hd.hospital_id;
      strcpy(newnode->address, hd.address);
      newnode->phone_no = hd.phone_no;
      newnode->next = NULL;
      
      return newnode;    

}//createNode()






/*adding node to linkedlist containing hospital_details
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
This is fuction that take structre as an input and its return type is void,
The main use of this fucntion is to add details to an database file "hospital_detail.txt" by taking all the inputs from the user.
*/
void addHospitalDetails(h_details hd)
{
      int i,ch;
      FILE *fptr;    
   
      fptr = fopen("hospital_details.txt","a");    //opens the file in append mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
           printf("\nCannot open file: ");
                exit(0);
      }
      
      int temphospitalid= 0;
   
      do  //if file succesfully opened then the program start taking input     
      {
      
           printf("Enter all required details:\n");    //display statement
                 
           while(getchar()!= '\n');                  
           printf("Hospital's Name : ");                //display statement
           scanf("%[^\n]%*c",hd.hospital_name);     //taking user input for hospital name 
           
           if(nameToValidate(hd.hospital_name)==0){
              hospital_menu();
              }
           
           
           hd.hospital_id = generateid()+ temphospitalid;
           temphospitalid++;
                 
                    
           printf("Hospital's Phone No : ");        //display statement
           scanf("%ld",&hd.phone_no);          //taking user input for phone no   
           
           if(phoneNoToValidate(hd.phone_no)==0){
              hospital_menu();
              }  
           
            while(getchar()!= '\n');                  
           printf("Hospital's Address : ");      //display statement
           scanf("%s",hd.address);           //taking user input for address
           
                
          
           //apending new data into the file in next line
           writeFile(fptr,hd);  
           
           printf("\nhospital data successsfully entered\n");
          
           printf("if you want to enter more data select\n1=yes\n0=no\n(1/0): ");   //display statement
           scanf("%d",&ch);            //taking user input for yes or no     
           hospital_menu();     
          
      }while(ch != 0);  //do while loop ended     
      
     
   
      fclose(fptr); //closes the file opened in append mode after work is complete      
      
      
      
      hospital_menu();
          
}//addHospitalDetails();






/*This is a function that writes data(values) inside a file,
parameters:It take a FILE pointer and h_details variable */
void writeFile(FILE *fptr,h_details hd)
{
      //apending new data into the file in next line  
      fprintf(fptr,"%s,%d,%s,%ld\n", hd.hospital_name, hd.hospital_id,  hd.address, hd.phone_no);   

}//writeFile()






/*  This is a display function to display all the owner details in the database file.
This function firt opens the file the display all the content line by line present inside the file   */
void display(h_details hd)
{

      FILE *fptr;
     
      fptr = fopen("hospital_details.txt","r");    //opens the file in append mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
             printf("\nCannot open file: ");
                  exit(0);
      }
     
      while(fscanf(fptr,"%[^,],%d,%[^,],%ld\n",hd.hospital_name, &hd.hospital_id, hd.address, &hd.phone_no)  != -1 ) //EOF = -1
      {  
             printf("%s,%d,%s,%ld\n", hd.hospital_name, hd.hospital_id,  hd.address, hd.phone_no);
      }
      
      
      fclose(fptr);
        
}//display()





/*This is the function we will be using to modify our data in the list*/
void modifyHospitalDetails(h_details hd,node* head)
{
      FILE *fptr;
      //node *head = NULL;
      node *temp = NULL;
      node *newnode = NULL;
      int id;
      
      fptr = fopen("hospital_details.txt","r");    //opens the file in read mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
             printf("\nCannot open file: ");
                  exit(0);
      }
     
      while(fscanf(fptr,"%[^,],%d,%[^,],%ld\n",hd.hospital_name, &hd.hospital_id, hd.address, &hd.phone_no)  != -1 ) //EOF = -1
      {  
             newnode = createNode(hd);
             head = addNode(head,newnode);
      }
      
      fclose(fptr);
      
      printf("<------ HOSPITAL'S ID LIST ------> \n");
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
                  if(id == temp->hospital_id)
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
       
       
       
       fptr = fopen("hospital_details.txt","w");
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
                   fprintf(fptr,"%s,%d,%s,%ld\n", temp->hospital_name, temp->hospital_id,  temp->address, temp->phone_no);
                   temp=temp->next;   
             }
       }      
       fclose(fptr);
       hospital_menu();
              
}//modifyHospitalDetails()





//This is a function to delete data from the database list of hospital_details
void deleteHospitalDetails(h_details hd,node *head)
{
      FILE *fptr;
      node *temp = NULL, *tag = NULL, *newnode = NULL;
      int id;
      
      fptr = fopen("hospital_details.txt","r");    //opens the file in read mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
             printf("\nCannot open file: ");
                  exit(0);
      }
     
      while(fscanf(fptr,"%[^,],%d,%[^,],%ld\n",hd.hospital_name, &hd.hospital_id,  hd.address, &hd.phone_no)  != -1 ) //EOF = -1
      {  
             newnode = createNode(hd);
             head = addNode(head,newnode);
      }
      
      fclose(fptr);
      
      
      printf("<------ HOSPITAL'S ID LIST ------> \n");
      displayID(head);
      printf("CHOOSE WHOSE RECORDS YOU WANT TO DELETE : ");
      scanf("%d",&id);
      
      tag = temp;
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
                  if(id == temp->hospital_id)
                  {
                     if(temp == head)
                     {
                           head = temp->next;
                           free(temp);
                           break;
                     }
                     else
                     {
                           tag->next = temp->next;
                           free(temp);
                           break;
                     }         
                  }
                  else
                  {
                  tag = temp;
                  temp = temp->next;
                  }
            }
       }
       
       
       fptr = fopen("hospital_details.txt","w");
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
                   fprintf(fptr,"%s,%d,%s,%ld\n", temp->hospital_name, temp->hospital_id,  temp->address, temp->phone_no);
                   temp=temp->next;   
             }
       }      
       fclose(fptr);
      
       
}//deleteHospitalDetails() 







void enterModifiedData(node *temp)
{
       h_details hd;
       int choice;
       
            printf("PLEASE CHOOSE FROM THE LIST WHICH DATA YOU WANT TO UPDATE\n");
   
       	    printf("1 : NAME\n");
            printf("2 : ADDRESS\n");
            printf("3 : PHONE NUMBER\n");
            printf("4 : BACK TO PREVIOUS MENU\n");
            printf("5 : EXIT\n");
       
            printf("ENTER YOUR CHOICE : ");
            scanf("%d",&choice);
            switch(choice)
            {
            	case 1:
                 	while(getchar()!= '\n');
                 	printf("Current Hospital's Name : %s\n",temp->hospital_name);                  
       		 	printf("Update Hospital's Name To : ");          //display statement
       		 	scanf("%[^\n]%*c",hd.hospital_name);     //taking user input for owner name 
       		 	strcpy(temp->hospital_name, hd.hospital_name);
       		 	printf("\n\n\tHOSPITAL'S NAME HAS BEEN UPDATED......\n");
                 	break;
            	
            	case 2: 
            		while(getchar()!= '\n');
            	        printf("Old Hospital's Address : %s\n",temp->address);       
                 	while(getchar()!= '\n');                  
                 	printf("Update Hospital's Address To : ");      //display statement
                 	scanf("%[^\n]%*c",hd.address);           //taking user input for email id
                 	strcpy(temp->address, hd.address);
                 	printf("\n\n\tHOSPITAL'S ADDRESS HAS BEEN UPDATED......\n");
                 	break;
            	case 3:
            	        printf("Current Hospital's Phone Number : %ld\n",temp->phone_no);       
                 	printf("Update Hospital's Phone Number To : ");     //display statement
                 	scanf("%ld",&hd.phone_no);      //taking user input for phone no  
                 	temp->phone_no = hd.phone_no;
                 	printf("\n\n\tHOSPITAL'S PHONE NO HAS BEEN UPDATED......\n");
                 	break;
            	case 4:
                 	hospital_menu();
                 	break;          
            	case 5:
                	exit(0);              
            	default:
                 	printf("INVALID CHOICE"); 
       		}   
                           
}//enterModifiedData()






//This function will list all the hospital names registered in the database.
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
                  printf("%d\n",temp->hospital_id);
                  temp = temp->next;
            }
      }
                        
}//displayID()
























