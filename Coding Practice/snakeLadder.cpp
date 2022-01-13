#include <bits/stdc++.h>
using namespace std;

class Snake
{
    int head;
    int tail;
public:
    void setHeadPos(int pos)
    {
        head = pos;
    }
    void setTailPos(int pos)
    {
        tail = pos;
    }
    int getHeadPos(void)
    {
        return head;
    }
    int getTailPos(void)
    {
        return tail;
    }
};

class Ladder
{
    int start;
    int end;
public:
    void setStartPos(int pos)
    {
        start = pos;
    }
    void setEndPos(int pos)
    {
        end = pos;
    }
    int getStartPos(void)
    {
        return start;
    }
    int getENdPos(void)
    {
        return end;
    }
};

class Board
{
    int size;
    int numSnakes;
    int numLadders;
    vector<int> boardValues;
public:
    void setSize(int sz)
    {
        size = sz;
        boardValues.assign(sz+1, 0);
    }
    int getSize(void)
    {
        return size;
    }
    void setNumSnakes(int n)
    {
        numSnakes = n;
    }
    void setNumLadders(int n)
    {
        numLadders = n;
    }
    int getNumSnakes(void)
    {
        return numSnakes;
    }
    int getNumLadders(void)
    {
        return numLadders;
    }
    void updateBoardValues(vector<Snake> snakes, vector<Ladder> ladders)
    {        
        for(auto snake: snakes)
        {
            boardValues[snake.getHeadPos()] = -(snake.getHeadPos() - snake.getTailPos());
        }
        for(auto ladder: ladders)
        {
            boardValues[ladder.getStartPos()] = ladder.getENdPos() - ladder.getStartPos();
        }
    }
    vector<int> getBoardValues(void)
    {
        return boardValues;
    }
};

class Player
{
    string name;
    int currPos;
public:
    void setName(string name)
    {
        this->name = name;
    }
    string getName(void)
    {
        return name;
    }
    void setPos(int pos)
    {
        printf("***Set Positon = %d *****\n", pos);
        currPos = pos;
    }
    int getPos(void)
    {
        return currPos;
    }
};

class DiceRoll
{
    int minValue;
    int maxValue;
public:
    void setMinValue(int val)
    {
        minValue = val;
    }
    void setMaxValue(int val)
    {
        maxValue = val;
    }
    int getNumOnDice(void)
    {
        return rand()%maxValue + minValue;
    }
};
/*
// For generating random positions of snakes and ladders
class randomPair
{
    pair<int, int> p;
    int boardSize;
public:
    void setBoardSize(int size)
    {
        boardSize = size;
    }
    pair<int, int> genRandomPair()
    {
        p.first = rand()%(boardSize-2) + 1;
        p.second = rand()%(boardSize-p.first) + p.first;
    }
};
*/

bool IsWinner(Board board, Player p)
{
    return p.getPos() == board.getSize();
}

void playGame(Board board, vector<Player> players)
{
    DiceRoll dice;
    dice.setMinValue(1);
    dice.setMaxValue(6);
    vector<int> boardValues = board.getBoardValues();
    while(1)
    {
        for(int i = 0; i < players.size(); ++i)
        {
            int diceValue = dice.getNumOnDice();
            /*
            if(diceValue == 6)
            {
                diceValue += dice.getNumOnDice();
                if(diceValue == 12)
                {
                    diceValue += dice.getNumOnDice();
                }
            }
            if(diceValue == 18)
            {
                continue;
            }
            */
            int newPos = players[i].getPos() + diceValue;
            if(newPos > board.getSize())
            {
                printf("%s rolled a %d but can't moved from %d to %d\n", players[i].getName().c_str(), diceValue, players[i].getPos(), newPos);
                continue;
            }
            while(newPos < board.getSize() and boardValues[newPos] != 0)
            {
                newPos += boardValues[newPos];
            }
            printf("%s rolled a %d and moved from %d to %d\n", players[i].getName().c_str(), diceValue, players[i].getPos(), newPos);
            players[i].setPos(newPos);
            if(IsWinner(board, players[i]))
            {
                printf("%s wins the game\n", players[i].getName().c_str());
                //players.erase(players.begin() + i);
                return;
            }
            /*
            if(players.size() == 1)
            {
                return;
            }
            */
        }
    }
}

int main(void)
{
    int boardSize = 100;
    Board board;
    board.setSize(boardSize);
    int numSnakes;
    cin >> numSnakes;
    board.setNumSnakes(numSnakes);
    vector<Snake> snakes;
    snakes.resize(numSnakes);
    int head, tail;
    for(int i = 0; i < numSnakes; ++i)
    {
        cin >> head >> tail;
        snakes[i].setHeadPos(head);
        snakes[i].setTailPos(tail);
    }

    int numLadders;
    cin >> numLadders;
    board.setNumLadders(numLadders);
    vector<Ladder> ladders;
    ladders.resize(numLadders);
    int start, end;
    for(int i = 0; i < numLadders; ++i)
    {
        cin >> start >> end;
        ladders[i].setStartPos(start);
        ladders[i].setEndPos(end);
    }
    board.updateBoardValues(snakes, ladders);

    int numPlayers;
    cin >> numPlayers;
    vector<Player> players;
    players.resize(numPlayers);
    string name;
    for(int i = 0; i < numPlayers; ++i)
    {
        cin >> name;
        players[i].setName(name);
        players[i].setPos(0);
    }

    playGame(board, players);
    return 0;
}

/*
12
12 6
24 12
6 1
11 5
23 11
5 1
25 13
13 11
26 25
27 26
28 25
29 26
12
1 16
4 11
2 22
3 10
7 19
19 30
30 90
8 20
20 30
9 31
31 90
10 11
3
Alice
Bob
Charley
*/