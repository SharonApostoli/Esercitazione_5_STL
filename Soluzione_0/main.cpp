#include <iostream>
#include <Eigen/Eigen>

using namespace std;
using namespace Eigen;

int main()
{
    //    auto a; // error
    auto aint = 1;
    auto adouble = 1.0;

    cout << "sizeof(aint): " << sizeof(aint) << endl;
    cout << "sizeof(adouble): " << sizeof(adouble) << endl;

    int i = 0;
    int &r = i;
    auto b = r; // a is int - when we use a reference as an initializer, the intiializer is the corresponding object.
    auto &bref = r; // bref is a reference for i;
    auto p = &i;

    i++;
    cout << "b: " << b << endl;
    cout << "bref: " << bref << endl;
    cout << "p: " << (*p) << endl;

    const int iconst = 1;
    auto c = iconst;
    c = 2; // top-level const are ignored
    const auto cconst = iconst; // declare a top-level const explicitly
    auto ptr = &iconst;
    // (*ptr)++; // error: low-level const is preserverd


    /// STL

    vector<int> v1 = {1, 2, 3}; // list inizialitazion
    list<int> l1 = {1, 2, 3};
    array<int, 3> a = {1, 2, 3};

    // Other types
    vector<int> v2{1, 2}; // list inizialitazion // v2 has 2 elements: 1, 2
    vector<int> v3(v2); // copy inizialitazion
    vector<int> v4(5, 2); // value inizialitazion // v4 has 5 elements with value 2
    vector<string> v5{10, "hi"}; // if list intiialization is not possible, the compiler looks for other ways to initialize the object from the given values

    // Some operations
    cout << "v1.empty(): " << v1.empty() << endl; // true if v1 is empty
    cout << "v1.size(): " << v1.size() << endl; // number of elements of v1
    cout << "v1[1]: " << v1[1] << endl; // reference to the second element of v1
    v1.push_back(4); // add element at back
    cout << "v1.size() after push_back: " << v1.size() << endl; // number of elements of v1

    // The for range
    cout << "v1: " << endl;
    for(auto& el: v1)
        cout << el << " ";
    cout << endl;

    // for range is equivalent to
    cout << "v1 with iterator: " << endl;
    for(auto it = v1.begin(); it != v1.end(); it++) // for range
        cout << *it << " ";
    cout << endl;

    //    cout << "v1: " << endl;
    //    for(auto& el: v1)
    //    {
    //        v1.push_back(0); // adding element to a vector pontentially invalidates all existing iterators, reference, etc
    //        cout << el << " ";
    //    }
    //    cout << endl;

    vector<int>::iterator it_vec = v1.begin();
    cout << "*it_vec: "<< (*it_vec) << endl;

    auto it = v1.begin() + 1; // like pointers
    v1.insert(it, 2, 0); // adding an element in front or in the middle of a vector is legal but potentially expensive
    cout << "v1: " << endl;
    for(auto& el: v1) // for range
        cout << el << " ";
    cout << endl;

    v1.erase(v1.begin()+3, v1.end()-1); // elimina elementi da it1 a it2 non compreso

    cout << "v1: " << endl;
    for(auto& el: v1) // for range
        cout << el << " ";
    cout << endl;

    // How vector growth
    vector<int> vv;
    for(unsigned int i = 0; i < 8; i++)
    {
        vv.push_back(i);
        cout << &vv[0] << endl;
        cout << "vv.size() = " << vv.size() << ", vv.capacity() = " << vv.capacity() << endl;
    }

    vv.reserve(30);

    cout << "vv: " << endl;
    for(auto& el: vv)
        cout << el << " ";
    cout << endl;

    cout << "vv.size() = " << vv.size() << ", vv.capacity() = " << vv.capacity() << endl;
    vv.reserve(15);
    cout << "vv.size() = " << vv.size() << ", vv.capacity() = " << vv.capacity() << endl;
    vv.reserve(4);
    cout << "vv.size() = " << vv.size() << ", vv.capacity() = " << vv.capacity() << endl;

    vv.resize(15);
    cout << "vv.size() = " << vv.size() << ", vv.capacity() = " << vv.capacity() << endl;

    cout << "vv: " << endl;
    for(auto& el: vv)
        cout << el << " ";
    cout << endl;

    vv.resize(4);
    cout << "vv.size() = " << vv.size() << ", vv.capacity() = " << vv.capacity() << endl;

    cout << "vv: " << endl;
    for(auto& el: vv)
        cout << el << " ";
    cout << endl;

    Eigen::VectorXd eigenVV = Eigen::VectorXd::Ones(15);

    cout << "eigenVV: " << endl;
    cout << eigenVV.transpose() << endl;

    eigenVV.resize(4); // not conservative for eigen: try conservativeResize()

    cout << "eigenVV: " << endl;
    cout << eigenVV.transpose() << endl;


    return 0;
}

