#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Función que define de cuantos digitos es el número
int getTamanio(long x){
  int tamanio=0;
  while (x>=1) {
    tamanio++;
    x/=10;
  }
  return tamanio;
}

//Función que calcula la potencia de un número x elevado a la y
int potencia(int x, int y){
  int z=0,
      potencia=1;
  for(z=0;z<y;z++){
    potencia*=x;
  }
  return potencia;
}

//Función que devuelve el mayor de los 2 números
int max(int x, int y){
  if(x>y){
    return x;
  }
  else{
    return y;
  }
}

//Función de multiplicación por medio del algoritmo de karatsuba
long long karatsuba(long long A, long long B){
  long long c1=0,
            c2=0,
            c3=0,
            A0=0,
            A1=0,
            B0=0,
            B1=0,
            z1=0,
            z2=0,
            z3=0;
  //Determinamos el tamaño del mayor de los números
  int At = getTamanio(A),
      Bt = getTamanio(B),
      n = (int) max(At,Bt);
  //Definimos nuestro caso base con un número con menos de 3 digitos
  if(n<3){
    return A*B;
  }
  //Definimos el tamaño en que vamos a partir nuestros números
  n=floor(n/2);
  //Calculamos los coeficientes del algoritmo de karatsuba
  c1=potencia(10,2*n);
  c2=potencia(10,n);
  c3=c2+1;
  /*Partimos cada uno de los números en 2 números con la misma cantidad de
  digitos*/
  A1=floor(A/c2);
  A0=A%c2;
  B1=floor(B/c2);
  B0=B%c2;
  /*Calculamos la multiplicación de estos por medio del mismo algoritmo de forma
  recursiva*/
  z1=karatsuba(A1,B1);
  z3=karatsuba(A0,B0);
  z2=karatsuba(A1+A0,B1+B0)-z1-z3;
  //Juntamos todo y enviamos el resultado
  return c1*z1+c2*z2+z3;
}

//Metodo main para introducir y mostrar los datos
int main(void){
  long long numero1=0,
            numero2=0,
            resultado=0;
  printf("Multiplicador por el algoritmo de karatsuba\n");
  printf("Ingrese el primer numero a multiplicar\n");
  scanf("%lld",&numero1);
  printf("Ingrese el segundo numero a multiplicar\n");
  scanf("%lld",&numero2);
  resultado=karatsuba(numero1,numero2);
  printf("El resultado es: %lld\n",resultado);
}
