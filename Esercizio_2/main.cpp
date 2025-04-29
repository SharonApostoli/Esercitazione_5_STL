#include <iostream>
#include "PolygonalMesh"
#include "Utils.hpp"
#include "UCDCtilities.hpp"

using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;

int main()
{
    PolygonalLibrary mesh;

    if(!ImportMesh(mesh))
    {
        cerr << "File not foud!" << endl;
        return 1;
    }

    return 0;
}
