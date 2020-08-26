#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

class Card
{
    public:
    enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    enum Value { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
                 NINE, TEN, JACK, QUEEN, KING };

    private:
        Value value;
        Suit suit;
        // string suitStr[4] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
        // 0x2660..0x2663
        string suitStr[4] = {"\u2660", "\u2661", "\u2662", "\u2663"};
        string valueStr[13] = { "A", "2", "3", "4", "5", "6", "7", "8",
                 "9", "10", "J", "Q", "K" };

    public:
    Card(Value v, Suit s) { Card::value = v; Card::suit = s; }
    Value getValue() { return Card::value; };
    string getValueStr() { return Card::valueStr[Card::value]; };
    Suit getSuit() { return Card::suit; };
    string getSuitStr() { return Card::suitStr[Card::suit]; };
    void print() { cout << Card::getValueStr() << " " << Card::getSuitStr(); }
};

class Deck
{
    private:
    list<Card*> generateDeckCards()
    {
        list<Card*> c;
        for(int i=0; i<52; i++)
            c.push_back(new Card(static_cast<Card::Value>(i%13), static_cast<Card::Suit>(i/13)));
        return c;
    }

    public:
    list<Card*> cards;

    Deck(bool fill = true)
    {
        if(fill)
            Deck::cards = generateDeckCards();
    }

    void shuffle()
    {
        vector<Card*> v({ Deck::cards.begin(), Deck::cards.end() });
        random_shuffle(v.begin(), v.end());
        Deck::cards = list<Card*>({v.begin(), v.end()});
    }

    // draw
    vector<Card*> Draw(int n = 1)
    {
        vector<Card*> v(n);
        for(auto& c : v)
        {
            c = Deck::cards.back();
            Deck::cards.pop_back();
        }
        return v;
    }

    void print()
    {
        for(auto& c : Deck::cards)
        {
            c->print();
            cout << ", ";
        }
        cout << endl;
    }

};

int main()
{
    Deck d;
    cout << "Created deck:\n";
    d.print();
    cout << "\nShuffling deck...\n";
    d.shuffle();
    cout << "Shuffled: ";
    d.print();

    cout << "\nDrawing 3 cards...";
    vector<Card*> hand = d.Draw(3);
    cout << "\nDrawn cards: ";
    for(auto& c : hand)
    {
        c->print();
        cout << "   ";
    }
    cout << "\nLeft on the deck: ";
    d.print();
    return 0;
}
