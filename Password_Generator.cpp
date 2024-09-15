/*
                                THIS CODE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
                                BY : VKEY
*/

// ================================================== LIBRARY ==========================================================
#include <iostream> // std::cout, std::cin
#include <string> // std::string, append()
#include <cstdlib> // srand(), rand()
#include <ctime> // time()

/*
====================================	 srand(unsigned int seed)	====================================================
The srand() function sets the seed for the rand() function. The seed for rand() function is 1 by default.
It means that if no srand() is called before rand(), the rand() function behaves as if it was seeded with srand(1).
If an srand() function is called before rand(), the rand() function generates a number with the seed set by srand()
*/
/*
==============================================	 rand()	   =============================================================
rand() is used to generate a series of random numbers. If generated with rand() without calling srand()
, your program will create the same sequence of numbers each time it runs
*/

// ================================================= FUNCTIONS =========================================================
// to convert a string to lowercase
void toLowerCase(std::string& str){
    for ( int i =  0; i < str.size(); i++ ) str[i] = tolower(str[i]);
}

// =============================================== MAIN PROGRAM ========================================================
int main(){
        
        std::string lowerCase = "abcdefghijklmnopqrstuvwxyz";
        std::string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string numbers = "0123456789";
        std::string symbols = "!@#$%^&*()_+<>?-=,./";
        std::string password, str, option;
        int length;

    // run the program continously
    while(true){
        // length length of password
        std::cout << "length THE LENGTH OF THE PASSWORD : ", std::cin >> length;
        if ( length == 0 ) continue;

        // time() function returns the number of seconds since 00:00 hours, 1 Jan, 1970 UTC.
        // As a result, the value seed changes with time. So when we run the program, a new random numbers is generated
        srand(time(0));

        // to set the contain of the password
        while(true){
            // append(string)
            std::cout << "\nLowercase ? (yes/no) : ", std::cin >> option, toLowerCase(option);
            if ( option == "yes" or option == "y" ) str.append(lowerCase);
            std::cout << "Uppercase ? (yes/no) : ", std::cin >> option, toLowerCase(option);
            if ( option == "yes" or option == "y" ) str.append(upperCase);
            std::cout << "Numbers ? (yes/no) : ", std::cin >> option, toLowerCase(option);
            if ( option == "yes" or option == "y" ) str.append(numbers);
            std::cout << "Symbols ? (yes/no) : ", std::cin >> option, toLowerCase(option);
            if ( option == "yes" or option == "y" ) str.append(symbols);
            
            // to handle if the user input nothing, so it'll rerun
            if ( str != "" ) break;
            std::cout << "\nPlease select one of the items !!\n";
        }
        
        // to make the password with rand()
        // append a char into a string, can't use append() or insert() because it's for string
        for ( int i = 0; i < length; i++ ) password += str[rand() % str.size()];
        
        std::cout << "\nYOUR PASSWORD IS \" " << password << " \"\n" << std::endl;

        break;
    }
    return 0;
}