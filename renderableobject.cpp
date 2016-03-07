#include "renderableobject.h"

RenderableObject::RenderableObject()
{

}


RenderableObject::~RenderableObject()
{
	destroy();
}

#define GL_CHECK_ERRORS assert(glGetError()== GL_NO_ERROR);
void RenderableObject::initialize() {
	GL_CHECK_ERRORS
	//setup vao and vbo stuff
	glGenVertexArrays(1, &vaoId_);
	glGenBuffers(1, &vboVerticesId_);
	glGenBuffers(1, &vboIndicesId_);

	GL_CHECK_ERRORS
	//Get total vertices, indices and primitive type
	totalVertices_ = getTotalVertices();
	totalIndices_ = getTotalIndices();
	primType_ = getPrimitiveType();

	//Allocate buffers
	glBindVertexArray(vaoId_);
	GL_CHECK_ERRORS

	//vertices
	glBindBuffer(GL_ARRAY_BUFFER, vboVerticesId_);
	glBufferData(GL_ARRAY_BUFFER, totalVertices_ * sizeOfVertexElement(), 0, GL_STATIC_DRAW);
	GL_CHECK_ERRORS

	GLfloat* pBuffer = static_cast<GLfloat*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	assert(pBuffer != nullptr);
	fillVertexBuffer(pBuffer);
	//glUnmapBuffer(GL_ARRAY_BUFFER)
	assert(glUnmapBuffer(GL_ARRAY_BUFFER) == GL_TRUE);
	GL_CHECK_ERRORS

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, vertexNumberOfComponents(), GL_FLOAT, GL_FALSE, 0, 0);
	GL_CHECK_ERRORS

	//Faces indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndicesId_);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, totalIndices_ * sizeof(GLuint), 0, GL_STATIC_DRAW);
	GL_CHECK_ERRORS

	GLuint* pIBuffer = static_cast<GLuint*>(glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY));
	assert(pIBuffer != nullptr);
	fillIndexBuffer(pIBuffer);
	//glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
	assert(glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER) == GL_TRUE);

	glBindVertexArray(0);
	GL_CHECK_ERRORS
}

void RenderableObject::destroy() {
	//Destroy vao and vbo
	glDeleteBuffers(1, &vboVerticesId_);
	glDeleteBuffers(1, &vboIndicesId_);
	glDeleteVertexArrays(1, &vaoId_);
}

#include <iostream>
void RenderableObject::render() const
{
	glGetError();
	//Bind vao and draw it.
	glBindVertexArray(vaoId_);
	glDrawElements(primType_, totalIndices_, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	//{ GLenum err; while ((err = glGetError()) != GL_NO_ERROR) { std::cerr << "OpenGL error: " << err << std::endl; } }
	GL_CHECK_ERRORS
}
