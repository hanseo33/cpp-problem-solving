#include <iostream>
#include <vector>
#include <algorithm> // sort를 쓰기 위해서
#include <utility> // pair를 쓰기 위해서

using namespace std;

void printVec(vector<pair<int, int>> vec) {
    for(const auto& p : vec) {
        cout << p.first << ", " << p.second << " / ";
    }
    cout << endl;
}

void printVec(vector<long long > vec) {
    for(const auto& p : vec) {
        cout << p << " / ";
    } 
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    // 모듈을 입력받은 순서와 함께 저장하기
    vector<pair<int, int>> vec_pairs;
    int input;
    for(int i=0; i<n; i++) {
        cin >> input;
        vec_pairs.push_back({input, i+1});
    }

    // first를 기준으로 정렬
    sort(vec_pairs.begin(), vec_pairs.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    });

    // // 내림차순으로 정렬된 vec_pairs
    // cout << "sorted vec_pairs : ";
    // printVec(vec_pairs);

    vector<long long> sum_Max_to_j;
    sum_Max_to_j.emplace_back(vec_pairs[0].first);
    for(int i=1; i<vec_pairs.size(); i++) {
        sum_Max_to_j.emplace_back(sum_Max_to_j[i-1] + vec_pairs[i].first);
    }

    // // 중간 출력하기
    // cout << "sum_Max_to_j : ";
    // printVec(sum_Max_to_j);

    // 최종 점수 중 어느 것이 가장 큰지 비교, 저장 (Max점수 값은 동일하기에 다같이 책정 안함)
    long long F_score = vec_pairs[0].first + sum_Max_to_j[0];
    int index_of_j = 0;
    for(int i=1; i<vec_pairs.size(); i++) {
        long long temp = vec_pairs[i].first + sum_Max_to_j[i];
        if(temp > F_score) {
            F_score = temp;
            index_of_j = i;
        }
    }

    // // 중간 출력하기
    // cout << F_score << " , " << index_of_j << endl;

    // 최종 결과 출력하기
    cout << index_of_j+1 << endl;
    vector<int> sorted_index;
    for(int i=0; i<=index_of_j; i++) {
        sorted_index.emplace_back(vec_pairs[i].second);
    }
    sort(sorted_index.begin(), sorted_index.end());
    for(const auto& v : sorted_index) {
        cout << v << " ";
    }

    return 0;
}

/*
    근데 set으로 풀려 하면 처음에 입력받았던 모듈 번호를 기억해야 하는데 그걸 어떻게 해야하는지 잘 모르겠다...
    sort를 써야하나? 이거 알아봐야겠다.
    우선 가장 큰 값은 버릴 필요가 없는 것 같다. 
    가장 작은 값을 뺄지말지 골라야하는데 두번 째로 작은 값과의 차이와 가장 작은 값을 계산해봐야 할 것 같다.
    5 1 7 2 이라고 하면, 우선 정렬을 하면 1 2 5 7이다. 하나씩 해보면 #1은 최소 값 1이고, #2는 7이다. #3은 15이다. 총 23이다.
    여기서 1을 뺀다 라고 하면 #1이 2가 되고, #2는 그대로 7, #3은 14가 되어서 총 23이다. 여기까지는 총 결과가 같아진다. 
    그 다음으로 2를 제외한다고 하면 #1은 5가되고, #2는 그대로 7, #3은 12가 된다. 총 24이다.
    만약 5까지 뺀다면 #1은 7, #2는 7, #3은 7로 21로 감소하게 된다.
    그렇다면 가장 큰 값은 무조건 넣는다고 생각하였을 때
    가장 작은값 x, 그다음으로 작은 값 y라고 할때 전체 값을 total이라고 하자.
    total - 2x + y가 다음 제외했을 경우 값이 된다. 좋다. 계산은 이렇게 하면 되겠다.
    그렇다면 정렬을 하고 순서를 어떻게 정해야 할까...
    우선 배열로 받고 새로운 sort배열을 만들고 최대 값을 구하고, 배열이랑 비교해볼까?

*/