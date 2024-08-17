#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enchoice {
    stone = 1,
    paper = 2,
    scissors = 3
};

enum enwiner {
    winplayer = 1,
    wincomputer = 2,
    draw = 3
};

struct strond {
    short roundnumber;
    enchoice choiceplayer1;
    enchoice choicecomputer;
    enwiner winner;
    string winnername;
};

struct stgameresult {
    short gamesround;
    short winplayertimes;
    short wincomputertimes;
    short drawround;
    enwiner winnwrergame;
    string winnernamegame;
};

int howmanyroundrtime() {
    int roundnumber;
    do {
        cout << "How many rounds 1 to 10 play? ";
        cin >> roundnumber;
    } while (roundnumber < 1 || roundnumber > 10);
    return roundnumber;
}

int randomnumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

string choiecRPS(enchoice choice) {
    string arrchoice[3] = { "[1] Stone", "[2] Paper", "[3] Scissors" };
    return arrchoice[choice - 1];
}

enchoice readplayer1() {
    short choice;
    do {
        cout << "Your choice: [1] Stone, [2] Paper, [3] Scissors? ";
        cin >> choice;
    } while (choice < 1 || choice > 3);
    return enchoice(choice);
}

enchoice getcomputer() {
    return enchoice(randomnumber(1, 3));
}

enwiner whowonround(const strond& roundinfo) {
    if (roundinfo.choiceplayer1 == roundinfo.choicecomputer) {
        return enwiner::draw;
    }

    switch (roundinfo.choiceplayer1) {
    case enchoice::stone:
        if (roundinfo.choicecomputer == enchoice::paper) {
            return enwiner::wincomputer;
        }
        else if (roundinfo.choicecomputer == enchoice::scissors) {
            return enwiner::winplayer;
        }
        break;
    case enchoice::paper:
        if (roundinfo.choicecomputer == enchoice::scissors) {
            return enwiner::wincomputer;
        }
        else if (roundinfo.choicecomputer == enchoice::stone) {
            return enwiner::winplayer;
        }
        break;
    case enchoice::scissors:
        if (roundinfo.choicecomputer == enchoice::stone) {
            return enwiner::wincomputer;
        }
        else if (roundinfo.choicecomputer == enchoice::paper) {
            return enwiner::winplayer;
        }
        break;
    }
    return enwiner::draw; // Fallback, though it should not reach here
}

string winnername(enwiner winner) {
    string arrwinner[3] = { "Player1", "Computer", "Draw" };
    return arrwinner[winner - 1];
}

void setscreen(enwiner winner) {
    switch (winner) {
    case enwiner::winplayer:
        system("color 2F");
        break;
    case enwiner::wincomputer:
        system("color 4F");
        break;
    case enwiner::draw:
        system("color 6F");
        break;
    }
}

void printresultgame(const strond& roundinfo) {
    cout << "-----------------[" << roundinfo.roundnumber << "]----------------\n";
    cout << "Player choice   : " << choiecRPS(roundinfo.choiceplayer1) << endl;
    cout << "Computer choice : " << choiecRPS(roundinfo.choicecomputer) << endl;
    cout << "Round winner    : " << roundinfo.winnername << endl;
    cout << "--------------------------------------------------------------\n";
    setscreen(roundinfo.winner);
}

void gameover() {
    cout << "\n\t\t\t\t------------------------------------------------------\n";
    cout << "\n\t\t\t\t                 +++ Game Over +++                     \n";
    cout << "\n\t\t\t\t------------------------------------------------------\n";
}

void finalgameresult(stgameresult& gameresult) {
    cout << "\n\t\t\t\t--------------------[Game Results]--------------------\n";
    cout << "\t\t\t\tGame Rounds        : " << gameresult.gamesround << endl;
    cout << "\t\t\t\tPlayer1 won times  : " << gameresult.winplayertimes << endl;

    cout << "\t\t\t\tComputer won times : " << gameresult.wincomputertimes << endl;
    cout << "\t\t\t\tDraw times         : " << gameresult.drawround << endl;
    cout << "\t\t\t\tFinal Winner       : " << gameresult.winnernamegame << endl;
    cout << "\n\t\t\t\t------------------------------------------------------n";

    if (gameresult.winnwrergame == enwiner::wincomputer) {
        cout << "\n \t\t\t                            * Computer Wins! *                   \n";
    }
    else if (gameresult.winnwrergame == enwiner::winplayer) {
        cout << "\n \t\t\t                            * Player1 Wins! *                     \n";
    }
    else {
        cout << "\n \t\t\t                            * It's a Draw! *                     \n";
    }
}

void startgame() {
    stgameresult gameresult;
    gameresult.gamesround = howmanyroundrtime();
    gameresult.winplayertimes = 0;
    gameresult.wincomputertimes = 0;
    gameresult.drawround = 0;

    for (int gameround = 1; gameround <= gameresult.gamesround; gameround++) {
        cout << "Round [" << gameround << "] begins:\n";
        strond roundinfo;
        roundinfo.roundnumber = gameround;
        roundinfo.choiceplayer1 = readplayer1();
        roundinfo.choicecomputer = getcomputer();
        roundinfo.winner = whowonround(roundinfo);
        roundinfo.winnername = winnername(roundinfo.winner);

        if (roundinfo.winner == enwiner::winplayer)
            gameresult.winplayertimes++;
        else if (roundinfo.winner == enwiner::wincomputer)
            gameresult.wincomputertimes++;
        else
            gameresult.drawround++;

        printresultgame(roundinfo);
    }

    if (gameresult.winplayertimes > gameresult.wincomputertimes) {
        gameresult.winnwrergame = enwiner::winplayer;
        gameresult.winnernamegame = "Player1";
    }
    else if (gameresult.wincomputertimes > gameresult.winplayertimes) {
        gameresult.winnwrergame = enwiner::wincomputer;
        gameresult.winnernamegame = "Computer";
    }
    else {
        gameresult.winnwrergame = enwiner::draw;
        gameresult.winnernamegame = "No Winner";
    }

    gameover();
    finalgameresult(gameresult);
}

int main() {
    srand((unsigned)time(NULL));

    char playagainchice;
    do {
        startgame();
        cout << "Do you want to play again? Y/N\n";
        cin >> playagainchice;
    } while (playagainchice == 'y' || playagainchice == 'Y');

    gameover(); 
    system("pause");
    return 0;
}
