// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read1) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read2) {
    istringstream r("10 1000\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 10, i);
    ASSERT_EQ(1000, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(0, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(10, 10);
    ASSERT_EQ(7, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(10000000, 10000000);
    ASSERT_EQ(146, v);}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(501, 101);
    ASSERT_EQ(144, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(1, 9999);
    ASSERT_EQ(262, v);}


TEST(CollatzFixture, eval_11) {
    const int v = collatz_eval(319662, 322868);
    ASSERT_EQ(371, v);}


TEST(CollatzFixture, eval_12) {
    const int v = collatz_eval(3000, 340);
    ASSERT_EQ(217, v);}


TEST(CollatzFixture, eval_13) {
    const int v = collatz_eval(9999, 9998);
    ASSERT_EQ(92, v);}




// -----
// print
// -----

TEST(CollatzFixture, print1) {
    ostringstream w;
    collatz_print(w, 0, 100, 101);
    ASSERT_EQ("0 100 101\n", w.str());}

TEST(CollatzFixture, print2) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print3) {
    ostringstream w;
    collatz_print(w, 0, 0, 0);
    ASSERT_EQ("0 0 0\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

    TEST(CollatzFixture, solve2) {
    istringstream r("500 101\n3000 340\n1 9999\n20 20\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("500 101 144\n3000 340 217\n1 9999 262\n20 20 8\n", w.str());}


