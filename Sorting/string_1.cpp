#include <bits/stdc++.h>

using namespace std;

int main() {
    string password;
    bool hasUpper = false, hasLower = false, hasSpecial = false;
    string specialChars = "!@#$%^&*()";

    for (char c: password) {
        if (isupper(c)) hasUpper=true;
        if (islower(c)) hasLower=true;
        if (specialChars.find(c) != string::npos) hasSpecial = true;
    }
    
    return 0;
}