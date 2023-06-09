//
// Created by abakh on 5/27/2023.
//

#ifndef XOGAME_XOGAME_H
#define XOGAME_XOGAME_H

#include <iostream>
#include <string>

using namespace std;

class XOGame {
private:
    char arr[5][5]{};
    char k = '1';
public:
    void newGame(char answer) {
        if (answer == 'Y' || answer == 'y') {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (i%2!=0 && j%2==0) {
                        arr[i][j] = '-';
                    }else if (j%2!=0) {
                        arr[i][j] = '|';
                    }else {
                        arr[i][j] = k;
                        ++k;
                    }
                }
            }
        }
    }
    void roundResult() {
        //Print code
        for (auto & i : arr) {
            for (char j : i) {
                cout << j;
            }
            cout << endl;
        }
    }
    void play(int num, Player pNum) {
        switch (num) {
            case 1:
                if (arr[0][0] == '1')
                    arr[0][0] = pNum.getPlayMark();
                break;
            case 2:
                if (arr[0][2] == '2')
                    arr[0][2] = pNum.getPlayMark();
                break;
            case 3:
                if (arr[0][4] == '3')
                    arr[0][4] = pNum.getPlayMark();
                break;
            case 4:
                if (arr[2][0] == '4')
                    arr[2][0] = pNum.getPlayMark();
                break;
            case 5:
                if (arr[2][2] == '5')
                    arr[2][2] = pNum.getPlayMark();
                break;
            case 6:
                if (arr[2][4] == '6')
                    arr[2][4] = pNum.getPlayMark();
                break;
            case 7:
                if (arr[4][0] == '7')
                    arr[4][0] = pNum.getPlayMark();
                break;
            case 8:
                if (arr[4][2] == '8')
                    arr[4][2] = pNum.getPlayMark();
                break;
            case 9:
                if (arr[4][4] == '9')
                    arr[4][4] = pNum.getPlayMark();
                break;
            default:
                break;
        }
    }
    bool checkWin(Player pNum) {
        char mark = pNum.getPlayMark();
        for (int i = 0; i < 5; i+=2) {
            if (arr[i][0] == mark && arr[i][2] == mark && arr[i][4] == mark) {
                return true;
            }
            if (arr[0][i] == mark && arr[2][i] == mark && arr[4][i] == mark) {
                return true;
            }
        }
        if (arr[0][0] == mark && arr[2][2] == mark && arr[4][4] == mark) {
            return true;
        }
        if (arr[0][4] == mark && arr[2][2] == mark && arr[4][0] == mark) {
            return true;
        }
        return false;
    }
};

#endif //XOGAME_XOGAME_H
