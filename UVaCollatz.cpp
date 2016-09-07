<<<<<<< HEAD
#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

using namespace std;



=======
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
#include <map> //hashmap

using namespace std;
const int N = 100000;
>>>>>>> dev
// ------------
// collatz_read
// ------------

bool collatz_read (istream& r, int& i, int& j) {
    if (!(r >> i))
        return false;
    r >> j;
    return true;}

<<<<<<< HEAD
//-------------
//cycle_length
//-------------
int cycle_length (int n) {

    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}

    return c;}

=======
>>>>>>> dev
// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {

    if (j < i){
        int temp = i;
        i = j;
        j = temp;
    }

    int max_cycle = 0;
<<<<<<< HEAD

    for (i; i<=j && i > 0; ++i){
        if(max_cycle < cycle_length(i))
            max_cycle = cycle_length(i);
=======
    int cache[N] = {0};

    for (int x = i; x <= j && x >= 0; ++x){

        //////////////////////////

        int c = 1;
        int n = x;
        map<int,int>::iterator z;
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
        //////////////////////////

        if(max_cycle < c)
            max_cycle = c;
>>>>>>> dev
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
<<<<<<< HEAD
=======


>>>>>>> dev
// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
