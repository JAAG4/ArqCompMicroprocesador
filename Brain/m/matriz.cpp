#include<iostream>
#include<cstdlib>

using namespace std;

int i,j = 0;

void imprimem();

int main(){
    imprimem();
    return 0;}

void imprimem(){
    cout << "i = x / j = y\n";
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout << " " << i << j << " ";
        }
        cout << endl;
    }    
    cout << "\nj = x / i = y\n";
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout << " " << j << i << " ";   
        }
        cout << endl;
    }
    cout << endl;
    }    
