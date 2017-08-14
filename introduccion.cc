#include <iostream>

/*********************************************************
Materia: Gráficas Computacionales
Fecha: 13 de Agosto del 2017
Autor: A01374637 Josep Romagosa Llorden
*********************************************************/

int PerimetroRectangulo(int base, int altura);
float AreaTriangulo(float base, float altura);
int Mayor(int numero1, int numero2, int numero3);
int Menor(int numero1, int numero2, int numero3);
void FilaEstrellas(int n);
void MatrizEstrellas(int n);
void PiramideEstrellas(int n);
void FlechaEstrellas(int n);
void Fibonacci(int n);
bool EsPrimo(int numero);

int main()
{
   std::cout << "Area de Rectangulo: " << PerimetroRectangulo(5,3) << std::endl;
   std::cout << "Area del triangulo: " << AreaTriangulo(5.0f,3.0f) << std::endl;
   std::cout << "Numero mayor es: " << Mayor(5,9,1) << std::endl;
   std::cout << "Numero menor es: " << Menor(5,9,1) << std::endl;
   FilaEstrellas(5);
   MatrizEstrellas(4);
   PiramideEstrellas(6);
   FlechaEstrellas(3);
   Fibonacci(9);
   std::cout << EsPrimo(79) << std::endl;
   std::cout << EsPrimo(52) << std::endl;
}

int PerimetroRectangulo(int base, int altura) {
    int p = base * altura;
    return (p);
}

float AreaTriangulo(float base, float altura) {
    float a = base * altura / 2;
    return (a);
}

int Mayor(int numero1, int numero2, int numero3) {
    if (numero1 >= numero2) {
        if (numero1 >= numero3){
            return numero1;
        } else {
            return numero3;
        }
    } else{
        return numero2;
    }
}

int Menor(int numero1, int numero2, int numero3) {
    if (numero1 <= numero2) {
        if (numero1 <= numero3){
            return numero1;
        } else {
            return numero3;
        }
    } else{
        return numero2;
    }
}

void FilaEstrellas(int n) {
    char texto[n];
    for (int i=0;i<n;i++){
        texto[i] = '+';
    }
    std::cout << texto << std::endl;
    std::cout << std::endl;
}

void MatrizEstrellas(int n) {
    for (int i=0;i<n;i++){
        for (int e=0;e<n;e++){
            std::cout << "+";
        }
        std::cout << std::endl;
    }
    
}

void PiramideEstrellas(int n) {
    for (int i=0;i<=n;i++){
        for (int e=0;e<i;e++){
            std::cout << "+";
        }
        std::cout << std::endl;
    }
}

void FlechaEstrellas(int n) {
    for (int i=0;i<=n;i++){
        for (int e=0;e<i;e++){
            std::cout << "+";
        }
        std::cout << std::endl;
    }
    for (int i=n-1;i>0;i--){
        for (int e=0;e<i;e++){
            std::cout << "+";
        }
        std::cout << std::endl;
    }
    
}

void Fibonacci(int n) {
    int a = 0;
    int b = 1;
    int c;
    for (int i = 0; i<n;i++){
        c = a + b;
        a = b;
        b = c;
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

bool EsPrimo(int numero){
    int a=0;
    for(int i=1;i<numero+1;i++){
        if(numero%i==0){
             a++;
            }
         }
         if(a!=2){
              return false;
            }else{
                return true;
         }
}



