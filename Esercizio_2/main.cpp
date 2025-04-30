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

    Gedim::UCDUtilities utilities;
    {
        vector<Gedim::UCDProperty<double> cell0Ds_properties(1);

        cell0Ds_properties[0].Label = "Marker";
        cell0Ds_properties[0].UnitLabel = "-";
        cell0Ds_properties[0].NumComponents = 1;

        vector<double> cell0Ds_marker(mesh.NumCell0Ds, 0.0);
        for(const auto &m : mesh.MarkerCell0Ds)
            for(const unsigned int id : m.second)
                cell0Ds_marker.at(id) = m.first;

        cell0Ds_properties[0].Data = cell0Ds_marker.data();

        utilities.ExportPoints("./Cell0Ds.inp", mesh.Cell0DsCoordinates, cell0Ds_propertier);
    }

    {
        vector<Gedim::UCDProperty<double>> cell1Ds_properties(1);

        cell1Ds_properties[0].Label = "Marker";
        cell1Ds_properties[0].UnitLabel = "-";
        cell1Ds_properties[0].NumComponents = 1;

        vector<double> cell1Ds_marker(mesh.NumCell1Ds, 0.0);
        for(const auto &m : mesh.MarkerCell1Ds)
            for(const unsigned int id: m.second)
                cell1Ds_marker.at(id) = m.first;

        cell1Ds_properties[0].Data = cell1Ds_marker.data();

        utilities.ExportSegments("./Cell1Ds.inp",
                                 mesh.Cell0DsCoordinates,
                                 mesh.Cell1DsExtrema,
                                 {},
                                 cell1Ds_properties);
    }

    if(!CheckLengthEdge(mesh))
    {
        cerr << "At least one edge has length equal to zero" << endl;
        return 1;
    }else
        cout << "All edges have non-zero length" << endl;


    if(!CheckNonZeroArea(mesh))
    {
        cerr << "At least one polygon has an area equal to zero or near-zero" << endl;
        return 1;
    }
    else
        cout << "All polygons have area greater than zero!" << endl;

        
    return 0;
}
