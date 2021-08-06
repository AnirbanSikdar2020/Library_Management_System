 //LIBRARY MANAGEMENT SYSTEM IN C using structure,function and file
 //----------------------------------------------------------------
 //password for app:anirban
 //password for library assistant:2021


 //Structures
 //----------
 // line no. 045 - struct stud
 // line no. 055 - struct fine_book
 // line no. 062 - struct books

 
 //Functions
 //---------
 // line no. 079 - fine_operations()
 // line no. 330 - book_fine()
 // line no. 418 - returning()
 // line no. 570 - lend_stud()
 // line no. 641 - lending()
 // line no. 774 - profile() 
 // line no. 803 - login()
 // line no. 844 - reg()
 // line no. 939 - book_reg()
 // line no. 972 - remove_book()
 // line no. 1046 - update() 
 // line no. 1129 - book_store()
 // line no. 1191 - book_operations()
 // line no. 1241 - student_operations()
 // line no. 1275 - student()
 // line no. 1305 - user()
 // line no. 1342 - main()
 
 
 #include<stdio.h>
 #include<string.h>
 #include<windows.h>
 #include<stdlib.h>
 
 char student_db[]={"student.txt"};
 char stud_temp[]={"stud_temp.dat"};
 
 char book[]={"book.dat"};
 char book_temp[]={"book_temp.dat"};
 
 char fine_db[]={"fine.txt"};
 char fine_temp[]={"fine_temp.dat"};
 
 int user_type=0;
 
 struct stud
 {
 	char id[20];
 	char name[20];
 	char pass[20];
	char lended_book_id[20];
 	char lended_book_name[50];
 	int rday,rmonth,ryear,lday,lmonth,lyear,fine_due;
 };
 
 struct fine_book
 {
 	char stud_id[20];
 	char book_id[20];
 	int fine_amt;
 };
 
 struct books
 {
 	char id[10];
 	char name[50];
	char writter[50];
	int qnty;
 };
 
 
 
 //+++++++++++++FINE OPERATIONS SECTION+++++++++++++++++++++++++
 int fine_operations(char s_id[20],char b_id[20],int user_type,int fine_amount)
 {
 	int found=0,fine=0;
 	FILE *fb,*fb1;
 	struct fine_book f1;
 	int j=1,amt=0;
 	char opt[2],chk[2],id[20];
 	
 	fb=fopen(fine_db,"rb");
 	fb1=fopen(fine_temp,"wb");
 	
 	if(user_type==1)
	{
		while(1)
 		{
 			fread(&f1,sizeof(f1),1,fb);
 		
 			if(feof(fb))// eof= end of file
 			{
 				break;
			}
			if(strcmp(f1.stud_id,s_id)==0)
			{
				found=1;
				
				strcpy(f1.book_id,b_id);
				f1.fine_amt=fine_amount;
				fwrite(&f1,sizeof(f1),1,fb1);
			}	
			else
			{
				fwrite(&f1,sizeof(f1),1,fb1);
			}
		}

		fclose(fb);
		fclose(fb1);
	 	
		if(found==1)
		{
			fb=fopen(fine_db,"wb");
			fb1=fopen("fine_temp.dat","rb");
		
			while(1)
			{
				fread(&f1,sizeof(f1),1,fb1);
			
				if(feof(fb1))
				{
					break;
				}
				fwrite(&f1,sizeof(f1),1,fb);
			}
		}	
		fclose(fb);
		fclose(fb1);
	}
	
	if(user_type==2)
	{
		printf("\n\n\n************************************************************************************************************************\n");
	 	printf("\t\t\t\t\t\t    FINE  CHART\n\n");
		printf("************************************************************************************************************************\n\n");
		printf("\t\t  ===========================================================\n");
		printf("\t\t  |   Stud id    |        Book id        |        Fine      |\n");
	 	printf("\t\t  ===========================================================\n");
		while(1)
	 	{
	 		fread(&f1,sizeof(f1),1,fb);
	 		
	 		if(feof(fb))// eof= end of file
	 		{
	 			break;
			}
			printf("\t\t        %s\t            %s\t\t           %d\n",f1.stud_id,f1.book_id,f1.fine_amt); 
		
		}
		printf("\t\t  ===========================================================\n\n");
		fclose(fb);
		fclose(fb1);
		
		printf("\nChoose Options\n\nAdd Fine = '1'\nClear Fine = '2'\nBack = '0'\n");
		scanf("%d",&j);
		
		switch(j)
		{
			case 1:
			{
				fb=fopen(fine_db,"rb");
 				fb1=fopen(fine_temp,"wb");
				
				printf("Enter student id (case sensative) \n");
				scanf("%s",&id);
				
				while(1)
			 	{	
			 		fread(&f1,sizeof(f1),1,fb);
					
					if(feof(fb))
					{
						break;	
					}	
					else if(strcmp(f1.stud_id,id)==0)
					{
						found=1;
						printf("Enter Fine Amount\n");
						scanf("%d",&amt);
						
						f1.fine_amt=amt;
						
						fwrite(&f1,sizeof(f1),1,fb1);
					}
					else
					{
						fwrite(&f1,sizeof(f1),1,fb1);
					}
				}
				
			 	fclose(fb);
				fclose(fb1);
				if(found=0)
				{
					printf("\n No Records Found\n");
				}
				else
				{
					fb=fopen(fine_db,"wb");
					fb1=fopen("fine_temp.dat","rb");
					
					while(1)
					{
						fread(&f1,sizeof(f1),1,fb1);
						
						if(feof(fb1))
						{
							break;
						}
						
						fwrite(&f1,sizeof(f1),1,fb);
					}
				} 
				fclose(fb);
				fclose(fb1);
				
				printf("\nDo you want to continue ? (Y/N)\n");
				scanf("%s",&opt);
				
				if(strcmp(opt,"Y")==0)
				{
					user();// line no. 1305
			    }
				else
				{
				    user();// line no. 1305
				}
				break;
				return 0;
			}
			case 2:
			{
				fb=fopen(fine_db,"rb");
 				fb1=fopen(fine_temp,"wb");
				
				printf("Enter student id (case sensative) \n");
				scanf("%s",&id);
				
				while(1)
			 	{	
			 		fread(&f1,sizeof(f1),1,fb);
					
					if(feof(fb))
					{
						break;	
					}	
					else if(strcmp(f1.stud_id,id)==0)
					{
						found=1;
						
						strcpy(f1.book_id,"");
						f1.fine_amt=0;
						
						fwrite(&f1,sizeof(f1),1,fb1);
					}
					else
					{
						fwrite(&f1,sizeof(f1),1,fb1);
					}
				}
				
			 	fclose(fb);
				fclose(fb1);
				if(found=0)
				{
					printf("\n No Records Found\n");
				}
				else
				{
					fb=fopen(fine_db,"wb");
					fb1=fopen("fine_temp.dat","rb");
					
					while(1)
					{
						fread(&f1,sizeof(f1),1,fb1);
						
						if(feof(fb1))
						{
							break;
						}
						
						fwrite(&f1,sizeof(f1),1,fb);
					}
				} 
				fclose(fb);
				fclose(fb1);
				
				printf("\nDo you want to continue ? (Y/N)\n");
				scanf("%s",&opt);
				
				if(strcmp(opt,"Y")==0)
				{
					user();// line no. 1305
			    }
				else
				{
				    user();// line no. 1305
				}
				break;
				return 0;
			}
			case 0:
			{
				book_operations();
				break;
			}
			default:
			{
				break;
			}
		}
		
	}
	return 0;
}
		
			
 
 //----------------------STUDENT DETAILS--------------------------------------------
 
 
 
 //+++++++++++++FINE SECTION+++++++++++++++++++++++++
 int book_fine(char s_id[20])
 {
 	int found=0,fine=0;
 	FILE *st,*st1;
 	struct stud s1;
 	int i=1,b_fine=0;
 	char opt[2],chk[2],b_id[20];
 	
 	SYSTEMTIME stime;
 	GetSystemTime(&stime);
 	
 	st=fopen(student_db,"rb");
 	
	while(1)
 	{
 		fread(&s1,sizeof(s1),1,st);
 		
 		if(feof(st))// eof= end of file
 		{
 			break;
		}
		if(strcmp(s1.id,s_id)==0 && s1.lended_book_id!=0)// && strcmp(s1.lend,"YES")!=0)
		{	
			printf("\n\n***************\n*   PROFILE   *\n***************\n");
			printf("ID : %s\n",s1.id);
			printf("Name : %s\n\n",s1.name);
			printf("Lended Book ID: %s\n",s1.lended_book_id);
			strcpy(b_id,s1.lended_book_id);
			printf("Lended Book Name : %s\n",s1.lended_book_name);
			printf("Lending Date : %d / %d / %d\n",s1.lday,s1.lmonth,s1.lyear);
			printf("Returning Date : %d / %d / %d\n",s1.rday,s1.rmonth,s1.ryear);
			printf("Today's Date : %d / %d / %d\n",stime.wDay,stime.wMonth,stime.wYear);
			if(s1.rday<stime.wDay && s1.rday!=0)
			{
				found=1;
				fine=s1.rday-stime.wDay;
				printf("\nYour book is %d days late and as per rules the fine amount will be %d X 5/-(per days) that is rupees %d\n\n",fine,fine,fine*5);
				printf("Please submit the fine amount to the Library executive and ask to clear your dues and try again later");
				s1.fine_due=fine*5;
				b_fine=s1.fine_due;
				fwrite(&s1,sizeof(s1),1,st1);
					
			}
			else if(s1.fine_due==0)
			{
				printf("\nYou have no fine due\n");
				student_operations(s1.id);
				
			}
			else
			{
				printf("Fine Amount : %d\n",s1.fine_due); 
				printf("Please submit the fine amount to the Library executive and ask to clear your dues and try again later");
				fine_operations(s_id,b_id,1,b_fine);
				exit;
			}	
		}
		else
		{
			fwrite(&s1,sizeof(s1),1,st1);
		}
	}
	fclose(st);
	fclose(st1);
 	
	if(found==1)
	{
		st=fopen(student_db,"wb");
		st1=fopen("stud_temp.dat","rb");
	
		while(1)
		{
			fread(&s1,sizeof(s1),1,st1);
		
			if(feof(st1))
			{
				break;
			}
			fwrite(&s1,sizeof(s1),1,st);
		}
	}	
	fclose(st);
	fclose(st1);
	
	return 0;
}
 
 //+++++++++++++RETURNING SECTION+++++++++++++++++++++++++
 int returning(char s_id[20])
 {
 	int found=0;
 	FILE *st,*st1,*bk,*bk1,*fb;
	struct stud s1;
	struct books b;
	struct fine_book f1;
	int i=1,fine_amt;
 	char chk[2];
 	 	
 	SYSTEMTIME stime;
 	GetSystemTime(&stime);
 	
 	fb=fopen(fine_db,"rb");
 	
 	st=fopen(student_db,"rb");
 	st1=fopen(stud_temp,"wb");
 	
  	bk=fopen(book,"rb");
 	bk1=fopen(book_temp,"wb");
 	
 	while(1)
 	{
 		fread(&f1,sizeof(f1),1,fb);
 		
 		if(feof(fb))// eof= end of file
 		{
 			break;
		}
		if(strcmp(f1.stud_id,s_id)==0)
		{
			if(f1.fine_amt==0)
			{
				while(1)
			 	{
			 		fread(&s1,sizeof(s1),1,st);
			 		
			 		if(feof(st))// eof= end of file
			 		{
			 			break;
					}
					if(strcmp(s1.id,s_id)==0)
					{	
						if(s1.rday==stime.wDay || s1.rday>stime.wDay)
						{	
							found=1;
							while(1)
							{
								fread(&b,sizeof(b),1,bk);
								
								if(feof(bk))// eof= end of file
				 				{
				 					break;
								}
								if(strcmp(b.id,s1.lended_book_id)==0)
								{
									b.qnty=b.qnty+1;
									fwrite(&b,sizeof(b),1,bk1);
									
								}
								else
								{
									fwrite(&b,sizeof(b),1,bk1);
								}
							}		
							
							s1.lday=0;
							s1.lmonth=0;
							s1.lyear=0;
							s1.rday=0;
							s1.rmonth=0;
							s1.ryear=0;
							strcpy(s1.lended_book_id,"No Books Yet");
							strcpy(s1.lended_book_name,"No Books Yet");
							
							fwrite(&s1,sizeof(s1),1,st1);
							
							printf("\n\n -----------------\n");
							printf(" * Book Returned *\n");
							printf(" -----------------\n");
							break;
						}
						else
						{	
							found=1;
							book_fine(s_id);// line no. 330
						}	
					}
					else
					{
						fwrite(&s1,sizeof(s1),1,st1);
					}
				}
				fclose(st);
				fclose(st1);
				fclose(bk);
				fclose(bk1);
			 	
				if(found==0)
				{
					printf("\n No Records Found\n");
				}
				else
				{
					st=fopen(student_db,"wb");
					st1=fopen("stud_temp.dat","rb");
			
					bk=fopen(book,"wb");
					bk1=fopen("book_temp.dat","rb");
					
					while(1)
					{
						fread(&b,sizeof(b),1,bk1);	
						
						if(feof(bk1))// eof= end of file
			 			{
			 				break;
						}
						fwrite(&b,sizeof(b),1,bk);
					}
							
					while(1)
					{
						fread(&s1,sizeof(s1),1,st1);	
						
						if(feof(st1))// eof= end of file
			 			{
			 				break;
						}
						fwrite(&s1,sizeof(s1),1,st);
					}
				}	
				fclose(st);
				fclose(st1);
				
				fclose(bk);
				fclose(bk1);
				profile(s_id);// line no. 774
				return 0;
			}
			else
			{
				printf("Fine Amount : %d\n",f1.fine_amt); 
				printf("Please submit the fine amount to the Library executive and ask to clear your dues and try again later");
				exit;
			}
 		}
 	}
	return 0;
}
 
