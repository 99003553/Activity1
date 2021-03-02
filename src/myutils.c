#include "myutils.h"

// Function to find factorial of a number
int factorial(int num)
{
  if (num == 0) 
    return 1;
  else
    return (num*factorial(num-1));
}
// Function to check wheather a number is prime or not
int isPrime(int num)
{
  
   for (int i = 2;i <= num - 1;i++)
   { 
      if ( num%i == 0 )
     return 0;
   }
   return 1;
}
// Function to check wheather a number is palindrome or not
int isPalindrome(int num)
{
    int rem,pal=0,temp;
    temp=num;
    while(num>0)    
    {    
        rem=num%10;    
        pal=(pal*10)+rem;    
        num=num/10;    
    }    
    if(temp==pal)    
       return 1; 
    else     
       return 0;  

}
// Function to find the sum of dynamic arguments
int vsum(int arg_count, ...) 
int j; 
   int sum = 0; 
  
   // va_list is a type to hold information about 
   // variable arguments 
   va_list ap; 
  
   // va_start must be called before accessing 
   // variable argument list 
   va_start(ap, arg_count); 
  
   // Now arguments can be accessed one by one 
   // using va_arg macro. Initialize min as first 
   // argument in list 
   sum = va_arg(ap, int); 
  
   // traverse rest of the arguments to find out minimum 
   for (j = 2; j <= arg_count; j++) 
   {
      sum = sum + va_arg(ap, int);
   }
   // va_end should be executed before the function 
   // returns whenever va_start has been previously 
   // used in that function 
   va_end(ap); 
   return sum; 
} 
