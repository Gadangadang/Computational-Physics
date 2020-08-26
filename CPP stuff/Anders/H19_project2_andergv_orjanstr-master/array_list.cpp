#include <iostream>
#include <exception>
#include <vector>
#include <array>
#include <iterator>
#include <math.h>
#include <stdexcept>

class ArrayList
{
  public:
    int size;

  private:
    int* data;
    int capacity;
    int growth;

    int& operator[] (int i) {
      if (0 <= i && i < size){
        return data[i];
      }else {
        throw std::range_error("IndexError");
      }
    }

    void resize() {
      capacity *= 2;
      //std::cout << "resizing Array " << capacity <<std::endl;
      int* tmp = new int[capacity];
      for (int i = 0; i < size; i++)
      {
        tmp[i] = data[i];
      }

      delete[] data;
      data = tmp;
      //std::cout << "resize successfull" << std::endl;
    }

  public:
    ArrayList() {
      std::cout << "Creating ArrayList" << std::endl;
      capacity = 1;
      size = 0;
      growth = 2;
      data = new int[capacity];
    }

    ArrayList(std::vector<int> initial) {
      std::cout << "Creating ArrayList" << std::endl;
      capacity = 1;
      size = 0;
      growth = 2;
      data = new int[capacity];
      for (int e: initial) {
        Append(e);
      }
    }

    void length() {
    std::cout << "length of data is " << size << std::endl;
    }

    ~ArrayList() {
      delete[] data;
    }

    void Append(int f) {
      if (size >= capacity) {
        resize();
      }
      data[size] = f;
      size++;
      }

    void shrink_to_fit() {
      int n = 1;
      int i = size;
      while (i >= pow(2, n)) {
        n++;
      }
      int y = pow(2, n);
      int* tmp = new int[y];
      for (int j = 0; j <= i; j++){
        tmp[j] = data[j];
      }
      delete[] data;
      data = tmp;
      capacity = y;
    }

    void print(){
      int i = 0;
      while(i != capacity) {
        std::cout << "data[" << i << "] is: " << data[i] << ", ";
        i++;
      }
      std::cout << std::endl;
      std::cout << " " << std::endl;
    }

    void insert(int val, int index) {
      if (index > size) {
        throw std::range_error("IndexError");
      }

      /*{
        data[index] = val;
        size = index+1;
      }else {
          while (index > capacity) {
            resize();
          }
          data[index] = val;
          size = index+1;
        } */

      if (index == size){
        data[index] = val;
        size++;
    }

      if (index < size){
      int* tmp = data;
      for (int i = index; i < size; i++){
        data[i] = tmp[i+1];
      }
      data[index] = val;
      size++;
    }
  }
    void remove(int i) {
      if (i > size) {
        throw std::range_error("That index is out of bounds (too big)");
      }
      if (i == size) {
        data[i-1] = 0; // setter inn -1 her fordi size 0 kan ikke inneholde et element og være 0
        size -= 1;
        if (size/capacity > 0.25); {
          shrink_to_fit();
        }

        }
      if (i < size) {
        for (int j = i-1; j < (size); j++) { // setter inn -1 her fordi size 0 kan ikke inneholde et element og være 0
          data[j] = data[j+1];
        }
        data[size] = 0;
        size -= 1;
        if (size/capacity > 0.25); {
          shrink_to_fit();
        }
      }
      }
   int pop(int i) {
     int j = data[i];
     remove(i);
     if (size/capacity > 0.25); {
       shrink_to_fit();
     }
     return j;
   }
   int pop() {
     int j = data[size];
     remove(size);
     if (size/capacity > 0.25); {
       shrink_to_fit();
     }
     return j;
   }
   void test_shrink(){
     resize(); // 2
     resize(); // 4
     resize(); // 8
     resize(); // 16

   }
};

bool is_prime(int n) {
  if (n==1) {
    return false;
  }
  int i = 2;
  while (i*i <= n) {
    if (n % i == 0) {
      return false;
    }
    i++;
  }
  return true;
}

int main() {
  // test for oppgaver 1a --> 1d
  /* ArrayList p;
    p.length();
    p.Append(3);
    p.length()
    p.Append(5);
    p.Append(6);
    p.Append(12);
    p.Append(8);
    p.length();
    p.print();
  */
  // test for oppgave 1e
  /*
  int f = 1;
  ArrayList c;
  while (f < 30) {  // det ligger 1p primtall mellom 0-30
    if (is_prime(f) == true) {
      c.Append(f);
    }
    f++;
  }
  c.print();
  */
  /* // tester for 1f og 1g
  ArrayList primes({2, 3, 5, 8, 11});
  primes.print();
  primes.insert(18, 0);
  primes.insert(18, 2);
  primes.insert(18, 4);
  primes.print();
  return 0;
  */
  ArrayList primes({2, 3, 5, 8, 11});
  primes.print();
  std::cout << "Removing data[2]: " << primes.pop(2) << std::endl;
  primes.print();
  primes.test_shrink();
  primes.print();
  std::cout << "Removing last data: " << primes.pop() << std::endl;
  primes.print();
}
