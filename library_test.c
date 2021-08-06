 #include<stdio.h>
 #include<string.h>
 #include<windows.h>
 #include<stdlib.h>
 
 struct stud
 {
 	int id;
 	char name[20];
 	char lended_book_id[20];
 	char lended_book_name[50];
 	int rday,rmonth,ryear,lday,lmonth,lyear;
 };
 
 struct books
 {
 	char id[10];
 	char name[50];
	char writter[50];
	int qnty;
 };
 
 char fname[]={"student.txt"};
 
 
 int profile()
 {
 	FILE *fp;
 	struct stud t;
 	fp=fopen(fname,"rb"); //rb= read binary
 	while(1)
 	{
 		fread(&t,sizeof(t),1,fp);
 		if(feof(fp))// eof= end of file
 		{
 			break;
		}
		printf("%d\n",t.id);
		printf("%s\n",t.name);
		//printf("%d\n",p);
	}
 }
  
 int reg()
 {
 	FILE *fp;
 	int p,j;
	struct stud s1;
	int i=2021;
	fp=fopen(fname,"ab");
 	printf("\nEnter your ID ");
 	scanf("%d",&s1.id);
 	printf("Enter your NAME ");
 	scanf("%s",&s1.name);
 	printf("Enter your password ");
 	scanf("%d",&p);
 	fwrite(&s1,sizeof(s1),1,fp);
 	
 	fclose(fp);

 	if(i==p)
 	{
 		printf("\nChoose Options\n\nProfile='1'\nLend Books='2'\n");
		scanf("%d",&j);
		switch(j)
		{
			case 1:
			{
				profile();
			}
			case 2:
			{
			 	book(s1.id,s1.name,501,0);
			}
			default:
			{
				break;
			}
		}
 	}
 	else
 	{
 		printf("\nPlease enter correct password\n");
		reg();	 	
	}
	return 0;
 }
 
 
 
 void main()
 {
 	
 	struct stud s1;
	printf("************************************************************************************************************************\n");
 	printf("\t\t\t\t\t    LIBRARY MANAGEMENT SYSTEM\n\n");
	printf("************************************************************************************************************************\n");
	reg();
 	
 } 
