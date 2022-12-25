#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

int main(){
    bool loop=true;
    bool valid=false;
    while(loop){
        valid=false;
        bool lowerletter = false;
        bool upperletter = false;
        bool sc = false;
        string length;
        cout << "Type a length of your password: ";
        cin>>length;
        if(isNumber(length)){
            int l = stoi(length);
            if(l<21&&l>7){
                valid = true;
                cout<<"Lower letters(y means yes)? ";
                string t;
                cin>>t;
                if(t=="y"){
                    lowerletter=true;
                }
                cout<<"Upper letters(y means yes)? ";
                cin>>t;
                if(t=="y"){
                    upperletter=true;
                }
                cout<<"Need a special character(y means yes)? ";
                cin>>t;
                if(t=="y"){
                    sc=true;
                }
                string result;
                for(int i=0;i<l;i++){
                    char temp;
                    if(lowerletter){
                        if(rand()%2){
                            temp=(rand() % 10)+48;//number;
                        }
                        else{
                            temp = 'a' + rand()%26;
                        }                        
                    }
                    else{
                        temp=(rand() % 10)+48;//number;
                    }
                    result.push_back(temp);
                }
                if(upperletter){
                    for(int i=0;i<l;i++){
                        if(rand()%2){
                            result[i]=(90 - (rand() % 26));
                        }
                    }
                }
                if(sc){
                    result[rand()%l] = char(rand()%15+33);
                }
                cout<<result<<endl;
            }
        }
        if(!valid){
            cout<<"Your input is not a valid value(8-20)."<<endl;
        }
        cout<<"Retry?(y means yes)";
        char t;
        cin>>t;
        if(t!='y'){
            loop=false;
            cout<<"Thanks for using this program, bye."<<endl;
        }
    }
}