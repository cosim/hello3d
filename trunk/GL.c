
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

#include "i51KitAde.h"
#include "math.h"
#include "schal.h"
#include "sccl.h"
#include "GL.h"
#include "glMatrix.h"
#include "glOpenGl.h"
#include "glRender.h"

OpenGL opengl = { 0 } ;

void glViewport ( GLint x , GLint y , GLsizei width , GLsizei height ) {

	//	author : Jelo Wang
	//	since : 2013.1.18
	//	(C) TOK

	opengl.glViewPort.x = x ; 
	opengl.glViewPort.y = y ; 	
	opengl.glViewPort.width = width ;
	opengl.glViewPort.height = height ;
	
	
}

void glClearColor ( GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha ) {

	//	author : Jelo Wang
	//	since : 2013.1.18
	//	(C) TOK

	opengl.glViewPort.background.red = red ;
	opengl.glViewPort.background.green = green ;
	opengl.glViewPort.background.blue = blue ;
	opengl.glViewPort.background.alpha = alpha ;
	
}

void glClear ( GLbitfield mask ) {


	//	author : Jelo Wang
	//	since : 2013.1.18
	//	(C) TOK

	GLint color = 0 ;
	
#if 0
	if ( GL_COLOR_BUFFER_BIT == (GL_COLOR_BUFFER_BIT & mask) ) {


	}


	if ( GL_DEPTH_BUFFER_BIT == (GL_COLOR_BUFFER_BIT & mask) ) {


	}


	if ( GL_ACCUM_BUFFER_BIT == (GL_COLOR_BUFFER_BIT & mask) ) {


	}


	if ( GL_STENCIL_BUFFER_BIT == (GL_COLOR_BUFFER_BIT & mask) ) {


	}
	
#endif


	if ( glCOLOR_RGB565 == opengl.glColor.panelformat ) {
		
		GLbyte r5 = 31 ;
		GLbyte g6 = 63 ;
		GLbyte b5 = 31 ;

		GLbyte nr5 = 0 ;
		GLbyte ng6 = 0 ;
		GLbyte nb5 = 0 ;		

		GLint walker = 0 ;
		GLint totall = 0 ;
		GLushort* panel = 0 ;
		
		nr5 = opengl.glViewPort.background.red * r5 ;
		ng6 = opengl.glViewPort.background.green * g6 ;
		nb5 = opengl.glViewPort.background.blue * b5 ;

		panel = opengl.glViewPort.panel ;
		totall = opengl.glViewPort.width*opengl.glViewPort.height ;

		RENDERRGB565COLOR_EX(color,nr5,ng6,nb5) ;

		for ( walker = 0 ; walker < totall ; walker ++ ) {
			panel[walker] = color ;
		}				
		
	}


	
	
	
}

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

	glRenderMatrixDraw ( opengl.glViewMatrix , glVIEWMATRIXSIZE ) ;
	
	
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

	opengl.glColor.pipeformat = glCOLOR_RGB_F3 ;
	glMatrixAdd ( 0 , x , y , z ) ;

}

void glFlush (void) {

	//	author : Jelo Wang
	//	since : 2013.1.10
	//	(C) TOK
	
	i51AdeMmiUpdateScreen () ;
	
}

