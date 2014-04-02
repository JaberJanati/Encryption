/**************************************************************************************
Title: Encryption Program
Author: Jaber
Description: Program allows the user to enter an already existing file and the user has option to choose that file. Options include
encryption which allow all letter to be shifted to the right by three and decryption which shifts the letters to the left by three.
Checks for possible errors.
Date Created: 01/12/14
***************************************************************************************/
#include<iostream>
#include<cstring>
#include<string>
#include "encryption.h"
#include "encryption.cpp"
using namespace std;

bool checkChoice(string input)              //checks if user choice is valid
{
    if(input.length() == 1)
    {
        if(isdigit(input[0]))
        {
            return true;
        }
    }
    else
        return false;
}

string getInput()
{
    string name;
    cout << "Enter the new file name" << endl;
    getline(cin, name);
    return name;
}

int main()
{
    Encryption encrypt;
    string choice;
    string name;
    encrypt.showChoices();
    cin >> choice;


    if(checkChoice(choice) == true)
    {
        while((atoi(choice.c_str()) < 7) && (atoi(choice.c_str()) >= 0))    //while loop executes until number is 0 or out of range
        {
            if(choice == "0")
            {
                cout << "Good bye" << endl;
                exit(1);
            }
            else if(choice == "1")
            {
                encrypt.encryptFile();
                cout << endl;
                encrypt.showChoices();
                cin >> choice;
                if(checkChoice(choice) == false)
                {
                    break;
                }
                cout << endl;
            }
            else if(choice == "2")
            {
                encrypt.decryptFile();
                cout << endl;
                encrypt.showChoices();
                cin >> choice;
                if(checkChoice(choice) == false)
                {
                    break;
                }
                cout << endl;
            }
            else if(choice == "3")
            {
                encrypt.readFile();
                cout << endl;
                encrypt.showChoices();
                cin >> choice;
                if(checkChoice(choice) == false)
                {
                    break;
                }
                cout << endl;
            }
            else if(choice == "4")
            {
                getline(cin, name);
                encrypt.chooseFile(getInput());
                cout << endl;
                encrypt.showChoices();
                cin >> choice;
                if(checkChoice(choice) == false)
                {
                    break;
                }
                cout << endl;
            }
            else if(choice == "5")
            {
                getline(cin, name);
                encrypt.append();
                cout << endl;
                encrypt.showChoices();
                cin >> choice;
                if(checkChoice(choice) == false)
                {
                    break;
                }
                cout << endl;

            }
            else if(choice == "6")
            {
                encrypt.clearFile();
                cout << endl;
                encrypt.showChoices();
                cin >> choice;
                if(checkChoice(choice) == false)
                {
                    break;
                }
                cout << endl;
            }
            else
                cout << "Number is not in the proper range" << endl;
        }
    }

    else
        cout << choice << " is not a number" << endl;

    return 0;
}

