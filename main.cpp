#include <iostream>
#include <windows.h>
#include "GraphGenerator.h"
#include "Operations.h"

using namespace std;

void randomGraph() {


    GraphGenerator generator(5);
    Operations graph;
    graph.createDirectedGraph();
    graph.createUndirectedGraph();
    graph.createMatrixForDirectedGraph();
    graph.createMatrixForUndirectedGraph();
    graph.makeDirectedNeighbourList();
    graph.makeUndirectedNeighbourList();

    int choice = 0;
    do {
        cout << endl;

        cout << "wybierz opcje " << endl;
        cout << "[1] algorytm dijkstry dla grafu skierowanego na bazie reprezentacji macierzowej" << endl;
        cout << "[2] algorytm dijkstry dla grafu skierowanego na bazie reprezentacji listowej" << endl;
        cout << "[3] koniec" << endl << endl;
        cin >> choice;

        switch (choice) {

            case 1:
                graph.dijkstryMatrix(graph.startVerticle);
                break;
            case 2:
                graph.dijkstryList(graph.startVerticle);
                break;
            default:

                break;
        }

    } while (choice != 3);
}

void readGraph() {
    bool success;
    Operations graph;
    do {
        success = graph.readFromFile();
    } while (success != true);

    graph.createUndirectedGraph();
    graph.createMatrixForDirectedGraph();
    graph.createMatrixForUndirectedGraph();
    graph.makeDirectedNeighbourList();
    graph.makeUndirectedNeighbourList();

    int choice = 0;
    do {
        cout << endl;
        cout << "wybierz opcje " << endl;
        cout << "[1] algorytm dijkstry dla grafu skierowanego na bazie reprezentacji macierzowej" << endl;
        cout << "[2] algorytm dijkstry dla grafu skierowanego na bazie reprezentacji listowej" << endl;
        cout << "[3] koniec" << endl << endl;
        cin >> choice;

        switch (choice) {

            case 1:
                graph.dijkstryMatrix(graph.startVerticle);
                break;
            case 2:
                graph.dijkstryList(graph.startVerticle);
                break;
            default:
                break;
        }

    } while (choice != 3);


}


int main() {

    int randomOrFile = 0;

    do {
        cout << "wybierz sposob wygenerowania grafu " << endl;
        cout << "[1] losowo" << endl;
        cout << "[2] z pliku" << endl;
        cout << "[3] wyjscie" << endl << endl;
        cin >> randomOrFile;

        switch (randomOrFile) {
            case 1:
                randomGraph();
                break;

            case 2:
                readGraph();
                break;
            case 3:
                break;
            default:
                cout << "bledny wybor" << endl;
                break;
        }
    } while (randomOrFile != 3);





}