#include <bits/stdc++.h>
using namespace std;

// Normal Recursion
int fibRec(int num) {
    if(num == 0 || num == 1) return num;
    return fibRec(num-1) + fibRec(num-2);
}

// Memoization 
int fibMem(int num, vector<int>&fibs) {
    if(num == 0 || num == 1) return num;
    if(fibs[num] != -1) 
        return fibs[num];
    return fibs[num] = fibMem(num-1,fibs) + fibMem(num-2,fibs);
}

// Tabulariztion (bottom-up)
int fibTab(int num, vector<int>&fibs) {
    fibs[0] = 0;
    fibs[1] = 1;
    for (int i = 2; i < num+1; i++)
    {
       fibs[i] = fibs[i-1]+fibs[i-2];
    }
   return fibs[num];
}

// Space optimzed bottom-up
int fibTabSpaceOptimezed(int num, vector<int>&fibs) {
    int prev = 0;
    int next = 1;
    int temp;
    for (int i = 2; i < num+1; i++)
    {
        temp = prev+next;
        prev = next;
        next = temp;
    }
   return next;
}


int main()
{
    vector<int>nums(11, -1);
    cout << fibTabSpaceOptimezed(10, nums) << endl;
    return 0;
}
