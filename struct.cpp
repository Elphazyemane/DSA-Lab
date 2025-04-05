#include <iostream>
#include <string>

namespace Yoseph {
    
    struct InstagramFriend {
        std::string name;
        std::string status;

       
        InstagramFriend(std::string n, std::string s) : name(n), status(s) {}
    };

  
    void displayValue(std::string item) {
        std::cout << "String value: " << item << '\n';
    }

    
    template <typename T>
    void displayValue(T item) {
        std::cout << ":) " << item << '\n';
    }

    
    void displayFriend(InstagramFriend friendObj) {
        std::cout << "Friend: " << friendObj.name << " - Status: " << friendObj.status << '\n';
    }
}

int main() {
    
    Yoseph::InstagramFriend friend1("Nahom", "Online");
    Yoseph::InstagramFriend friend2("Abel", "Offline");
    Yoseph::InstagramFriend friend3("Aymen", "Busy");

    
    Yoseph::displayFriend(friend1);
    Yoseph::displayFriend(friend2);
    Yoseph::displayFriend(friend3);

    
    Yoseph::displayValue("Hello, Instagram!");

    

    return 0;
}