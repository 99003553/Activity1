#include "bitmask.h"

// Function to set the n th bit of num 
int set(int num, int n) 
{ 
    return (num | (1 << (n - 1))); 
} 
  
// Function to Reset the nth bit of num
int clear(int num, int n) 
{ 
    return (num & (~(1 << (n - 1)))); 
} 
  
// Function to flip the nth bit of num 
int flip(int num, int n) 
{ 
    return (num ^ (1 << (n - 1))); 
} 
// Function to query the nth bit of num 
int query(int num, int n) 
{ 
    return ((num >> n) & 1); 
} 
