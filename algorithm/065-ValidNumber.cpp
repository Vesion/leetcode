#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Solution 1 : std::strtod
class Solution {
public:
    bool isNumber(string s) {
        const char *start = s.c_str();
        char *end;
        strtod(start, &end);
        if (end == start)
            return false;
        for (; *end; ++end) {
            if (*end != ' ') return false;
        }
        return true;
    }
};


// Solution 2 : DFA
class Solution_2 {
public:
    bool isNumber(string str) {
        int state=0, flag=0; // flag to judge the special case "."
        while(str[0]==' ')  str.erase(0,1);//delete the  prefix whitespace 
        while(str[str.length()-1]==' ') str.erase(str.length()-1, 1);//delete the suffix whitespace
        for(int i=0; i<(int)str.length(); i++){
            if('0'<=str[i] && str[i]<='9'){
                flag=1;
                if(state<=2) state=2;
                else state=(state<=5)?5:7;
            }
            else if('+'==str[i] || '-'==str[i]){
                if(state==0 || state==3) state++;
                else return false;
            }
            else if('.'==str[i]){
                if(state<=2) state=6;
                else return false;
            }
            else if('e'==str[i]){
                if(flag&&(state==2 || state==6 || state==7)) state=3;
                else return false;
            }
            else return false;
        }
        return (state==2 || state==5 || (flag&&state==6) || state==7);
    }
};

int main() {
    return 0;
}
