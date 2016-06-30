#include <fstream>
#include <string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
	string ste;
       ifstream ci("aa.txt");
	   ofstream co("bb.txt",ios::out);
	   string stra;
	   for(int i = 0;;i++)
	   {
	          if(getline(ci,stra))
			  {
			  	
			        int ire = stra.find("AAA");
					if (ire !=  -1)
					 {
						    string stre = "AAA";
							stra.erase(0,stre.length());
							co<<stra;
							co<<endl;
						
					}
					
		     }
		     
			 else
			{
				break;
				
			}
       }
       	printf("%s\n",stra);
             return 0;
}
