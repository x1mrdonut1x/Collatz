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

int i = z;

while(t[i][0] != k && i >0){
    --i;
}

if (t[i][0] != k)
    return 0;

return t[i][1];}

//-------------
//cycle_length
//-------------
int cycle_length (int n) {

    int cache[10000][2], z = 0;
    int c = 1;

    while (n > 1) {
        int p = search_array(cache, n, 1);
        if ((n % 2) == 0){
            n = (n / 2);
            if (p != 0)
                return p;
        }else{
            n = (3 * n) + 1;
        }
        ++c;}

    cache[z][0] = n;
    cache[z][1] = c;
    ++z;


    return c;}
// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {

    if (j < i){
        int temp = i;
        i = j;
        j = temp;
    }

    int cache[10000][2], z = 0;
    int max_cycle = 0;

    for (i; i<=j && i >= 0; ++i){

        //////////////////////////
        int c = 1;
        int n = i;
        int p = 0;
        while (n > 1) {
            p = search_array(cache, n, z);
            if ((n % 2) == 0){
                n = (n / 2);
            }else{
                n = (3 * n) + 1;
            }
            if (p != 0){
                //cout << n << " -- " << p << endl;
                c += p - 1;
                break;
            }

            ++c;}
        //cout << " -- " << c << endl;
        if (p == 0){
            cache[z][0] = i;
            cache[z][1] = c;
            ++z;}

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
