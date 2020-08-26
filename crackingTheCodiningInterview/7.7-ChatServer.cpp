#include <iostream>
#include <set>
#include <string>
#include <list>

using namespace std;


class User
{
public:
    enum ConnectionStatus { OFFLINE, ONLINE };
    enum Status { INVISIBLE, BUSY, AWAY, AVAILABLE};
private:
    set<User*> friends;
    list<Chat*> chats;
    string email;   // serves as username
    string password;
    string name;
    Status status;
    ConnectionStatus connectionStatus;

public:
    void addFriend(User* user)
    {
        if (!friends.count(user)) friends.insert(user);
        if (!user->friends.count(this)) user->friends.insert(this);
    }

    void removeFriend(User* user)
    {
        if (friends.count(user)) friends.erase(user);
        if (user->friends.count(this)) user->friends.erase(this);
    }

    string getName() { return name; }
    string getEmail() { return email; }
    Status getStatus() { return status; }
    Status setStatus(Status newStatus) { status = newStatus; }
    ConnectionStatus getConnectionStatus() { return connectionStatus; }
    ConnectionStatus setConnectionStatus(ConnectionStatus newStatus) { connectionStatus = newStatus; }
    bool login(string pass)
    {
        if (pass == password)
        {
            status = ConnectionStatus::ONLINE;
            return true;
        }
        return false;
    }
    void logout()
    {
        status = ConnectionStatus::OFFLINE;
    }
    void newChat(vector<User*> participants)
    {
        Chat *c = new Chat();
        c->participants = list<User*>(participants);
        c->participants.push_back(this);

    }
    void sendMessage(Chat* chat, string message)
    {
        Message * msg = new Message({this, chat, message});
        if (find(chats.begin(), chats.end(), chat) != chats.end()))
        {
            chat->newMessage(msg);
            return true;
        }
        return false;
    }
    void deliverMessage(Message *msg)
    {
        if (sendMessageToClient(this, msg))
            return true;
        ConnectionStatus = ConnectionStatus::OFFLINE;
        return false;
    }
};

class Message
{
public:
    User* from;
    enum Status { SENT, DELIVERED, SEEN };
    Chat *chat;
    string body;
    int timestamp;
    Status status;

    Message (User* user, Chat* chatt, string text)
    : from(user), status(SENT), chat(chatt), timestamp(now())
    {}
};

class Chat
{
    list<Message*> messages;
    list<User*> participants;

    bool addUser(User *user)
    {
        participants.push_back(user);
        sendMessage(user, user->getName() + "joined the chat.\n");
    }
    void newMessage(Message *msg)
    {
        messages.push_back(msg);
        for(auto& participant : participants)
            if (participant != msg->from && participant->getConnectionStatus() == User::ConnectionStatus::ONLINE)
                participant->deliverMessage(msg);
    }
};

int main()
{

    return 0;
}
