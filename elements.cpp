#include <GL/glew.h>
#include <GL/glfw.h>
#include <stdlib.h>
class Element{ //interface for renderable objects
	public:
	float* vertices();
	int verticesLength();
	int* indices();
	int indicesLength();
};
class RawElement : public Element{
	float* vertData;
	int vertLength;
	int* indexData;
	int indexLength;
	RawElement(float* verts, int vertLen, int* inds, int indLen)
	{
		vertData = (float*)malloc(vertLen*sizeof(float));
		indexData = (int*)malloc(indLen*sizeof(float));
		vertLength = vertLen;
		indexLength = indLen;
		for (int i=0; i<vertLength; i++){
			vertData[i] = verts[i];
		}
		for (int i=0; i<indLen; i++){
			indexData[i] = inds [i];
		}
	}
	float* vertices(){return vertData;}
	int verticesLength(){return vertLength;}
	int* indices(){return indexData;}
	int indicesLength(){return indexLength;}
	~RawElement(){free(vertData); free(indexData);}
};
