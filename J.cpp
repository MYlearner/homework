#include <bits/stdc++.h>
using namespace std;
const int row = 6,column = 4;
int main() {
    int map[row][column];
    for (int i = 0; i < row; i++)
    for (int j = 0; j < column; j++)
        cin >> map[i][j];

    int num[7];
    int target;
    num[map[1][0]] = map[1][2];
    num[map[1][2]] = map[1][0];
    for (int i = 0; i < column; i++) {
        if(map[0][i]) {
            for (int j = 0; j < column; j++)
                if(map[2][j]) {
                    num[map[0][i]] = map[2][j];
                    num[map[2][j]] = map[0][i];

                    int last = 21-map[0][i]-map[2][j]-map[1][0]-map[1][2] - map[1][1];
                    num[map[1][1]] = last;
                    num[last] = map[1][1];
                    break;
                }
            break;
        }
    }
    if(num[map[4][0]] != map[4][2]) {
        cout<<"NO\n";
    }
    else {
        for (int i = 0; i < column; i++)
        {
            if(map[3][i]) {
                for (int j = 0; j < column; j++)
                {
                    if(map[5][j]) {
                        if(num[map[3][i]] != map[5][j]) {
                            cout<<"NO\n";
                        }
                        else {
                            cout<<"YES\n";
                        }
                        return 0;
                    }
                }
                
                
            }
        }
        
    }
    
    
}
