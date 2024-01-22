#include <bits/stdc++.h>
using namespace std;

class TextByAnnonymous{
    private:
        map < string, vector<string> > messages; // username and message
        map < string, int > users; // username and password

        // hashed algorithm
        const int PRIME_CONST = 31;
        int hashFunction(string key) {
            int hashCode = 0;
            for (int i = 0; i < key.length(); i++) {
                hashCode += key[i] * pow(PRIME_CONST, i);
            }
            return hashCode;
        }
        bool authenticate(string username, string password){
            int authenticate_password = hashFunction(password);
            if(users[username] == authenticate_password) return true;
            else return false;
        }
        // Create a new user
        bool authenticate_user_exist(string username, string password){
            if(users[username]){
                return false;
            }else{
                users[username] = hashFunction(password);
                messages[username].push_back("welcome to TextByAnnonymous");
                return true;
            }
        }
        bool get_message(string username, string message) {
            if(users[username]){
                messages[username].push_back(message);
                return true;
            }else{
                return false;
            }
        }
        void printInbox(string username, string password){
            if(authenticate(username, password)){
                for(auto message : messages[username]){
                    cout << message << endl;
                }
            }else{
                cout << "Authentication failed" << endl;
            }
        }
    public:
        void login(string username, string password){
            printInbox(username, password);
        }
        void create_user(string username, string password){
            if(authenticate_user_exist(username, password)){
                cout << "Accounts created successfully" << endl;
                login(username, password);
            }else{
                cout << "This username already exists" << endl;
            }
        }
        void send_message_to_user(string username, string message){
            if(get_message(username, message)){
                cout << "Message sent" << endl;
            }else{
                cout << "This user not found" << endl;
            }
        }     
};

int main(){
    TextByAnnonymous textByAnnonymous = TextByAnnonymous();
    string username , password , text;

    // creating the user
    cin >> username >> password;
    textByAnnonymous.create_user(username, password);
    cout << endl;
    // cheaking the username confickt
    cin >> username >> password;
    textByAnnonymous.create_user(username, password);
    cout << endl;
    //sending message to sakib_cse
    cin >> username >> text;
    textByAnnonymous.send_message_to_user(username, text);
    cin >> text;
    textByAnnonymous.send_message_to_user(username, text);
    cin >> text;
    textByAnnonymous.send_message_to_user(username, text);
    cout << endl;
    //cheaking inbox
    textByAnnonymous.login(username, password);

    return 0;
}