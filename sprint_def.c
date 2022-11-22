//Definition File::
//This file contains all the function definitions


#include"sprint.h" //including header-file
#include"validation.h"

/*This is the function definition to display the Main Menu
  Without parameters and return type is integer*/
  
int displayMainMenu()
{
       int option1;   //declaring integer variable inorder to choose the appropriate option.
       //system("clear");
       printf("\n\n---------------------MAIN MENU-----------------------");
       printf("\n\t1::ADMIN\
               \n\t2::DONOR\
               \n\t3::RECEIVER\
               \n\t4::HOSPITAL\
               \n\t0::EXIT");
               
       printf("\n\tEnter Your Choice:: ");
       scanf("%d",&option1);
       
       return option1;
}//displayMainMenu



/*This is the function definition to display the Sub Menu
  Without parameters and return type is integer*/
  
int displaySubMenu()
{
       int option2;   //declaring integer variable inorder to choose the appropriate option.
       //system("clear");
       printf("\n\n---------------------SUB MENU-----------------------");
       printf("\n\t5::REGISTER\
               \n\t6::LOGIN\
               \n\t7::Back To Main Menu");
               
       printf("\n\tEnter Your Choice:: ");
       scanf("%d",&option2);
       
       return option2;
}//displaySubMenu



/*This is the function definition to get the choice from the user to choose the appropriate option
  With parameters of integer type and return type is void*/
void getChoice(int option1)
{
      int option2;
      Admin admin;
      Donor donor;
      Receiver receiver;
      Hospital hospital;
      option1=displayMainMenu();
      do{
           //option1=displayMainMenu();
           
           switch(option1)
           {
                  case ADMIN:  
                               do
                               {
                                   option2=displaySubMenu();
                                   
                                     switch(option2)
                                     {
                                        
                                            case LOGIN:
                                                         admin_login(admin); 
                                                         exit(0); 
                                             case BACK:
                                                         displayMainMenu();
                                                         
                                     }//switch
                               }while(option2!=7);
                               
                               break;
                               
                 case DONOR:
                               do
                               {
                                   option2=displaySubMenu();
                               
                                     switch(option2)
                                     {
                                         case REGISTER:
                                                         donor_registration(donor);
                                                         break;
                                            case LOGIN: 
                                                         donor_login(donor); 
                                                         exit(0); 
                                             case BACK: 
                                                         displayMainMenu();
                                                         exit(0); 
                                     }//switch
                               }while(option2!=7);
                               
                               break;
                               
             case RECEIVER:
                               do
                               {
                                   option2=displaySubMenu();
                               
                                     switch(option2)
                                     {
                                         case REGISTER:
                                                         receiver_registration(receiver);
                                                         break;
                                            case LOGIN:  
                                                         receiver_login(receiver); 
                                                         exit(0); 
                                             case BACK:  
                                                         displayMainMenu();
                                                         exit(0); 
                                     }//switch
                               }while(option2!=7);
                               
                               break;
                               
               case HOSPITAL:
                               do
                               {
                                   option2=displaySubMenu();
                               
                                     switch(option2)
                                     {
                                         case REGISTER:
                                                         hospital_registration(hospital);
                                                         break; 
                                            case LOGIN:  
                                                         hospital_login(hospital); 
                                                         exit(0); 
                                             case BACK:  
                                                         displayMainMenu();
                                                         exit(0); 
                                     }//switch 
                               }while(option2!=7);
                               
                               break;
                               
                  case EXIT:
                              exit(0);
           
           }//switch
        
        }while(option1!=0);
}//getChoice



/*This is the function definition to display the Admin Menu
  Without parameters and return type is void*/
