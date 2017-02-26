#include <bits/stdc++.h>

using namespace std;

class GIRL {
	public:
	char* name;
	int attract;
	int budget;
	int int_level;
	string type;
	int happ;
	string status;
};

class BOY {
	public:
        char* name;
        int attract;
        int budget;
        int int_level;
        string type;
	int happ;
	string status;
};

class GIFT {
	public:
	int price;
	int value;
	string type;

};
char* randomm1 (int arr1[]);
char* randomm (int arr[]);
int main()
{
	ofstream myfile;
	myfile.open("CSV.txt");	
	ofstream myfile1;
	myfile1.open("CSV1.txt");
	ofstream myfile2;
	myfile2.open("CSV2.txt");
	int n = 100, i, temp, m = 10, arr[100] = {0,0}, arr1[10] = {0,0}, o = 50;
	//scanf("%d%d%d",&n,&m,&o);
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++) {
		temp = rand ()%3;
		BOY boy;
		boy.name = randomm (arr);	
		boy.attract = rand ()%102;
		boy.budget = rand ()%1003;
		boy.int_level = rand ()%10;
		boy.status = "single";	
		if (temp == 0) {
			boy.type = "miser";
		}
		else if (temp == 1) {
			boy.type = "Generous";
		}
		else {
			boy.type = "Geek";
		}			
	cout<<boy.name<<","<<boy.attract<<","<<boy.budget<<","<<boy.int_level<<","<<boy.type<<endl;
	//fprintf(fptr1,"%s,%d,%d,%d,%s",boy.name,boy.attract,boy.budget,boy.int_level,boy.type);
	myfile<<boy.name<<" "<<boy.attract<<" "<<boy.budget<<" "<<boy.int_level<<" "<<boy.type<<" "<<boy.status<<endl;
	
	}

	for (i = 0; i < m; i++) {
	temp = rand ()%3;
	GIRL girl;
	girl.name = randomm1 (arr1);	
	girl.attract = rand ()%101;
	girl.budget = rand ()%1001;
	girl.int_level = rand ()%10;	
	girl.status = "single";
	if (temp == 0) {
		girl.type = "choosy";
	}
	else if (temp == 1) {
		girl.type = "normal";
	}
	else {
		girl.type = "desperate";
	}			
	cout<<girl.name<<","<<girl.attract<<","<<girl.budget<<","<<girl.int_level<<","<<girl.type<<endl;
	myfile1<<girl.name<<" "<<girl.attract<<" "<<girl.budget<<" "<<girl.int_level<<" "<<girl.type<<" "<<girl.status<<endl;
	
	}



	for (i = 0; i < o; i++) {
		temp = rand ()%3;
		GIFT gift;
		gift.price = rand()%500;
		gift.value = rand()%100;
		if (temp == 0) {
			gift.type = "Essential";
		}
		else if (temp == 1) {
			gift.type = "Luxury ";
		}
		else {
			gift.type = "Utility";
		}			
	cout<<gift.price<<","<<gift.value<<","<<gift.type<<endl;
	//fprintf(fptr1,"%s,%d,%d,%d,%s",boy.name,boy.attract,boy.budget,boy.int_level,boy.type);
	myfile2<<gift.price<<" "<<gift.value<<" "<<gift.type<<endl;
	
	}
}
char* randomm (int arr[])
{
	int i, p;
	srand((unsigned int)time(NULL));
	FILE* fptr;
      //char words[10][10];
	char **words;
     words = (char **)malloc(100*sizeof(char*));
	for(i=0;i<100;i++)
    {
      words[i]=(char *)malloc((10)*sizeof(char));

    }
	fptr = fopen ("test.txt","r");
	for(i = 0;fscanf(fptr,"%s",words[i]) && !feof(fptr);i++){}
	p = rand()%100;
	while (arr[p] == 1) {
		p = rand()%100;
	}
	arr[p] = 1;
//	 cout << words[p] << endl;
	return words[p];
} 

char* randomm1 (int arr1[])
{
	int i, p;
	srand((unsigned int)time(NULL));
	FILE* fptr;
      //char words[10][10];
	char **words;
     words = (char **)malloc(10*sizeof(char*));
	for(i=0;i<10;i++)
    {
      words[i]=(char *)malloc((10)*sizeof(char));

    }
	fptr = fopen ("test1.txt","r");
	for(i = 0;fscanf(fptr,"%s",words[i]) && !feof(fptr);i++){}
	p = rand()%10;
	while (arr1[p] == 1) {
		p = rand()%10;
	}
	arr1[p] = 1;
//	 cout << words[p] << endl;
	return words[p];
} 
