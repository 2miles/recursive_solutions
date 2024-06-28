#include "arr.h"


int main()
{
    table object; 
    table object2;
    object.build(); //creates an array of LLL
    object.display(); //displays the array

    //PLEASE PUT YOUR CODE HERE to call the function assigned


    object.display();  //display again afterward!



    int result = object.sumEvens();
    cout << "The sum of the evens: " << result;
    
    return 0;
}
