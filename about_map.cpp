#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // map 사용
    map<string, double> costs = {
        {"Paper", 5799},
        {"Printer", 12050},
        {"Planners", 3125},
        {"Binders", 2250},
        {"Calendar", 1095},
        {"Notebooks", 1120},
        {"Ink", 6695}
    };

    long long sum = 0;
    string input;

    while(true) {
        cin >> input;
        if(input=="EOI") break;
        sum += costs[input];
    }

    long long dollar = sum / 100;
    long long cent = sum % 100;

    cout << fixed << setprecision(2);
    cout << "$" << dollar << '.';
    // cent자리가 한지리면 앞에 0을 채워주기
    cout << setfill('0') << setw(2) << cent << endl;

    return 0;
}

int main() {
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        map<string, int> clothes;

        clothes.clear();
       
        int n;
        cin >> n;

        for(int j = 0; j < n; j++) {
            string name, type;
            cin >> name >> type; 

            // name은 중요하지 않음... 어처피 갯수만 따질꺼라서
            clothes[type]++;
        }
  
        long long result = 1;
    
        for(auto& pair : clothes) {
            result *= (pair.second + 1);
        }
    
        cout << result - 1 << '\n';
    }

    return 0;
}