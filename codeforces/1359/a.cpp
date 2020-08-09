#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    cin >> n_cases;

    while(n_cases--)
    {
        int cards, jokers, players;
        cin >> cards >> jokers >> players;
        
        int cards_in_hand = cards / players;
        if (jokers <= cards_in_hand)
        {
            // all jokers to the winner
            cout << jokers << '\n';
            continue;
        }
        // winner gets max jokers, and the rest of the jokers are distributed
        // equally between other players
        int points = 0;
        points = cards_in_hand - (int) ceil( (float) (jokers-cards_in_hand) / (float) (players-1));
        cout << points << '\n';
    }
    return 0;
}