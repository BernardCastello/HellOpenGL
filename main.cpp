#include "Core.h"
#include "System.h"

void main()
{
	coreLoad(Window);
	coreLoad(Time);
	coreLoad(Input);
	coreLoad(Camera);
 	coreLoad(Factory);
	coreLoad(Asset);
	
	systemLoad(TransformUpdate);
	systemLoad(Rendering);
	
	initCore();



	// Safe to load assets and make dudes.
	core(Asset).loadShader("Flat","./shaders/simpleShader.vert", "./shaders/simpleShader.frag");
	
	Vertex verts[3] = { { {   0,  30, 0, 1 }, { 0, 1, 1, 1 } },
						{ { -30, -30, 0, 1 }, { 1, 1, 0, 1 } }, { {  30, -30, 0, 1 }, { 1, 0, 1, 1 } } };
	Triangle tris[1] = { 0, 1, 2 };

	core(Asset).loadMesh("Triangle", verts, 3, tris, 1);


	core(Factory).MakeTriangle();

	runGame();
}