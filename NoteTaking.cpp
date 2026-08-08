#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>

using namespace std;

class Note
{
    private:
    string title;
    string body;
    public:
    Note(string Title, string Body)
    {
        title = Title;
        body = Body;
    }
    void NoteTaking()
    {
        cout << "Title: ";
        getline(cin, title);
        fstream myNote;
        myNote.open("MyNote.txt", ios::out);
        if (myNote.is_open())
        {
            myNote << "Title: " << title << "\n";
            myNote.close();
        };

        cout << "Body: ";
        getline(cin, body);
        myNote.open("MyNote.txt", ios::app);
        if (myNote.is_open())
        {
            myNote << "Body: " << body << "\n";
            myNote.close();
        };

    }
};

void CurrentNotes()
{
    fstream myNote;
    cout << "Current Notes: " << endl;
    myNote.open("myNote.txt", ios::in);
    if (myNote.is_open())
    {
        string text;
        while (getline(myNote, text))
        {
            cout << text << endl;
        }
        myNote.close();
    }
};


int main()
{
    Note note = Note("", "");
    note.NoteTaking();
    string choice;
    //CurrentNotes();

    fstream myNote;
        myNote.open("MyNote.txt", ios::app);
        if (myNote.is_open()){
        auto now = chrono::system_clock::now();
        time_t t = chrono::system_clock::to_time_t(now);
        myNote << ctime(&t) << "\n";
        }
    // cout << "Would you like to change anything about the notes?" << endl;
    // cout << "Type Title, Body or Nothing: ";
    // cin >> choice;
    // if(choice == "Title")
    // {
    //     string title;
    //     cout << "Please enter your new Title: ";
    //     getline(cin, title);
    // }



    
}