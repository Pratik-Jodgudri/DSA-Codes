#include <bits/stdc++.h>
using namespace std;

int main()
{
    string table, hand;
    cin >> table;

    int flag = 0;
    for (int i = 0; i < 5; i++){
        cin >> hand;
        if (table[0] == hand[0] || table[1] == hand[1]){
            flag = 1;
        }
    }

    if (flag){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}