#include <bits/stdc++.h>
using namespace std;
class GIRL {
	public:
		char name[10];
		int attract;
		int budget;
		int int_level;
		char type[10];
		int happ;
		char status[10];
};

class BOY {
	public:
		char name[10];
		int attract;
		int budget;
		int int_level;
		char type[10];
		int happ;
		char status[10]; 
};
void display (int arr[], int arr1[]);
int main()
{	char t;
	int w = 0, i;
	int arr[100] = {0,0};
	int arr1[10] = {0,0};
	BOY boy;
	GIRL girl;
	FILE *fp, *fp1;
	fp = fopen("CSV.txt", "r");
	fp1 = fopen("CSV1.txt", "r");
	int  n = 0, m = 0, j;
	while (m < 10) {
		fscanf(fp1,"%s %d %d %d %s %s",girl.name,&girl.attract,&girl.budget,&girl.int_level,girl.type,girl.status);
		while (n < 100) {	
			fscanf(fp,"%s %d %d %d %s %s",boy.name,&boy.attract,&boy.budget,&boy.int_level,boy.type,boy.status);
			if (arr1[m] == 0 && arr[n] == 0) {
				if (girl.budget > boy.budget) {
					n = n+1;
				}
				else if (girl.attract < boy.attract) {
					n = n+1;
				}
				else {
					cout<<boy.name<<" and "<<girl.name<<endl;
					arr1[m] = 1;
					arr[n] = 1;
					n = n+1;
					break;				
				}
			}
			else if (arr[n] == 1) {
				n = n+1;
			}
		}
		m = m+1;
	}	
}