//+++++++++++++LENDING SECTION+++++++++++++++++++++++++
 int lend_stud(char b_id[20],char b_name[20],char s_id[20])
 {
 	int found=0;
 	FILE *st,*st1;
	struct stud s1;
	
	int i=1;
 	char opt[2],chk[2];
 	
 	SYSTEMTIME stime;
 	GetSystemTime(&stime);
 	
 	st=fopen(student_db,"rb");
 	st1=fopen(stud_temp,"wb");
 	
	while(1)
 	{
 		fread(&s1,sizeof(s1),1,st);
	 		
 		if(feof(st))// eof= end of file
 		{
 			break;
		}
		if(strcmp(s1.id,s_id)==0)
		{	
			
				found=1;
				s1.lday=stime.wDay;
				s1.lmonth=stime.wMonth;
				s1.lyear=stime.wYear;
				//-----------------------------------------------------------
				s1.rday=stime.wDay+10;
				//-----------------------------------------------------------
				s1.rmonth=stime.wMonth;
				s1.ryear=stime.wYear;
				strcpy(s1.lended_book_id,b_id);
				strcpy(s1.lended_book_name,b_name);
				fwrite(&s1,sizeof(s1),1,st1);
		}
		else
		{
			fwrite(&s1,sizeof(s1),1,st1);
		}
	}
	fclose(st);
	fclose(st1);
 	
	if(found==1)
	{
		st=fopen(student_db,"wb");
		st1=fopen("stud_temp.dat","rb");
	
		while(1)
		{
			fread(&s1,sizeof(s1),1,st1);
			
			if(feof(st1))
			{
				break;
			}
			fwrite(&s1,sizeof(s1),1,st);
			
		}
	}	
	fclose(st);
	fclose(st1);
	return 0;
}

