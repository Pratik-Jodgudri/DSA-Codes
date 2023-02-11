#include <stdio.h>

void tower_of_hanoi(int n, char frompeg, char topeg, char auxpeg)
{
    if(n == 1)
    {
        printf("Move disk from rod %c to %c\n", frompeg, topeg);
    }
    else
    {
        tower_of_hanoi(n-1, frompeg, auxpeg, topeg);
        printf("Move disk from rod %c to %c\n", frompeg, topeg);
        tower_of_hanoi(n-1, auxpeg, topeg, frompeg);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
    
}