void adminMenu()
{
     int ch;
     printf("\n\n---------------------ADMIN MENU-----------------------");
     printf("\n\t11::ADD DONOR DETAILS\
             \n\t12::DELETE DONOR DETAILS\
             \n\t13::UPDATE DONOR DETAILS\
             \n\t14::ADD RECEIVER DETAILS\
             \n\t15::DELETE RECEIVER DETAILS\
             \n\t16::UPDATE RECEIVER DETAILS\
             \n\t17::ADD HOSPITAL DETAILS\
             \n\t18::DELETE HOSPITAL DETAILS\
             \n\t19::UPDATE HOSPITAL DETAILS\
             \n\t0::EXIT");
             
     printf("\nPlease Choose Your Option:: ");
     scanf("%d",&ch);
     do
     {
          switch(ch)
         {
               case ADD_DONOR:
               case DELETE_DONOR:
               case UPDATE_DONOR:
               case ADD_RECEIVER:
               case DELETE_RECEIVER:
               case UPDATE_RECEIVER:
               case ADD_HOSPITAL:
               case DELETE_HOSPITAL:
               case UPDATE_HOSPITAL:
               case EXIT:
                           exit(0);
          }
     }while(ch!=0);
     
}//adminMenu



/*This is the function used for login purpose of Admin.
 This function takes the parameters of structure type
 to display details and return type is void
*/

void admin_login(Admin admin) //parameter is of structure type and return type is void
{
    
    FILE *fptr;  //declaring file pointer
    char emailId[50],pword[20];
    int usrFound=0;
    
     printf("\nEnter Admin Email Id :: ");
     while(getchar()!='\n');   //user defined logic to replace fflush()
     fgets(emailId,50,stdin);
     emailId[strlen(emailId)-1]='\0';
     if(emailToValidate(admin.admin_emailId) == 0)
     {
              displayMainMenu();
     }
     
     printf("Enter Admin Password :: ");
     fgets(pword,20,stdin);
     pword[strlen(pword)-1]='\0';
     
     //reading formatted data from file::
     fptr = fopen("admin.txt","r");
     if(fptr==NULL)
     {
         printf("\nCannot open file");
         exit(0);
     }
     
 while(fscanf(fptr,"%[^,],%s",admin.admin_emailId,admin.admin_password) != -1) //EOF=-1
 {
    if(!strcmp(admin.admin_emailId,emailId))
    {
      if(!strcmp(admin.admin_password,pword))
      {
         printf("\n\t*************LOGIN SUCCESSFULL****************\n");
         adminMenu();
         break;
       }
       else
       {
            printf("\n....INVALID PASSWORD....\n");
            break;
       }
                
             usrFound=1;
     }
     else if(!usrFound)
     {
            printf("\n...USER NOT REGISTERED...\n");
            break;
     }
   }//while     
    fclose(fptr);   //closing file to release resources allocated for the file    
}//admin_login 



/*This is the function used for registration purpose of Donor.
  This function takes the parameters of structure type
  and return type is void
*/

void donor_registration(Donor donor) //parameter is of structure type and return type is void
{    
     char password2[20];  //declaring char variable
     FILE *fptr;  //declaring file pointer
      fptr = fopen("donor.txt","a"); //opens donor.txt file if it is exists or creates new file if not existing
      if(fptr==NULL)  //file not existing then fopen returns NULL
      {
         printf("\nCannot open file");
         exit(0);
      }
     
         //get data from user and write to donor.txt file
         
          printf("\nEnter the Donor Email Id :: ");
          while(getchar()!='\n');   //user defined logic to replace fflush()
          fgets(donor.donor_emailId,50,stdin);
          donor.donor_emailId[strlen(donor.donor_emailId)-1]='\0';
          
          if(emailToValidate(donor.donor_emailId) == 0)
            {
              displayMainMenu();
            }
          
          printf("Enter the Donor Password :: ");
          fgets(donor.donor_password,20,stdin);
          donor.donor_password[strlen(donor.donor_password)-1]='\0';
         
          printf("Confirm Your Password :: ");
          fgets(password2,20,stdin);
          password2[strlen(password2)-1]='\0';
          
          fprintf(fptr,"%s,%s\n",donor.donor_emailId,donor.donor_password); //for formatted output
          if(!strcmp(donor.donor_password,password2))
          {
             if(fptr!=NULL)
                   printf("\n\t***********REGISTRATION SUCCESSFULL**************");
              else
                   printf("\nSorry:Something Went Wrong");          
          }
          else
             printf("\n...PASSWORD DOES NOT MATCH...");
                     
     fclose(fptr); //closing file to release resources allocated for the file
} //donor_registration



