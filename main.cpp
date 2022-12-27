#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <class T>
class Vector: public std::vector<T>
{
  private:
    void swap(T *a, T *b)
    {
      T temp = *a;
      *a = *b;
      *b = temp;
    }

  public:
    Vector(const initializer_list<T> &il) : vector<T>(il) {}

    void sort() {
      this->sort([](int curr, int next) { return curr < next; });
    }

    void sort(bool (*compFn)(T curr, T next)) {
      int size = this->size();

      for (int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++) {
          if (compFn((*this)[j], (*this)[j + 1])) {
            this->swap(&(*this)[j], &(*this)[j + 1]);
          }
        }
      }
    }

    void print() {
      int size = this->size();

      for (int i = 0; i < size; i++)
        std::cout<<(*this)[i]<<" ";
      std::cout<<std::endl;
    }
};

int main() {
  Vector<int> x{1, 2, -1, -4, 5};

  x.print();

  x.sort([](int curr, int next) { return curr < next; });

  x.print();

  return 0;
}
