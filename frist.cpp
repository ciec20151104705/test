#include<stdio.h>
typedef
struct{
	char lat[100];
	char lon[100];
	char time[100];
}trkpt;
trkpt anytrkpt,*pstu;
int main()
{
	FILE*fp;
	int i=1;
	pstu=&anytrkpt;
	if((fp=fopen("export.gpx","r"))==NULL)
	{
		printf("Can not file\n");
		return -1;
	}
	rewind(fp);
	fseek(fp,i*sizeof(trkpt),0);
	fread(pstu,sizeof(trkpt),1,fp);
	printf("时间\t 经度   纬度:\n ");
	printf("%s\t%3d   %s %5d\n",pstu->time,pstu->lon,pstu->lat);
	return 0;
}	
	
