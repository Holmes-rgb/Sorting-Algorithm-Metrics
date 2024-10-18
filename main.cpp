#include "Airport.cc"
#include "sorting-algorithms/bubbleSort.h"
#include "sorting-algorithms/heapSort.h"
#include "sorting-algorithms/mergeSort.h"
#include "sorting-algorithms/selectionSort.h"
#include "stability-test/contactsList.h"
#include <chrono>
#include <cstring>
#include <random>

using namespace std;

void stabilityTest();

int main(int argc, char *argv[]) {
  int reads = 0;
  int writes = 0;
  std::vector<Airport> airports;
  std::string fn = "../Airports_Shorter.csv";

  if (loadFromFile(fn, airports)) {
    std::cout << airports.size() << " records read from file" << std::endl;
    int firstId = airports.front().getObjectid();
    std::cout << "The first row ID read was " << firstId << std::endl;
    int lastId = airports.back().getObjectid();
    std::cout << "The last row ID read was " << lastId << std::endl;
  } else {
    std::cout << "Something went wrong." << std::endl;
  }

  // vector is already sorted, so I shuffled it before sorting
  // Source https://www.educba.com/c-plus-plus-shuffle/
  unsigned num = chrono::system_clock::now().time_since_epoch().count();
  ;
  std::shuffle(airports.begin(), airports.end(), default_random_engine(num));

  for (int i = 10; i > 0; --i) {
    airports.resize(i * 100);
    selectionSort(airports, reads, writes);
    mergeSort(airports, reads, writes);
    heapSort(airports, reads, writes);
  }

  int size = atoi(argv[1]);

  if (strcmp(argv[2], "Selection") == 0) {
    airports.resize(size * 100);
    selectionSort(airports, reads, writes);
  } else if (strcmp(argv[2], "Merge") == 0) {
    airports.resize(size * 100);
    mergeSort(airports, reads, writes);
  } else if (strcmp(argv[2], "Heap") == 0) {
    airports.resize(size * 100);
    heapSort(airports, reads, writes);
  } else if (strcmp(argv[2], "Bubble") == 0) {
    airports.resize(size * 100);
    bubbleSort(airports, reads, writes);
  }

  stabilityTest();

  return 0;
}

void stabilityTest() {
  ContactsList people;
  people.readContactsFromFile("../stability-test/names.csv");
  cout << "People (Default ordering)" << endl;
  people.printList();

  cout << endl << "Bubble Sort" << endl;
  people.sortAndPrint(bubbleSort<contact>);

  cout << endl << "Merge Sort" << endl;
  people.sortAndPrint(mergeSort<contact>);

  cout << endl << "Heap Sort" << endl;
  people.sortAndPrint(heapSort<contact>);

  cout << endl << "Selection Sort" << endl;
  people.sortAndPrint(selectionSort<contact>);
}
