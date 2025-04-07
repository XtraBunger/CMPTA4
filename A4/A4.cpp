#include <iostream>
#include <string>
#include "RedBlackTree.h"
#include "BinarySearchTree.h"
#include "Treap.h"
#include <time.h>
#include <array>
#include <iomanip>

double elapsed_time(clock_t start, clock_t finish) { // returns elapsed time in milliseconds 
    return (finish - start) / (double)(CLOCKS_PER_SEC / 1000);
}

void printTimingTable(double bstInsert, double bstTraverse,
                      double rbtInsert, double rbtTraverse,
                      double treapInsert, double treapTraverse) {
    using std::cout;
    using std::setw;

    cout << std::left;
    cout << setw(18) << "BST Insert (ms)"
         << setw(20) << "BST Traverse (ms)"
         << setw(18) << "RBT Insert (ms)"
         << setw(20) << "RBT Traverse (ms)"
         << setw(20) << "Treap Insert (ms)"
         << "Treap Traverse (ms)" << '\n';

    cout << std::string(100, '-') << '\n';

    cout << setw(18) << bstInsert
         << setw(20) << bstTraverse
         << setw(18) << rbtInsert
         << setw(20) << rbtTraverse
         << setw(20) << treapInsert
         << treapTraverse << '\n';
}

int main() {

    std::cout<<"Aaron Yee; 301586491; aya102";
    std::cout<<"Chosen data trees are BST, Red-Black Trees and Treaps";

    std::array<int, 20> n1{};
    std::array<int, 10> n2{};

    int n1_size = n1.size();
    int n2_size = n2.size();
    std::cout << "Size of n1: " << n1_size << " Size of n2: " << n2_size;
    for (int i{}; i < n1_size; i++) {
        n1[i] = i + 3;
    }
    for (int i{}; i < n2_size; i++) {
        n2[i] = 2 * i;
    }
  
    clock_t start, finish;// used for getting the time. 
    start = clock();

    BinarySearchTree<int> whug;
    BinarySearchTree<int> mug;

    for (size_t i{}; i < n1.size(); i++) {
        whug.insert(n1[i]);
    }

    for (size_t i{}; i < n2.size(); i++) {
        mug.insert(n2[i]);
    }

    finish = clock();
    double time_taken_BST_insert = elapsed_time(start, finish);
    std::cout << "Time for BST insertion: " << time_taken_BST_insert << '\n';

    start = clock();

    whug.countEven();
    mug.countEven();

    finish = clock();
    double time_taken_BST_traversal = elapsed_time(start, finish);
    std::cout << "Time for BST traversal: " << time_taken_BST_traversal << '\n';

    
    std::cout << "\nFirst tree\n";
    whug.tdisplay();
    std::cout << "\nSecond tree\n";
    mug.tdisplay();
    

    const int NEG_INF = -9999;

    start = clock();

    RedBlackTree<int> turtle{ NEG_INF };
    RedBlackTree<int> tortoise{ NEG_INF };

    for (int i = 0; i < n1_size; i++) {
        turtle.insert(n1[i]);
    }

    for (int i = 0; i < n2_size; i++) {
        tortoise.insert(n2[i]);
    }


    finish = clock();
    double time_taken_RBT_insertion = elapsed_time(start, finish);
    std::cout << "Time for RBT insertion: " << time_taken_RBT_insertion << '\n';

    start = clock();

    turtle.countEven();
    tortoise.countEven();

    finish = clock();
    double time_taken_RBT_traversal = elapsed_time(start, finish);
    std::cout << "Time for RBT traversal: " << time_taken_RBT_traversal << '\n';

    
    std::cout << "\nFirst tree\n";
    turtle.tDisplay();
    std::cout << "\nSecond tree\n";
    tortoise.tDisplay();
    

    start = clock();

    Treap<int> noodle;
    Treap<int> rice;

    for (size_t i{}; i < n1.size(); i++) {
        noodle.insert(n1[i]);
    }

    for (size_t i{}; i < n2.size(); i++) {
        rice.insert(n2[i]);
    }

    finish = clock();
    double time_taken_treap_insertion = elapsed_time(start, finish);
    std::cout << "Time for Treap insertion: " << time_taken_treap_insertion << '\n';

    start = clock();

    noodle.countEven();
    rice.countEven();

    finish = clock();
    double time_taken_treap_traversal = elapsed_time(start, finish);
    std::cout << "Time for Treap traversal: " << time_taken_treap_traversal << '\n';

    
    std::cout << "\nFirst tree\n";
    noodle.tDisplay();
    std::cout << "\nSecond tree\n";
    rice.tDisplay();
    

    printTimingTable(time_taken_BST_insert, time_taken_BST_traversal, 
                    time_taken_RBT_insertion, time_taken_RBT_traversal,
                    time_taken_treap_insertion, time_taken_treap_traversal);
    
    return 0;
}