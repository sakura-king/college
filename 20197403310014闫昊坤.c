#include <stdio.h>//预编译，头文件 
#include <stdlib.h>
#include"string.h" 
struct student{//定义结构体类型和内容 
	char nam[10];
	char gender[5];
	int num;
	int Maths;
	int English;
	int C;
	int PE;
}stu[100];//结构体数组长度 

void finput()//定义输入函数 
{
	FILE*fp;//声明文件指针 
	int i,p;
	fp=fopen("stu.txt","w");//打开文件，只写 
	for(i=0;i<100;i++)
	{
		printf("请输入序号(当输入p=-1时不再录入)，p=\n");
		scanf("%d",&p);//判断是否继续录入 
		if(p==-1){
			fclose(fp);
			return;
		}else{          //输入信息 
			printf("请依次输入学生姓名，性别，学号，数学成绩，英语成绩，c成绩，体育成绩：\n");
			scanf("%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE);
			fprintf(fp,"%s%8s%8d%8d%8d%8d%8d",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);//写入文件 
		}
	}fclose(fp);//关闭文件 
}


void list()//定义输出函数 
{
	FILE*fp;//声明文件指针 
	int i;
	fp=fopen("stu.txt","r");//打开文件，只读 
	printf("-------------成绩列表-------------\n");
	printf("                                  \n");
	printf(" 姓名	   性别	   学号	   数学	   英语	     C	   体育\n");
    for(i=0;fscanf(fp,"%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE)!=EOF;i++){
    	printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
    }                //将结构体内的信息输出 
    printf("----------------------------------\n");
    fclose(fp);//关闭文件 
	 
}



void fsearch()//定义查找函数 
{
	FILE*fp;//声明文件指针 
	int i,num,k=1;
	fp=fopen("stu.txt","r");//打开文件 ，只读 
	rewind(fp);//将指针移到文件开头 
	printf("请输入要查找的学号：\n");
	scanf("%d",&num);
	printf("查询结果：\n");
	for(i=0;i<100;i++){//遍历寻找与用户输入的数字相同的学号 
		if(num==stu[i].num){//若找到则输出 
			k=0;
			printf(" 姓名	   性别	   学号	   数学	   英语	     C	   体育\n");
			printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
		}
		 
	}
	if(k==1){//若未找到则提醒用户输入错误 
		printf("********************************************\n");
		printf("您输入的学号有误，未找到该学员，请返回重新输入！！！");
		return;
		}
	printf("--------------------------------------------------\n");
	fclose(fp);//关闭文件 
}


void fadd()//定义添加函数 
{
	FILE*fp;//声明文件指针 
	int i,s,p;
	fp=fopen("stu.txt","a+");//打开文件并进行读写，将添加的内容写到文件末尾 
	rewind(fp);//将指针移到文件开头 
	printf("-------------成绩列表-------------\n");
	printf("                                  \n");
	printf(" 姓名	   性别	   学号	   数学	   英语	     C	   体育\n");
    for(i=0;fscanf(fp,"%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE)!=EOF;i++){
    	printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
    }
	s=i;//找出有多少个结构体 
	for(i=s;i<100;i++){
		printf("请输入序号(当输入p=-1时不再录入)，p=\n");
		scanf("%d",&p);
		if(p==-1){//判断是否要继续输入 
			fclose(fp);
			return;
		}else{//若输入不为-1继续需输入内容 
			printf("请依次输入学生姓名，性别，学号，数学成绩，英语成绩，c成绩，体育成绩：\n");
			scanf("%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE);
			fprintf(fp,"%s%8s%8d%8d%8d%8d%8d",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);//将信息写入文件 
		}
	}
	fclose(fp);
}



void fdelete()//定义删除函数 
{
	FILE*fp,*fp1;//声明两个文件指针 
	int i,num;
	int f=0;
	fp=fopen("stu.txt","r");//声明文件指针，只读 
	fp1=fopen("hh.txt","w");//声明文件指针，只写 
	if(fp==NULL||fp1==NULL){//判断文件是否能正常打开 
		printf("打开失败\n"); 
		exit(0);
	}else{
		printf("请输入要删除信息的学号:\n");
		scanf("%d",&num);
		for(i=0;i<100;i++){//遍历函数寻找 
			if(num==stu[i].num){//若找到该学生信息输出 
				printf(" 姓名	   性别	   学号	   数学	   英语	     C	   体育\n");
				printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
				f=1;
				break;
			}
		}
		if(f==0){//若未找到，提醒用户 
			printf("未找到该学员，请返回！！！");
			return;
		}
		for(i=0;i<100;i++){//遍历 
			while(fscanf(fp,"%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE)!=EOF){
				if(num!=stu[i].num){//若与用户所输入数字不一样
				fprintf(fp1,"%s%8s%8d%8d%8d%8d%8d",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);//将内容写入新创建的文件 
			}
		}
		}
	}
	fclose(fp);//关闭文件 
	fclose(fp1);
	remove("stu.txt");//移除原文件 
	rename("hh.txt","stu.txt");//将新文件命名为原文件名 
}



void frank()//定义排序函数 
{
	int i,j,n;
	FILE*fp;//声明文件指针 
	struct student t;//定义新的结构体 
	fp=fopen("stu.txt","r");//打开文件，只读 
	printf("-------------成绩列表-------------\n");
	printf("                                  \n");
	printf(" 姓名	   性别	   学号	   数学	   英语	     C	   体育\n");
	for(i=0;fscanf(fp,"%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE)!=EOF;i++){
		printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
	}
	fclose(fp);
	n=i;
	for(i=0;i<n;i++){//冒泡法排序 
		for(j=i+1;j<n;j++){
			if(stu[i].num>stu[j].num){
				t=stu[i];
				stu[i]=stu[j];
				stu[j]=t;
			}
		}
	}
	fp=fopen("stu.txt","w");
	printf("\n\n\n\n\n\n\n\n\n");
	printf("-------------成绩列表-------------\n");
	printf("                                  \n");
	printf(" 姓名	   性别	   学号	   数学	   英语	     C	   体育\n");
    for(i=0;i<n;i++){
    	fprintf(fp,"%s%8s%8d%8d%8d%8d%8d",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);//将排序好的信息写入文件 
    	printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
    }
    printf("----------------------------------\n");
    fclose(fp);
}




int main()//定义主函数 
{
	int n;
	for(;;){
	printf("\n");
	printf("-------------------------------------------------------------\n");
	printf(" 欢迎来到学生信息管理系统 \n");
	printf(" 主菜单 ※\n");
	printf(" \n");
	printf(" 1.录入数据▲ ※\n");
	printf(" 2.输出数据▲ ※\n");
	printf(" 3.查找数据▲ ※\n");
	printf(" 4.添加数据▲ ※\n");
	printf(" 5.删除数据▲ ※\n");
	printf(" 6.成绩排序▲ ※\n");
	printf(" 7.退出系统▲ ※\n");
	printf("--------------------------------------------------------------\n");
	printf("请输入选择项(1-7):\n");
	scanf("%d",&n);
	if(n>0&&n<8){
		switch(n){
			case 1:finput();break;
			case 2:list();break;
			case 3:fsearch();break;
			case 4:fadd();break;
			case 5:fdelete();break;
			case 6:frank();break;
			case 7:printf("* 谢谢使用! *\n");
                   printf("* 再见! *\n");
                   printf("* *\n");
                   printf("------------------------------------------------\n");
                   exit(0);  
		}
	}else{
		printf(" 输入错误! \n");
		printf(" 请退出! \n");
		break;
	}
	}
}
