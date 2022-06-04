//author : Ziad Mohammed ibrahim
#include <iostream>
#include <string>
using namespace std;
string row_alphabet = "ABCDEFGHJKLMNOPQRSTUVWXYZ";
string col_alphabet = "AFLQVBGMRWCHNSXDJOTYEKPUZ";

void encryption(string word, char key[5]) {
    for (int i{}; i < word.size(); i++) {
        for (int j{}; j < 25; j++) {
            if (word[i] == col_alphabet[j])
                cout << key[j % 5];
            if (word[i] == row_alphabet[j])
                cout << key[j % 5];
        }
    }
}
string decryption(string word, char key[5]) {

    string decrypted_word = "";
    int k{};
    for (int i{}; i < word.size(); i++) {
        if (i % 2 == 0) {
            for (int j{}; j < 5; j++) {
                if (word[i] == key[j])
                    k = j * 5;
                if (word[i + 1] == key[j])
                    decrypted_word += row_alphabet[k + j];
            }
        }
    }
    return decrypted_word;
}
string ToUpperCase(string lower_word) {
    string upper_word = "";
    for (int i{}; i < lower_word.size(); i++) {
        if (lower_word[i] == 'I' || lower_word[i] == 'i')
            upper_word += 'J';
        else
            upper_word += toupper(lower_word[i]);
    }
    return upper_word;

}
int main()
{
    char key[5]{};
    cout << "Enter your key separated by spaces: ";
    for (int i{}; i < 5; i++)
        cin >> key[i];
    while (true) {
        cout << "\n1.To cipher a text\n2.To decipher a text\n3.To enter a new key\n4.To exit";
        string word{};
        cout << "\nEnter a word: ";
        cin >> word;
        cout << "\nEnter your choice: ";
        int choice; cin >> choice;
        string upper_word = ToUpperCase(word);
        switch (choice) {
            cin >> word;
            upper_word = ToUpperCase(word);
            case 1:
                encryption(upper_word, key);
                break;
            case 2 :
                cout << decryption(word, key);
                break;
            case 3:
                cout << "Enter your key separated by spaces: ";
                for (int i{}; i < 5; i++)
                    cin >> key[i];
                break;
            case 4:
                return 0;
            }
        }
    return 0;
}