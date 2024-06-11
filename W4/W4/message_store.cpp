#pragma once
#include "message_store.h"
#include <algorithm> 
#include <iostream>  


MessageStore::MessageStore(const string& filename)
{
    read_messages_from_file(filename);
}

void MessageStore::display_messages_for_user(const string& user) const
{    
    auto iterator = messages.find(user);

    if (iterator == messages.end()) { 
        return;
    }

    auto& list = iterator->second;

    for (const auto& message : list) {
        message.display_properties();
    }
}


void MessageStore::read_message(const string& user, int msg_id) const
{
    auto iterator = messages.find(user);

    if (iterator == messages.end()) { 
        return;
    }

    auto& list = iterator->second; 

    
    for (const auto& message : list) {
        if (msg_id == message.get_id()) { 
            message.display_message();
            break;
        }
    }
}

void MessageStore::delete_message(const string& user, int msg_id)
{
    auto iterator = messages.find(user);

    if (iterator == messages.end()) { 
        return;
    }

    auto& list = iterator->second; 

    
    list.remove_if([msg_id](auto m) { return msg_id == m.get_id(); });

}

void MessageStore::send_message(const string& sender, const string& receiver,
    const string& subject, const string& content)
{
    Message message(sender, receiver, subject, content);

    messages[receiver].push_back(message);

}

void MessageStore::save_message_store(const string& filename)
{
    write_messages_to_file(filename);
}

void MessageStore::read_messages_from_file(const string& filename)
{
    ifstream fin(filename); 

    if (fin.fail()) {
        cout << "Error, unable to open file " << filename << endl;
        return;
    }

    while (!fin.fail()) {
        string sender;
        string receiver;
        string date;
        string subject;
        string content;
        getline(fin, sender, '|');
        getline(fin, receiver, '|');
        getline(fin, date, '|');
        getline(fin, subject, '|');
        getline(fin, content, '\n');

        if (!fin.fail()) {
            Message message(sender, receiver, date, subject, content);
            messages[receiver].push_back(message);
        }
    }

    fin.close();
}

void MessageStore::write_messages_to_file(const string& filename)
{
    ofstream fout(filename);
    if (fout.fail()) {
        cout << "Unable to write to " << filename << endl;
        return;
    }

    for (auto& each : messages) {
        for (auto& message : each.second) {
            fout << message.get_sender() << "|"
                << message.get_receiver() << "|"
                << message.get_date() << "|"
                << message.get_subject() << "|"
                << message.get_contents() << endl;
        }
    }

    fout.close();
}