#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;
int main(){
         FILE *fp;
	 FILE *fp1;
        char s[1000];
        fp = fopen("code.txt", "r");
	fp = fopen("code1.c", "w");
        int tab = 0;
        //fgets(s, 1000, fp);
        while(!feof(fp)){
		fgets(s, 1000, fp);
                if(s[0] == '{'){
			
                       cout<<setw(tab+1)<<setfill('\t')<<'{'<<endl;
		       //fputs(s, fp1);
		       string ss = str(setw(tab+1)) + str(setfill('\t')) + "{" + "\n";
		       fputs(ss, fp1);
                       tab++;
                       if(tab == 0)
                               tab++;
                }
                else if(s[0] == '}'){
                       tab--;
                       cout<<setw(tab+1)<<setfill('\t')<<'}'<<s+1<<endl;

                }else{
                       cout<<setw(tab+1)<<setfill('\t')<<s[0]<<s+1<<endl;
                }
        }
        fclose(fp);
        return 0;
}
