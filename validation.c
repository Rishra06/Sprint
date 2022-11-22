#include<stdio.h>
#include"validation.h"

int main()
{

  char *name;
  name=(char*)malloc(sizeof(char));
  printf("\nEnter the name: ");
  scanf("%[^\n]%*c",name);
  
  nameToValidate(name);
  
 
 
  
  long int phone;
  printf("\nenter contact number: ");
  scanf("%ld",&phone);
  phoneNoToValidate(phone);
  
  
  return 0;
}
