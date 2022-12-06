#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    fstream file;
    file.open("input.txt");

    //initialize vector by reading the first line
    string line;
    getline(file, line);
    vector<vector<char>> crates((line.length()+2)/4);

    for(int i=1; i<line.length(); i+=4){
        if(line.at(i) >= 65 && line.at(i)<= 90){
            crates[i/4].push_back(line.at(i));
        }
    }

    bool br = 1;
    while(br){
        getline(file, line);
        for(int col=1; col<line.length(); col+=4){  // every 4th character starting from 1st is either space, number or letter in crate
            int vec_idx = col/4;
            if(line.at(col) > 48 && line.at(col) < 58){ //looking for number
                br = 0;
                break;
            }else if(line.at(col) >= 65 && line.at(col)<= 90){  //looking for letters
                crates[vec_idx].push_back(line.at(col));
            }
        }
    }

    //skip empty line
    getline(file, line);

    //reverse vectors
    for(int i=0; i<crates.size(); i++){
        reverse(crates[i].begin(), crates[i].end());
    }

    //reading moves and erasing unnecessary data
    while(!file.eof()){
        getline(file, line);
        line.erase(0, line.find("move ")+5);

        string amount_str = line.substr(0, ' from ');
        line.erase(0, line.find(" from ")+6);

        string from_str = line.substr(0, ' to ');
        line.erase(0, line.find(" to ")+4);

        string to_str = line;

        int amount = stoi(amount_str);
        int from = stoi(from_str);
        int to = stoi(to_str);

        from -= 1;
        to -= 1;

        for(int a=amount; a>0; a--){    //starting from a=amount (not a=amount-1), because end() returns position behind last element
            char move_crate = crates[from].end()[-a];
            crates[from].erase(crates[from].end()-a);
            crates[to].push_back(move_crate);
        }
    }

    cout<<"Result: ";
    for(auto c : crates){
        cout<<c.back();
    }

    return 0;

}

