#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){

    fstream file;
    file.open("input.txt");
    vector<string> elves;
    string rucksack;
    int sum=0;

    //saving rucksacks into vector
    while(!file.eof()){
        getline(file, rucksack);
        elves.push_back(rucksack);
    }

    for(int i=0; i<elves.size()- 2; i+=3){

        char badge;

        string elf1 = elves[i], elf2 = elves[i+1], elf3 = elves[i+2];

        //looking for the same letter
        for(int j=0; j<elf1.length(); j++){
            for(int k=0; k<elf2.length(); k++){
                for(int l=0; l<elf3.length(); l++){
                    if(elf1.at(j) == elf2.at(k) && elf1.at(j) == elf3.at(l)){
                        badge = elf1.at(j);
                        break;
                    }
                }
            }
        }

        //adding priority by ASCII value

        if(badge > 96){
            sum += badge-96;
        }else{
            sum += badge-38;
        }
    }

    cout<<"Sum: "<<sum;

    file.close();

    return 0;
}
