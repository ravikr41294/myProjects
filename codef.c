#include <stdio.h>
#include <GL/glut.h>
#include <string.h>         //Header Files Used
#include <stdlib.h>
#include<time.h>
	
#define monitor	1         //Display List for PC Screen 
#define	upbox	2         //Display List for Boxes
#define	boxbuses 3        //Display List for Buses
#define	fi	4         //Display List for files used in communication
#define	keys	5         //Display List for Keyboard
		


		float	x=-18,y=34;
		int	i,flag=0,w=0,q=5,r=0,s=0,u=0;
		float	tr=0.0,t=0.0,t2=0.0,t3=0.0,t4=0.0,t1=0.0,t5=0.0;
		float	tr1=0.0;
		float	tr2=0.0;
		float	tr3=0.0;
		float	tr4=0.0;	
		float	tr5=0.0;
		void	animated();
		void	anim();
		
		
void	textures()
       {
		char	*ptr="CTRL PROCESSOR\n[Client]";
		int	len=strlen(ptr);
		glColor3f(0.8,0.2,0.1);					     //Control Processor Client Side
		glRasterPos3f(-40.0,-10.0,0.0);
		for(int	i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ptr[i]);
		
		char	*ptr1="CTRL PROCESSOR\n[Server]";
		int	len1=strlen(ptr1);
		glColor3f(1.0,0.0,0.0);					    //Control Processor Server Side
		glRasterPos3f(19.5,3.0,00.0);
		for(i=0;i<len1;i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ptr1[i]);
		
		char	*ptr2="DATA PROCESSOR\n{Server}";
		int	len2=strlen(ptr2);
		glColor3f(0.8,0.0,0.1);					   //Data Processor Server Side
		glRasterPos3f(19.5,-31,00.0);
		for(i=0;i<len2;i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ptr2[i]);
		
		char	*ptr3="DATA PROCESSOR\n{Client}";
		int	len3=strlen(ptr3);
		glColor3f(1.0,0.0,0.0);					  //Data Processor Client Side
		glRasterPos3f(-40.0,-44,0.0);
		for(i=0;i<len3;i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ptr3[i]);
		

		char	*ptr4="SERVER";
		int	len4=strlen(ptr4);
		glColor3f(1.0,0.0,0.0);					//Server Label
		glRasterPos3f(28,45,0.0);
		for(i=0;i<len4;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ptr4[i]);

		char	*ptr5="CLIENT";
		int	len5=strlen(ptr5);
		glColor3f(1.0,0.0,0.0);					//Client Label
		glRasterPos3f(-36.0,44.0,0.0);
		for(i=0;i<len5;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ptr5[i]);

		char *ptr7="Simple Client Server Working Model";
		int len7=strlen(ptr7);
		glColor3f(0.1,0.2,0.3);
		glRasterPos3f(-16.0,43.5,0.0);
		for(i=0;i<len7;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ptr7[i]);

		glFlush();
		}
		
void	ctrline()
		{
		glLineWidth(4.1);
		glBegin(GL_LINES);
		glVertex3f(-22,34.0,10.0);
		glVertex3f(-20,34.0,10.0);
		glEnable(GL_LINE_SMOOTH);    //antialiasing for Line Smoothing
		glEnd();
		}
		
void	file()
	{

         glNewList(fi,GL_COMPILE_AND_EXECUTE);
		glBegin(GL_POLYGON);
		glColor3f(0.5,0.3,0.1);
		glVertex2f(-17.5,31.5);
		glVertex2f(-17.5,34.5);
		glVertex2f(-16.0,34.5);
		glVertex2f(-16.0,31.5);
		glEnd();
		
		glLineWidth(1.5);
		glEnable(GL_LINE_SMOOTH);  
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(-16.3,32);
		glVertex2f(-17.3,32);
		glEnd();
		
		glLineWidth(1.5);
		glEnable(GL_LINE_SMOOTH);  
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(-16.3,33);
		glVertex2f(-17.2,33);
		glEnd();
		
		glLineWidth(1.5);
		glEnable(GL_LINE_SMOOTH);  
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(-16.3,34);
		glVertex2f(-17.3,34);
		glEnd();
		
	glEndList();
	}
		
