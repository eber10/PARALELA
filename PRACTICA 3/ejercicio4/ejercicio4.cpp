#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

double sum1 = 0;
double sum2 = 0;

struct myclass {
    bool operator() (int i, int j) {return (i<j);};
} myobject;

vector<int> myvector;


void task1(){
cout << "Task1 esta empezando ... \n";
double c=0;
while (c < 10){c++; sum1 +=c;}
//sum1 = 1+2+3+4+5+6+7+8+9+10
cout << "Task1 esta completa. \n";
}

void task2(){
cout << "Task2 esta empezando ... \n";
double c=0;
while (c < 5){c++; sum2 +=c;}
//sum2=1+2+3+4+5
cout << "Task2 esta completa. \n";
}

void task3(){
cout << "Task3 esta empezando ... \n";
myvector = {12,33,22,44,15,66,56,39,72};
std::sort(myvector.begin(),myvector.end(),myobject);
cout << "Task3 esta completa. \n";
}

int main() {
    thread t1(task1);
    thread t2(task2);
    thread t3(task3);

    thread::id id1 = t1.get_id();
    thread::id id2 = t3.get_id();
    thread::id id3 = t3.get_id();

    if (t1.joinable()) {
    t1.join();
    cout << "tj id = " << id1 << "\n";
    }
    if (t2.joinable()) {
    t2.join();
    cout << "t2 id = " << id2 << "\n";
    }
    if (t3.joinable()) {
    t3.join();
    cout << "t3 id = " << id3 << "\n";
    for(int c=0; c < myvector.size(); c++) {
    cout << "vector (" << c << "); "<< myvector[c] << "\n";
    }
    }
    cout << "sum1: " << sum1 << ", sum2: " << sum2 << "\n";
    return 0;
}
