#include <iostream>
using namespace std;

class phone
{
public:
    string mb_name, year, camer_res, memory_card, operating_sys;
    int ram;
    void fill()
    {
        cout << "Mobile name : " << endl;
        cin >> mb_name;
        cout << "Enter year : " << endl;
        cin >> year;
        cout << "Enter camer_res : " << endl;
        cin >> camer_res;
        cout << "Enter Ram : " << endl;
        cin >> ram;
        cout << "Enter memory_card : " << endl;
        cin >> memory_card;
        cout << "Enter operating : " << endl;
        cin >> operating_sys;
    }

    void print()
    {
        cout << mb_name << endl;
        cout << year << endl;
        cout << camer_res << endl;
        cout << ram << endl;
        cout << memory_card << endl;
        cout << operating_sys << endl;
        cout << endl;
        cout << endl;
    }
};

int main()
{
    int numberOfmobile;
    cout << "Enter number of mobile phone : "
         << " ";
    cin >> numberOfmobile;
    phone area[numberOfmobile];
    for (int i = 0; i < numberOfmobile; i++)
        area[i].fill();

    for (int step = 1; step < numberOfmobile; step++)
    {
        int key = area[step].ram;
        int j = step - 1;
        while (key < area[j].ram && j >= 0)
        {
            area[j + 1] = area[j];
            j--;
        }
        area[j + 1] = area[step];
    }
    for (int i = 0; i < numberOfmobile; i++)
    {
        area[i].print();
    }
    return 0;
}