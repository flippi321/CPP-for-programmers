#include <iostream>

using namespace std;

int main() {    
    string word1;
    string word2;
    string word3;

    // Task A
    cout << "Hva er ditt første ord?" << endl;
    cin >> word1;
    cout << "Hva er ditt andre ord?" << endl;
    cin >> word2;
    cout << "Hva er ditt tredje ord?" << endl;
    cin >> word3;
    
    // Task  B
    string sentence = word1 + " " +  word2 + " " +  word3 + ".";
    
    // Task C
    cout << "Word 1 lenght: " << word1.length() << endl;
    cout << "Word 2 lenght: " << word2.length() << endl;
    cout << "Word 3 lenght: " << word3.length() << endl;
    cout << "Sentence lenght: " << sentence.length() << endl;

    // Task D
    string sentence2 = sentence;

    // Task E
    sentence.replace(10, 3, "xxx");

    // Task F
    string sentence_start = sentence.substr(0, 5);

    // Task G
    if (sentence.find("hallo") != std::string::npos) {
        cout << "The sentence contains 'hallo'" << endl;
    } else {
        cout << "The sentence does NOT contain 'hallo'" << endl;
    }

    // Task H
    int count = 0;

    for (int i = 0; i < sentence.size(); i++)
        if (sentence[i] == 'e' && sentence[i+1] == 'r') count++;

    cout << "'er' appears " << count << " times in the sentence" << endl;

}