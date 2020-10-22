/*autor,email,web,fecha,nombre_fichero,programa,descripcion
**comentar funcionamiento de funciones
**bin,include,src (no es necesario, pero recomendable)
**controlar solo números > 0 ni letras ni ostias
*/
#include <iostream>
#include <list>
#include <utility>
#include <vector>

using namespace std;

void Sieve(vector<pair<int,bool>>& data);
void Remove(vector<pair<int,bool>>& data,unsigned int number);
void DeleteNonPrimes(vector<pair<int,bool>>& data);
void PrintHolder(vector<pair<int,bool>>& data);

// A partir del 2 marcamos todo multiplo de primo como falso
void Sieve(vector<pair<int,bool>>& data) {
  data[0].second = false;
  unsigned int value;
  for (unsigned int index = 2; index <= data.size(); index ++) {
    if (data[index-1].second == true){
      for (unsigned int multiple = 2; multiple <= data.size(); multiple ++) {
        value=index*multiple;
        if (value<=data.size()) {
          Remove(data, value);
        }
      }
    }
  }
}

void Remove(vector<pair<int,bool>>& data, unsigned int number) {
  if (data[number-1].second == true) {
    data[number-1].second = false;
  }
}

// Eliminamos los marcados como no primos                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           y redimensionamos
void DeleteNonPrimes(vector<pair<int,bool>>& data) {
  unsigned int count = 0;
  do {
    if (data[count].second == false) {
      // Borramos en la posicion pointer si no es primo
      data.erase(data.begin()+count);
      count = 0;
    }
    count ++;
  } while (count < data.size());
}

void PrintHolder(vector<pair<int,bool>>& data) {
  unsigned int counter = 0;
  do {
    cout << "( " << data[counter].first  << ":";
    if (data[counter].second == true) {         
      cout << " prime)" << endl;;
    } else {
      cout << " non prime)" << endl;;
    }    
    counter ++;
  }while (counter < data.size());
}         

int main(int argc, const char** argv) {

    const int holder_dim = atoi(argv[1]);
    if (holder_dim <= 0){
      cout << "ERROR: Se esperaba un valor > 0, usted ha introducido: " << holder_dim << endl;
      cout << "Saliendo del programa.";
      exit (EXIT_FAILURE);
    }

    // Creamos nuestra estructura y la redimensionamos con dimension N
    vector<pair<int,bool>> prime_holder;
    prime_holder.resize(holder_dim);
 
    // Inicializamos nuestra estructura con 1 ... N como primos
    int count=0;

    do {
      prime_holder[count].first = count+1;
      prime_holder[count].second = true;
      count++;
    } while (count < holder_dim);

    Sieve(prime_holder);
    PrintHolder(prime_holder);
    DeleteNonPrimes(prime_holder);
    PrintHolder(prime_holder);
   
}