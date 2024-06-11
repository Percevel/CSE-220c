#pragma once
#include "message_store.h"
#include <iostream> 
#include <limits> 
#include <string>

void display_menu();
void user_loop(const string& username, MessageStore& store);
void user_login(MessageStore& store);
int prompt_for_id();

const string FILENAME = "sample_messages.txt";

int main()
{
    MessageStore store(FILENAME);
    user_login(store);
    store.save_message_store(FILENAME);
}

void display_menu()
{
    cout << "Choose an option: " << endl;
    cout << "\t d - Display all messages" << endl;
    cout << "\t r - Read a message" << endl;
    cout << "\t x - Delete a message" << endl;
    cout << "\t s - Send a message" << endl;
    cout << "\t q - Exit user" << endl;
}

void user_loop(const string& username, MessageStore& store)
{
    char response;        
    int id;                 
    string receiver;       
    string subject;         
    string message_content;  

    cout << "\n Welcome, " << username << endl;

    while (true) {

        display_menu();
        cout << "\n" << username << "> ";
        cin >> response;
        cin.ignore(); 

        cout << endl;
        switch (response) {
        case 'd': 
            store.display_messages_for_user(username);
            break;
        case 'r':
            id = prompt_for_id();
            if (id < 0) { 
                break; 
            }
            cout << endl;
            store.read_message(username, id);
            break;
        case 'x': 
            id = prompt_for_id();
            if (id < 0) { break; } 
            store.delete_message(username, id);
            break;
        case 's': 
            cout << "Who are you sending to? ";
            getline(cin, receiver);
            cout << "What is the subject? ";
            getline(cin, subject);
            cout << "What is the message? ";
            getline(cin, message_content);
            store.send_message(username, receiver, subject, message_content);
            break;
        case 'q':
            cout << "Goodbye " << username << "." << endl;
            return;
        default:
            cout << "Invalid option: " << response << endl;
            break;
        }
        cout << endl;
    }
}

void user_login(MessageStore& store)
{
    string username;

    while (true) {
        cout << "\n Enter user name ('quit' to exit): ";
        getline(cin, username);

        if (username == "quit") {
            cout << "Goodbye." << endl << endl;
            return;
        }

        user_loop(username, store);

    }
}

int prompt_for_id()
{
    int id;
    cout << "Enter message id: ";
    cin >> id;
    if (!cin) {
        cout << "Invalid ID" << endl;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return id;
}