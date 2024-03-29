#include <iostream>
#include <string>
#include <regex>

class PasswordChecker {
public:
    PasswordChecker() {}

    std::string checkPasswordStrength(const std::string& password) {
        if (password.length() < 8) {
            return "Weak";
        } else if (!containsUppercase(password) || !containsLowercase(password) || !containsDigit(password)) {
            return "Medium";
        } else {
            return "Strong";
        }
    }

private:
    bool containsUppercase(const std::string& str) {
        return std::regex_search(str, std::regex("[A-Z]"));
    }

    bool containsLowercase(const std::string& str) {
        return std::regex_search(str, std::regex("[a-z]"));
    }

    bool containsDigit(const std::string& str) {
        return std::regex_search(str, std::regex("[0-9]"));
    }
};

int main() {
    PasswordChecker passwordChecker;

    
    std::string password;
    std::cout << "Enter your password: ";
    std::cin >> password;

    std::string strength = passwordChecker.checkPasswordStrength(password);
    std::cout << "Password Strength: " << strength << std::endl;

    return 0;
}