//------------------------

int lending(char s_id[20])
 {
 	int found=0,c=0;
 	FILE *bk,*bk1,*st;
 	
	struct stud s1;
 	struct books b;
 	int i=1;
 	char bid[20],opt[2],chk[2];
 	
 	SYSTEMTIME stime;
 	GetSystemTime(&stime);
 	
	book_store(); //line no: 512
 	
 	st=fopen(student_db,"rb");
 	
	bk=fopen(book,"rb"); 
	bk1=fopen(book_temp,"wb");
	
 	
	printf("\n\n\n************************************************************************************************************************\n");
 	printf("\t\t\t\t\t\tBOOK LENDING SECTION\n\n");
	printf("************************************************************************************************************************\n\n");
	printf("\n+++++++++++++++++++++++++++++++++++++++\n+   You can lend one book at a time   +\n+++++++++++++++++++++++++++++++++++++++\n");
	printf("\nEnter Book-id (case sensative) \n");
	scanf("%s",&bid);	
	
	while(1)
	{
		fread(&s1,sizeof(s1),1,st);
		if(feof(st))// eof= end of file
 		{
 			break;
		}
		if(strcmp(s1.id,s_id)==0)
		{
			if(strcmp(s1.lended_book_id,"No Books Yet")==0)
			{
				c=1;
			}
		}
	}
	if(c==1)
	{
		while(1)
	 	{
	 		fread(&b,sizeof(b),1,bk);
	 		
	 		if(feof(bk))// eof= end of file
	 		{
	 			break;
			}
			if(strcmp(b.id,bid)==0)
			{	
				if(b.qnty!=0)
				{
					found=1;
					printf("Book id : %s\n\n",b.id);
					printf("Book Name : %s\n",b.name);
					printf("Writter Name : %s\n\n",b.writter);
					
					printf("\nLending Date : %d / %d / %d\n",stime.wDay,stime.wMonth,stime.wYear);
					printf("Returning Date : %d / %d / %d\n",stime.wDay+10,stime.wMonth,stime.wYear);
		
					printf("Do you want to lend ? (Y/N)\n");
					scanf("%s",&opt);
					if(strcmp(opt,"Y")==0)
					{	
						b.qnty=b.qnty-1;
						
						fwrite(&b,sizeof(b),1,bk1);
						lend_stud(b.id,b.name,s_id); //line no:570
						printf("\n\n *****************\n");
						printf(" *   Successful  *\n");
						printf(" *****************\n");		
					}
					else if(strcmp(opt,"N")==0)
					{
						profile(s_id);// line no. 774
					}
				}
				else
				{
					printf("\n No More Copies Available \n");
					profile(s_id);// line no. 774
				}
			}
			else
			{
				fwrite(&b,sizeof(b),1,bk1);
			}
		}
	 	fclose(bk);
		fclose(bk1);
		if(found==0)
		{
			printf("\n No Records Found\n");
		}
		else
		{
			bk=fopen(book,"wb");
			bk1=fopen("book_temp.dat","rb");
			
			while(1)
			{
				fread(&b,sizeof(b),1,bk1);
			
				if(feof(bk1))
				{
					break;
				}
			
				fwrite(&b,sizeof(b),1,bk);
			}
		}	
		fclose(bk);
		fclose(bk1);
		
		profile(s_id);// line no. 774
		return 0;
	}
			
	else
	{
		printf("\n\n ******************************************************************************\n");
		printf(" * You can lend one book at a time, Please return your book to lend a new one * \n");
		printf(" ******************************************************************************\n");	
		profile(s_id);// line no. 774
	}
}
 
 //+++++++++++++STUDENT PROFILE+++++++++++++++++++++++++
 int profile(char s_id[20])
 {
 	FILE *st;
 	struct stud s1;
 	st=fopen(student_db,"rb"); //rb= read binary
 	while(1)
 	{
 		fread(&s1,sizeof(s1),1,st);
 		if(feof(st))// eof= end of file
 		{
 			break;
		}
		if(strcmp(s1.id,s_id)==0)
		{
			printf("\n\n***************\n*   PROFILE   *\n***************\n");
			printf("ID : %s\n",s1.id);
			printf("Name : %s\n\n",s1.name);
			printf("Lended Book ID: %s\n",s1.lended_book_id);
			printf("Lended Book Name : %s\n",s1.lended_book_name);
			printf("Lending Date : %d / %d / %d\n",s1.lday,s1.lmonth,s1.lyear);
			printf("Returning Date : %d / %d / %d\n",s1.rday,s1.rmonth,s1.ryear);
			student_operations(s_id);// line no. 1241
		}
	}
	fclose(st);
 }
 
 
