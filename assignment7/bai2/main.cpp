#include <iostream>
using namespace std;

class Polygon {
private:
  int numEdges;   
  int *edgeLengths; 

public:
  Polygon(int n) {
    numEdges = n;
    edgeLengths = new int[numEdges];
  }

  ~Polygon() {
    if (edgeLengths != NULL) {
      delete[] edgeLengths;
    }
  }

  void inputEdgeLengths() {
    cout << "Enter the lengths for " << numEdges << " edges:" << endl;
    for (int i = 0; i < numEdges; i++) {
      cout << "Edge " << i + 1 << ": ";
      cin >> edgeLengths[i];
    }
  }

  long calculatePerimeter() {
    long perimeter = 0;
    for (int i = 0; i < numEdges; i++) {
      perimeter += edgeLengths[i];
    }
    return perimeter;
  }

  void printEdges() {
    cout << "Edge lengths of the polygon: ";
    for (int i = 0; i < numEdges; i++) {
      cout << edgeLengths[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  int n;
  bool check;
  do {
    cout << "Enter the number of edges for the polygon: ";
    cin >> n;
    if (n < 3) {
      cout << "ERROR! number of edges >= 3. Please try again";
    }
  } while (n < 3);

  Polygon poly(n);
  poly.inputEdgeLengths();

  cout << "\n--- RESULTS ---" << endl;
  poly.printEdges();
  cout << "Perimeter of the polygon: " << poly.calculatePerimeter() << endl;

  return 0;
}