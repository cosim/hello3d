
/*

+	'Hello3d' is a implementation of OpenGL

+	You can redistribute it and/or modify it under the terms of the gnu general public version 3 of 
+	the license as published by the free software foundation.this program is distributed in the hope 
+	that it will be useful,but WITHOUT ANY WARRANTY.without even the implied warranty of merchantability 
+	or fitness for a particular purpose.																					
																												
+	(C)	突壳开源Techniques of Knowledge
+		an open source community since 2008
+		Community : http://www.tok.cc
+		Contact Us : jelo.wang@gmail.com

+		-Thanks to Our Committers and Friends
+		-Best Wish to all who Contributed and Inspired
+		-Techniques of Knowledge 
+		-致伙伴们最美好祝愿
+		-突壳开源社区

*/ 

#include "math.h"
#include "schal.h"
#include "sccl.h"
#include "GL.h"
#include "glMatrix.h"
#include "glOpenGl.h"

OpenGL opengl = { 0 } ;

void glBegin ( GLenum mode ) {

	//	author : Jelo Wang
	//	since : 2013.1.9
	//	(C) TOK

	opengl.glPrimitive = mode ;
	
}

void glEnd () {

	//	author : Jelo Wang
	//	since : 2013.1.9
	//	(C) TOK

	return ;
	
}

void glColor3f ( GLfloat red, GLfloat green, GLfloat blue ) {

	//	author : Jelo Wang
	//	since : 2013.1.10
	//	(C) TOK

	opengl.glColor.format.f3.red = red ;
	opengl.glColor.format.f3.green = green ;
	opengl.glColor.format.f3.blue = blue ;
	
	
}

void glVertex3f ( GLfloat x , GLfloat y , GLfloat z ) {

	//	author : Jelo Wang
	//	since : 2013.1.9
	//	(C) TOK

	glMatrixAdd ( 0 , x , y , z ) ;

}

void glFlush (void) {

	//	author : Jelo Wang
	//	since : 2013.1.10
	//	(C) TOK
	
	glRenderMatrixDraw ( opengl.glViewMatrix , glVIEWMATRIXSIZE ) ;
	
}
