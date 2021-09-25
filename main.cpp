#include <iostream>
#include <string>

#include "bidirectional_list.h"
#include "iterator.h"

int main() {
    // LIST TESTS

    //---------------constructors------------------------

//    std::cout << "default constructor:\n";
//    BidirectionalList<int> list1;
//    list1.Show();
//    std::cout << "\nconstructor with certain capacity:\n";
//    BidirectionalList<std::string> list2(6);
//    list2.Show();
//    std::cout << "\nconstructor by std::initializer_list:\n";
//    BidirectionalList<int> list3({1, 2, 3, 4, 5, 6, 7, 8});
//    list3.Show();
//    std::cout << "\ncopy constructor:\n";
//    BidirectionalList<int> list4(list3);
//    list4.Show();
//    std::cout << "\nmove constructor\n";
//    BidirectionalList<int> list5(std::move(list3));
//    list5.Show();

    //--------------------- copy= ----------------------------

//    std::cout << "\nCOPY =\n";
//    BidirectionalList<char> list6({'a', 'b', 'c'});
//    list6.Show();
//    BidirectionalList<char> list7({'q', 'w', 'e', 'r'});
//    list7.Show();
//    list6 = list7;
//    list6.Show();
//    list7.Show();

    //--------------------- move= ----------------------------

//    std::cout << "\nMOVE =\n";
//    BidirectionalList<double> list8({1.1, 2.2, 3.3, 4.4, 5.5});
//    list8.Show();
//    BidirectionalList<double> list9({3.14, 9.8});
//    list9.Show();
//    list8 = std::move(list9);
//    list8.Show();
//    //list9.Show();

    //---------------------resize methods-------------------------

//    std::cout << "\nRESIZE\n";
//    BidirectionalList<int> list10({1, 2, 3});
//    list10.Show();
//    list10.Resize(10);
//    list10.Show();
//    list10.Resize();
//    list10.Show();

    //----------------------push/pop methods-------------------------

//    std::cout << "\nPUSH\POP\n";
//    BidirectionalList<int> list11({1, 2, 3});
//    list11.Show();
//    list11.PushFront(7);
//    list11.Show();
//
//    list11.PushBack(4);
//    list11.PushBack(5);
//    list11.PushBack(6);
//    list11.Show();
//
//    list11.PopBack();
//    list11.Show();
//    list11.PopFront();
//    list11.PopFront();
//    list11.PopFront();
//    list11.Show();

    //------------------------clear-------------------------------------

//    std::cout << "\nCLEAR\n";
//    BidirectionalList<std::string> list12({"cat", "dog", "frog", "mouse"});
//    list12.Show();
//    list12.Clear();
//    list12.Show();

    //--------------------------- + += ---------------------------------

//    std::cout << "\n+ +=\n";
//    BidirectionalList<int> list13({1, 2, 3, 4, 5});
//    list13.Show();
//    BidirectionalList<int> list14({6, 7, 8, 9, 10});
//    list14.Show();
//
//    BidirectionalList<int> list15;
//    list15 = list13 + list14;
//    list15.Show();
//    list15 += list14;
//    list15.Show();

    //--------------------------- == != -----------------------------------

//    std::cout << "\n== !=\n";
//    BidirectionalList<int> list16({1, 2, 3, 4, 5});
//    list16.Show();
//    BidirectionalList<int> list17({6, 7, 8, 9, 10});
//    list17.Show();
//
//    if(list16 != list17)
//        std::cout << "////////// != //////////\n";
//    else
//        std::cout << "////////// == //////////\n";
//
//    list17 = list16;
//    list17.Show();
//
//    if(list16 == list17)
//        std::cout << "////////// == //////////\n";
//    else
//        std::cout << "////////// != //////////\n";


//            VISITOR TESTS

    BidirectionalList<int> list({1, 2, 3, 4, 5});
    VisitorToString<int> vts;
    list.ExecuteOperation(&vts);
    std::cout << vts.GetString();

    return 0;
}
