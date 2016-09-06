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


using namespace std;

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

    int cache[100000][2] = {0}, z = 0;
    int max_cycle = 0;



    for (int x = i; x <= j && x >= 0; ++x){

        //////////////////////////

        int c = 1;
        int n = x;

        while (n > 1) {
            if (n < j && n == cache[n-i][0]){
                c += cache[n-i][1] - 1;
                break;
                }

            if ((n % 2) == 0)
                n = (n / 2);
            else
                n = (3 * n) + 1;

            ++c;}

            cache[z][0] = x;
            cache[z][1] = c;
            ++z;

        //////////////////////////

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
