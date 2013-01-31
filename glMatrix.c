
/*

+	'Hello3d' is a implementation of OpenGL

+	You can redistribute it and/or modify it under the terms of the gnu general public version 3 of 
+	the license as published by the free software foundation.this program is distributed in the hope 
+	that it will be useful,but WITHOUT ANY WARRANTY.without even the implied warranty of merchantability 
+	or fitness for a particular purpose.																					
																												
+	(C)	ͻ�ǿ�ԴTechniques of Knowledge
+		an open source community since 2008
+		Community : http://www.tok.cc
+		Contact Us : jelo.wang@gmail.com

+		-Thanks to Our Committers and Friends
+		-Best Wish to all who Contributed and Inspired
+		-Techniques of Knowledge 
+		-�»����������ףԸ
+		-ͻ�ǿ�Դ����

*/ 

#include "memory.h"
#include "GL.h"
#include "schal.h"
#include "sccl.h"
#include "glMatrix.h"
#include "glOpenGl.h"

void glMatrixAdd ( GLint model ,  GLfloat x , GLfloat y , GLfloat z ) {

	//	author : Jelo Wang
	//	since : 2013.1.9
	//	(C) TOK

	//	��������������һ��һά����ʵ�־Ϳ����ˣ���Ҫ�ǹ��򵥡�	
	
	glVIEWMATRIXATOM atom = { 0 } ;

	if ( 0 == opengl.glViewMatrix.buffer ) {		

		opengl.glViewMatrix.buffer = (void* ) SCMalloc ( glVIEWMATRIXSIZE * sizeof(glVIEWMATRIXATOM) ) ;
		ASSERT(opengl.glViewMatrix.buffer) ; 
		opengl.glViewMatrix.walker = 0 ;
		opengl.glViewMatrix.buffersize = glVIEWMATRIXSIZE * sizeof(glVIEWMATRIXATOM) ;
		
	} else if ( opengl.glViewMatrix.walker >= opengl.glViewMatrix.buffersize ) {
		
		SCRealloc ( opengl.glViewMatrix.buffer , opengl.glViewMatrix.buffersize + glVIEWMATRIXSIZE ) ;
		opengl.glViewMatrix.buffersize = opengl.glViewMatrix.buffersize + glVIEWMATRIXSIZE ;

	}
	
	atom.Orignal.x= x ;
	atom.Orignal.y = y ;
	atom.Orignal.z = z ;

	atom.Current.x = x ;
	atom.Current.y = y ;
	atom.Current.z = z ;	

	memcpy ( (void*)((int) opengl.glViewMatrix.buffer+opengl.glViewMatrix.walker) , &atom , sizeof(glVIEWMATRIXATOM) ) ;
	opengl.glViewMatrix.walker = opengl.glViewMatrix.walker + sizeof(glVIEWMATRIXATOM) ;

}


void glMatrixPerspectiveTransform () {

	//	author : Jelo Wang
	//	since : 2013.1.9
	//	(C) TOK

	//	͸��ͶӰ�任��͸��ͶӰ���������Ѿ���gluPerspective �������ú���
	//	����ı任���̾ͺܼ��ˣ�ֻ��Ҫ�������������ͶӰ���󼴿�

	GLint walker = 0 ;
	GLint totall = 0 ;

	glVIEWMATRIXATOM atom = { 0 } ;

	for ( walker = 0 ; walker < opengl.glViewMatrix.walker ; walker += sizeof(glVIEWMATRIXATOM) ) {

		memcpy ( &atom , (void*)((int) opengl.glViewMatrix.buffer+walker ) , sizeof(glVIEWMATRIXATOM) ) ;

		//	x*(2N/(right-left)) + (right+left/(right-left))
		atom.Current.x = atom.Current.x*opengl.glPerspMatrix.matrix[0][0] + (atom.Current.z*opengl.glPerspMatrix.matrix[0][2]) ;
		//	y*(2N/(top-bottom)) + (top+bottom/(top-bottom))
		atom.Current.y = atom.Current.y*opengl.glPerspMatrix.matrix[1][1] + (atom.Current.z*opengl.glPerspMatrix.matrix[1][2]) ;

		if ( 0 != atom.Current.z ) {

			atom.Current.x = atom.Current.x / atom.Current.z ;
			atom.Current.y = atom.Current.y / atom.Current.z ;

			//	z*a+b / (z)
			atom.Current.z = (atom.Current.z*opengl.glPerspMatrix.matrix[2][2] + opengl.glPerspMatrix.matrix[2][3] ) / atom.Current.z ;
			
		}

		#ifdef glDEBUG
			printf("x %1.3f\n",atom.Current.x*opengl.glViewMatrix.matrix[0][0]+opengl.glViewMatrix.matrix[0][2]) ;
			printf("y %1.3f\n",atom.Current.y*opengl.glViewMatrix.matrix[1][1]+opengl.glViewMatrix.matrix[0][2]) ;
		#endif
		
		//	���ձ任����Ļ����
		atom.Current.x = atom.Current.x*opengl.glViewMatrix.matrix[0][0]+opengl.glViewMatrix.matrix[0][2] ;
		atom.Current.y = opengl.glViewMatrix.matrix[1][1]+opengl.glViewMatrix.matrix[0][2] ;

		memcpy ( (void*)((int) opengl.glViewMatrix.buffer+walker ) , &atom , sizeof(glVIEWMATRIXATOM) ) ;
					
		
	}
	
}

