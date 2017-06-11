#ifndef _FATSPI_TEST_H_
#define _FATSPI_TEST_H_

typedef struct
{
	u8  pic_head[2];				//1
	u16 pic_size_l;			        //2
	u16 pic_size_h;			        //3
	u16 pic_nc1;				    //4
	u16 pic_nc2;				    //5
	u16 pic_data_address_l;	        //6
	u16 pic_data_address_h;		    //7	
	u16 pic_message_head_len_l;	    //8
	u16 pic_message_head_len_h;	    //9
	u16 pic_w_l;					//10
	u16 pic_w_h;				    //11
	u16 pic_h_l;				    //12
	u16 pic_h_h;				    //13	
	u16 pic_bit;				    //14
	u16 pic_dip;				    //15
	u16 pic_zip_l;			        //16
	u16 pic_zip_h;			        //17
	u16 pic_data_size_l;		    //18
	u16 pic_data_size_h;		    //19
	u16 pic_dipx_l;			        //20
	u16 pic_dipx_h;			        //21	
	u16 pic_dipy_l;			        //22
	u16 pic_dipy_h;			        //23
	u16 pic_color_index_l;	        //24
	u16 pic_color_index_h;	        //25
	u16 pic_other_l;			    //26
	u16 pic_other_h;			    //27
	u16 pic_color_p01;		        //28
	u16 pic_color_p02;		        //29
	u16 pic_color_p03;		        //30
	u16 pic_color_p04;		        //31
	u16 pic_color_p05;		        //32
	u16 pic_color_p06;		        //33
	u16 pic_color_p07;		        //34
	u16 pic_color_p08;			    //35			
}BMP_HEAD;

typedef struct
{
	u16 x;
	u16 y;
	u8  r;
	u8  g;
	u8  b;		
}BMP_POINT;

#define RED  	0xf800
#define GREEN	0x07e0
#define BLUE 	0x001f
#define WHITE	0xffff
#define BLACK	0x0000
#define YELLOW  0xFFE0

void test(void);

#endif
