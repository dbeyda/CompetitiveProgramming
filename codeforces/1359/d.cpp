#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCards;
    cin >> nCards;

    vector<int> cards(nCards);
    for(auto& c : cards) cin >> c;
    
    int seqStart=0, seqEnd=0, seqSum=cards[0], seqMax=cards[0];
    int deltaStart=1, deltaSum=0, deltaMax=INT_MIN;

    for(int i=1; i<nCards; i++)
    {
        deltaSum += cards[i];
        deltaMax = max(deltaMax, cards[i]);

        if(deltaSum + seqSum - max(deltaMax, seqMax) > seqSum - seqMax)
        {
            // incorpora
            seqEnd = i;
            seqSum += deltaSum;
            seqMax = max(seqMax, deltaMax);
            deltaSum = 0;
            deltaMax = INT_MIN;
            deltaStart = i;
        }
        if((seqSum - seqMax) < deltaSum - deltaMax)
        {
            //reinicia
            seqStart = deltaStart;
            seqEnd = i;
            seqSum = deltaSum;
            seqMax = deltaMax;

            deltaStart = i+1;
            deltaSum = 0;
            deltaMax = INT_MIN;
        }
    }

    cout << seqSum - seqMax << '\n';

    return 0;
}