//+++++++++++++STUDENT LOGIN+++++++++++++++++++++++++ 
 int login()
 {
 	user_type=1;
 	int f=0;
 	FILE *st;
 	char opt[2],s_id[20],s_pass[20];
	struct stud s1;
 	printf("\n*********************\n*   Student Login   *\n*********************\n");
	printf("\nEnter your ID (case sensative) ");
 	scanf("%s",&s_id);
 	printf("Enter your password (case sensative) ");
 	scanf("%s",&s_pass);
	
	st=fopen(student_db,"rb");
	
	while(1)
	{
		fread(&s1,sizeof(s1),1,st);

		if(feof(st))
		{
			break;
		}
		if(strcmp(s1.id,s_id)==0 && strcmp(s1.pass,s_pass)==0)
		{
			f=1;
			printf("\nLogin Successful\n");
			profile(s_id);// line no. 774
		}
	}
	if(f==0)
	{
		printf("\n\nPlease try again\n\n");
		login();// line no. 803
	}
	fclose(st);
	return 0;
 }
 
 
//+++++++++++++STUDENT REGISTRATION+++++++++++++++++++++++++ 
int reg()
 {
 	FILE *st,*f,*st1; 
 	char opt[2],s_id[20];
 	struct stud s1;
 	struct fine_book f1;
 	
 	int found=0;
 	
 	st=fopen(student_db,"ab");
	st1=fopen(student_db,"rb");
	
 	printf("\n****************************\n*   Student Registration   *\n****************************\n");
	printf("\nEnter your ID (case sensative)");
 	scanf("%s",&s1.id);
 	strcpy(s_id,s1.id);
	printf("Enter your NAME ");
 	scanf("%s",&s1.name);
 	printf("Enter your password (case sensative)");
 	scanf("%s",&s1.pass);
	
	
	while(1)
	{
		fread(&s1,sizeof(s1),1,st1);
		
		if(feof(st1))
		{
			break;
		}

		if(strcmp(s1.id,s_id)==0)
		{
			found=1;
			fclose(st1);	
			break;
		}
	}
	
	if(found==0)
	{	
		s1.lday=0;
		s1.lmonth=0;
		s1.lyear=0;
		s1.rday=0;
		s1.rmonth=0;
		s1.ryear=0;
		s1.fine_due=0;
		strcpy(s1.lended_book_id,"No Books Yet");
		strcpy(s1.lended_book_name,"No Books Yet");
	
		fwrite(&s1,sizeof(s1),1,st);
		fclose(st);
		
			
		f=fopen(fine_db,"ab");// fine db initialization
		strcpy(f1.stud_id,s_id);
		strcpy(f1.book_id,"");
		f1.fine_amt=0;
		fwrite(&f1,sizeof(f1),1,f);
		fclose(f);
		
			
		printf("\nRegistration Successful\n");
			
		printf("\nDo you want to continue ? (Y/N)\n");
		scanf("%s",&opt);
		
		if(strcmp(opt,"Y")==0)
		{
			reg();// line no.844
	    }
		else
		{
			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\nPlease restart once to login the recently added account\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		    login();//line no. 803
		}
	}
	
	else if(found==1)
	{
		printf("\n\nAlready Registered\n\n");
		login();// line no. 803
	}
	fclose(st);
	return 0;
 }
 
 
 
 //-----------------------------------BOOK DETAILS--------------------------------------------
 
 
 
 //+++++++++++++ADD BOOK+++++++++++++++++++++++++
 int book_reg() 
 {
 	char opt[2];
 	FILE *bk;
 	struct books b;
	bk=fopen(book,"ab"); //ab= append binary
	printf("\n********************\n*   Add New Book   *\n********************\n");
 	printf("\nEnter Book ID (case sensative)");
 	scanf("%s",&b.id);
 	printf("Enter Book NAME \n");
 	scanf("%s",&b.name);
 	printf("Enter Book Writter \n");
 	scanf("%s",&b.writter);
 	printf("Enter Book Quantity \n");
 	scanf("%d",&b.qnty);
	fwrite(&b,sizeof(b),1,bk);
 	printf("\nDo you want to continue ? (Y/N)\n");
	scanf("%s",&opt);
	
	if(strcmp(opt,"Y")==0)
	{
		book_reg(); //line no.939
    }
	else
	{
		printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\nPlease restart once to view the recently added record\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	    book_store(); //line no. 1129
	}
 	fclose(bk);
 	
 }
 
