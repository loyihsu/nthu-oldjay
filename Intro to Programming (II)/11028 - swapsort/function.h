#ifndef _SWAPSORT_
#define _SWAPSORT_
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
using namespace std;
using State = vector<int>;
class SwapSort
{
private:
    set<list<State>> _paths;
    set<list<State>> _solutions;
    set<State> _explored;
public:
    SwapSort(State init)
    {
        list<State> ls;
        ls.push_back(init);
        _paths.insert(ls);
    }

    void show_solutions()
    {
        if (_solutions.size()==0) {
            cout << "No solution.\n";
        } else {
            for (auto p : _solutions) {
                for (auto s : p) {
                    for (auto i : s) {
                        cout << i << " ";
                    }
                    cout << "-> ";
                }
                cout << ".\n";
            }
        }
    }

    set<State> extend(State s);
    void solve(int steps);
};

#endif
