#include <bits/stdc++.h>
using namespace std;
class GIRL {
	public:
		char name[10];
		int attract;
		int budget;
		int int_level;
		char type[10];
		double happ;
		char status[10];
};

class BOY {
	public:
		char name[10];
		int attract;
		int budget;
		int int_level;
		char type[10];
		double happ;
		char status[10]; 
};

class GIFT {
	public:
	int price;
	int value;
	char type[10];

};
void display (int arr[], int arr1[]);
int main()
{	char t;
	int w = 0, i;
	int arr[100] = {0,0};
	int arr1[10] = {0,0};
	int temp, flag;
	BOY boy;
	GIRL girl;
	GIFT gift;
	double happ;
	int compat;
	FILE *fp, *fp1, *fp2, *fp3;
	fp = fopen("CSV.txt", "r");
	fp1 = fopen("CSV1.txt", "r");
	fp2 = fopen("CSV2.txt", "r");
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
					//cout<<boy.name<<" and "<<girl.name<<endl;
					w = w+1;
					arr1[m] = w;
					arr[n] = w;
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
	fclose (fp);
	fclose (fp1);
	fclose (fp2);
	fp = fopen("CSV.txt", "r");
	fp1 = fopen("CSV1.txt", "r");
	fp2 = fopen("CSV2.txt", "r");

	ofstream myfile3;
	myfile3.open("CSV3.txt");	
	for (t = 1; t <= w; t++) {
		for (i = 0; i < 10; i++) {
			if (arr1[i] == t) {
				temp = i;
				break;
			}

		}	
		for (i = 0; i < 100; i++) {
			if (arr[i] == t) {
				flag = i;
				break;
			}
		}
	fclose (fp);
	fclose (fp1);
	fclose (fp2);
	fp = fopen("CSV.txt", "r");
	fp1 = fopen("CSV1.txt", "r");
	fp2 = fopen("CSV2.txt", "r");
		

		while (temp >= 0) {
			fscanf(fp1,"%s %d %d %d %s %s",girl.name,&girl.attract,&girl.budget,&girl.int_level,girl.type,girl.status);
			temp = temp-1;
		}
		while (flag >= 0) {
			fscanf(fp,"%s %d %d %d %s %s",boy.name,&boy.attract,&boy.budget,&boy.int_level,boy.type,boy.status);
			flag = flag-1;
		}
		int budget = boy.budget;
		int total = 0;
		int total1 = 0;
		while (!feof(fp2) && total <= girl.budget ) {
			fscanf(fp2,"%d %d %s",&gift.price,&gift.value,gift.type);
			if (gift.price < budget) {
				total = total+gift.price;
				total1 = total1+gift.value;
				budget = budget-gift.price;
			}			
		}
		
		if (strcmp ("choosy",girl.type) == 0) {
			girl.happ  = log(total+(2*total1));
			if (strcmp ("miser",boy.type) == 0) {
				boy.happ = budget;
			}
			else if (strcmp ("Generous", boy.type) == 0) {
				boy.happ = girl.happ;
			}
			else if (strcmp ("Geeks", boy.type) == 0) {
				boy.happ = girl.int_level;
			}
			happ = boy.happ+girl.happ;
			compat = abs (girl.int_level - boy.int_level) + abs (girl.attract - boy.attract)+abs(boy.budget-girl.budget);
			myfile3<<compat<<" "<<happ<<" "<<boy.name<<" "<<girl.name<<endl;	
			
		}
		else if (strcmp ("normal",girl.type) == 0) {
			girl.happ = total+total1;
			if (strcmp ("miser",boy.type) == 0) {
				boy.happ = budget;
			}
			else if (strcmp ("Generous", boy.type) == 0) {
				boy.happ = girl.happ;
			}
			else if (strcmp ("Geeks", boy.type) == 0) {
				boy.happ = girl.int_level;
			}
			happ = boy.happ+girl.happ;
			compat = abs (girl.int_level - boy.int_level) + abs (girl.attract - boy.attract)+abs(boy.budget-girl.budget);
			myfile3<<compat<<" "<<happ<<" "<<boy.name<<" "<<girl.name<<endl;
		}
		else if (strcmp ("desperate",girl.type) == 0) {
			girl.happ = exp (total);
			if (strcmp ("miser",boy.type) == 0) {
				boy.happ = budget;
			}
			else if (strcmp ("Generous", boy.type) == 0) {
				boy.happ = girl.happ;
			}
			else if (strcmp ("Geeks", boy.type) == 0) {
				boy.happ = girl.int_level;
			}
			happ = boy.happ+girl.happ;
			compat = abs (girl.int_level - boy.int_level) + abs (girl.attract - boy.attract) + abs(boy.budget-girl.budget);
			myfile3<<compat<<" "<<happ<<" "<<boy.name<<" "<<girl.name<<endl;
			
		}
	}
	
	int check[10] = {0,0};
	char str[10];
	char str1[10];
	cout<<"TOP FIVE HAPPIEST COUPLES ARE :"<<endl;
	for (int var = 0; var < 5; var++) {
		fp3 = fopen ("CSV3.txt","r");
		double maxx = 0.0;
		int h = 0;
	
		for (i = 0; i < 10; i++) {
			fscanf (fp3,"%d %lf %s %s",&compat,&happ,str,str1);
			if (maxx < happ && check[i] == 0) {
				maxx = happ;
				h = i;
				
			}
			
		}
		check[h] = 1;
		fclose (fp3);
		fp3 = fopen ("CSV3.txt","r");
			while (h >= 0) {
				fscanf (fp3,"%d %lf %s %s",&compat,&happ,str,str1);
				h = h-1;
			}	
		cout<<happ<<" "<<str<<" "<<str1<<endl;	
		fclose (fp3);
	}


	int check1[10] = {0,0};
	cout<<"TOP FIVE COMPATIBLE COUPLES ARE :"<<endl;
	for (int var = 0; var < 5; var++) {
		fp3 = fopen ("CSV3.txt","r");
		double maxx = 0.0;
		int h = 0;
	
		for (i = 0; i < 10; i++) {
			fscanf (fp3,"%d %lf %s %s",&compat,&happ,str,str1);
			if (maxx < compat && check1[i] == 0) {
				maxx = compat;
				h = i;
				
			}
			
		}
		check1[h] = 1;
		fclose (fp3);
		fp3 = fopen ("CSV3.txt","r");
			while (h >= 0) {
				fscanf (fp3,"%d %lf %s %s",&compat,&happ,str,str1);
				h = h-1;
			}	
		cout<<compat<<" "<<str<<" "<<str1<<endl;	
		fclose (fp3);
	}		
}
