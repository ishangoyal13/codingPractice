
#include<bits/stdc++.h> 
using namespace std; 
  
int prime(int num) 
{ 
    int i, flag = 0; 
    for(i = 2; i<= num / 2; i++) 
    { 
        if(num % i == 0) 
        { 
            flag = 1; 
            break; 
        } 
    } 
      
     
   
    if(flag == 0) 
        return 1; 
    else
        return 0; 
} 
  
void print_alternate_prime(int n) 
{ 
    
    int counter = 0; 
  
    
    for(int num = 2; num < n; num++) 
    { 
        
        if (prime(num) == 1) 
        {  
             
            if (counter % 2 == 0) 
                cout << num << " "; 
                  
            counter ++; 
        } 
    } 
} 
   
int main() 
{ 
    int n = 15; 
    cout << "Following are the alternate prime"
         << " number smaller than or equal to " 
         << n << endl; 
           
   
    print_alternate_prime(n); 
} 
