#include <iostream>
#include <math.h>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <deque>
#include <fstream>
using namespace std;

int main()
{
    string str = "abc dfwef dsafsf qwerwer qwerew rqwer qwer";

    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0 || str[i - 1] == ' ')
            str[i] = toupper(str[i]);
    }
    cout << str;
}