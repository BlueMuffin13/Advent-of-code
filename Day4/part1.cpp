#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){

    fstream file;
    file.open("input.txt");
    vector<string> sections;
    int sum=0;

    while(!file.eof()){
        string line;
        getline(file, line);
        stringstream ss(line);
        while(!ss.eof()){
            //splitting strings by ',' and saving in vector
            getline(ss, line, ',');
            sections.push_back(line);
        }
    }

    for(int i=0; i<sections.size(); i+=2){
        string elf1start, elf1fin, elf2start, elf2fin;

        //splitting strings by '-'
        elf1start = sections[i].substr(0, sections[i].find('-'));
        elf1fin = sections[i].erase(0, sections[i].find('-')+1);

        elf2start = sections[i+1].substr(0, sections[i+1].find('-'));
        elf2fin = sections[i+1].erase(0, sections[i+1].find('-')+1);

        int e1start, e1fin, e2start, e2fin;

        //conversion to int
        e1start = stoi(elf1start);
        e1fin = stoi(elf1fin);
        e2start = stoi(elf2start);
        e2fin = stoi(elf2fin);


        if((e1start <= e2start && e1fin >= e2fin) || (e2start <= e1start && e2fin >= e1fin)){   //checking if one range fits in the other
            sum++;
        }
    }

    cout<<"sum: "<<sum<<"\n";


    return 0;
}
