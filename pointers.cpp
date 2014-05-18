/************************************************************************************************
 *  This is an example program of how pointers work.
 *  - This first covers pointers to variables.
 *  - It then covers pointers to arrays.
 *  - Finally it covers pointers to structures, and a pointer within a structure.
 ************************************************************************************************
 *  Writen By:  Brandon Stanley
 ************************************************************************************************/

#include <iostream>

using namespace std;

//Demo structure
struct point_structure{
       int value;
       int *ptr;
};


typedef struct point_structure ptr_struct; //for easier to define structures


//Function Prototypes, functions are at the bottom of the page
void pass_by_reference(int &ref);
void pass_by_pointer(int *ptr);
void change_array_pointer_element(int *ptr);
void change_structure(ptr_struct *Z);  




int main(){
    
  /**** normal pointer  *****/
  int g = 8;
  int *h = &g;
  *h = 1000;
  cout << "g = " << g << endl;
  
  pass_by_reference(g); //g is passed by reference, meaning the function has full access to the variable (like a pointer)
  cout << "g = " << g << endl;
  
  pass_by_pointer(&g); //address if g is passed to pointer in function
  cout << "g = " << g << endl;
  
  g = 1000; //just to change the number
   
  pass_by_pointer(h); //h passes the address of g to the function (since the value of h is the address of g)
  cout << "g = " << g << endl;
    
  /*******  Pointers with Arrays  ****/
  int a[20];
  int *b = a; //pointer takes the address of 'a' variable
  int *c;
  c = a; //pointers point to the first element of an array
  
  for(int i = 0; i < 20; ++i)
    b[i] = i; //array is filled with its element number
    
  cout << "a[4] starting point " << a[4] << endl;
  
  change_array_pointer_element(b); //address of 'a' is being passed
  
  for(int i = 0; i < 3; i++){
    c++; //incriment through the current pointed to element
  }
  *c = b[4]; //element 3 of 'a' is now 99
  
  cout << "a[4] = " << a[4] << endl; //element 4 of 'a' is now 99
  cout << "*c = " << *c << endl; //prints element 3 of 'a'
  cout << "a[3] =  " << a[3] << endl; //just to show it
  
  
  /********** Structures and Pointers ***********/
  struct point_structure Y;
  ptr_struct *X;
  
  Y.value = 1; 
  Y.ptr = a; //the structure's pointer now points to the 'a' variable from above
  
  X = &Y; //the X structure pointer now points to the Y structure's address
  
  X->value = 3; //the value variable in Y is now 3
  X->ptr[9] = 66; //a[9] is now equal to 66
  
  cout << "Y.value = " << Y.value << " X->value = " << X->value << endl; //Showing the values are the same
  cout << "a[9] = " << a[9] << " X->ptr[9] = " << X->ptr[9] << endl; //showing a[9] actually changed
  
  change_structure(&Y);
  
  cout << "Y.value = " << Y.value << endl;
  cout << "Y.ptr[18] = " << Y.ptr[18] << endl;
  
  cin.get(); //wait for user input before closing
  return 1; //success
}



void pass_by_reference(int &ref){
     ref = 19;
}

void pass_by_pointer(int *ptr){
     *ptr = 96;
}


void change_array_pointer_element(int *ptr){
     ptr[4] = 99;
}

void change_structure(ptr_struct *Z){
     Z->value = 18;
     Z->ptr[18] = 1000;
}





