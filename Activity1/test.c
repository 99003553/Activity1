#include "mystring.h"
#include "myutils.h"
#include "bitmask.h"
#include <stdio.h>
//Main Function
int main()
{
  char s[10]="Hello";
  char s1[10]="World";
  int fact=8,palindrome=131,prime=7,num=6,n=2;
  // String Functions
  printf("Length of the string is %lu\n ",mystrlen(s));
  printf("Copy of the strings %s %s is %lu\n ", s, s1, strcpy(s,s1));
  printf("Concatination of the strings %s %s is %lu\n ", s, s1, mystrcat(s,s1));
  printf("Comparison of the strings %s %s is %lu\n ", s, s1, mystrcmp(s,s1));
  
  // Number Functions
  printf("factorial of %d is %d \n",num,factorial(fact));
  
  if(ispalindrome(palindrome))
    printf("The number is palindrome\n");
  else
    printf("The number is not palindrome\n");  
  
  if(isPrime(prime))
      printf("The number is prime number\n");
  else
    printf("The number is not a prime number\n");   
  
  vsum(2,10,20); 
  vsum(3,10,12,18);
  vsum(4,10,12,18,20);
  
  // Bit Functions
  printf("Setting %d th of %d is %d \n",n,num,set(num,n));
  printf("Resetting %d th of %d is %d \n",n,num,reset(num,n));
  printf("Fliping %d th of %d is %d \n",n,num,flip(num,n));
  printf("Quering %d th of %d is %d \n",n,num,query(num,n));

  return 0;
}
