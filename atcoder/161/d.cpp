#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void getDigits(long long n, vector<int>& v)
{
    // cout << "getting digits of: " << n << " ==> ";
    v.clear();
    while (n > 0)
    {
        v.push_back(n%10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    // for( auto& i : v) cout << i << " ";
    // cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int found = 0;
    vector<int> digits;

    cin >> n;

    long long i=1;
    while(found < n)
    {
        // cout << "testing i=" << i << endl;
        getDigits(i, digits);
        bool is_lun = true;

        // test if number i is lunlun number
        for(int j=0; j<digits.size()-1; j++)
        {
            if (digits[j+1] < digits[j] -1)
            {
                i += (digits[j] - digits[j+1] -1) * pow(10, digits.size()-j-2);
                is_lun = false;
            }
            else if (digits[j+1] > digits[j] + 1)
            {
                i -= i % (int) pow(10, digits.size()-j-1);
                i += pow(10, digits.size()-j-1);
                is_lun = false;
                break;
            }
        }

        // update number of lunlun found
        if (is_lun) 
        {
            found++;
            i++;
        }
    }

    cout << i-1 << endl;
    return 0;
}
