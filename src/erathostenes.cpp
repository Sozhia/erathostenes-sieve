#include "erathostenes.hpp"

using namespace std;

void Sieve(bool array[],int dimension) {

    cout << dimension << endl;
    //Suponemos que todos son primos
    for (int number = 0; number < dimension; number++) {
        array[number] = true;
    }
    
    
    //Desde el 2 eliminamos los multiplos posteriores de los primos:
    // aux*2, aux*3, aux*4, ... siempre y cuando sea primo
    for (int position = 2;position < dimension; position++ ) {
        
        if (array[position]) {
            
            for (int aux=2; aux < dimension; aux++ ) {
                if (position*aux <= dimension){
                
                    Remove(array, position*aux);
                }
            }
        }
    }
}

void Remove(bool array[], int pos) {
    
    array[pos] = false;
}

void printPrimo(bool array[], int dimension) {

    cout << "Mostrando primos:" << endl;
    for (int index = 2; index <= dimension; index++) {
        if (array[index]){
            cout << index << " ";
        } 
    }
    cout << endl;

}

