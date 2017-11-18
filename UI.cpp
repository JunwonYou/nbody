#include <iostream>
#include <string>
#include "UI.hpp"
using namespace std;

void UI(string com)
{
    string* com_arr = split(com);
    
    if (com_arr[0] == "pa")
    {
        cout << "information about particle" << endl;
        
    }
    if (com_arr[0] == "pp")
        cout << "print information of particle <particle>" << endl;
    if (com_arr[0] == "ps")
        cout << "print information of set <set>" << endl;
    if (com_arr[0] == "pf")
        cout << "print information of forces" << endl;
    if (com_arr[0] == "pt")
        cout << "print current time" << endl;
    if (com_arr[0] == "pr")
        cout << "print memory usage" << endl;
    if (com_arr[0] == "pg")
        cout << "print wether gravity is enabled" << endl;
    if (com_arr[0] == "ap")
        cout << "add particle" << endl;
    if (com_arr[0] == "as")
        cout << "add set" << endl;
    if (com_arr[0] == "ae")
        cout << "add particle to set" << endl;
    if (com_arr[0] == "af")
        cout << "add force" << endl;
    if (com_arr[0] == "dp")
        cout << "delete particle" << endl;
    if (com_arr[0] == "de")
        cout << "delete particle from set" << endl;
    if (com_arr[0] == "df")
        cout << "delete force" << endl;
    if (com_arr[0] == "da")
        cout << "delete every particles, sets, forces" << endl;
    if (com_arr[0] == "ct")
        cout << "change time tick" << endl;
    if (com_arr[0] == "cg")
        cout << "turn on and off gravity" << endl;
    if (com_arr[0] == "cp")
        cout << "fix the location of a particle" << endl;
    if (com_arr[0] == "ru")
        cout << "run the simulation" << endl;
    if (com_arr[0] == "rv")
        cout << "run the simulatrion and print result" << endl;
    
    cout << "UI execution : " << com_arr[0] << endl;
    delete[] com_arr;
    
    
    return;
}


string* split(string com)
{
    
    com = trim(com);
    
    string* result = new string[10];
    char buffer[1024];
    int i;
    int j = 0;
    int index = 0;
    for (i = 0; i < com.length(); i++)
    {
        
        if (i == com.length() -1)
        {
            buffer[j] = com[i];
            result[index] = buffer;
            buffer[0] = 0;
        }
        
        if (com[i] != ' ' )
        {
            buffer[j] = com[i];
            j++;
        }
        
        else
        {
            result[index] = buffer;
            buffer[0] = 0;
            j = 0;
            index++;
            
        }
    }
    
        return result;
}
string trim(string& com)
{
    
    for (int i = 0; i < com.length(); i++)
    {
        if (com[0] != ' ')
            break;
        
        if (com[0] == ' ')
        {
            com.erase(0,1);
        }
    }
    
    for (int i = com.length()-1 ; i > -1; i-- )
    {
        if (com[i] != ' ')
            break;
        
        if (com[i] == ' ')
        {
            com.erase(i,1);
        }
    }
    return com;
}
