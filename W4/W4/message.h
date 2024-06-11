#pragma once
// message.h
// 
// Represents a single message from a sender (author) 
// to a receiver (recipient), along with the message id,
// date, subject, and content
//

#ifndef message_h // prevents the header from being imported multiple times
#define message_h

#include <string>

using namespace std;

class Message {

public:

    // The typical constructor for a message
    Message(const string& sender, const string& receiver, const string& subject,
        const string& content);

    // Constructor used to create a message with a specific date.
    Message(const string& sender, const string& receiver, const string& date,
        const string& subject, const string& content);

    // Get a message id
    int get_id() const;

    // Display the contents of the message
    void display_message() const;

    // Display the properties of the message excluding its content in this format
    // [id] Message from sender at date - Subject: subject
    //
    // Example:
    // [1] Message from Karen at 11/1/2020 - Subject: Good afternoon
    void display_properties() const;

    // Get individual message properties
    string get_sender() const { return author; }
    string get_receiver() const { return recipient; }
    string get_date() const { return date; }
    string get_subject() const { return subject; }
    string get_contents() const { return content; }

private:
    int id;
    static int id_next; // Incremented to generate the id for each new message
    string author;
    string recipient;
    string date;
    string subject;
    string content;
};

#endif // message_h