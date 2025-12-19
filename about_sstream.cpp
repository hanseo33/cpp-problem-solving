// this is a code using sstream. 
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    stringstream ss(str);

    string word;
    int word_count = 0;
    while(ss >> word) word_count++;

    cout << word_count;

    return 0;
}
// and this is a code counting every event.
#include <iostream>

using namespace std;

int main() {
    string str;
    int wcount = 1;
    getline(cin, str);
    if(str[0]==' ') wcount--;
    if(str[str.length()-1]==' ') wcount--;
    for(char c : str) {
        if(c==' ') wcount++;
    }

    cout << wcount;
    return 0;
}

/*
    second one was faster than first one. but looks more complicated.
*/