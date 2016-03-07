#include "screenquad.h"

const std::vector<glm::vec2> ScreenQuad::_vertices = { glm::vec2(0.0, 0.0), glm::vec2(1.0, 0.0), glm::vec2(1.0, 1.0), glm::vec2(0.0, 1.0) };
const std::vector<unsigned int> ScreenQuad::_indices = { 0, 1, 2, 0, 2, 3 };


std::shared_ptr<ScreenQuad> ScreenQuad::getInstance()
{
	static auto instance = std::shared_ptr<ScreenQuad>(new ScreenQuad());
	return instance;
}

ScreenQuad::ScreenQuad()
	: RenderableObject()
{
	initialize();
}

ScreenQuad::~ScreenQuad()
{
}

unsigned int ScreenQuad::getTotalVertices()
{
    return static_cast<unsigned int>(_vertices.size());
}

unsigned int ScreenQuad::getTotalIndices()
{
    return static_cast<unsigned int>(_indices.size());
}

GLenum ScreenQuad::getPrimitiveType()
{
	return GL_TRIANGLES;
}

unsigned int ScreenQuad::sizeOfVertexElement()
{
	return sizeof(glm::vec2);
}

unsigned int ScreenQuad::vertexNumberOfComponents()
{
	return 2;
}

void ScreenQuad::fillVertexBuffer(GLfloat* pBuffer)
{
	glm::vec2* vert = (glm::vec2*)(pBuffer);
    for (unsigned int i = 0; i < getTotalVertices(); ++i)
        vert[i] = _vertices[i];
}

void ScreenQuad::fillIndexBuffer(GLuint* pBuffer)
{
	int* idx = (int*)(pBuffer);
    for (unsigned int i = 0; i < getTotalIndices(); ++i)
        idx[i] = _indices[i];
}
