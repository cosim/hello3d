
#include "i51KitAde.h"
#include "Hello3D.h"
#include "GL.h"
#include "glut.h"

i51KIT_STATIC_KIT_DEF(Adapter);
extern void glMatrixAdd ( GLint model ,  GLfloat x , GLfloat y , GLfloat z ) ;
extern void glVertex3f (float,float,float) ;

iKIT iBOOL i51KitMain ( iS32 aid , iU32 message , void* parameter )
{

	//	TODO :	ÏûÏ¢Ñ­»·

	switch ( message )
	{
		case i51_MSG_PAINT :

		break ;
	
		case i51_MSG_RUN :
		break ;
		
		case i51_MSG_INIT :
		{
	
			i51KIT_STATIC_KIT_SET(Adapter,parameter);
			i51KIT_STATIC_KIT_ASSERT(Adapter);
		
			glutInit ( 0 , 0 ) ;
			gluOrtho2D ( 0.0 , 240.0 , 0.0 , 320.0 ) ;
			gluPerspective ( 0 , 1 , -1 , -100 ) ;
			glColor3f ( 0.5 , 0.5 , 0.5 ) ;

			glBegin ( GL_LINE_STRIP ) ;
			glVertex3f ( 200.0 , 200.0 , -2.0 ) ;
			glVertex3f ( 200.0 , 200.0 , -2.0 ) ;
			glEnd () ;
			glFlush () ;

		}
		break ;
		
		case i51_MSG_PAUSE :
		break ;

		case i51_MSG_EXIT :
		break ;
		

	}

	

	return iTRUE ;

}

iKIT iU32* i51KitPort ()
{

	//	TODO : Initialize API Port for external layer
	
	//	i51KIT_DYNAMIC_KIT_MAPING_BEGIN(DlDemo)
	//	i51KIT_DYNAMIC_KIT_MAPING_END 

	//	return i51KIT_DYNAMIC_KIT_GET_MAPING(DlDemo) ;

	return 0 ;

}
