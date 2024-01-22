class TextByAnonymous:
    def __init__(self):
        self.messages = {}  # username and message
        self.users = {}  # username and password
        self.PRIME_CONST = 31

    def hash_function(self, key):
        hash_code = 0
        for i in range(len(key)):
            hash_code += ord(key[i]) * pow(self.PRIME_CONST, i)
        return hash_code

    def authenticate(self, username, password):
        authenticate_password = self.hash_function(password)
        return self.users.get(username) == authenticate_password

    def authenticate_user_exist(self, username, password):
        if username in self.users:
            return False
        else:
            self.users[username] = self.hash_function(password)
            self.messages[username] = ["welcome to TextByAnonymous"]
            return True

    def get_message(self, username, message):
        if username in self.users:
            self.messages[username].append(message)
            return True
        else:
            return False

    def print_inbox(self, username, password):
        if self.authenticate(username, password):
            for message in self.messages[username]:
                print(message)
        else:
            print("Authentication failed")

    def login(self, username, password):
        self.print_inbox(username, password)

    def create_user(self, username, password):
        if self.authenticate_user_exist(username, password):
            print("Account created successfully")
            self.login(username, password)
        else:
            print("This username already exists")

    def send_message_to_user(self, username, message):
        if self.get_message(username, message):
            print("Message sent")
        else:
            print("This user not found")


def main():
    text_by_anonymous = TextByAnonymous()

    # creating the user
    username, password = input().split()
    text_by_anonymous.create_user(username, password)
    print()

    # checking the username conflict
    username, password = input().split()
    text_by_anonymous.create_user(username, password)
    print()

    # sending message to the user
    username, text = input().split()
    text_by_anonymous.send_message_to_user(username, text)
    text_by_anonymous.send_message_to_user(username, input())
    text_by_anonymous.send_message_to_user(username, input())
    print()

    # checking inbox
    text_by_anonymous.login(username, password)


if __name__ == "__main__":
    main()
