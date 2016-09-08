// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

using namespace std;
const int N = 100000;
// ------------
// collatz_read
// ------------

bool collatz_read (istream& r, int& i, int& j) {
    if (!(r >> i))
        return false;
    r >> j;
    return true;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {

    if (j < i){
        int temp = i;
        i = j;
        j = temp;
    }

    int m = (j / 2) + 1;

    if (m > i)
        i = m;

    int max_cycle = 0;
    int cache[N] = {0};

    for (int x = i; x <= j && x >= 0; ++x){

        int c = 1;
        int n = x;

        while (n > 1) {

            if (n < j && n < N){
                if (cache[n] != 0){
                    c += cache[n] - 1;
                    cache[x] = c;
                    break;
                }
            }

            if ((n % 2) == 0)
                n = (n / 2);
            else
                n = (3 * n) + 1;
            ++c;}

            if (x < N){
                if (cache[x] == 0)
                    cache[x] = c;
                    
            }

        if(max_cycle < c)
            max_cycle = c;
    }

    return max_cycle;}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}

// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
