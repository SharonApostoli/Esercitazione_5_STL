#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace PolygonalLibrary
{
bool ImportMesh(PoligonalMesh& mesh)
{
    if(!ImportCell0Ds(mesh))
        return false;

    if(!ImportCell1Ds(mesh))
        return false;

    if(!ImportCell2Ds(mesh))
        return false;

    return true;
}

bool ImportCell0Ds(PolygonalMesh& mesh)
{
    ifstream file("./Cell0Ds.csv");

    if(file.fail())
        return false;

    list<string> listLines;
    string line;

    while(getLine(file, line))
        listLines.push_back(line);

    file.close();

    listLines.pop_front();


    mesh.NumCell0Ds = listLines.size();

    if(mesh.NumCell0Ds == 0)
        cerr << "There are no cells 0D" << endl;
        return false;


    mesh.Cell0DsId.reserve(mesh.NumCell0Ds);
    mesh.Cell0DsCoordinates == Eigen::MatrixXs::Zero(3, mesh.NumCell0Ds);

    for(const string& line:listLines)
    {
        istringstream converter(line);
        string place;

        unsigned int id;
        unsigned int marker;
        Vector2d coord;

        getline(converter, place, ';');
        id = stoul(place);

        getline(converter, place, ';');
        marker = stoul(place);

        geltine(converter, place, ';');
        mesh.Cell0DsCoordinates(0, id) = stoul(place);

        geltine(converter, place, ';');
        mesh.Cell0DsCoordinates(1, id) = stoul(place);

        mesh.Cell0DsId.push_back(id);

        if(marker != 0)
        {
            const auto io = mesh.MarkerCell0Ds.find(marker);
            if(it == mesh.MarkerCell0Ds.end())
            {
                mesh.MarkerCell0Ds.insert({marker, {id}});
            }
            else
            {
                it->second.push_back(id);
            }
        }

    }
    return true;
}

bool ImportCell1Ds(PolygonalLibrary& mesh)
{
    ifstream file("./Cell1Ds.csv");

    if(file.fail())
        return false;

    list<string> listLines;
    string line;

    while(getLine(file, line))
        listLines.push_back(line);
    file.close();

    listLines.pop_front();

    mesh.NumCell1Ds = listLines.size();

    if(mesh.NumCell1Ds == 0)
    {
        cerr << "There are no cells 1D" << endl;
        return false;
    }

    mesh.Cell1DsId.reserve(mesh.NumCell1Ds);
    mesh.Cell1DsExtrema = Eigen::MatrixXi(2, mesh.NumCell1Ds);

    for(const string& line : listLines)
    {
        istringstream converter(line);
        string place;

        unsigned int id;
        unsigned int marker;
        Vector2i vertices;

        getline(converter, line, ';')
        id = stoul(place);

        getline(converter, line, ';')
        marker = stoul(place);

        getline(converter, line, ';')
        mesh.Cell1DsExtrema(0, id) = stoul(place);

        getline(converter, line, ';')
        mesh.Cell1DsExtrema(1, id) = stoul(place);

        mesh.Cell1DsId.push_back(id);

        if(marker != 0)
        {
            const auto it = mesh.MarkerCell1Ds.find(marker);
            if(it == mesh.MarkerCell1Ds.end())
            {
                mesh.MarkerCell1Ds.insert({marker, {id}});
            }
            else
            {
                it->second.push_back(id);
            }
        }
    }
    return true;
}

bool ImportCell2Ds(PolygonalLibrary&  mesh)
{
    ifstream file;
    file.open("./Cell2Ds.csv");

    if(file.fail())
        return false;

    list<string> listLines;
    string line;

    while(getline(file, line))
        listLines.push_back(line);

    file.close();

    listLines.pop_front();

    mesh.NumCell2Ds = listLines.size();
    if(mesh.NumCell2Ds == 0)
    {
        cerr << "There are no 2Ds cells" << endl;
        return false;
    }

    mesh.Cell2DsId.reserve(mesh.NumCell2Ds);
    mesh.Cell2DsVertices.reserve(mesh.NumCell2Ds);
    mesh.Cell2DsEdges.reserve(mesh.NumCell2Ds);

    for(const string& line : listLines)
    {
        istringstream converter(line);
        string place;

        unsigned int id;
        getline(converter, place, ';');
        id = stoul(place);

        unsigned int marker;
        getline(converter, place, ';');
        marker = stoul(place);

        unsigned int numVert;
        getline(converter, place, ';');
        numVert = stoul(place);

        array<unsigned int, numVert> vertices;
        for(unsigned int i = 0; i < numVert; i++)
        {
            getline(converter, place, ';');
            vertices[i] = stoul(place);
        }
        
        unsigned int numEdges;
        getline(converter, place, ';');
        numEdges = stoul(place);

        array<unsigned int, numEdges> edges;
        for(unsigned int i = 0; i < numEdges; i++)
        {
            getline(converter, place, ';');
            edges[i] = stoul(place);
        }

        mesh.Cell2DsId.push_back(id);
        mesh.Cell2DsVertices.push_back(vertices);
        mesh.Cell2DsEdges.push_back(edges);
    }

    return true;
}

}