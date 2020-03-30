#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

struct arreglo{
  int v1;
  int v2;
  int max;
};

arreglo parejas[1000];



int maxCycleCalculator(int a,int b){
    int max;
    
    if (a < b){
        for (int i = a;i<=b;i++){
            int temp = i;
            int contador = 1;
            
            while (temp != 1){
                if (temp % 2 != 0){
                    temp = 3*temp+1;
                }
                else{
                    temp = temp/2;
                }
            contador++;
            }
            if (contador > max){
                max = contador;
            }
        }
    }
    
    else if (b <= a){
        for (int i = b;i<=a;i++){
            int temp = i;
            int contador = 0;
            
            while (temp != 1){
                if (temp % 2 != 0){
                    temp = 3*temp+1;
                }
                else{
                    temp = temp/2;
                }
            contador++;
            }
            if (contador > max){
                max = contador;
            }
        }
    }
    
    return max;
}


int main (){
    
    int contador = 0;
    int flag = 0;
    string Evaluador;
    
    string V1;
    string V2;
    
    int Valor1;
    int Valor2;
    
    int max;
    
    while (flag == 0){
        getline(cin,Evaluador);
        if (Evaluador != ""){
            //Separo los valores por espacios y los conviero a int
            istringstream iss(Evaluador);
            
            iss >> V1;
            iss >> V2;
            
            stringstream geek1(V1);
            geek1 >> Valor1;
            
            stringstream geek2(V2);
            geek2 >> Valor2;
            
            max = maxCycleCalculator(Valor1,Valor2);
            
            parejas[contador].v1 = Valor1;
            parejas[contador].v2 = Valor2;
            parejas[contador].max = max;
            contador++;
        }
        else{
            flag = 1;
        }
        
    }
    
    
    for(int i = 0;i < contador;i++){
        cout << parejas[i].v1 << " " << parejas[i].v2 << " " << parejas[i].max << endl;
    }
    
    return 0;
}
