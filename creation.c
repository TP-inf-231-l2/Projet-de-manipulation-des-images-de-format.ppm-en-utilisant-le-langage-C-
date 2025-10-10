#include<stdio.h>
#include<stdlib.h>

int main(){
    int width,heigth,t[3];
    t[0]=255;
    t[1]=0;
    t[2]=0;
    
    FILE *f=fopen("img.ppm","w");
    printf("entrer la largeur et la hauteur de votre image:\n");
    scanf("%d %d",&width,&heigth);
    fprintf(f,"P3 \n%d %d\n255\n",width,heigth);
    for(int i=0;i<heigth;i++){
    	if(i==210){
			t[0]=0;
	   		 t[1]=255;
	        t[2]=0;}
    	if(i==400){
	     	 t[0]=0;
		    t[1]=0;
		    t[2]=255;}
        for(int j=0;j<width;j++){
            if(i<2 && j<2){
                fprintf(f,"%d %d %d   ",t[0],t[1],t[2]       );
            }else if(i<2 && j>=2){
                fprintf(f,"%d %d %d   ",t[0],t[1],t[2]       );
            }else if(i>=2 && j<2){
                fprintf(f,"%d %d %d   ",t[0],t[1],t[2]       );
            }else{
            	 fprintf(f,"%d %d %d   ",t[0],t[1],t[2]       );
			}   
        }
        fprintf(f,"\n");
       
    }
    fclose(f);
    printf("image créé!!!");
}