void	disp()
{
	glLineWidth(4.1);
	glBegin(GL_LINES);
	glColor3f(0.8,0.5,0.3);
	glVertex3f(-16.0,42.5,1.0);
	glVertex3f(14.0,42.5,1.0);
	glEnable(GL_LINE_SMOOTH);    //antialiasing for Line Smoothing
	glEnd();	

	//LEFT	SIDE CLIENT CPU........
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-27.0,15.0,0.0);
	glVertex3f(-19.0,15.0,0.0);
	glVertex3f(-19.0,40.0,0.0);
	glVertex3f(-27.0,40.0,0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-30.0,12.0,3.0);
	glVertex3f(-22.0,12.0,3.0);
	glVertex3f(-19.0,15.0,0.0);
	glVertex3f(-27.0,15.0,0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-30.0,12.0,3.0);
	glVertex3f(-26.0,15.0,0.0);
	glVertex3f(-26.0,40.0,0.0);
	glVertex3f(-30.0,37.0,3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1,0.1,0.1);
	glVertex3f(-22.0,12.0,3.0);
	glVertex3f(-22.0,37.0,3.0);
	glVertex3f(-19.0,40.0,0.0);
	glVertex3f(-19.0,15.0,0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1,0.1,0.1);
	glVertex3f(-30.0,37.0,3.0);
	glVertex3f(-22.0,37.0,3.0);
	glVertex3f(-19.0,40.0,0.0);
	glVertex3f(-27.0,40.0,0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8,0.1,0.1);
	glVertex3f(-30.0,12.0,3.0);
	glVertex3f(-22.0,12.0,3.0);
	glVertex3f(-22.0,37.0,3.0);
	glVertex3f(-30.0,37.0,0.0);
	glEnd();


	glLineWidth(1.5);
	glEnable(GL_LINE_SMOOTH); 
	glBegin(GL_LINES);
	glColor3f(0.2,0.2,0.5);
	glVertex3f(-23.0,33.0,3.0);
	glVertex3f(-23.0,32.5,3.0);
	glVertex3f(-23.0,32.5,3.0);
	glVertex3f(-23.5,32.5,3.0);
	glVertex3f(-23.5,32.5,3.0);
	glVertex3f(-23.5,33.0,3.0);
	glVertex3f(-23.5,33.0,3.0);
	glVertex3f(-23.0,33.0,3.0);
	glEnd();

	
	glLineWidth(1.5);
	glEnable(GL_LINE_SMOOTH); 
	glBegin(GL_LINES);
	glColor3f(0.2,0.2,0.5);
	glVertex3f(-29.0,35.0,3.0);
	glVertex3f(-23.0,35.0,3.0);
	glVertex3f(-23.0,35.0,3.0);
	glVertex3f(-23.0,34.0,3.0);
	glVertex3f(-23.0,34.0,3.0);
	glVertex3f(-29.0,34.0,3.0);
	glVertex3f(-29.0,34.0,3.0);
	glVertex3f(-29.0,35.0,3.0);
	glEnd();

	glLineWidth(1.5);
	glEnable(GL_LINE_SMOOTH); 
	glBegin(GL_LINES);
	glColor3f(0.2,0.2,0.5);
	glVertex3f(-26.0,19.0,3.0);
	glVertex3f(-27.0,19.0,3.0);
	glVertex3f(-27.0,19.0,3.0);
	glVertex3f(-27.0,18.0,3.0);
	glVertex3f(-27.0,18.0,3.0);
	glVertex3f(-26.0,18.0,3.0);
	glVertex3f(-26.0,18.0,3.0);
	glVertex3f(-26.0,19.0,3.0);
	glEnd();

	glLineWidth(1.5);
	glEnable(GL_LINE_SMOOTH); 
	glBegin(GL_LINES);
	glColor3f(0.2,0.2,0.5);
	glVertex3f(-22.0,12.0,3.0);
	glVertex3f(-22.0,37.0,3.0);
	glVertex3f(-22.0,37.0,3.0);
	glVertex3f(-19.0,40.0,3.0);
	glVertex3f(-19.0,40.0,3.0);
	glVertex3f(-19.0,15.0,3.0);
	glVertex3f(-19.0,15.0,3.0);
	glVertex3f(-22.0,12.0,3.0);
	glEnd();

	glLineWidth(1.5);
	glEnable(GL_LINE_SMOOTH); 
	glBegin(GL_LINES);
	glColor3f(0.2,0.2,0.5);
	glVertex3f(-30.0,37.0,3.0);
	glVertex3f(-22.0,37.0,3.0);
	glVertex3f(-22.0,37.0,3.0);
	glVertex3f(-19.0,40.0,3.0);
	glVertex3f(-19.0,40.0,3.0);
	glVertex3f(-27.0,40.0,3.0);
	glVertex3f(-27.0,40.0,3.0);
	glVertex3f(-30.0,37.0,3.0);
	glEnd();
	
	glLineWidth(1.5);
	glEnable(GL_LINE_SMOOTH); 
	glBegin(GL_LINES);
	glColor3f(0.2,0.2,0.5);
	glVertex3f(-30.0,12.0,3.0);
	glVertex3f(-22.0,12.0,3.0);
	glVertex3f(-22.0,12.0,3.0);
	glVertex3f(-22.0,37.0,3.0);
	glVertex3f(-22.0,37.0,3.0);
	glVertex3f(-30.0,37.0,3.0);
	glVertex3f(-30.0,37.0,3.0);
	glVertex3f(-30.0,12.0,3.0);
	glEnd();
	                                   //CPU DISPLAYING ENDS


	
	glNewList(monitor,GL_COMPILE_AND_EXECUTE);

		glBegin(GL_POLYGON);
		glColor3f(0.7,0.65,0.83);	     //Base of Monitor Stand
		glVertex3f(-43.50,26.0,-10.0);
		glVertex3f(-43.50,23.0,-10.0);
		glVertex3f(-40.0,23.0,-10.0);
		glVertex3f(-40.0,26.0,-10.0);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.2,0.3,.4);		    //Body of Monitor Stand
		glVertex2f(-44.5,23.0);
		glVertex2f(-39.0,23.0);
		glVertex2f(-39.0,22.0);
		glVertex2f(-44.5,22.0);
		glEnd();

		glBegin(GL_QUAD_STRIP);
		glColor3f(0.2,0.3,0.4);
		glVertex2f(-48.0,25.0);            //Outer Rim of Monitor
		glVertex2f(-36.0,25.0);
		glVertex2f(-36.0,38.5);
		glVertex2f(-48.0,38.5);
		glVertex2f(-48.0,38.5);
		glVertex2f(-48.0,25.0);
		glVertex2f(-36.0,38.5);
		glVertex2f(-36.0,25.0);
		glEnd();
	
		glBegin(GL_POLYGON);	           //Monitor
		glColor3f(0.6,0.73,0.83);
		glVertex2f(-47.0,26.0);
		glVertex2f(-37.0,26.0);
		glVertex2f(-37.0,38.0);
		glVertex2f(-47.0,38.0);
		glEnd();
		

		glBegin(GL_POLYGON);
		glColor3f(0.3,0.5,0.6);
		glVertex2f(-48.0,17.0);
		glVertex2f(-35.0,17.0);          //KeyBoard
		glVertex2f(-36.0,21.0);
		glVertex2f(-47.0,21.0);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.3,0.3,0.6);
		glVertex2f(-48.0,17.0);
		glVertex2f(-35.0,17.0);
		glVertex2f(-35.0,16.0);
		glVertex2f(-48.0,16.0);
		glEnd();
	

	//KEYS Formation Starts
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-46.0,17.0);
	glVertex2f(-42.0,17.0);
	glVertex2f(-42.0,17.5);
	glVertex2f(-46.0,17.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-41.5,17.0);
	glVertex2f(-40.5,17.0);
	glVertex2f(-40.5,17.5);
	glVertex2f(-41.5,17.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-40,17.0);
	glVertex2f(-39,17.0);
	glVertex2f(-39,17.5);
	glVertex2f(-40,17.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-47.7,17.0);
	glVertex2f(-47,17.0);
	glVertex2f(-47,17.5);
	glVertex2f(-47.7,17.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-46.8,17.0);
	glVertex2f(-46.1,17.0);
	glVertex2f(-46.1,17.5);
	glVertex2f(-46.8,17.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-47.6,17.7);
	glVertex2f(-46.3,17.7);
	glVertex2f(-46.3,17.5);
	glVertex2f(-47.6,17.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-47.6,17.7);
	glVertex2f(-46.3,17.7);
	glVertex2f(-46.3,18.5);
	glVertex2f(-47.6,18.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-45.8,17.7);
	glVertex2f(-44.8,17.7);
	glVertex2f(-44.8,18.3);
	glVertex2f(-45.8,18.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-44.3,17.7);
	glVertex2f(-43.3,17.7);
	glVertex2f(-43.3,18.3);
	glVertex2f(-44.3,18.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-42.8,17.7);
	glVertex2f(-41.8,17.7);
	glVertex2f(-41.8,18.3);
	glVertex2f(-42.8,18.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-42.3,17.7);
	glVertex2f(-41.3,17.7);
	glVertex2f(-41.3,18.3);
	glVertex2f(-42.3,18.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-40.8,17.7);
	glVertex2f(-39.8,17.7);
	glVertex2f(-39.8,18.3);
	glVertex2f(-40.8,18.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-47.2,18.6);
	glVertex2f(-46.1,18.6);
	glVertex2f(-46.1,19.3);
	glVertex2f(-47.2,19.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-45.5,18.6);
	glVertex2f(-44.5,18.6);
	glVertex2f(-44.5,19.3);
	glVertex2f(-45.5,19.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-44,18.6);
	glVertex2f(-43,18.6);
	glVertex2f(-43,19.3);
	glVertex2f(-44,19.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-42.5,18.6);
	glVertex2f(-41.5,18.6);
	glVertex2f(-41.5,19.3);
	glVertex2f(-42.5,19.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-41,18.6);
	glVertex2f(-40,18.6);
	glVertex2f(-40,19.3);
	glVertex2f(-41,19.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-39.5,18.6);
	glVertex2f(-38.5,18.6);
	glVertex2f(-38.5,19.3);
	glVertex2f(-39.5,19.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-46.8,19.6);
	glVertex2f(-45.8,19.6);
	glVertex2f(-45.8,20.3);
	glVertex2f(-46.8,20.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-45.3,19.6);
	glVertex2f(-44.3,19.6);
	glVertex2f(-44.3,20.3);
	glVertex2f(-45.3,20.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-43.8,19.6);
	glVertex2f(-42.8,19.6);
	glVertex2f(-42.8,20.3);
	glVertex2f(-43.8,20.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-42.3,19.6);
	glVertex2f(-41.3,19.6);
	glVertex2f(-41.3,20.3);
	glVertex2f(-42.3,20.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-40.8,19.6);
	glVertex2f(-39.8,19.6);
	glVertex2f(-39.8,20.3);
	glVertex2f(-40.8,20.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-39.3,19.6);
	glVertex2f(-38.6,19.6);
	glVertex2f(-38.6,20.3);
	glVertex2f(-39.3,20.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-38,17);
	glVertex2f(-37,17);
	glVertex2f(-37,17.5);
	glVertex2f(-38,17.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-36.5,17);
	glVertex2f(-35.5,17);
	glVertex2f(-35.5,17.5);	
	glVertex2f(-36.5,17.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-38,17.7);
	glVertex2f(-37,17.7);
	glVertex2f(-37,18.3);
	glVertex2f(-38,18.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-36.5,17.7);
	glVertex2f(-35.5,17.7);
	glVertex2f(-35.5,18.3);
	glVertex2f(-36.5,18.3);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-38,18.6);
	glVertex2f(-37,18.6);
	glVertex2f(-37,19.3);
	glVertex2f(-38,19.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-36.5,18.6);
	glVertex2f(-35.5,18.6);
	glVertex2f(-35.5,19.3);
	glVertex2f(-36.5,19.3);
	glEnd();
	      //KEY Formation Ends

	glBegin(GL_POLYGON);	//SCREEN
	glColor3f(0.0,0.0,0.3);
	glVertex2f(-46.5,27.0);
	glVertex2f(-37.5,27.0);
	glVertex2f(-37.5,37.0);
	glVertex2f(-46.5,37.0);
	glEnd();
	glEndList();
	

	//Server Formation Starts.................
	

	glBegin(GL_POLYGON);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(25.0,20.0,0.0);
	glVertex3f(40.0,17.0,0.0);
	glVertex3f(40.0,42.0,0.0);
	glVertex3f(25.0,45.0,0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(25.0,20.0,0.0);
	glVertex3f(40.0,17.0,0.0);
	glVertex3f(20.0,15.0,5.0);
	glVertex3f(35.0,12.0,5.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(25.0,20.0,0.0);
	glVertex3f(25.0,45.0,0.0);
	glVertex3f(20.0,40.0,5.0);
	glVertex3f(20.0,15.0,5.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(20.0,40.0,5.0);
	glVertex3f(25.0,45.0,0.0);
	glVertex3f(20.0,40.0,5.0);
	glVertex3f(20.0,15.0,5.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(20.0,40.0,5.0);
	glVertex3f(25.0,45.0,0.0);
	glVertex3f(40.0,42.0,0.0);	
	glVertex3f(35.0,37.0,5.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(35.0,12.0,5.0);
	glVertex3f(35.0,37.0,5.0);
	glVertex3f(40.0,42.0,0.0);
	glVertex3f(40.0,17.0,0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(20.0,15.0,5.0);
	glVertex3f(35.0,12.0,5.0);
	glVertex3f(35.0,37.0,5.0);
	glVertex3f(20.0,40.0,5.0);
	glEnd();

	
//Glass View at the front and on right side #STARTS
	
	
	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0.7);
	glVertex3f(20.0,40.0,5.0);
	glVertex3f(20.0,37.0,5.0);
	glVertex3f(35.0,34.0,5.0);
	glVertex3f(35.0,37.0,5.0);
	glEnable(GL_POLYGON_SMOOTH);
	glEnd();

	
	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0.7);
	glVertex3f(40.0,39.0,0.0);
	glVertex3f(40.0,42.0,0.0);
	glVertex3f(35.0,37.0,5.0);
	glVertex3f(35.0,34.0,5.0);
	glEnable(GL_POLYGON_SMOOTH);	
	glEnd();

	
	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0.7);
	glVertex3f(20.0,36.0,5.0);
	glVertex3f(20.0,33.0,5.0);
	glVertex3f(35.0,30.0,5.0);
	glVertex3f(35.0,33.0,5.0);
	glEnable(GL_POLYGON_SMOOTH);
	glEnd();

	
	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0.7);
	glVertex3f(40.0,38.0,0.0);
	glVertex3f(40.0,35.0,0.0);
	glVertex3f(35.0,30.0,5.0);
	glVertex3f(35.0,33.0,5.0);
	glEnable(GL_POLYGON_SMOOTH);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0.7);
	glVertex3f(20.0,32.0,5.0);
	glVertex3f(20.0,29.0,5.0);
	glVertex3f(35.0,26.0,5.0);
	glVertex3f(35.0,29.0,5.0);
	glEnable(GL_POLYGON_SMOOTH);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0.7);
	glVertex3f(40.0,31.0,0.0);
	glVertex3f(40.0,34.0,0.0);
	glVertex3f(35.0,29.0,5.0);
	glVertex3f(35.0,26.0,5.0);
	glEnable(GL_POLYGON_SMOOTH);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0.7);
	glVertex3f(20.0,28.0,5.0);
	glVertex3f(20.0,25.0,5.0);
	glVertex3f(35.0,22.0,5.0);
	glVertex3f(35.0,25.0,5.0);
	glEnable(GL_POLYGON_SMOOTH);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0.7);
	glVertex3f(40.0,27.0,0.0);
	glVertex3f(40.0,30.0,0.0);
	glVertex3f(35.0,25.0,5.0);
	glVertex3f(35.0,22.0,5.0);
	glEnable(GL_POLYGON_SMOOTH);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0.7);
	glVertex3f(20.0,24.0,5.0);
	glVertex3f(20.0,21.0,5.0);
	glVertex3f(35.0,18.0,5.0);
	glVertex3f(35.0,21.0,5.0);
	glEnable(GL_POLYGON_SMOOTH);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0.7);
	glVertex3f(40.0,23.0,0.0);
	glVertex3f(40.0,26.0,0.0);
	glVertex3f(35.0,21.0,5.0);
	glVertex3f(35.0,18.0,5.0);
	glEnable(GL_POLYGON_SMOOTH);
	glEnd();

	glEnable(GL_BLEND);
	glBegin(GL_POLYGON);
	glColor3f(0.1,0.1,0.1);
	glVertex3f(20.0,20.0,5.0);
	glVertex3f(20.0,15.0,5.0);
	glVertex3f(35.0,12.0,5.0);
	glVertex3f(35.0,17.0,5.0);
	glEnable(GL_POLYGON_SMOOTH);
	glEnd();

	
	glBegin(GL_POLYGON);
	glColor3f(0.1,0.1,0.1);
	glVertex3f(40.0,17.0,0.0);
	glVertex3f(40.0,22.0,0.0);
	glVertex3f(35.0,17.0,5.0);
	glVertex3f(35.0,12.0,5.0);
	glEnd();

	//Formation of Server Building Ends
	

	//Buses for Client Server STARTS!!
	glEnable(GL_BLEND);
	glColor4f(0.2,0.1,0.4,0.6);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(-19.0,35.0);
	glVertex2f(-19.0,33.0);
	glVertex2f(20.0,35.0);
	glVertex2f(20.0,33.0);
	glEnd();
	glBegin(GL_QUAD_STRIP);
	glVertex2f(-19.0,16.0);
	glVertex2f(-19.0,20.0);
	glVertex2f(20.0,16.0);
	glVertex2f(20.0,20.0);
	glEnd();
	glDisable(GL_BLEND);
	//Buses for Client Server Ends
	
	
	//Upbox Display List Called
	glNewList(upbox,GL_COMPILE_AND_EXECUTE);
		
		glBegin(GL_POLYGON);
		glColor3f(0.4,0.2,0.4);
		glVertex3f(25.0,2.0,0.0);
		glVertex3f(25.0,-3.0,0.0);                  //Boxes to Represent Data and Control Processors
		glVertex3f(35.0,-3.0,0.0);                  
		glVertex3f(35.0,2.0,0.0);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.2,0.5,0.3);
		glVertex3f(23.0,-5.0,5.0);
		glVertex3f(33.0,-5.0,5.0);
		glVertex3f(25.0,-3.0,0.0);
		glVertex3f(25.0,-3.0,5.0);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.4,0.4,0.2);
		glVertex3f(25.0,2.0,0.0);
		glVertex3f(25.0,-3.0,0.0);
		glVertex3f(23.0,-5.0,5.0);
		glVertex3f(23.0,0.0,5.0);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.6,0.4,0.6);	
		glVertex3f(23.0,0.0,5.0);
		glVertex3f(33.0,0.0,5.0);
		glVertex3f(35.0,2.0,0.0);
		glVertex3f(25.0,2.0,0.0);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.4,0.5,0.9);
		glVertex3f(33.0,0.0,5.0);
		glVertex3f(33.0,-5.0,5.0);
		glVertex3f(35.0,-3.0,0.0);
		glVertex3f(35.0,2.0,5.0);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.4,0.2,0.7);
		glVertex3f(23.0,-5.0,5.0);
		glVertex3f(33.0,-5.0,5.0);
		glVertex3f(33.0,0.0,5.0);
		glVertex3f(23.0,0.0,5.0);
		glEnd();
	glEndList();

	glPushMatrix();
	glScalef(0.0,0.5,0.0);
	glCallList(2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-55.0,0.0,0.0);
	glCallList(2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-55.0,-35.0,0.0);
	glCallList(2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0,-35.0,0.0);
	glCallList(2);
	glPopMatrix();
	
	
	glNewList(boxbuses,GL_COMPILE_AND_EXECUTE);
		glEnable(GL_BLEND);
		glColor4f(0.4,0.1,0.2,0.5);
		glBegin(GL_QUAD_STRIP);
		glVertex2f(-22.0,-1.0);
		glVertex2f(-22.0,-5.0);
		glVertex2f(23.0,-1.0);		        //Buses to show Communication between Processors
		glVertex2f(23.0,-5.0);
		glEnd();
		glDisable(GL_BLEND);
	glEndList();
		glPushMatrix();
		glTranslatef(0.0,-35.0,0.0);
		glCallList(3);
		glPopMatrix();
}
	

