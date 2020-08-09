#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    int t;
    scanf("%d", &t);
    while((c = getchar()) != EOF)
	    putchar(c == '1' ? '2' : c);
    return 0;
}