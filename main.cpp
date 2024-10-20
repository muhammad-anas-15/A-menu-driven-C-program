
/*
A menu-driven program which will have three of the following functionalities,
1. Add new number
2. Delete a number
3. Print the array
4. Print sum of array
5. Exit Program
*/
#include<iostream>
#include<cstdlib>
#include<ctime>// Library for srand() function.

using namespace std;
//Function Prototype
/*
int *ptr as a function parameter,
It means that the function receives a copy of the pointer,
and any changes made to it inside the function are not reflected outside the function.

Therefore we use *&ptr which will passing a reference to the pointer itself, allows
 the function to modify the pointer and these changes will be reflected outside the function.

*/
void Resize_array(int *&ptr, int &size_of_array);// &size is also passing reference to variable and any changes to it will
void Add_new_number(int *&ptr, int &size_of_array);//cause changes to original variable
void Delete_a_number(int *&ptr, int &size_of_array);
void Print_the_array(int *ptr, int size_of_array);
void Print_sum_of_array(int *ptr, int size_of_array);

int main()
{
	
	int size_of_array = 5;//Declare size of array as 5.
	int *ptr = new int[size_of_array];//Dyamically allocate Pointer to array of size 5.
	
	srand(time(NULL));//Calling srand function include in library.
	
	for (int i = 0; i < size_of_array; i++) {
        ptr[i] = rand() % 11;    //give random values from 0 - 10.
    }
	
	int choice;//Declare choice variable. 

    // As it is menu driven program so we use do-while loop.
	do
	{
		//This menu should be dispaly to user to enter choice.
		cout<<"*********************\n";
		cout<<"Press [1] to Add a Number: \n";
		cout<<"Press [2] to Delete a Number:\n";
		cout<<"Press [3] to Print the Array:\n";
		cout<<"Press [4] to Print Sum of Array:\n";
		cout<<"Press [5] to Exit:\n";
		cout<<"\n\n";
		cout<<"Enter your choice (1-5): ";// Prompt user to enter choice from(1-5).
		cin>>choice;
		
		switch(choice)
		{
			//If user enter 1 executes this 
			case 1:
				Add_new_number(ptr,size_of_array);//Function calling add number.
				break;
			
			//If user enter 2 executes this
			case 2:
                Delete_a_number(ptr, size_of_array);//Function calling delete number.
			    break;
		
		    //If user enter 3 executes this
			case 3:
                Print_the_array(ptr, size_of_array);//Function calling print array .
			    break;
			
			//If user enter 4 executes this
     		case 4:
                Print_sum_of_array(ptr, size_of_array);//Function calling print sum of array .
			    break;
			      
			//If user enter 5 executes this      
			case 5:
				cout<<"Exiting the Menu!\n";//Exit the program.
				break;
			
			default:
				cout<<"Invalid Input!";//If above cases not executed run default statement.
		}
		   if(choice ==5)//On entering 5 loop should break and program exited.
		   {
		   	break;
		   }
    	
    	//After running loop 1 time ask user to enter main menu or exit the loop.
            cout<<"\nEnter your choice:\n[1] Main Menu\n[0] Exit: ";
            cin>>choice;
     
}
   while(choice == 1);//Loop run until user enter 1.
   
   //After executing program.
    cout<<"$$$Thank you for Using$$$";
    delete[]ptr;// Deallocating pointer variable.
    
   return 0;
	
}
void Resize_array(int *&ptr, int &size_of_array)//Function will adjust the size of array in case of adding or deleting a number.
{
	int new_size = size_of_array+1;//increase initial size by 1.
	int *ptr2 = new int[new_size];//ptr2 pointer points to array of size (new_size).
	
	for(int i=0; i<size_of_array; i++)
	{
		ptr2[i]= ptr[i];// Put elements of actual array in temp array.
	}
	ptr2[size_of_array] = 0;
   delete[] ptr;//Deallocating the pointer.
   ptr = NULL;
    
    ptr = ptr2; //put address of ptr 2 pointer in initial pointer.
    size_of_array = new_size;// Put new_size in actual size.
}
void Add_new_number(int *&ptr, int &size_of_array)// Function for adding a new number.
{
    
	int num;
	cout<<"Enter number: ";//Number enter by user
	cin>>num;
	
	Resize_array(ptr, size_of_array);//Calling resize function
    ptr[size_of_array - 1] = num;//storing num at last index of array.
    cout << "Number added successfully.\n";
}
	

void Delete_a_number(int *&ptr, int &size_of_array)// Function for Delete_a_number .

{
	int num;
	cout<<"Enter Number to delete:";//Number enter by user to delete.
	cin>>num;
	int found =0;//Get record of number found or not
	
	for(int i=0; i< size_of_array; i++)
	{
		if(ptr[i]==num)// Number to delete is present in array 
		{
			found++;// if number found .
			
		for(int j=i; j< size_of_array -1; j++)//if number is deleted than the size of array should be decreased.
	{
		ptr[j]=ptr[j+1];
	}
	//ptr[size_of_array - 1] = 0; // Set the last element to 0 after deletion
	size_of_array--;//decrease in size of array.
	cout<<"Number Deleted Successfully.\n";
	break;
     }
	
   }
   
	if(found==0)// if number enter by user is not found
	{
		cout<<"Number not found!\n\n";
	}
}

void Print_the_array(int *ptr, int size_of_array)//Function will print the updated array.
  
{
    cout<<"Array is: ";
	for(int i=0; i<size_of_array; i++)
	{
		cout<<ptr[i]<<" ";
	}
}

void Print_sum_of_array(int *ptr, int size_of_array)//Function will print the sum of array.
{
  	int sum =0;
  	cout<<"Sum of Array is : ";
  	
  	for(int i=0; i<size_of_array; i++)
  	{
  		cout<<ptr[i]<<" ";//printing original array then
	  }
	  cout<<"\n";
  	
  	for(int i=0; i<size_of_array; i++)
  	{
  		sum +=ptr[i];//Sum of array.
	  }
	cout<<"Sum of array is: "<<sum<<endl;  
}
