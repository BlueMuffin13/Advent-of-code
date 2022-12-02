#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){

    fstream file;
    file.open("input.txt");
    string s;
    char player1, player2;
    int points = 0;

    while(!file.eof()){
        getline(file, s);
        istringstream iss(s);
        iss >> player1;
        iss >> player2;
        switch(player2){
        case 'X':{  //rock
            points += 1;

            if(player1 == 'A'){ //rock
                points += 3;    //draw
            }else if(player1 == 'C'){   //scissors
                points += 6;    //win
            }

            break;
        }
        case 'Y':{  //paper
            points += 2;

            if(player1 == 'A'){ //rock
                points += 6;    //win
            }else if(player1 == 'B'){   //paper
                points += 3;    //draw
            }

            break;
        }
        case 'Z':{  //scissors
            points += 3;

            if(player1 == 'B'){ //paper
                points += 6;    //win
            }else if(player1 == 'C'){   //scissors
                points += 3;    //draw
            }

            break;
        }
        default: break;
        }
    }

    cout<<"Total points: "<<points<<"\n";

    file.close();

    return 0;
}
