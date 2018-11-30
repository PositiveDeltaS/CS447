/*
 * Buildings.cpp: Texture mapping some rectangles
 *
 *  --KT
 */
#include <FL/glu.H>
#include "Buildings.h"
#include <windows.H>
#include <GL/glut.h>
#include <FL/math.H>
#include "libtarga.h"
#include <stdio.h>

bool
Buildings::Initialize(void) {
	
	ubyte   *image_data;
	int	    image_height, image_width;

	// Load the image for the texture. The texture file has to be in
	// a place where it will be found.
	if (!(image_data = (ubyte*)tga_load("minecraft.tga", &image_width, &image_height, TGA_TRUECOLOR_24)))
	{
		fprintf(stderr, "Buildings::Initialize: Couldn't load minecraft.tga\n");
		return false;
	}
	glGenTextures(1, &texture_obj);
	glBindTexture(GL_TEXTURE_2D, texture_obj);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width, image_height, 0, GL_RGB,
		GL_UNSIGNED_BYTE, image_data);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image_width, image_height, GL_RGB, GL_UNSIGNED_BYTE, image_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	free(image_data);

	ubyte   *image_data2;
	int	    image_height2, image_width2;

	// Load the image for the texture. The texture file has to be in
	// a place where it will be found.
	if (!(image_data2 = (ubyte*)tga_load("bday.tga", &image_width2, &image_height2, TGA_TRUECOLOR_24)))
	{
		fprintf(stderr, "Buildings::Initialize: Couldn't load .tga\n");
		return false;
	}

	glGenTextures(1, &texture_obj2);
	glBindTexture(GL_TEXTURE_2D, texture_obj2);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width2, image_height2, 0, GL_RGB,
		GL_UNSIGNED_BYTE, image_data2);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image_width2, image_height2, GL_RGB, GL_UNSIGNED_BYTE, image_data2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	free(image_data2);


	return true;
}

void 
Buildings::Draw(void) {

	
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_obj);

	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
	   // Top face (y = 1.0f)
	   // Define vertices in counter-clockwise (CCW) order with normal pointing out
	//glColor3f(0.0f, 1.0f, 0.0f);     // Green
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);

	// Bottom face (y = -1.0f)
	//glColor3f(1.0f, 0.5f, 0.0f);     // Orange
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);

	// Front face  (z = 1.0f)
	//glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);

	// Back face (z = -1.0f)
	//glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);

	// Left face (x = -1.0f)
	//glColor3f(0.0f, 0.0f, 1.0f);     // Blue
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);

	// Right face (x = 1.0f)
	//glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Buildings::DrawPyramid() {
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_obj2);

	glBegin(GL_TRIANGLES);
	//Triangle 1
	

	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 5.0f, 0.0f);   //V0(red)
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);   //V1(green)
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);   //V2(blue)
  //Triangle 2

	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 5.0f, 0.0f);   //V0(red)
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);   //V2(blue)
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);   //V3(green)
  //Triangle 3

	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 5.0f, 0.0f);   //V0(red)
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);   //V3(green)
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);   //V4(blue)
  //Triangle 4

	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 5.0f, 0.0f);   //V0(red)
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);   //V4(blue)
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);   //V1(green)


	glEnd();

	glDisable(GL_TEXTURE_2D);

}

void Buildings::DrawSphere() {
	ubyte   *image_data3;
	int	    image_height3, image_width3;

	// Load the image for the texture. The texture file has to be in
	// a place where it will be found.
	if (!(image_data3 = (ubyte*)tga_load("90061.tga", &image_width3, &image_height3, TGA_TRUECOLOR_24)))
	{
		fprintf(stderr, "Buildings::Initialize: Couldn't load .tga\n");
	}

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &spheretex);
	glBindTexture(GL_TEXTURE_2D, spheretex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width3, image_height3, 0, GL_RGB,
		GL_UNSIGNED_BYTE, image_data3);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

	glutSolidSphere(1, 50, 50);

	glDisable(GL_TEXTURE_2D);

}