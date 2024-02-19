///////// importante, el nombre de usuario es Aris,
////////
//////// la contrasena es 123, para ingresar como seller el id es 54321 y como client 12345
///////

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class User {
protected:
    string Name;
    string Tel;
    int Age;
    string Password;

public:
    User(string _Name, string _Tel, int _Age, string _Password)
            : Name(_Name), Tel(_Tel), Age(_Age), Password(_Password) {}

    virtual void Login(string name, string password) {
        if (name == Name && password == Password) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid username or password." << endl;
        }
    }

    void Logout() {
        cout << Name << " has logged out." << endl;
    }

    bool ChangePsw(string oldPsw, string newPsw) {
        if (oldPsw == Password) {
            Password = newPsw;
            cout << "Password changed successfully!" << endl;
            return true;
        } else {
            cout << "Incorrect old password!" << endl;
            return false;
        }
    }
};

class Client : public User {
private:
    string IdClient;

public:
    Client(string _Name, string _Tel, int _Age, string _Password, string _IdClient)
            : User(_Name, _Tel, _Age, _Password), IdClient(_IdClient) {}

    void Buy() {
        cout << Name << " is buying." << endl;
    }

    void Claim() {
        cout << Name << " is claiming." << endl;
    }

    void SendBack() {
        cout << Name << " is sending back." << endl;
    }

    void ClientOptions() {
        bool continueSession = true;
        while (continueSession) {
            int option;
            cout << "Select an option:\n";
            cout << "1. Buy\n";
            cout << "2. Claim\n";
            cout << "3. Send back\n";
            cout << "4. Change password\n";
            cout << "5. Logout\n";
            cin >> option;

            switch (option) {
                case 1:
                    Buy();
                    break;
                case 2:
                    Claim();
                    break;
                case 3:
                    SendBack();
                    break;
                case 4:
                {
                    string newPass;
                    cout << "Enter new password: ";
                    cin >> newPass;
                    ChangePsw(Password, newPass);
                }
                    break;
                case 5:
                    continueSession = false;
                    Logout();
                    break;
                default:
                    cout << "Invalid option!" << endl;
                    break;
            }
        }
    }
};

class Seller : public User {
private:
    string IdSeller;

public:
    Seller(string _Name, string _Tel, int _Age, string _Password, string _IdSeller)
            : User(_Name, _Tel, _Age, _Password), IdSeller(_IdSeller) {}

    void Sell() {
        cout << Name << " is selling." << endl;
    }

    void Update(string productName, double newPrice) {
        cout << "Product " << productName << " updated. New price: " << newPrice << endl;
    }

    void SellerOptions() {
        bool continueSession = true;
        while (continueSession) {
            int option;
            cout << "Select an option:\n";
            cout << "1. Sell\n";
            cout << "2. Update\n";
            cout << "3. Change password\n";
            cout << "4. Logout\n";
            cin >> option;

            switch (option) {
                case 1:
                    Sell();
                    break;
                case 2:
                {
                    string productName;
                    double newPrice;
                    cout << "Enter product name: ";
                    cin >> productName;
                    cout << "Enter new price: ";
                    cin >> newPrice;
                    Update(productName, newPrice);
                }
                    break;
                case 3:
                {
                    string newPass;
                    cout << "Enter new password: ";
                    cin >> newPass;
                    ChangePsw(Password, newPass);
                }
                    break;
                case 4:
                    continueSession = false;
                    Logout();
                    break;
                default:
                    cout << "Invalid option!" << endl;
                    break;
            }
        }
    }
};

int main() {
    string name, password;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your password: ";
    cin >> password;

    if (name == "Aris" && password == "123") {
        string userType;
        cout << "Enter 'client' or 'seller': ";
        cin >> userType;

        if (userType == "client") {
            string idClient = "12345";
            cout << "Enter your Client ID: ";
            cin >> idClient;
            auto client = make_shared<Client>(name, "123456789", 22, password, idClient);
            client->Login(name, password);
            client->ClientOptions();
        } else if (userType == "seller") {
            string idSeller = "54321";
            cout << "Enter your Seller ID: ";
            cin >> idSeller;
            auto seller = make_shared<Seller>(name, "123456789", 22, password, idSeller);
            seller->Login(name, password);
            seller->SellerOptions();
        }
    } else {
        cout << "Invalid credentials." << endl;
    }

    return 0;
}
