#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){

    fstream file;
    file.open("input.txt");
    string s;
    char player1, result;
    int points = 0;

    while(!file.eof()){
        getline(file, s);
        istringstream iss(s);
        iss >> player1;
        iss >> result;
        switch(result){
        case 'X':{  //loss

            switch(player1){
                case 'A': points += 3; break;   //rock -> scissors loose 3p
                case 'B': points += 1; break;   //paper -> rock looses 1p
                case 'C': points += 2; break;   //scissors -> paper looses 2p
                default: break;
            }

            break;
        }
        case 'Y':{  //draw
            points += 3;

            switch(player1){
                case 'A': points += 1; break;   //rock 1p
                case 'B': points += 2; break;   //paper 2p
                case 'C': points += 3; break;   //scissors 3p
                default: break;
            }

            break;
        }
        case 'Z':{  //win
            points += 6;

            switch(player1){
                case 'A': points += 2; break;   //rock -> paper wins 2p
                case 'B': points += 3; break;   //paper -> scissors win 3p
                case 'C': points += 1; break;   //scissors -> rock wins 1p
                default: break;
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