/*This is the function used for login purpose of Donor.
 This function takes the parameters of structure type
 to display details and return type is void
*/

void donor_login(Donor donor) //parameter is of structure type and return type is void
{
    
    FILE *fptr=NULL;  //declaring file pointer
    Dnode *head=NULL;
    Dnode *temp;
    Dnode *newnode=NULL;
    char emailId[50],password[20];
   
     printf("\nEnter Donor Email Id :: ");
     while(getchar()!='\n');   //user defined logic to replace fflush()
     fgets(emailId,50,stdin);
     emailId[strlen(emailId)-1]='\0';
     
      if(emailToValidate(donor.donor_emailId) == 0)
      {
              displayMainMenu();
      }
     
     printf("Enter Donor Password :: ");
     fgets(password,20,stdin);
     password[strlen(password)-1]='\0';
     
     //reading formatted data from file::
     fptr = fopen("donor.txt","r");
     if(fptr==NULL)
     {
         printf("\nCannot open file");
         exit(0);
     }
     
     while(fscanf(fptr,"%[^,],%s\n",donor.donor_emailId,donor.donor_password) != -1) //EOF=-1
     {
           newnode = D_createNode(donor);
           head=D_addNode(head,newnode);
     }
     
     temp = head;
     while(temp!=NULL)
     {
         if(strcmp(emailId,temp->donor_emailId)!=0)
         temp = temp->next;
         else
             break;
     } 
     if(temp!=NULL)
     {
            if(strcmp(temp->donor_password,password)==0)
            {
                    printf("\n\t*************LOGIN SUCCESSFULL****************\n");
            }
            else
            {
                  printf("\n....INVALID PASSWORD....\n");
                  donor_login(donor);
            }
     }
     if(temp==NULL)
     {
          printf("\n...USER NOT REGISTERED...\n");
     } 
     fclose(fptr);   //closing file to release resources allocated for the file  
} //donor_login



/*creating newnode for LL with data(values) fetched from file 
in formal parameter donor*/
Dnode* D_createNode(Donor donor)
{
    	Dnode *newnode = (Dnode*)malloc(sizeof(Dnode));
      
    	strcpy(newnode->donor_emailId,donor.donor_emailId); 
    	strcpy(newnode->donor_password,donor.donor_password);
    
    	newnode->next = NULL;
    
    	return newnode;
}//D_createNode



/*adding node in LL containing passengerdetails
parameters: *head pointing to 1st node of LL, *newnode containing new record fetched from file*/
Dnode* D_addNode(Dnode *head,Dnode *newnode)
{
    	Dnode *temp=head;
    	//check if LL is empty
    	if(head==NULL)
        	head = newnode;
    	else
    	{
       		while(temp->next!=NULL)
             	temp = temp->next;
             
       		temp->next = newnode;
    	}
    
   	return head;
}//D_addNode



/*This is the function used for registration purpose of Receiver.
  This function takes the parameters of structure type
  and return type is void
*/

void receiver_registration(Receiver receiver) //parameter is of structure type and return type is void
{    
     char password2[20];  //declaring char variable
     FILE *fptr;  //declaring file pointer
     
      fptr = fopen("receiver.txt","a"); //opens beneficiary.txt file if it is exists or creates new file if not existing
      if(fptr==NULL)  //file not existing then fopen returns NULL
      {
         printf("\nCannot open file");
         exit(0);
      }
     
         //get data from user and write to beneficiary.txt file
          
          
          printf("\nEnter the Receiver Email Id :: ");
          while(getchar()!='\n');   //user defined logic to replace fflush()
          fgets(receiver.receiver_emailId,50,stdin);
          receiver.receiver_emailId[strlen(receiver.receiver_emailId)-1]='\0';
          
           if(emailToValidate(receiver.receiver_emailId) == 0)
            {
              adminMenu();
            }
          
          printf("Enter the Receiver Password :: ");
          fgets(receiver.receiver_password,20,stdin);
          receiver.receiver_password[strlen(receiver.receiver_password)-1]='\0';
          
          printf("Confirm Your Password :: ");
          fgets(password2,20,stdin);
          password2[strlen(password2)-1]='\0';
          
          fprintf(fptr,"%s,%s\n",receiver.receiver_emailId,receiver.receiver_password); 
          
          if(!strcmp(receiver.receiver_password,password2))
          {
             if(fptr!=NULL)
                 printf("\n\t***********REGISTRATION SUCCESSFULL**************");
             else
                 printf("\nSorry:Something Went Wrong");   
          } 
          else
              printf("\n...PASSWORD DOES NOT MATCH...");           
          
     fclose(fptr); //closing file to release resources allocated for the file
} //receiver_registration



