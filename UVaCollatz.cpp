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
// search_array
// ------------

int search_array(int t[][2], int k, int z){

int i = 0;

while(t[i][0] != k && i > 0){
    --i;
}

if (t[i][0] != k){
    return 0;
}

return t[i][1];}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {

    if (j < i){
        int temp = i;
        i = j;
        j = temp;
    }

    int cache[10000][2], z = 4;
    int max_cycle = 0;
              
            cache[0][0] = 2;
            cache[0][1] = 2;
            cache[1][0] = 4;
            cache[1][1] = 3;
            cache[2][0] = 8;
            cache[2][1] = 4;
            cache[3][0] = 16;
            cache[3][1] = 5;
            cache[4][0] = 3;
            cache[4][1] = 8;
            cache[5][0] = 7;
            cache[5][1] = 17;
            
    for (int x = i; x <= j && x >= 0; ++x){

        //////////////////////////

        int c = 1;
        int n = x;
        int p = 0;

        while (n > 1) {
            p = search_array(cache, n, z);
            if (p != 0){
                c += p - 1;
                break;
            }
            if ((n % 2) == 0){
                n = (n / 2);
            }else{
                n = (3 * n) + 1;
            }

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
