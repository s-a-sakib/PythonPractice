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




// #include <iostream>
// #include <map>
// #include <vector>
// #include <bcrypt.h>

// class TextByAnonymous {
// private:
//     std::map<std::string, std::vector<std::string>> messages;  // username and message
//     std::map<std::string, std::wstring> users;  // username and hashed password

//     bool authenticate(const std::string& username, const std::wstring& password) {
//         return BCryptCheckPassword(password.c_str(), users[username].c_str()) == 0;
//     }

//     bool authenticate_user_exist(const std::string& username, const std::wstring& password) {
//         if (users.find(username) != users.end()) {
//             return false;
//         } else {
//             std::wstring hashed_password;
//             if (BCryptHashPassword(password.c_str(), NULL, &hashed_password) != 0) {
//                 std::cerr << "Error hashing password." << std::endl;
//                 return false;
//             }
//             users[username] = hashed_password;
//             messages[username].push_back("Welcome to TextByAnonymous");
//             return true;
//         }
//     }

//     bool get_message(const std::string& username, const std::string& message) {
//         auto it = users.find(username);
//         if (it != users.end()) {
//             messages[username].push_back(message);
//             return true;
//         } else {
//             return false;
//         }
//     }

//     void print_inbox(const std::string& username, const std::wstring& password) {
//         if (authenticate(username, password)) {
//             for (const auto& message : messages[username]) {
//                 std::cout << message << std::endl;
//             }
//         } else {
//             std::cout << "Authentication failed" << std::endl;
//         }
//     }

// public:
//     void login(const std::string& username, const std::wstring& password) {
//         print_inbox(username, password);
//     }

//     void create_user(const std::string& username, const std::wstring& password) {
//         if (authenticate_user_exist(username, password)) {
//             std::cout << "Account created successfully" << std::endl;
//             login(username, password);
//         } else {
//             std::cout << "This username already exists" << std::endl;
//         }
//     }

//     void send_message_to_user(const std::string& username, const std::string& message) {
//         if (get_message(username, message)) {
//             std::cout << "Message sent" << std::endl;
//         } else {
//             std::cout << "This user not found" << std::endl;
//         }
//     }
// };

// int main() {
//     TextByAnonymous textByAnonymous;
//     std::string username;
//     std::wstring password;
//     std::string text;

//     // creating the user
//     std::cin >> username >> text;
//     password.assign(text.begin(), text.end());
//     textByAnonymous.create_user(username, password);
//     std::wcout << std::endl;

//     // checking the username conflict
//     std::cin >> username >> text;
//     password.assign(text.begin(), text.end());
//     textByAnonymous.create_user(username, password);
//     std::wcout << std::endl;

//     // sending message to the user
//     std::cin >> username >> text;
//     textByAnonymous.send_message_to_user(username, text);
//     std::cin >> text;
//     textByAnonymous.send_message_to_user(username, text);
//     std::cin >> text;
//     textByAnonymous.send_message_to_user(username, text);
//     std::wcout << std::endl;

//     // checking inbox
//     textByAnonymous.login(username, password);

//     return 0;
// }
