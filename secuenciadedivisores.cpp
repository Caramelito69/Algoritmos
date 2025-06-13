#include<stdio.h>

int divisores(int n){
    int suma_divisores=0;

    for(int i=1;i<=n/2;i++){
            if(n%i==0){
                  suma_divisores+=i;
            }
    }
    return suma_divisores;
}
int main(){
    int casos, numero;scanf("%i", &casos);
    while(casos--){
        scanf("%i", &numero);
        int resultado=divisores(numero);
        int perfecto=0;
        int amigo=0;
        int abundante=0;
        printf("%i", numero);
        if(resultado==numero)
        {
            perfecto=1;
            printf(" perfecto");
        }
        else if(numero==divisores(resultado))
        {
            amigo=1;
            printf(" romantico");
        }

        if(resultado>numero)
        {
            abundante=1;
            printf(" abundante");
        }

        if(!perfecto && !amigo && !abundante)
        {
            printf(" complicado");
        }
        printf("\n");
    }
}
