#include <iostream>
#include <string>
#include "UI.hpp"
using namespace std;

int main()
{
    string commend;
    char input_buffer[1024];
    
    while(true)
    {
        
        cout << "Enter a commend: " ;
        cin.getline(input_buffer,1024);
        commend = input_buffer;
        if (commend == "qq")
            break;
        
        UI(commend);
    }
}

