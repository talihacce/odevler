#include <stdio.h>
#include <stdlib.h>
 
int main() {
   float a[20], f[20],ad[20], c,t=0;
   int es, i, j, k,z,y;
   char isim[100][100];
   float oran[20], yedek;
   printf("\nGireceginiz esya sayisi: ");
   scanf("%d", &es);
   for (i = 0; i < es; i++) {
   	printf("\nEsya ismini giriniz:");
   	scanf("%s",&isim[i]);
   	printf("\n %d . Esyanin agirligini ve fiyatini bosluk birakarak giriniz : ",i+1);
      scanf("%f %f" ,&a[i], &f[i]);
   }
   printf("\nCantanizin kapasitesini giriniz: ");
   scanf("%f", &c);
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
	
   for (k = 0; k < es; k++)
      ad[k] = 0.0;
   for (k = 0; k < es; k++) {
      if (a[k] > c)
         break;
      else {
         ad[k] = 1.0;
         t = t + f[k];
         c = c - a[k];
      }
   }  
   if (k < es)
      ad[k] = c / a[k];
   t = t + (ad[k] * f[k]);
   for(z=0;z<k;z++){
   		printf("\n Alabileceginiz %d . esyanin isimi=%s",z+1,isim[z]);
	   }
   printf("\nMaksimum fiyat: %.2f", t);
   return(0);
}
