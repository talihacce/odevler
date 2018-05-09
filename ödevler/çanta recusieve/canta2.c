#include <stdio.h>
#include <stdlib.h>
 void canta(int esya,float a[],float f[],float kapasite){
 	float ad[20],t=0;
 	int i,j,c;
 	c=kapasite;
   for (i = 0; i < esya; i++)
      ad[i] = 0.0;
   for (i = 0; i < esya; i++) {
      if (a[i] > c)
         break;
      else {
         ad[i] = 1.0;
         t = t + f[i];
         c = c - a[i];
      }
   }  
   if (i < esya)
      ad[i] = c / a[i];
   t = t + (ad[i] * f[i]);
   printf("\nMaksimum fiyat: %.2f", t);
 }
int main() {
   float a[20], f[20],kapasite;
   int es, i, j,z;
   char isim[100][100];
   float oran[20], yedek;
   printf("\nGireceginiz esya sayisi: ");
   scanf("%d", &es);
   for (i = 0; i < es; i++) {
   	printf("\nEsya ismini giriniz:");
   	scanf("%s",&isim[i]);
   	printf("\n %d . Esyanin agirligini ve fiyatini bosluk birakarak giriniz : ",i+1);
      scanf("%f %f", &a[i], &f[i]);
   }
   printf("\nCantanizin kapasitesini giriniz: ");
   scanf("%f", &kapasite);
   for (i = 0; i < es; i++) {
      oran[i] = f[i] / a[i];
   }
   for (i = 0; i < es; i++) {
      for (j = i + 1; j < es; j++) {
         if (oran[i] < oran[j]) {
            yedek = oran[j];
            oran[j] = oran[i];
            oran[i] = yedek;
            
            yedek = isim[j][i];
            isim[i][j] = isim[j][i];
            isim[i][j] = yedek;
 
            yedek = a[j];
            a[j] = a[i];
            a[i] = yedek;
 
            yedek = f[j];
            f[j] = f[i];
            f[i] = yedek;
         }
      }
	}	
	for(z=0;z<i;z++){
   		printf("\n Alabileceginiz %d . esyanin isimi=%s",z+1,isim[z]);
	   }
	canta(es,a,f,kapasite);		
    return(0);
}
