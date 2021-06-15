//Solution: C++  Problem: http://onlinejudge-problems.blogspot.com/2016/04/uva-514-rails-solution.html
#include<cstdio>
#include<stack>
 
using namespace std;

//enteros N y c que representan el valor de la primera linea de cada bloque de valores (N) y,
//(c) que representa a los valores de los carros en las líneas de cada bloque.
int N, c;
//se utiliza stack implementado de ADT
stack<int> cars;
 
void marshal() {
    for(;;) {
        //Loop que se encarga de vaciar el stack en una etapa posterior a manipularlo.
        while(cars.size() > 0) cars.pop();
        //(j) variable que se incrementa para llenar el stack hasta el valor tope (N)
        int j = 0;
        //Loop principal que se encarga de ir escaneando las lineas correspondientes a los trenes hasta que se encuentra el 0
        for(int i = 0; i < N; i++) {
            //escaneo de enteros en los trenes
            scanf("%d", &c);
            //hasta que se encuentra el 0
            if(c == 0) return;
            while(j < N && j != c) {
                //condicional...
                if(cars.size() > 0 && cars.top() == c) break;
                j++;
                //se va llenando el stack
                cars.push(j);
            }
            //se va comprobando el entero escaneado si es que es el tope del stack, si es así, entonces se retira del stack...
            if(cars.top() == c) cars.pop();
        }
        //si es que el stack queda sin elementos entonces es aceptado el orden, si es que no no.
        if(cars.size() == 0) printf("Yes\n");
        else printf("No\n");
    }
}
 
int main() {
    for(;;) {
        scanf("%d", &N);
        if(N == 0) break;
 
        marshal();
        printf("\n");
    }
}