/*This is the function used for login purpose of Receiver.
 This function takes the parameters of structure type
 to display details and return type is void
*/

void receiver_login(Receiver receiver) //parameter is of structure type and return type is void
{
    
    FILE *fptr=NULL;  //declaring file pointer
    Rnode *head=NULL;
    Rnode *temp;
    Rnode *newnode=NULL;
    char emailId[50],password[20];
   
     printf("\nEnter Receiver Email Id :: ");
     while(getchar()!='\n');   //user defined logic to replace fflush()
     fgets(emailId,50,stdin);
     emailId[strlen(emailId)-1]='\0';
     
      if(emailToValidate(receiver.receiver_emailId) == 0)
       {
              adminMenu();
       }
     
     printf("Enter Receiver Password :: ");
     fgets(password,20,stdin);
     password[strlen(password)-1]='\0';
     
     //reading formatted data from file::
     fptr = fopen("receiver.txt","r");
     if(fptr==NULL)
     {
         printf("\nCannot open file");
         exit(0);
     }
     
     while(fscanf(fptr,"%[^,],%s\n",receiver.receiver_emailId,receiver.receiver_password) != -1) //EOF=-1
     {
           newnode = R_createNode(receiver);
           head=R_addNode(head,newnode);
     }
     
     temp = head;
     while(temp!=NULL)
     {
         if(strcmp(emailId,temp->receiver_emailId)!=0)
         temp = temp->next;
         else
             break;
     } 
     if(temp!=NULL)
     {
            if(strcmp(temp->receiver_password,password)==0)
            {
                    printf("\n\t*************LOGIN SUCCESSFULL****************\n");
            }
            else
            {
                  printf("\n....INVALID PASSWORD....\n");
                  receiver_login(receiver);
            }
     }
     if(temp==NULL)
     {
          printf("\n...USER NOT REGISTERED...\n");
     } 
     fclose(fptr);   //closing file to release resources allocated for the file  
} //receiver_login



/*creating newnode for LL with data(values) fetched from file 
in formal parameter receiver*/
Rnode* R_createNode(Receiver receiver)
{
    	Rnode *newnode = (Rnode*)malloc(sizeof(Rnode));
      
    	strcpy(newnode->receiver_emailId,receiver.receiver_emailId); 
    	strcpy(newnode->receiver_password,receiver.receiver_password);
    
    	newnode->next = NULL;
    
    	return newnode;
}//R_createNode



/*adding node in LL containing passengerdetails
parameters: *head pointing to 1st node of LL, *newnode containing new record fetched from file*/
Rnode* R_addNode(Rnode *head,Rnode *newnode)
{
    	Rnode *temp=head;
    	//check if LL is empty
    	if(head==NULL)
        	head = newnode;
    	else
    	{
       		while(temp->next!=NULL)
             	temp = temp->next;
             
       		temp->next = newnode;
    	}
    
   	return head;
}//R_addNode



/*This is the function used for registration purpose of Hospital.
  This function takes the parameters of structure type
  and return type is void
*/

