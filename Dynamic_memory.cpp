 #include <iostream>
 using namespace std;

 int main() {
     int *pointer;
     int number;
     int elements;
   /*
    * Prompts the user to enter a number as the size of the array
    * Allocate memory to the pointer 
    * Check if our pointer is null
    */
    cout << "How many number would you wanna type: ";
    cin >> number;
    pointer = new (nothrow) int[number];
  
    if (pointer == nullptr)
       cout << "There is no available memory";
    /*
     * If our pointer is not null
     * Loop through the elements
     * Allocates each elements of the array to the pointer
     * Displays the elements
     * Deletes the memory allocated
     */
    else {
       for (elements = 0; elements < number; elements++) {
            cout << "Enter number: ";
            cin >> pointer[elements];
       }
  
       cout << "You have entered: ";
       for (elements = 0; elements < number; elements++)
           cout << pointer[elements] << ",";
           delete[] pointer;
    }
  
    return 0;
  }

