#include <iostream>

using namespace std;

int main() {    
    string word1;
    string word2;
    string word3;

    // Task A
    cout << "Hva er ditt første ord?" << endl;
    cin >> word1;
    cout << "[Fikk inn: " << word1 << " ]" << endl;
    cout << "Hva er ditt andre ord?" << endl;
    cin >> word2;
    cout << "[Fikk inn: " << word2 << " ]" << endl;
    cout << "Hva er ditt tredje ord?" << endl;
    cin >> word3;
    cout << "[Fikk inn: " << word3 << " ]" << endl;
    
    // Task  B
    string sentence = word1 + " " +  word2 + " " +  word3 + ".";
    cout << "Vi har setningen: " << sentence << endl;
    
    // Task C
    cout << "Word 1 har lengden: " << word1.length() << endl;
    cout << "Word 2 har lengden: " << word2.length() << endl;
    cout << "Word 3 har lengden: " << word3.length() << endl;
    cout << "Setningen har lengden: " << sentence.length() << endl;

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

    cout << "'er' dukker opp " << count << " ganger i setningen" << endl;

}