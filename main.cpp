#include <iostream>
#include "Player.h"
#include "XOGame.h"

using namespace std;

int main() {

    XOGame game;
    Player p1, p2;
    char answer;
    char anotherGame;


    cout << "\t---Start new game---\n";
    cout << "y/n: ";
    cin >> answer;
    do{
        //===============Player1Info===============
        string p1Name;
        char p1Mark;
        bool isPlayable;
        cout << "\t--Player1-- \n";
        cout << "Name: ";
        cin >> p1Name;
        p1.setName(p1Name);
        cout << "Choose-> X or O: ";
        do {
            cin >> p1Mark;
            if (p1Mark == 'x' || p1Mark == 'o') {
                p1Mark -= 32;
                isPlayable = true;
                p1.setPlayMark(p1Mark);
            }else {
                cout << "!valid mark" << endl;
                cout << "Mark must be X or O: ";
                isPlayable = false;
            }
        }while(!isPlayable);
        cout << "Your mark is: " << p1Mark << endl;


        //===============Player2Info===============
        string p2Name;
        cout << "\t--Player2-- \n";
        cout << "Name: ";
        cin >> p2Name;
        p2.setName(p2Name);
        if (p1Mark == 'X') {
            p2.setPlayMark('O');
            cout << "Your mark is: O";
        }else {
            p2.setPlayMark('X');
            cout << "Your mark is: X";
        }

        cout << endl << endl;

        //==========GameStarted==========

        game.newGame(answer);
        game.roundResult();

        //=========GameRound=============



        int arrNum;
        int i;
        for (i = 1; i <= 9 ; ++i) {
            if (i % 2 != 0) {
                cout << "Round " << i << "(1~9)?\n";
                cout << p1.getName() << ": ";
                cin >> arrNum;
                game.play(arrNum, p1);
                game.roundResult();
                if (game.checkWin(p1))
                    break;
            }
            if (i % 2 == 0) {
                arrNum = 0;
                cout << "Round " << i << "(1~9)?\n";
                cout << p2.getName() << ": ";
                cin >> arrNum;
                game.play(arrNum, p2);
                game.roundResult();
                if (game.checkWin(p2))
                    break;
            }
        }
        if (game.checkWin(p1)) {
            cout << p1.getName() << " Winner" << endl;
        }else if (game.checkWin(p2)) {
            cout << p2.getName() << " Winner" << endl;
        }else {
            cout << "Tie game" << endl;
        }

        //====================================//

        cout << "\n====Do you want to play again?====\n";
        cout << "y/n: ";
        cin >> anotherGame;

        //===================================//
    }while (anotherGame == 'y');
    return 0;
}
