/*
* @Author: Yedarm Seong
* @Date:   2021-09-24 03:25:34
* @Last Modified by:   Yedarm Seong
* @Last Modified time: 2021-09-24 03:25:45
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    // 미로 선언
    // 0: 길, 1: 벽, -1: 탈출지점
    vector<vector<short>> maze = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, -1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    // 방문 여부 확인
    // 길: false, 벽: true, 탈출지점: false
    vector<vector<bool>> visited = {
        {true, true, true, true, true, true, true, true},
        {true, false, true, false, false, false, true, true},
        {true, false, true, false, true, false, true, true},
        {true, false, true, false, true, true, true, true},
        {true, false, true, false, true, true, true, true},
        {true, false, true, false, false, false, false, true},
        {true, false, false, false, true, true, false, false},
        {true, true, true, true, true, true, true, true},
    };

    // X, Y 좌표를 담을 스택
    stack<pair<int, int>> st;

    int myY = 1;
    int myX = 1;

    // 스택에 두 개의 자료형을 담고싶은 경우 make_pair을 통해 pair로 만들어야 함
    st.push(make_pair(myY, myX));

    while (!st.empty()) {
        // 스택의 최상단 정보
        pair<int, int> element = st.top();
        // Y가 먼저인 이유는 vector of vector의 첫번째 원소가 Y열을 담당하기 때문
        myY = element.first;
        myX = element.second;
        visited[myY][myX] = true;
        cout << myY << ' ' << myX << endl;
        
        // 스택 pop
        st.pop();

        // 탈출에 성공했으면
        if (maze[myY][myX] == -1)
            break;

        if (maze[myY - 1][myX] != 1 && visited[myY - 1][myX] == false) // 위쪽
            st.push(make_pair(myY - 1, myX));
        if (maze[myY][myX - 1] != 1 && visited[myY][myX - 1] == false) // 왼쪽
            st.push(make_pair(myY, myX - 1)); 
        if (maze[myY + 1][myX] != 1 && visited[myY + 1][myX] == false) // 아래쪽
            st.push(make_pair(myY + 1, myX));
        if (maze[myY][myX + 1] != 1 && visited[myY][myX + 1] == false) // 오른쪽
            st.push(make_pair(myY, myX + 1));
    }
    cout << "maze escape!" << endl;

    return 0;
}