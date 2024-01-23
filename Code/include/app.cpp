#include "app.h"
#include <conio.h>


LoadFiles lf;

void app::start() {

    cout << "\nPlease choose the exercise you would like to see:" << endl;

    cout << "For exercise 2.1, press [21]" << endl;
    cout << "For exercise 2.2, press [22]" << endl;
    cout << "For exercise 2.3, press [23]" << endl;
    cout << "If you wish to stop running, press [0]" << endl;
    int exercise;
    cin >> exercise;


    int toy;
    switch (exercise){
        case 21:
            return exercise21();

        case 22:
            return exercise22();

        case 23:
            return exercise23();

        case 0:
            return end();

        default:
            cout << "Invalid input, please try again\n";
            return start();
    }


}

void app::end(){
        cout << "\nGoodbye for now!"
                "\n-------------------------------------------------------------------------" << endl;

}

void app::exercise21() {

    lf.chooseToy();
    Graph demo = lf.getToyGraph();
    tsp(demo);
    demo.deleteGraph();
    lf.deleteAll();
    // demo = Graph();

    cout << "\nPress any key to go back to menu \n";

    ////_getch();
    return start();

}

void app::exercise22 (){

    cout << "\nWhat graphs would you like to use?" << endl;
    cout << "For Toy Graphs, press [1]" << endl;
    cout << "For Real-World Graphs, press [2]" << endl;
    cout << "For Extra Fully Connected Graphs, press [3]" << endl;
    cout << "If you wish to stop running, press [0]" << endl;

    int num;
    cin >> num;

    Graph demo;
    switch (num){
        case 0:
            return end();
        case 1:
            lf.chooseToy();
            demo = lf.getToyGraph();
            triangularApproximationH(demo);
            demo.deleteGraph();
            lf.deleteAll();
            break;

        case 2:
            lf.chooseReal();
            demo = lf.getRealGraph();
            triangularApproximationH(demo);
            demo.deleteGraph();
            lf.deleteAll();
            break;

        case 3:
            lf.chooseExtra();
            demo = lf.getExtraGraph();
            triangularApproximationH(demo);
            demo.deleteGraph();
            lf.deleteAll();
            break;

        default:
            cout << "Invalid input, please try again\n";
            return exercise22();
    }

    cout << "\nPress any key to go back to menu \n";
    //_getch();
    return start();
}


void app::exercise23() {

    cout << "\nWhat kind of implementation would you like to see?" << endl;
    cout << "For our own algorithm implementation, press [1]" << endl;
    cout << "For the Lin Kernighan algorithm, press [2]" << endl;
    cout << "If you wish to stop running, press [0]" << endl;

    int num;
    cin >> num;

    switch (num){
        case 0:
            return end();
        case 1:
            return exercise231();
        case 2:
            return exercise232();
        default:
            cout << "Invalid input, please try again\n";
            return exercise23();
    }

}


void app::exercise231() {

    cout << "\nWhat type graph would you like to see?" << endl;
    cout << "For toy graphs, press [1]" << endl;
    cout << "For extra fully connected graphs, press [2]" << endl;
    cout << "For real world graphs, press [3]" << endl;

    int type;
    cin >> type;

    Graph extra;
    switch (type){
        case 1:
            lf.chooseToy();
            extra = lf.getToyGraph();
            join4(extra);
            extra.deleteGraph();
            lf.deleteAll();
            break;

        case 2:
            lf.chooseExtra();
            extra = lf.getExtraGraph();
            join4(extra);
            extra.deleteGraph();
            lf.deleteAll();
            break;

        case 3:
            lf.chooseReal();
            extra = lf.getRealGraph();
            join4(extra);
            extra.deleteGraph();
            lf.deleteAll();
            return;

        default:
            cout << "Invalid input, please try again\n";
            return exercise23();
    }

    cout << "\nPress any key to go back to menu \n";

    //_getch();
    return start();

}


void app::exercise232() {
    cout << "\nWhat type graph would you like to see?" << endl;
    cout << "For toy graphs, press [1]" << endl;
    cout << "For extra fully connected graphs, press [2]" << endl;
    cout << "For real world graphs, press [3]" << endl;

    int type;
    cin >> type;

    Graph extra;
    switch (type){
        case 1:
            lf.chooseToy();
            extra = lf.getToyGraph();
            linKernighan(extra);
            extra.deleteGraph();
            lf.deleteAll();
            break;

        case 2:
            lf.chooseExtra();
            extra = lf.getExtraGraph();
            linKernighan(extra);
            extra.deleteGraph();
            lf.deleteAll();
            break;

        case 3:
            lf.chooseReal();
            extra = lf.getRealGraph();
            linKernighan(extra);
            extra.deleteGraph();
            lf.deleteAll();
            return;

        default:
            cout << "Invalid input, please try again\n";
            return exercise23();
    }

    cout << "\nPress any key to go back to menu \n";

    //_getch();
    return start();

}