//+++++++++++++REMOVE BOOK+++++++++++++++++++++++++
 int remove_book()  
 {
 	char b_id[5],opt[2];
 	
 	FILE *bk,*bk1;
 	struct books b;
 	int found=0,n=0,i;
 	
	bk=fopen(book,"rb"); //ab= append binary
	bk1=fopen(book_temp,"wb"); //wb= write binary
 	
	printf("\n*******************\n*   Remove Book   *\n*******************\n");
	printf("\nEnter Book ID (case sensative) ");
 	scanf("%s",&b_id);
	while(1)
 	{
 		
 		fread(&b,sizeof(b),1,bk);
		
		if(feof(bk))
		{
			break;	
		}	
		if(strcmp(b.id,b_id)==0)
		{
			found=1;
		}
		else
		{
			fwrite(&b,sizeof(b),1,bk1);
		}
	}
 	fclose(bk);
	fclose(bk1);
	
	if(found=0)
	{
		printf("\n No Records Found\n");
	}
	else
	{
		bk=fopen(book,"wb");
		bk1=fopen("book_temp.dat","rb");
		
		while(1)
		{
			fread(&b,sizeof(b),1,bk1);
			
			if(feof(bk1))
			{
				break;
			}
			
			fwrite(&b,sizeof(b),1,bk);
		}
	} 
	fclose(bk);
	fclose(bk1);
	
	printf("\nDo you want to continue ? (Y/N)\n");
	scanf("%s",&opt);
	
	if(strcmp(opt,"Y")==0)
	{
		remove_book(); // line no. 972
    }
	else
	{
	    book_store();// line no.1129
	}
	return 0;	
 }
 
