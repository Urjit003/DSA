// 9) Write a Program to perform following operation on text file :

// 11.1) write content in a text file
// 11.2) read content from file
// 11.3) count no of word and no of lines in a file
// 11.4) copy contents of one file to another file

#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
int GetUserDecision()
{
    int decision, validinput = 0;
    while (!validinput)
    {
        printf("Enter 0 to continue and 1 to end \n");
        if (scanf("%d", &decision) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            printf("Invalid Input \n");
        }
        else if (decision != 0 && decision != 1)
        {
            printf("Invalid Input \n");
        }
        else
        {
            validinput = 1;
        }
    }
    return decision;
}
int GetUserChoice()
{
    int choice, validinput = 0;
    while (!validinput)
    {
        if (scanf("%d", &choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }
        else
        {
            validinput = 1;
        }
    }
    return choice;
}
void Write_content_In_file(fstream &fs)
{
    string inputline;
    fs.open("temp_write_content.txt", ios::out);
    cout << "Begine filling up the file\n press cltr+z and enter to exit\n";
    while (cin >> inputline)
    {
        fs << inputline << endl;
    }

    fs.close();
    fs.clear();
}
void Read_content_In_file(fstream &fs)
{
    if (fs.is_open())
    {
        fs.close();
    }
    string filename;
    cout << "enter file name \n";
    cin >> filename;
    fs.open(filename, ios::in);
    string line;
    cout << " \" ";
    while (getline(fs, line))
    {
        cout << line << " ";
    }
    cout << " \" ";
    fs.clear();
    fs.close();
}
void count_words_In_file(fstream &fs)
{
    fs.open("temp_write_content.txt", ios::in);
    string word;
    int count = 0;
    while (fs >> word)
    {
        count++;
    }
    cout << "total no of words in the temp_write_content.txt are :" << count;
}
void copy_content_of_file(fstream &fs)
{
    fs.open("temp_write_content.txt", ios::in);
    ofstream output("copied_content.txt");

    string line;
    while (getline(fs, line))
    {
        output << line << " ";
    }

    cout << "Content successfully copied to 'copied_content.txt'" << endl;

    fs.close();
    output.close();
}
int main()
{
    fstream of;
    int choice, ShouldExit = 0;
    do
    {
        printf("1 to write in a file.\n2 to Read content.\n3 to count no of words \n4 copy content of one file to another.\n");
        int choice = GetUserChoice();

        switch (choice)
        {
        case 1:
            Write_content_In_file(of);
            cout << endl;
            ShouldExit = GetUserDecision();
            break;
        case 2:
            Read_content_In_file(of);
            cout << endl;
            ShouldExit = GetUserDecision();
            break;
        case 3:
            count_words_In_file(of);
            cout << endl;
            ShouldExit = GetUserDecision();
            break;
        case 4:
            copy_content_of_file(of);
            cout << endl;
            ShouldExit = GetUserDecision();
            break;
        default:
            break;
        }
    } while (!ShouldExit);

    return 0;
}