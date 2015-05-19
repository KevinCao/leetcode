#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s);

int main(int argc, char** argv) {
    if(2 != argc) {
        cout << "Please input test string" << endl;
        return 1;
    }

    string s(argv[1]);
    cout << s << " is palindromw ? " << isPalindrome(s) << endl;

    return 0;
}

bool isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9');
}

bool isPalindrome(string s) {
    if (s.size() == 0)
        return true;

    int left_index = 0;
    int right_index = s.size() - 1;

    bool has_difference = false;
    while(!has_difference && left_index < right_index) {
        char left_char = s[left_index];
        char right_char = s[right_index];

        if(left_char == right_char) {
            left_index++;
            right_index--;
            continue;
        }
        if (!isAlphanumeric(left_char)) {
            left_index++;
            continue;
        }
        if(!isAlphanumeric(right_char)) {
            right_index--;
            continue;
        }

        if(left_char >= 'a' && left_char <= 'z') {
            left_char += 'A' - 'a';
        }

        if(right_char >= 'a' && right_char <= 'z') {
            right_char += 'A' - 'a';
        }

        if(left_char != right_char) {
            has_difference = true;
        } else {
            left_index++;
            right_index--;
        }

    }
    return !has_difference;
}
