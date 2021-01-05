#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
using namespace std;
typedef long long lld;

char ch[10001];

int amt[30];
int tot;
int count_odd = 0;

int main()
{
    scanf("%s",&ch);
    int L = strlen(ch);
    for (int i=0;i<L;i++)
    {
        amt[ch[i]-'a']++;
    }
    for (int i=0;i<26;i++)
    {
        if (amt[i] % 2 == 1) count_odd++;
    }
    if (count_odd == 0)
    {
        printf("First\n");
        return 0;
    }
    if (count_odd == 1)
    {
        printf("First\n");
        return 0;
    }
    if (count_odd % 2 == 0)
    {
        printf("Second\n");
        return 0;
    }
    printf("First\n");
    return 0;
}