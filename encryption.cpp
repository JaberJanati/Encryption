#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
#include<vector>
#include "encryption.h"
void Encryption::chooseFile(string filename)
{

    if(checkFile(filename) == true)                     //checks if the file name is valid and outputs the name
    {
        getFileName();
    }
    else
    {
        cout << "File could not be made or found" << endl;
    }

}

void Encryption::append()
{
    string Contents;
    cout << "Enter new conents of the file " << endl;
    getline(cin, Contents);                             //takes user input to append to file

    ofstream writing;
    writing.open(file_name.c_str(), ios::app);
    writing << ' ' << Contents;                     //adds the written contents to file
    writing.close();
    Contents = "";

}

void Encryption::showChoices()
{
    cout << "Enter a choice: " << endl;
    cout << endl;
    cout << "0 - Quit" << endl;
    cout << "1 - Encrypt File" << endl;
    cout << "2 - Decrypt File" << endl;
    cout << "3 - Read File " << endl;
    cout << "4 - Choose File" << endl;
    cout << "5 - Append to file " << endl;
    cout << "6 - Clear File" << endl;

}



bool Encryption::checkFile(string filename)
{
    int size = filename.length();                       //holds the file name's legnth
    string ending = "";
    if(size >= 5)                                       //checks if the length >= 5 for minimum length for a name that includes .txt
    {
        for(int i = size-4; i < size; i++)              //starts at the last 4 characters and adds value to ending variable
        {
            ending += filename[i];
        }
        if(ending != ".txt")                        //checks if the variable is .txt if not then adds it to the string file_name
        {
            file_name = filename + ".txt";
            return true;
        }
        else
            file_name = filename;
            return true;
    }
    else
        cerr << "Not a valid choice " << endl;
        return false;
}

void Encryption::clearFile()
{
    ofstream the_file;                          //clears file by opening to write
    the_file.open(file_name.c_str());
    the_file.close();
    cout << "File is now clear" << endl;
}

string Encryption::getFileName()                //returns name of the file
{
    return file_name;
}


void Encryption::encryptFile()
{
    vector<string> words;
    string reading;
    ifstream the_file;
    string read;

    the_file.open(file_name.c_str());

    if(the_file.fail())                                 //checks if the file can be open
    {
        cerr << "Could not open the file " << endl;
        exit(1);
    }
    else
        while(the_file >> reading)      //reads from a file and then puts contents in a vector
        {
            words.push_back(reading);
        }
    the_file.close();

    cout << "Encrypting file........" << endl;

    ofstream convert;
    convert.open(file_name.c_str());        //opens file
    for(int i = 0; i < words.size(); i++)
    {
        for(int j = 0; j < words[i].length(); j++)      //reads each letter in vecotr and shifts it three letters forward
        {
            read = char(words[i].at(j) +3);
            convert << read;                         //write new values to the file
        }
        convert << ' ';
    }
    convert.close();
    cout << "Encryption finished\n" << endl;
}

void Encryption::decryptFile()
{
    ifstream the_file;
    the_file.open(file_name.c_str());
    vector<string> words;
    string read;

    while(the_file >> read)
    {
        words.push_back(read);                      //adds each word in file to a vector
    }

    the_file.close();

    cout << "Decrypting the file....... " << endl;

    ofstream convert;
    convert.open(file_name.c_str());

    for(int i = 0; i < words.size(); i++)           //for all the words in the file
    {
        for(int j = 0; j < words[i].length(); j++)          //for the length of each word in file
        {
            read = char(words[i].at(j) - 3);            //reads each character and moves each letter by three to the left
            convert << read;                            //writes new letter back to file
        }
        convert << ' ';
    }

    convert.close();
    cout << "Decryption Completed!\n" << endl;

}

void Encryption::readFile()
{
    string name;

    ifstream the_file;
    string read;

    the_file.open(file_name.c_str());
    if(the_file.fail())                                 //checks if the file can be opened
    {
        cerr << "Could not find the file" << endl;
        exit(1);
    }
    cout << "Conents of file: " << endl;
    while(the_file >> read)                         //reads the contents of file and outputs it on screen
    {
        cout << read << ' ';
    }
    cout << "\nEnd of file.." << endl;
    the_file.close();
    cout << endl;

}
