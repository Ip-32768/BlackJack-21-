#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

string name;
int score_Chips = 20;

void status(string name, int chips) {
    cout << name << endl;
    cout << "Chips: " << chips << endl;
}

void startMatch() {
    int tempBet;
    do {
        cout << "Bet: ";
        cin >> tempBet;
    } while(tempBet > score_Chips || tempBet < 1);

    string hit_dec;
    srand(time(0));
    int plyrcrd1 = rand() % 11 + 1;
    int plyrcrd2 = rand() % 11 + 1;
    int cardValue [13] = {plyrcrd1, plyrcrd2};
    int cardNum = 2;
    int plyrTotalValue = plyrcrd1 + plyrcrd2;

    int hscrd1 = rand() % 11 + 1;
    int hscrd2 = rand() % 11 + 1;
    int houseCardValue = hscrd1 + hscrd2;
    do {
        if(plyrTotalValue > 21) {
            cout << "Over 21." << endl;
            break;    
        }

        cout << "House: " << endl;
        cout << "Card 1: " << hscrd1 << endl;
        cout << "Card 2: " << hscrd2 << endl;

        cout << name << ": " << endl;
        for(int i = 0; i < 13; i++) {
            if(cardValue[i] > 0) {
                cout << "Card " << i+1 << ": " << cardValue[i] << endl;
            }
        }

        cout << "Hit?" << endl;
        cin >> hit_dec;
        if(hit_dec == "hit") {
            srand(time(0));
            int plyrTempCard = rand() % 11 + 1;
            plyrTotalValue += plyrTempCard;
            cardValue[cardNum] = plyrTempCard;
            cardNum++;
        } else if("hold") {
            break;
        } else {
            break;
        }
    } while(hit_dec == "hit");

    if(plyrTotalValue > 21) {
        cout << "Over 21." << endl;
        score_Chips -= tempBet;
    } else {
        srand(time(0));
        int hscrd3 = rand() % 11 + 1;
        cout << "Card 3: " << hscrd3 << endl;
        houseCardValue += hscrd3;

        cout << "House Value: " << houseCardValue << endl;
        cout << "Player Value: " << plyrTotalValue << endl;

        if(houseCardValue > 21) {
            cout << "Player Wins." << endl;
            score_Chips += tempBet;
        } else {
            if(houseCardValue >= plyrTotalValue) {
               cout << "House Wins." << endl;
               score_Chips -= tempBet;
            } else {
                score_Chips += tempBet;
                cout << "Player Wins." << endl;
            }
        }
    }

}

int main() {
    cout << "Name: ";
    cin >> name;

    int dec = 0;
    while(score_Chips != 0) {
        status(name, score_Chips);
        cin >> dec;
        startMatch();
    }
    cout << "-Out of Chips-" << endl;
    return(0);
}