//+++++++++++++UPDATE BOOK+++++++++++++++++++++++++
 int update() 
 {
 	char b_id[5],opt[2];
 	
 	FILE *bk,*bk1;
 	struct books b;
 	int found=0,n=0,i;
 	
	bk=fopen(book,"rb"); //rb= read binary
	bk1=fopen(book_temp,"wb"); //wb= write binary
 	
 	printf("\n*******************\n*   Update Book   *\n*******************\n");
	printf("\nEnter Book ID (case sensative) ");
 	scanf("%s",&b_id);
	while(1)
 	{
 		
 		fread(&b,sizeof(b),1,bk);
		
		if(feof(bk))
		{
			break;	
		}	
		if(strcmp(b.id,b_id)==0)
		{
			found=1;
			printf("Enter Book NAME (case sensative) \n");
 			scanf("%s",&b.name);
 			printf("Enter Book Writter (case sensative) \n");
 			scanf("%s",&b.writter);
 			printf("Enter Book Quantity \n");
 			scanf("%d",&b.qnty);
			fwrite(&b,sizeof(b),1,bk1);
		}
		else
		{
			fwrite(&b,sizeof(b),1,bk1);
		}
	}
	
 	fclose(bk);
	fclose(bk1);
	if(found=0)
	{
		printf("\n No Records Found\n");
	}
	else
	{
		bk=fopen(book,"wb");
		bk1=fopen("book_temp.dat","rb");
		
		while(1)
		{
			fread(&b,sizeof(b),1,bk1);
			
			if(feof(bk1))
			{
				break;
			}
			
			fwrite(&b,sizeof(b),1,bk);
		}
	} 
	fclose(bk);
	fclose(bk1);
	
	printf("\nDo you want to continue ? (Y/N)\n");
	scanf("%s",&opt);
	
	if(strcmp(opt,"Y")==0)
	{
		update();// line no. 1046
    }
	else
	{
	    book_store();// line no. 1129
	}	
	return 0;
 }
 

 
 //+++++++++++++BOOK STORE+++++++++++++++++++++++++
 int book_store()
 {
 	FILE *bk;
 	struct books b;
	int i=1,k;
 	bk=fopen(book,"rb"); //rb= read binary
	
	printf("\n\n\n************************************************************************************************************************\n");
 	printf("\t\t\t\t\t\t    BOOK STORE\n\n");
	printf("************************************************************************************************************************\n\n");
	printf("\t\t  =============================================================================\n");
	printf("\t\t  |   Book id   |        Book Name        |        Writter       |  Available |\n");
 	printf("\t\t  =============================================================================\n");
	while(1)
 	{
 		fread(&b,sizeof(b),1,bk);
 		if(feof(bk))// eof= end of file
 		{
 			break;
		}
		printf("\t\t       %s\t      %s\t\t    %s\t\t\t%d    \n",b.id,b.name,b.writter,b.qnty); 
	
	}
	printf("\t\t  =============================================================================\n\n");
	
	if(user_type==2)
	{
		printf("\nChoose Options\n\nAdd Book = '1'\nUpdate Books = '2'\nRemove Books = '3'\nView Books = '4'\nExit = '0'\n");
		scanf("%d",&k);
		switch(k)
		{
			case 1:
			{
				book_reg();// line no. 939
				break;
			}
			case 2:
			{
				update();// line no. 1046
				break;	
			}
			case 3:
			{
				remove_book();// line no. 972
				break;
			}
			case 4:
			{
				book_store();// line no. 1129
				break;
			}
			default:
			{
				break;
			}
		}
	}
	return 0;
}
 
 
//+++++++++++++LIBRARY ASSISTANT OPERATIONS+++++++++++++++++++++++++
 int book_operations()
 {
 	int i;
	printf("\n--------------------\n   Library Portal \n--------------------\n\nAdd Book = '1'\nUpdate Books = '2'\nRemove Books = '3'\nView Books = '4'\nFine Chart = '5'\nExit = '0'\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
		{
			book_reg();// line no. 939
			book_operations();// line no. 1191
			break;
		}
		case 2:
		{
			update();// line no. 1046
			book_operations();// line no. 1191
			break;	
		}
		case 3:
		{
			remove_book();// line no. 972
			book_operations();// line no. 1191
			break;
		}
		case 4:
		{
			book_store();// line no. 1129
			book_operations();// line no. 1191
			break;
		}
		case 5:
		{
			fine_operations("","",2,0);
			book_operations();// line no. 1191
			break;
		}
		case 0:
		{
			user();// line no. 1305
			break;
		}
		default:
		{
			break;
		}
	}
 }
 
 //----------------------STUDENT OPERATIONS--------------------------------------------
 int student_operations(char s_id[20])
 {
 	int i;
	printf("\nChoose Options\n\nLend Books = '1'\nReturn Books = '2'\nFine = '3'\nExit = '0'\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
		{
			lending(s_id);// line no. 641
			break;	
		}
		case 2:
		{
			returning(s_id);// line no. 418
			break;
		}
		case 3:
		{
			book_fine(s_id);// line no. 330
			break;
		}
		case 0:
		{
			student();// line no. 1275
			break;
		}
		default:
		{
			break;
		}
	}
 }
 //+++++++++++++++++STUDENT LOGIN/REGISTER+++++++++++++++++++++++++++
 int student()
 {
 	int i;
	printf("\n\n--------------------\n   Student Portal\n--------------------\nRegister = '1'\nLogin = '2'\nExit = '0'\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
		{
			reg();// line no. 844
			break;
		}
		case 2:
		{
			login();// line no. 803
			break;
		}
		case 0:
		{
			user();// line no. 1305
			break;
		}
		default:
		{
			break;
		}
	}
 }
 //-----------------------USER DIFFERENCIATION-------------------------------
 
 int user()
 {
 	int i,k;
 	printf("\n\n--------------------\n   Choose User\n--------------------\nStudent='1'\nLibrary Assistant='2'\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
			{
				student();// line no. 1275
				break;
			}
			case 2:
			{
				printf("\n Enter Password \n");
				scanf("%d",&k);
				if(k==2021)
				{
					user_type=2;
					book_operations();// line no. 1191
				}
				else
				{
					printf("Incorrect Password");
					user();// line no. 1305
				}
			}
			default:
			{
				break;
			}
		}
 	return 0;
 }
 
 //----------------------------MAIN FUNCTION------------------------------
 
 void main()
 {
 	struct stud s1;
 	char i[50],j[50];
 	strcpy(i,"anirban");
	printf("************************************************************************************************************************\n");
 	printf("\t\t\t\t\t    LIBRARY MANAGEMENT SYSTEM\n\n");
	printf("************************************************************************************************************************\n");

	printf("*****************\n");
 	printf("*     LOGIN     *\n");
	printf("*****************\n");
	printf("Enter Password (case sensative)\t\t\t\n");
	scanf("%s",&j);
	if(strcmp(i,j)==0)
	{
		user();// line no. 1305
	}
	else
	{
		printf("\n Incorrect Password \n");
		printf(" Try Again \n");
		main();// line no. 1342
	}
 }
