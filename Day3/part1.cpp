#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    fstream file;
    file.open("input.txt");
    string rucksack;
    int sum=0;

    while(!file.eof()){
        getline(file, rucksack);
        //splitting into two compartments
        string comp1 = rucksack.substr(0, rucksack.length()/2);
        string comp2 = rucksack.substr(rucksack.length()/2);
        char mistake;

        for(int i=0; i<rucksack.length()/2; i++){
            for(int j=0; j<rucksack.length()/2; j++){
                if(comp1.at(i) == comp2.at(j)){
                    mistake = comp1.at(i);
                    break;
                }
            }
        }

        //adding priority by ASCII value
        if(mistake > 96){
            sum += mistake-96;
        }else{
            sum += mistake-38;
        }
    }

    cout<<"Sum: "<<sum;

    file.close();

    return 0;
}
