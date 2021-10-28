// week6BLewisPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    //strings
    string S = "ATGGATGAGTT";
    string Y = "AT";
    string L = "TGG";
    string R = "TT";
    string X = "TT";
    int lengthOfL = L.length();
    //loop through string
    bool stringIsCorrect = false;
    int j, k;
    for (int i = 0; i < S.length(); i++)
    {
        //if we find the first character of Y
        if (S[i] == Y[0])
        {
            //at each character, loop for the length of Y to see if Y is there
            stringIsCorrect = true;
            for (j = i + 1, k = 1; j < Y.length() - 1 && stringIsCorrect; j++, k++)
            {
                if (S[j] != Y[k])
                {
                    stringIsCorrect = false;
                }
            }
        }
        //we have either found Y or not
        if (stringIsCorrect)
        {
            //we have found Y
            //check before and after for L and not R
            //loop back from i
            int LisCorrect = 1;
            bool LisThere = false;
            for (int a = i - L.length(), b = 0; a > 0 && b < L.length(); a++, b++)
            {
                if (S[a] == L[b])
                {
                    //L is there
                    LisCorrect++;
                }
            }
            if (LisCorrect == L.length())
            {
                LisThere = true;
            }
            //if LisThere is true then L is before Y
            bool RisNotThere = false;
            int RisCorrect = 1;
            for (int a = j + 1, b = 0; a < S.length() && b < R.length(); a++, b++)
            {
                if (S[a] != R[b])
                {
                    //R is there
                    RisCorrect++;
                }
            }
            if (RisCorrect == R.length())
            {
                RisNotThere = true;
            }
            //at this point we know whether we can replace
            if (RisNotThere && LisThere)
            {
                cout << "position " << i << " can replace" << endl;
            }
        }
    }
}