void	display()

	{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	
	glPushMatrix();
	glColor3f(1.0,1.0,0.0);
	glTranslatef(0.0+tr,0.0,10.0);
	ctrline();
        glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	glTranslatef(47.0-tr1,0.0,10.0);
	ctrline();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0,0.0,1.0);
	glTranslatef(-3.0+tr2,-15.0,10.0);
	file();
	glPopMatrix();
	glPushMatrix();
	
	glTranslatef(-5.0+tr2,-15.0,0.0);
	glCallList(fi);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-7.0+tr2,-15.0,0.0);
	glCallList(fi);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-9.0+tr2,-15.0,0.0);
	glCallList(fi);
	glPopMatrix();
	glLineWidth(.1);
	
	
	//R.E.T.R.I.E.V.E   A   D.A.T.A
	
	if(flag==1)
	{
	glPushMatrix();
	glTranslatef(-5.0+t,-36.5,0.0);
	glColor3f(1.0,1.0,1.0);
	ctrline();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(41.0-t1,-71,0.0);
	glCallList(fi);
	glPopMatrix();
	
	glPushMatrix();
	
	//if(flag==1	&&	r<5)r++;
	//glTranslatef(r,r,0);

	char	*ptr7="RETRIEVE SIGNAL";
	int	len7=strlen(ptr7);
	glColor3f(1.0,1.0,1.0);
	glRasterPos3f(-18,0,0.0);
	for(int	i=0;i<len7;i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ptr7[i]);
	glPopMatrix();
	
	}
	

	//S.T.O.R.E.S  D..A..T..A
	if(flag==2)
{
	glPushMatrix();
	glTranslatef(-6.0+t2,-36.5,0.0);
	glColor3f(1.0,0.4,0.6);
	ctrline();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-5+t3,-71,0.0);
	glCallList(fi);
	glPopMatrix();
	glPushMatrix();
	if(flag==2	&&	s<5)	s++;
	glTranslatef(s,s,0);
	char	*ptr7="STORE SIGNAL";
	int	len7=strlen(ptr7);
	glColor3f(1.0,0.4,0.2);
	glRasterPos3f(-18,0,0.0);
	for(i=0;i<len7;i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ptr7[i]);
	glPopMatrix();

	}
	
	disp();
	textures();

	if(tr1>=48)
	{
	char	*ptr6="DATA";
	int	len6=strlen(ptr6);
	glColor3f(1.0,0.5,0.0);
	glRasterPos3f(-46,32,0.0);
	for(int	i=0;i<len6;i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,ptr6[i]);
	}
	
	if(tr2>=48)
	{
	char	*ptr7="DATA	SENT";
	int	len7=strlen(ptr7);
	glColor3f(0.6,0.2,1.0);
	glRasterPos3f(-46,32,0.0);
	for(int	i=0;i<len7;i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,ptr7[i]);
	}
	glPushMatrix();

	if(w<5)	w++;
	glTranslatef(w,w,0);
	char	*ptr5="REQUEST";
	int	len5=strlen(ptr5);
	glColor3f(0.8,0.4,0.3);
	glRasterPos3f(-18,34,0.0);
	for(int	i=0;i<len5;i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ptr5[i]);
	glPopMatrix();
	glPushMatrix();
	

