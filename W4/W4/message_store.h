#pragma once
// message_store.h
//
// Stores a collection of messages and provides a way to 
// send, read, and delete a message.
//

// prevents the header from being imported multiple times
#ifndef message_store_h
#define message_store_h

#include <fstream>  // ifstream, ofstream
#include <list>
#include <map>
#include <string>
#include "message.h"

using namespace std;

class MessageStore
{
public:
    // Default constructor to create an empty message store
    MessageStore() = default;

    // Constructor that reads a file to populate messages
    MessageStore(const string& filename);

    // Display all the messages for a given user
    void display_messages_for_user(const string& user) const;

    // Display a single message 
    void read_message(const string& user, int msg_id) const;

    // Delete a single message
    void delete_message(const string& user, int msg_id);

    // Send a message from sender to receiver
    void send_message(const string& sender, const string& receiver,
        const string& subject, const string& content);

    // Save all messages to a file
    void save_message_store(const string& filename);

private:
    // store usernames mapped to a list of messages
    map<string, list<Message>> messages;

    // read messages in from a file
    void read_messages_from_file(const string& filename);

    // write messages to a file
    void write_messages_to_file(const string& filename);
};

#endif // message_store_h