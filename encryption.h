#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include<iostream>
#include<string>
using namespace std;
class Encryption
{
public:
    void encryptFile();                             //Deals with encrypting file by shifting each letter three spaces
    void decryptFile();                             //shifts each letter of a file by three letters back
    void readFile();                                //reads a file
    void chooseFile(string filename);               //takes the files name checks if it is valid
    void append();                                  //choice to add writing to a file
    bool checkFile(string filename);                //checks if the file is a valid name or exists
    void showChoices();                             //shows the menu of choices
    void clearFile();                               //clears contents of file
    string getFileName();                           //returns the name of the file

private:
    string file_name;                               //holds the variable name for reading and wiritng
    string input;                                   //holds files name

};



#endif // ENCRYPTION_H


