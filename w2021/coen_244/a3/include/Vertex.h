#ifndef VERTEX_H
#define VERTEX_H

// Standard libs
#include <string>

using namespace std;

class Vertex {
    public:
        Vertex();
        virtual ~Vertex();

        bool    SetVertexID(int);
        bool    SetVertexValue(string);
        int     GetVertexID() const;
        string  GetVertexValue() const;

    private:
        int     id;
        string  value;
};

#endif