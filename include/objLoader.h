#ifndef _OBJLOADER_H_
#define _OBJLOADER_H_

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <assert.h>
#include "vector.h"

namespace rayTracer
{
typedef std::list<std::string> StringList;
class ObjLoader
{
public:
    ObjLoader () {}
    ~ObjLoader () {}

    bool ParseFile ( const char* _fileName );
    void PrintLoadedInfo ();
    void ClearData ();
    void TokenToArray ( const StringList& tokens, std::vector<float>& array );
    void Tokenize ( const std::string& _str,
                    const std::string& _delimiters,
                    StringList& o_tokens );
    void Serialize();

    const std::vector<Vector>& GetVertexArray() const
    {
        return m_vertexArray;
    }
    const std::vector<Vector>& GetTextureArray() const
    {
        return m_textureArray;
    }
    const std::vector<Vector>& GetNormalArray() const
    {
        return m_normalArray;
    }

private:
    std::vector<float> m_vertexBuffer;
    std::vector<float> m_normalBuffer;
    std::vector<float> m_textureBuffer;
    std::vector<float> m_faceBuffer;

    std::vector<Vector> m_vertexArray;
    std::vector<Vector> m_normalArray;
    std::vector<Vector> m_textureArray;
};//end of class
}//end of namespace
#endif