void hospital_registration(Hospital hospital) //parameter is of structure type and return type is void
{    
     char password2[20];  //declaring char variable
     FILE *fptr;  //declaring file pointer
     
      fptr = fopen("hospital.txt","a"); //opens hospital.txt file if it is exists or creates new file if not existing
      if(fptr==NULL)  //file not existing then fopen returns NULL
      {
         printf("\nCannot open file");
         exit(0);
      }
     
         //get data from user and write to hospital.txt file
        
          
          printf("\nEnter the Hospital Email Id :: ");
          while(getchar()!='\n');   //user defined logic to replace fflush()
          fgets(hospital.hospital_emailId,50,stdin);
          hospital.hospital_emailId[strlen(hospital.hospital_emailId)-1]='\0';
          
           if(emailToValidate(hospital.hospital_emailId) == 0)
            {
              adminMenu();
            }
          
          printf("Enter the Hospital Password :: ");
          fgets(hospital.hospital_password,20,stdin);
          hospital.hospital_password[strlen(hospital.hospital_password)-1]='\0';
          
          printf("Confirm Your Password :: ");
          fgets(password2,20,stdin);
          password2[strlen(password2)-1]='\0';
          
          fprintf(fptr,"%s,%s\n",hospital.hospital_emailId,hospital.hospital_password); //for formatted output
          if(!strcmp(hospital.hospital_password,password2))
          {
             if(fptr!=NULL)
                 printf("\n\t***********REGISTRATION SUCCESSFULL**************");
              else
                 printf("\nSorry:Something Went Wrong");          
          } 
          else
              printf("\n...PASSWORD DOES NOT MATCH...");
                      
     fclose(fptr); //closing file to release resources allocated for the file
}//hospital_registration



/*This is the function used for login purpose of Hospital.
 This function takes the parameters of structure type
 to display details and return type is void
*/

void hospital_login(Hospital hospital) //parameter is of structure type and return type is void
{
    
    FILE *fptr=NULL;  //declaring file pointer
    Hnode *head=NULL;
    Hnode *temp;
    Hnode *newnode=NULL;
    char emailId[50],password[20];
   
     printf("\nEnter Hospital Email Id :: ");
     while(getchar()!='\n');   //user defined logic to replace fflush()
     fgets(emailId,50,stdin);
     emailId[strlen(emailId)-1]='\0';
     
      if(emailToValidate(hospital.hospital_emailId) == 0)
       {
              adminMenu();
       }
     
     printf("Enter Hospital Password :: ");
     fgets(password,20,stdin);
     password[strlen(password)-1]='\0';
     
     //reading formatted data from file::
     fptr = fopen("hospital.txt","r");
     if(fptr==NULL)
     {
         printf("\nCannot open file");
         exit(0);
     }
     
     while(fscanf(fptr,"%[^,],%s\n",hospital.hospital_emailId,hospital.hospital_password) != -1) //EOF=-1
     {
           newnode = H_createNode(hospital);
           head=H_addNode(head,newnode);
     }
     
     temp = head;
     while(temp!=NULL)
     {
         if(strcmp(emailId,temp->hospital_emailId)!=0)
         temp = temp->next;
         else
             break;
     } 
     if(temp!=NULL)
     {
            if(strcmp(temp->hospital_password,password)==0)
            {
                    printf("\n\t*************LOGIN SUCCESSFULL****************\n");
            }
            else
            {
                  printf("\n....INVALID PASSWORD....\n");
                  hospital_login(hospital);
            }
     }
     if(temp==NULL)
     {
          printf("\n...USER NOT REGISTERED...\n");
     } 
     fclose(fptr);   //closing file to release resources allocated for the file  
} //hospital_login



/*creating newnode for LL with data(values) fetched from file 
in formal parameter hospital*/
Hnode* H_createNode(Hospital hospital)
{
    	Hnode *newnode = (Hnode*)malloc(sizeof(Hnode));
      
    	strcpy(newnode->hospital_emailId,hospital.hospital_emailId); 
    	strcpy(newnode->hospital_password,hospital.hospital_password);
    
    	newnode->next = NULL;
    
    	return newnode;
}//H_createNode



/*adding node in LL containing passengerdetails
parameters: *head pointing to 1st node of LL, *newnode containing new record fetched from file*/
Hnode* H_addNode(Hnode *head,Hnode *newnode)
{
    	Hnode *temp=head;
    	//check if LL is empty
    	if(head==NULL)
        	head = newnode;
    	else
    	{
       		while(temp->next!=NULL)
             	temp = temp->next;
             
       		temp->next = newnode;
    	}
    
   	return head;
}//H_addNode

