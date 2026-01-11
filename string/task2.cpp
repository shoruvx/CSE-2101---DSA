#include <iostream>
using namespace std;

int main() {
    string text, target, repl;
    string result;

    cout << "Enter the sentence: ";
    getline(cin, text);
    cout << "Enter the target word: ";
    getline(cin,target);
    cout << "Enter the replacement word: ";
    getline(cin, repl);

    int i = 0, j = 0;

    while (text[i] != '\0') {
        int match = 1;
        int k = 0;

        while (target[k] != '\0') {
            if (text[i + k] != target[k]) {
                match = 0;
                break;
            }
            k++;
        }

        if (match && k > 0) {
            int r = 0;
            while (repl[r] != '\0') {
                result[j++] = repl[r++];
            }
            i += k; 
        } else {
            result[j++] = text[i++];
        }
    }

    result[j] = '\0';

    cout << result << endl;
    return 0;
}