#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    fstream file;
    file.open("input.txt");

    string input;
    getline(file, input);

    int limit = 3;     //3 for part1, 13 for part2
    int message = limit;    //keep track of position
    bool cont = true;

    while(cont){
        next:
        for(int j=0; j<=limit; j++){
            char check1 = input.at(message-j);  //checking recent characters
            for(int k=0; k<=limit; k++){
                if(j==k) continue;      //skip to not compare the same character
                char check2 = input.at(message-k);
                if(check1 == check2){   //skip to next set of characters
                    message++;
                    goto next;
                }
            }
        }

        //code can reach this part only if it went through all 4/14 recent characters
        message++;
        cont = false;
    }



    cout<<"Message: "<<message<<"\n";

    return 0;
}

