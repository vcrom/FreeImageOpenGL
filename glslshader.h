#ifndef GLSLSHADER_H
#define GLSLSHADER_H

#include <glad/glad.h>
#include <map>
#include <string>
#include <glm\glm.hpp>


class GlslShader
{
	using Vec2 = glm::vec2;
	using Vec3 = glm::vec3;
	using Vec4 = glm::vec4;
	using Mat3x3 = glm::mat3;
	using Mat4x4 = glm::mat4;

	#define toPointer glm::value_ptr

public:
	GlslShader(void);
	~GlslShader(void);
	void loadFromString(GLenum whichShader, const std::string& source);
	void loadFromFile(GLenum whichShader, const std::string& filename);
	void createAndLinkProgram();
	void use();
	void unUse();
	void addAttribute(const std::string& attribute);
	void addUniform(const std::string& uniform);
	void setUniform(const std::string& uniform, int val);
	void setUniform(const std::string& uniform, float val);
	void setUniform(const std::string& uniform, const Vec2 &val);
	void setUniform(const std::string& uniform, const Vec3 &val);
	void setUniform(const std::string& uniform, const Vec4 &val);
	void setUniform(const std::string& uniform, const Mat3x3 &val);
	void setUniform(const std::string& uniform, const Mat4x4 &val);
	void setAttribute(const std::string& attribute);

	//An indexer that returns the location of the attribute/uniform
	GLuint operator[](const std::string& attribute);
	GLuint operator()(const std::string& uniform);
	void deleteShaderProgram();
private:
	enum ShaderType { VERTEX_SHADER, FRAGMENT_SHADER, GEOMETRY_SHADER };
	GLuint _program;
	int _totalShaders;
	GLuint _shaders[3];//0->vertexshader, 1->fragmentshader, 2->geometryshader
	std::map<std::string, GLuint> _attributeList;
	std::map<std::string, GLuint> _uniformLocationList;
};

#endif // GLSLSHADER_H
