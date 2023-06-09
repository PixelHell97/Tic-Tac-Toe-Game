//
// Created by abakh on 5/27/2023.
//

#ifndef XOGAME_PLAYER_H
#define XOGAME_PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    //Attr
    string name;
    char playMark;
public:
    //Con
    Player() = default;
    Player(string &name, char playMark) {
        this->name = name;
        this->playMark = playMark;
    }

    //Setter
    void setName(string name) {
        this->name = name;
    }
    void setPlayMark(char playMark) {
        if (playMark == 'X' || playMark == 'O')
            this->playMark = playMark;
        else
            cout << "!valid mark";
    }

    //Getter
    string getName() {
        return name;
    }
    char getPlayMark() {
        return playMark;
    }
};

#endif //XOGAME_PLAYER_H
