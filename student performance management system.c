#include <stdio.h>//Ԥ���룬ͷ�ļ� 
#include <stdlib.h>
#include"string.h" 
struct student{//����ṹ�����ͺ����� 
	char nam[10];
	char gender[5];
	int num;
	int Maths;
	int English;
	int C;
	int PE;
}stu[100];//�ṹ�����鳤�� 

void finput()//�������뺯�� 
{
	FILE*fp;//�����ļ�ָ�� 
	int i,p;
	fp=fopen("stu.txt","w");//���ļ���ֻд 
	for(i=0;i<100;i++)
	{
		printf("���������(������p=-1ʱ����¼��)��p=\n");
		scanf("%d",&p);//�ж��Ƿ����¼�� 
		if(p==-1){
			fclose(fp);
			return;
		}else{          //������Ϣ 
			printf("����������ѧ���������Ա�ѧ�ţ���ѧ�ɼ���Ӣ��ɼ���c�ɼ��������ɼ���\n");
			scanf("%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE);
			fprintf(fp,"%s%8s%8d%8d%8d%8d%8d",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);//д���ļ� 
		}
	}fclose(fp);//�ر��ļ� 
}


void list()//����������� 
{
	FILE*fp;//�����ļ�ָ�� 
	int i;
	fp=fopen("stu.txt","r");//���ļ���ֻ�� 
	printf("-------------�ɼ��б�-------------\n");
	printf("                                  \n");
	printf(" ����	   �Ա�	   ѧ��	   ��ѧ	   Ӣ��	     C	   ����\n");
    for(i=0;fscanf(fp,"%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE)!=EOF;i++){
    	printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
    }                //���ṹ���ڵ���Ϣ��� 
    printf("----------------------------------\n");
    fclose(fp);//�ر��ļ� 
	 
}



void fsearch()//������Һ��� 
{
	FILE*fp;//�����ļ�ָ�� 
	int i,num,k=1;
	fp=fopen("stu.txt","r");//���ļ� ��ֻ�� 
	rewind(fp);//��ָ���Ƶ��ļ���ͷ 
	printf("������Ҫ���ҵ�ѧ�ţ�\n");
	scanf("%d",&num);
	printf("��ѯ�����\n");
	for(i=0;i<100;i++){//����Ѱ�����û������������ͬ��ѧ�� 
		if(num==stu[i].num){//���ҵ������ 
			k=0;
			printf(" ����	   �Ա�	   ѧ��	   ��ѧ	   Ӣ��	     C	   ����\n");
			printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
		}
		 
	}
	if(k==1){//��δ�ҵ��������û�������� 
		printf("********************************************\n");
		printf("�������ѧ������δ�ҵ���ѧԱ���뷵���������룡����");
		return;
		}
	printf("--------------------------------------------------\n");
	fclose(fp);//�ر��ļ� 
}


void fadd()//������Ӻ��� 
{
	FILE*fp;//�����ļ�ָ�� 
	int i,s,p;
	fp=fopen("stu.txt","a+");//���ļ������ж�д������ӵ�����д���ļ�ĩβ 
	rewind(fp);//��ָ���Ƶ��ļ���ͷ 
	printf("-------------�ɼ��б�-------------\n");
	printf("                                  \n");
	printf(" ����	   �Ա�	   ѧ��	   ��ѧ	   Ӣ��	     C	   ����\n");
    for(i=0;fscanf(fp,"%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE)!=EOF;i++){
    	printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
    }
	s=i;//�ҳ��ж��ٸ��ṹ�� 
	for(i=s;i<100;i++){
		printf("���������(������p=-1ʱ����¼��)��p=\n");
		scanf("%d",&p);
		if(p==-1){//�ж��Ƿ�Ҫ�������� 
			fclose(fp);
			return;
		}else{//�����벻Ϊ-1�������������� 
			printf("����������ѧ���������Ա�ѧ�ţ���ѧ�ɼ���Ӣ��ɼ���c�ɼ��������ɼ���\n");
			scanf("%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE);
			fprintf(fp,"%s%8s%8d%8d%8d%8d%8d",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);//����Ϣд���ļ� 
		}
	}
	fclose(fp);
}



void fdelete()//����ɾ������ 
{
	FILE*fp,*fp1;//���������ļ�ָ�� 
	int i,num;
	int f=0;
	fp=fopen("stu.txt","r");//�����ļ�ָ�룬ֻ�� 
	fp1=fopen("hh.txt","w");//�����ļ�ָ�룬ֻд 
	if(fp==NULL||fp1==NULL){//�ж��ļ��Ƿ��������� 
		printf("��ʧ��\n"); 
		exit(0);
	}else{
		printf("������Ҫɾ����Ϣ��ѧ��:\n");
		scanf("%d",&num);
		for(i=0;i<100;i++){//��������Ѱ�� 
			if(num==stu[i].num){//���ҵ���ѧ����Ϣ��� 
				printf(" ����	   �Ա�	   ѧ��	   ��ѧ	   Ӣ��	     C	   ����\n");
				printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
				f=1;
				break;
			}
		}
		if(f==0){//��δ�ҵ��������û� 
			printf("δ�ҵ���ѧԱ���뷵�أ�����");
			return;
		}
		for(i=0;i<100;i++){//���� 
			while(fscanf(fp,"%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE)!=EOF){
				if(num!=stu[i].num){//�����û����������ֲ�һ��
				fprintf(fp1,"%s%8s%8d%8d%8d%8d%8d",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);//������д���´������ļ� 
			}
		}
		}
	}
	fclose(fp);//�ر��ļ� 
	fclose(fp1);
	remove("stu.txt");//�Ƴ�ԭ�ļ� 
	rename("hh.txt","stu.txt");//�����ļ�����Ϊԭ�ļ��� 
}



void frank()//���������� 
{
	int i,j,n;
	FILE*fp;//�����ļ�ָ�� 
	struct student t;//�����µĽṹ�� 
	fp=fopen("stu.txt","r");//���ļ���ֻ�� 
	printf("-------------�ɼ��б�-------------\n");
	printf("                                  \n");
	printf(" ����	   �Ա�	   ѧ��	   ��ѧ	   Ӣ��	     C	   ����\n");
	for(i=0;fscanf(fp,"%s %s %d %d %d %d %d",&stu[i].nam,&stu[i].gender,&stu[i].num,&stu[i].Maths,&stu[i].English,&stu[i].C,&stu[i].PE)!=EOF;i++){
		printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
	}
	fclose(fp);
	n=i;
	for(i=0;i<n;i++){//ð�ݷ����� 
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
	printf("-------------�ɼ��б�-------------\n");
	printf("                                  \n");
	printf(" ����	   �Ա�	   ѧ��	   ��ѧ	   Ӣ��	     C	   ����\n");
    for(i=0;i<n;i++){
    	fprintf(fp,"%s%8s%8d%8d%8d%8d%8d",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);//������õ���Ϣд���ļ� 
    	printf("%s%8s%8d%8d%8d%8d%8d\n",stu[i].nam,stu[i].gender,stu[i].num,stu[i].Maths,stu[i].English,stu[i].C,stu[i].PE);
    }
    printf("----------------------------------\n");
    fclose(fp);
}




int main()//���������� 
{
	int n;
	for(;;){
	printf("\n");
	printf("-------------------------------------------------------------\n");
	printf(" ��ӭ����ѧ����Ϣ����ϵͳ \n");
	printf(" ���˵� ��\n");
	printf(" \n");
	printf(" 1.¼�����ݡ� ��\n");
	printf(" 2.������ݡ� ��\n");
	printf(" 3.�������ݡ� ��\n");
	printf(" 4.������ݡ� ��\n");
	printf(" 5.ɾ�����ݡ� ��\n");
	printf(" 6.�ɼ������ ��\n");
	printf(" 7.�˳�ϵͳ�� ��\n");
	printf("--------------------------------------------------------------\n");
	printf("������ѡ����(1-7):\n");
	scanf("%d",&n);
	if(n>0&&n<8){
		switch(n){
			case 1:finput();break;
			case 2:list();break;
			case 3:fsearch();break;
			case 4:fadd();break;
			case 5:fdelete();break;
			case 6:frank();break;
			case 7:printf("* ллʹ��! *\n");
                   printf("* �ټ�! *\n");
                   printf("* *\n");
                   printf("------------------------------------------------\n");
                   exit(0);  
		}
	}else{
		printf(" �������! \n");
		printf(" ���˳�! \n");
		break;
	}
	}
}
