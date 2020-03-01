#include<iostream>
#include<cstdlib>
#include<string>
#include<random>
#include<time.h>
using namespace std;
int matrizg[4][4];
int matriz[4][4];
int i,j = 0;

void imprimem();
void reiniciam();
int move(int xa,int ya,int xb,int yb);
int xi,yi,xf,yf;

struct Lugar{
    int Biologico;
    int Cultural;
    int Emocional;
};
struct Lugar lugar[4][4];
int main(){
srand (time(NULL));
    reiniciam();
    int contadordemovimiento=0;
    int pbx=0;int pby=0;int pex=0;int pey=0;int pcx=0;int pcy=0;
    //decisión BIO
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(lugar[i][j].Biologico>lugar[pbx][pby].Biologico){pbx=i;pby=j;}
        }
    }
    //decision CULT
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(lugar[i][j].Cultural>lugar[pcx][pcy].Cultural){pcx=i;pcy=j;}
        }
    }
    //decision EMO
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(lugar[i][j].Emocional>lugar[pex][pey].Emocional){pex=i;pey=j;}
        }
    }    
    cout << pbx << " " << pby << " "<< pex << " "<< pey << " "<< pcx << " "<< pcy << endl;
    xi=0; yi=0;
    struct Lugar panita;
    panita.Biologico=rand() % 100 + 1;
    panita.Cultural=rand() % 100 + 1;
    panita.Emocional=rand() % 100 + 1;
    for(int mov=0; mov < 15;mov++){
    if(panita.Emocional>=panita.Cultural && panita.Emocional>=panita.Biologico){yf=pex;xf=pey;panita.Emocional-=5;cout<<"me ";}
    else if(panita.Biologico>panita.Cultural && panita.Biologico>panita.Emocional){yf=pbx;xf=pby;panita.Biologico-=5;cout<<"mb ";}
    else if(panita.Cultural>panita.Biologico && panita.Cultural>panita.Emocional){yf=pcx;xf=pcy;panita.Cultural-=5;cout<<"mc ";}
    contadordemovimiento += move(xi,yi,xf,yf);
    xi=xf;yi=yf;
    matriz[xf][yf]+=1;
    }
    cout << endl;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout << " " << matriz[i][j] << " "; 
        }
        cout << endl;
        }        
    cout << endl << "Movimientos: "<< contadordemovimiento << endl;
    
    return 0;}

void reiniciam(){
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            lugar[i][j].Biologico= rand() % 100 + 1;
            lugar[i][j].Cultural=rand() % 100 + 1;
            lugar[i][j].Emocional=rand() % 100 + 1;
        }
}}
void imprimem(){
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout << " " << matrizg[i][j] << " "; 
        }
    cout << endl;
        }    
}
int move(int xa,int ya,int xb,int yb){
    int a;
    while(xa != xb){
    matrizg[xa][ya] += 1;
    //imprimem();
        if(xa < xb)xa++;
        else if(xa > xb)xa--;
    //    cout << "\n\n";
    a++;
    }
    while(ya != yb){
    matrizg[xa][ya] += 1;
    //imprimem();
        if(ya < yb)ya++;
        else if(ya > yb)ya--;
    //    cout << "\n\n";
    a++;
    }
    matrizg[xa][ya] += 1;
    //imprimem();
    //cout << "\n\n";
    return a;
}