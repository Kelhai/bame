#ifndef SHADER_H_
#define SHADER_H_

#include <string>

#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../glad/include/glad/glad.h"

class Shader {
	public:
		unsigned int id;

		Shader() {}
		Shader& use();

		void compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr);
		
		void setFloat(const char* name, float value, bool useShader = false);
		void setInteger(const char* name, int value, bool useShader = false);
		void setVector2f(const char* name, float x, float y, bool useShader = false);
		void setVector2f(const char* name, const glm::vec2& value, bool useShader = false);
		void setVector3f(const char* name, float x, float y, float z, bool useShader = false);
		void setVector3f(const char* name, const glm::vec3& value, bool useShader = false);
		void setVector4f(const char* name, float x, float y, float z, float w, bool useShader = false);
		void setVector4f(const char* name, const glm::vec4& value, bool useShader = false);
		void setMatrix4(const char* name, const glm::mat4& matrix, bool useShader = false);
	private:
		void checkCompileErrors(unsigned int object, std::string type);
};

#endif
