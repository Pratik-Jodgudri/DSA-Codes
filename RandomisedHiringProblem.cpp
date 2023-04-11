#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct candidate
{
    int rank, interview_status;
};

int main()
{
    int n, no_hired = 0;
    n = 8;

    // only the ranks of the various candidates are given as input
    struct candidate cand[] = {{6}, {4}, {12}, {11}, {13}, {10}, {15}, {8}};
    // as per the input array, candidate at index 6 has the highest rank

    // below code is for taking inputs from the user
    /*	cout<<"enter the number of candidates\n";
        cin>>n;
        struct candidate *cand=new struct candidate[n];
        for(int i=0;i<n;i++)
          cin>>cand[i].rank;*/

    int best = -1;
    srand(time(0));

    int index;
    for (int i = 0; i < n; i++)
    {
        do
        {
            index = rand() % n; // since upper-lower=n-0=n
        } while (cand[index].interview_status == 1);
        // if the same number which was generated already is generated again, call rand() again

        cand[index].interview_status = 1;
        // cout<<"index "<<index<<"\n";

        if (best == -1)
        {
            best = index;
            no_hired += 1;
        }

        else if (cand[index].rank > cand[best].rank)
        {
            best = index;
            no_hired += 1;
        }
    }

    cout << "nr of hired candidates is " << no_hired << "\n";
    cout << "best candidate index and rank " << best << ", " << cand[best].rank;

    return 0;
}
