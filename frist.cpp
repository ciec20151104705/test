#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
int main()
{
	int len;
	char lat[50];
	char lon[10];
	char date[11];
	char time[9];
	char *str=NULL;
	FILE *fp;
	FILE *fp1;
	int i=0;
	fp=fopen("export.txt","r");
	fp1=fopen("export1.csv","w");
	if(fp==	NULL)
		{
		printf("Can not file\n");
		return -1;
		}
	else
	{
	
		int i=0; 
		fseek(fp,0,2);
		len=ftell(fp);
		fseek(fp,1,0);	
		str=(char *)malloc(len);                                                                                                                                                                     
		fread(str,1,len,fp);
	}
	fprintf(fp1,"\t纬度     \t经度     \t日期     \t时间\n");

	while( !((*(str+i)=='<')&&(*(str+i+1)=='/')&&(*(str+i+2)=='g')&&(*(str+i+3)=='p')&&(*(str+i+4)=='x')&&(*(str+i+5)=='>')))
	{	
		if((*(str+i)==' ')&&(*(str+i+1)=='l')&&(*(str+i+2)=='a')&&(*(str+i+3)=='t'))
		{
			strncpy(lat,str+i+6,9);
			lat[9]='\0';
			printf("lat: %s",lat);
			strncpy(lon,str+i+22,10);
			lon[10]='\0';
			printf("lon: %s",lon);
			strncpy(date,str+i+44,10);
			date[10]='\0';
			printf("date: %s",date);
			strncpy(time,str+i+55,8);
			time[8]='\0';
			printf("time: %s\n",time);
			fprintf(fp1,"%s,%s,%s,%s\n",lat,lon,date,time);
			
		}
		i++;
	}
fclose(fp);
fclose(fp1);
free(str);
return 0;
}
