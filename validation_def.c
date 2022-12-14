#include"validation.h"


/*this is a function to validate name of the user where it takes a name as parameter to the function whih is of string type and checks whether the name contains only alphabets and space and returns flag as 1 if true by printing the name as valid.But, if it contains any other special or alphanumeric character flag returns false(0) with an error message. */
int nameToValidate(char *name)
{
   int i,flag=0;
   char c[100];
   
   
   
   
      i=0;
      while(name[i] != '\0')  //checks until it encounters a null character to end the string
      {
      
        if(name[i]!=' ')   //checks if a character in the string contains space
        {
          if((name[i]>='A'&& name[i]<='Z') || (name[i]>='a' && name[i]<='z'))   //checks if the character is alphabet or not
          {
             c[i]=name[i];
             flag=1;       
          }  
          
          
          
          else
          {
             
             flag=0;
             break;
          }//else
          
          
        }//if
        
        else
            c[i]+=' '; 
            
        i++;
      }//while
      
       c[i]='\0';
   
       
      
          if(flag==1)
          {
              printf("\nName Validated\n");
              return 1;
              
              
          }
          else
          {
              printf("\nInvalid name!!It must contain alphabets only..!!!\n");
              
          }
          
          return 0;
}//nameToValidate()





/*function to validate phone number.This function takes phone number as argument to the function whose return type is long int. This function checks whether the entered phone number is of 10 digits or not and then checks if the phone number starts with 7,8,9 or not. */
int phoneNoToValidate(long int phone)
{
    int i=0,flag=0;
    char phone_string[11];
    sprintf(phone_string, "%ld", phone); //to convert long int to string
    
    if(strlen(phone_string)!=10)
          printf("\nPlease enter valid phone number...\n");
          
    else
    {
       if(phone_string[i]=='7' || phone_string[i]=='8' || phone_string[i]=='9')
       {
           for(i=1; phone_string[i]!='\0'; i++)
           {
              if(isdigit(phone_string[i]))
              {
                 //printf("\nvalid phone number");
                 flag=1;
              }//if
              
              else
                 flag=0;
                 
              
           }//for
           
           if(flag==1){
              printf("\nphone number is valid\n");
              return 1;
              }
              
           else{
              printf("\nphone number is invalid\n");
           
              }
       
       }
       else
          printf("\nInvalid phone number\n");       
    
    }//else
        

  return 0;
}//phoneToValidate()



