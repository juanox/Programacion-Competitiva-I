#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int size;
    int cont=0;
    char temp;
   /*  int temp2; */
    bool flag = true;

    while(flag){
        //LECTURA DEL TAMAÑO DE LA LINEA DE ENTEROS
        scanf("%d", &size);
        int list[size];

        if(size == 0){
            flag=false;
            break;
        }
        do{
            //LECTURA DE LA LINEA DE ENTEROS
            scanf("%d%c", &list[cont], &temp);
            cont++;
        }while(temp != '\n');
        //SORT ASCENDENTE
        sort(list, list + size);
        //SALIDA
        for (int i = 0; i < size; i++){
            printf("%d", list[i]);
            if (i < size - 1)
                printf(" ");
        }
        printf("\n");
        cont = 0;
    }
    return 0;
}
