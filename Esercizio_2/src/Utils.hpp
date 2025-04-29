#pragma once

#include <iostream>
#include "PolygonalMesh.hpp"

using namespace std;

namespace PolygonalLibrary
{
    bool ImportMesh(PolygonalLibrary& mesh);

    bool ImportCell0Ds(PolygonalLibrary& mesh);

    bool ImportCell1Ds(PolygonalLibrary& mesh);

    bool ImportCell2Ds(PolygonalLibrary& mesh);
}
