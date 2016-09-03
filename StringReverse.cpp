//
//  HayesMichael_StringReverse.cpp
//
//  Summary: This program uses command line input to reverse a string.
//           The command line paramaters specify the string to reverse
//           as well as the beginining and end of the string
//
//  Created by Michael Hayes on 1/24/16.
//

#include <iostream>

using namespace std;

// Reverse Function
// This function reverses the characters in a string according to pre-specified locations in the string

void reverse(char *front, char *rear){
    
    char holder;
    int length = rear - front;
    
    for (int i = 0; i < (length/2 +1); i++){ //only reverse half of the string so that you don't overlap on what you've already reversed
        
        holder = *rear;
        *rear = *front;
        *front = holder;
        
        front++;
        rear--;
        
    }
}

int main(int argc, const char * argv[]) {
    
    //retrieve the command line parameters and store in variables
    
    string sentence = argv[1];
    string strFront = argv[2];
    string strRear = argv[3];
    
    //convert the strings into integers
    
    int intFront = atoi(strFront.c_str());
    int intRear = atoi(strRear.c_str());
    
    //convert the integers to addresses
    char *frontPt = &sentence[intFront];
    char *rearPt = &sentence[intRear];
    
    
    
    //************************ Error checking *********************************
    
    //make sure the second and third values passed are actual numbers
    
    //if the first number is not an actual number
    if (intFront == 0 && strFront.compare("0") != 0) {
        
        //check if the second number is not an actual number either
        if (intRear == 0 && strRear.compare("0") != 0){
            
            cout << "Usage: " << strFront << " and " << strRear << " must be integers\n";
        }
        
        //if the second number is a real number then only the first number is wrong
        else{
            
            cout << "Usage: " << strFront << " must be an integer\n";
        }
        
        return 0; //exit the program
        
    }//end if
    
    //if the second number is not an actual number
    if (intRear == 0 && strRear.compare("0") != 0) {
        
        cout << "Usage: " << strRear << " must be an integer\n";
        
        return 0; //exit the program
        
    }//end if
    
    
    //make sure the numbers are non-negative
    if (intFront < 0 || intFront > intRear) {
        
        cout << "Usage: The front index must be non-negative and less than or equal to the rear index (i.e., less than or equal to " << intRear << ")\n";
        return 0;
    }
    
    if (intRear > (sentence.length()-1)) {
        
        cout << "Usage: The rear index must be less than the length of \"" << sentence << "\" (i.e., less than " << sentence.length() << ")\n";
        return 0;
    }

    
    //******************** Reverse the String **************************
    
    cout << "Reversing \"" << sentence << "\" from position " << intFront << " to position " << intRear << "\n";
    
    reverse(frontPt, rearPt);
    
    cout << "yields    \"" << sentence << "\"\n";
    
    return 0;
}