if(tr>=43	&&	w>=5	&&	q>2)q--;
	glTranslatef(q,q,0);
	char	*ptr6="RESPONSE";
	int	len6=strlen(ptr6);
	glColor3f(0.3,0.2,0.8);
	glRasterPos3f(7,27,0.0);
	for(i=0;i<len6;i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ptr6[i]);
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
	}
	
void	init()
{
	glClearColor(1.5,1.0,1.0,0.0);
	glOrtho(-50,50,-50,50,-50,50);
}
	

void	animate()
	{
	if(tr<48)
	tr+=0.2;
	else	if(tr>=48	&&	tr1<48)
	tr1+=0.2;
	else	if(tr1>=48	&&	tr2<48)
	tr2+=0.1;
	else	if(tr2>=48	&&	tr3<48)
	tr3+=0.1;
	glutPostRedisplay();
	}
	


void	anim()
	{
	if(t<53)
	t+=0.2;
	else	if(t>=53	&&	t1<53)
	t1+=0.2;
	
	//S	T	O	R	E
	else	if(t2<53)
	t2+=0.2;
	else	if(t2>=53	&&	t3<53)
	t3+=0.2;
	
	glutPostRedisplay();
	}
	
	


void	mymenu(int	id)
	{
	switch(id)
	{
	case	1:	tr = 0;tr1=0;tr2=0; tr3=0; 	glutIdleFunc(animate);
	break;
	case	2:flag=1; t=0,t1=0
	glutIdleFunc(anim);
	break;
	case	3: flag=2; t2=0;t3=0;     glutIdleFunc(anim);   
	break;
	case	4:exit(0);
	}
	}
	



int	main(int	argc,char	**argv)
	{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Simple Client Server Working");
	glutDisplayFunc(display);
	glutCreateMenu(mymenu);
	glutAddMenuEntry("START",1);
	glutAddMenuEntry("RETRIVE DATA",2);
	glutAddMenuEntry("STORE DATA",3);
	glutAddMenuEntry("EXIT",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	glBlendFunc(GL_SRC_ALPHA,GL_DST_ALPHA);
	init();
	glutMainLoop();
	return	0;
	}
	
