#include "elements.cpp"
class Renderer{ //interface for rendering objects.
	public:
	void upload(Element element);
	void draw();
};
//TODO: add, at the very least, barebones renderer here.
/*Concept: The idea is to create to class interfaces, renderer, which is right here, and element, which is in elements.cpp.
 * If you're not familiar with the concept of interfaces, the idea is simply that any classes that derive from Renderer and Element, and
 * define the empty methods defined in the interfaces themselves, will be compatible with each other, so that one can write an element class
 * to generate vertices and indices in any way one pleases, whether from raw data or by procedurally generated perlin noise(or anything else),
 * and render the data in any way, whether by simple lightless drawing or byt complex cel-shading techniques. 
 * And the two will be mostly independent.
