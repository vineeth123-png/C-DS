#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	FILE* fp;
	char name[50];
	int age;
	fp = fopen("example.txt", "w");
	fprintf(fp, "\n%s %d\n", "Tim", 31);
	fclose(fp);

	fp = fopen("example.txt", "r");
	while(!feof(fp)){
		fscanf(fp, "%s %d", name, &age);

		printf("Hello %s, you are %d years old\n", name, age);
	}
	fclose(fp);
	return 0;
}

