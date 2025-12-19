#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> card;
    for(int i=1; i<=n; i++) {
        card.emplace(i);
    }

    while(card.size() > 1) {
        card.pop();
        int temp = card.front();
        card.pop();
        card.emplace(temp);
    }

    cout << card.front() << "\n";

    return 0;
}