#pragma once

#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;


namespace TriangularLibrary {

struct TriangularMesh
{
    unsigned int NumCell0Ds = 0;
    std::vector<unsigned int> Cell0DsID = {};
    Eigen::MatrixXd Cell0DsCoordinates = {};
    std::map<unsigned int, list<unsigned int>> MarkerCell0Ds = {};

    unsigned int NumCell1Ds = 0;
    std::vector<unsigned int> Cell1DsId = {};
    Eigen::MatrixXi Cell1DsExtrema = {};
    std::map<unsigned int, list<unsigned int>> MarkerCell1Ds  = {}:

    unsigned int NumCell2Ds = 0;
    std::vector<unsigned int> Cell2DsId = {};
    std::vector<array<unsigned int, 3>> Cell2DsVertices = {};
    std::vector<array<unsigned int, 3>> Cell2DsEdges = {};
};

}
