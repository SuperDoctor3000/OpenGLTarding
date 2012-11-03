char *LoadShaderSource(char *);

GLuint MakeShader(char *, GLenum);

model makeModel(GLuint shader, float* data, int size);
