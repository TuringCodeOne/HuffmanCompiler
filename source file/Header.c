#pragma once

#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"Header.h"
#define SIZE 1024

//void HuffmanCoding(HuffmanTree HT, HuffmanCode HC, int *w, int n)
//{
//	/*存放n个字符的权值，构造Huffman树HT，并求出n个字符的haffuman编码HC*/
//	int i, j, m, c, start, s1, s2, f;
//	HuffmanTree p;
//	char *cd;
//	if (n <= 1) exit(0);
//	m = 2 * n - 1;
//
//	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
//
//	for (p = HT, i = 1; i <= n; i++) {
//		p[i].weight = w[i];
//		p[i].parent = 0;
//		p[i].lchild = 0;
//		p[i].rchild = 0;
//	}
//
//	for (; i <= m; i++) {
//		p[i].weight = 0;
//		p[i].parent = 0;
//		p[i].lchild = 0;
//		p[i].rchild = 0;
//	}
//
//
//	for (i = n + 1; i <= m; i++) {
//		j = 1;
//		p = HT;
//		while (j <= i - 1 && p[j].parent != 0)
//			j++;
//		s1 = j;
//
//		while (j <= i - 1) {
//			if (p[j].parent == 0 && p[j].weight < p[s1].weight)
//				s1 = j;
//			j++;
//		}
//
//		p[s1].parent = i;
//		j = 1;
//		p = HT;
//		while (j <= i - 1 && p[j].parent != 0)
//			j++;
//		s2 = j;
//
//		while (j <= i - 1) {
//			if (p[j].parent == 0 && p[j].weight < p[s2].weight)
//				s2 = j;
//			j++;
//		}
//
//		if (s1 > s2) {
//			j = s1;
//			s1 = s2;
//			s2 = j;
//		}
//
//		HT[s1].parent = i;
//		HT[s2].parent = i;
//		HT[i].lchild = s1;
//		HT[i].rchild = s2;
//		HT[i].weight = HT[s1].weight + HT[s2].weight;
//	}
//	
//	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
//	cd = (char *)malloc(n * sizeof(char));
//	cd[n - 1] = '\0';
//	for (i = 1; i <= n; i++) {
//		start = n - 1;
//		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
//			if (HT[f].lchild == c)
//				cd[--start] = '0';
//			else
//				cd[--start] = '1';
//		}
//		HC[i] = (char *)malloc((n - start) * sizeof(char));
//		strcpy(HC[i], cd + start);
//	}
//	free(cd);
//
//
//}
HuffmanCode HuffmanCoding(HuffmanTree HT, int *w, int n)
{
	/*w存放n个字符的权值，构造Huffman树HT，并求出n个字符的haffuman编码HC*/
	int i, j, m, c, start, s1, s2, f;
	HuffmanTree p;
	char *cd;
	if (n <= 1) exit(0);
	m = 2 * n - 1;



	for (p = HT, i = 1; i <= n; i++) {
		p[i].weight = w[i];
		p[i].parent = 0;
		p[i].lchild = 0;
		p[i].rchild = 0;
	}

	for (; i <= m; i++) {
		p[i].weight = 0;
		p[i].parent = 0;
		p[i].lchild = 0;
		p[i].rchild = 0;
	}


	for (i = n + 1; i <= m; i++) {
		j = 1;
		p = HT;
		while (j <= i - 1 && p[j].parent != 0)
			j++;
		s1 = j;

		while (j <= i - 1) {
			if (p[j].parent == 0 && p[j].weight < p[s1].weight)
				s1 = j;
			j++;
		}

		p[s1].parent = i;
		j = 1;
		p = HT;
		while (j <= i - 1 && p[j].parent != 0)
			j++;
		s2 = j;

		while (j <= i - 1) {
			if (p[j].parent == 0 && p[j].weight < p[s2].weight)
				s2 = j;
			j++;
		}

		if (s1 > s2) {
			j = s1;
			s1 = s2;
			s2 = j;
		}

		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	FILE *copy;
	copy = fopen("copyData.bin", "wb");
	for (i = 1; i <= 2 * n; i++) {
		fwrite(&HT[i].weight, sizeof(unsigned int), 1, copy);
		fwrite(&HT[i].parent, sizeof(unsigned int), 1, copy);
		fwrite(&HT[i].lchild, sizeof(unsigned int), 1, copy);
		fwrite(&HT[i].rchild, sizeof(unsigned int), 1, copy);
	}
	fclose(copy);


	/*for (int i = 1; i <= 2*n; i++)
		printf("%3d %3d %3d %3d %3d\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);*/
	HuffmanCode HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	cd = (char *)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (i = 1; i <= n; i++) {
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
			if (HT[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		HC[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy(HC[i], cd + start);
	}
	free(cd);
	return HC;


}



arrychar initialHarfman(HuffmanTree HT,int n) {

	int *percent;

	arrychar code = (arrychar)malloc((n + 1) * sizeof(arry));
	
	int m = 2 * n - 1;
	percent = (int*)malloc((n + 1) * sizeof(int));

	for (int i = 1; i <= n; i++) {
		bool isbreak=true;
		char choice;
		while (isbreak) {
			setbuf(stdin, NULL);
			printf("请输入第%d个字符：", i);
			choice = ruleScanf(false);
			if (i == 1) isbreak = false;
			for (int j = 1; j < i; j++) {
				if (choice == code[j].character) {
					printf("\n-----此次输入与第%d次输入相同，请重新输入!-----\n",j);
					isbreak = true;
					break;
				}
				else {
					isbreak = false;
					break;
				}
			}
		}
		code[i].character = choice;
		printf("\t权值:");
		scanf("%d", &percent[i]);
	}
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	HuffmanCode HC=HuffmanCoding(HT,percent, n);
	for (int i = 1; i <= n; i++)
		strcpy(code[i].longChar, HC[i]);


	FILE *openfile;
	openfile = fopen("hfmTree.txt", "w");
	if (openfile == NULL) {
		printf("未找到此文件，请确保文件路径正确后重试！\n");
		exit(0);
	}
	//fprintf(openfile, "%d\n", n);
	for (int i = 1; i <= n; i++) {
		fprintf(openfile, "%c ", code[i].character);
		fprintf(openfile, "%s\n", code[i].longChar);
	}
	fclose(openfile);
	printf("\n成功生成Haffman编码，请到hfmTree.txt查看吧！\n");
	gets();
	return code;
}




void enCoding(arrychar code,int n) {
	char tocode[SIZE];
	int i = 0;

	FILE *ToBeTran;
	ToBeTran = fopen("ToBeTran.txt", "r");
	if (ToBeTran == NULL) {
		printf("未找到此文件，请确保文件路径正确后重试！\n");
		exit(0);
	}
	while (!feof(ToBeTran)) {
		fscanf(ToBeTran, "%c", &tocode[i]);
		i++;
	}
	tocode[i] ='\0';/*字符串结尾标记，方便输出检验*/
	fclose(ToBeTran);
	/*puts(tocode);*///在运行过程中通过输出来检验是否读取成功

	FILE *codeFile;
	codeFile = fopen("codeFile.txt", "w");
	if (codeFile == NULL) {
		printf("未找到此文件，请确保文件路径正确后重试！\n");
		exit(0);
	}
		for (int j = 0; j < i; j++) {
			for(int k=1;k<=n;k++)
				if (code[k].character==tocode[j]) {
					fprintf(codeFile, "%s", code[k].longChar);
				}
		}
	fclose(codeFile);
	printf("完成编码，请到codeFile.txt中查看吧！\n");
}



void deCoding(arrychar code,int n) {
	FILE *codeFile;
	codeFile = fopen("codeFile.txt", "r");
	if (codeFile == NULL) {
		printf("未找到此文件，请确保文件路径正确后重试！\n");
		exit(0);
	}
	
	FILE *text;
	text = fopen("TextFile.txt", "w");
	if (text == NULL) {
		printf("未找到此文件，请确保文件路径正确后重试！\n");
		exit(0);
	}

	char ch;
	char temp[SIZE];
	char voidStr[] = "";
	int i = 0;
	do {
		ch = fgetc(codeFile);/*读写单个字符getc*/
		if (ch == EOF)
			break;
		temp[i++] = ch;
		temp[i] = '\0';
		for (int j = 1; j <= n; j++) {
			if (strcmp(temp, code[j].longChar) == 0) {
				fprintf(text, "%c", code[j].character);
				strcpy(temp, voidStr);
				i = 0;
			}
		}
	} while (1);

	fclose(text);
	fclose(codeFile);
	printf("译码成功，请到TextFile.txt中查看吧！\n");
}





void printCodeW() {
	FILE *prin;
	prin = fopen("codeFile.txt", "r");
	if (prin == NULL) {
		printf("未找到此文件，请确保文件路径正确后重试！\n");
		exit(0);
	}

	FILE *codeprin;
	codeprin = fopen("CodePrin.txt", "w");
	if (codeprin == NULL) {
		printf("未找到此文件，请确保文件路径正确后重试！\n");
		exit(0);
	}

	unsigned short int i = 0;
	char ch = fgetc(prin);
	while (ch != EOF) {
		putchar(ch);
		fprintf(codeprin, "%c", ch);
		ch = fgetc(prin);
		i++;
		if (i % 50 == 0) {
			printf("\n");
			fprintf(codeprin, "\n");
			i = 0;
		}
	}
	fclose(codeprin);
	fclose(prin);
	printf("\n\n此形式编码已成功写入CodePrin.txt文件夹！\n");

}




void printTreeW(arrychar code,int n) {
	HuffmanTree HT = (HuffmanTree)malloc((2*n) * sizeof(HTNode));
	
	
	FILE *copy;
	copy = fopen("copyData.bin", "rb");
	if (copy == NULL) {
		printf(" 文件打开失败，请重试！");
		exit(0);
	}
	for (int i = 1; i <2 * n; i++) {
		fread(&HT[i].weight, sizeof(unsigned int), 1, copy);
		fread(&HT[i].parent, sizeof(unsigned int), 1, copy);
		fread(&HT[i].lchild, sizeof(unsigned int), 1, copy);
		fread(&HT[i].rchild, sizeof(unsigned int), 1, copy);
	}
	fclose(copy);
	for (int i = 1; i <=n; i++)
		printf("%c %5d %5d %5d %5d\n", code[i].character, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	for (int i = n+1; i <2*n; i++)
		printf("- %5d %5d %5d %5d\n",  HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);

	//打印树函数接口

	printree(HT, 2 * n - 1);
	free(HT);

}

void exitSystem() {
	printf("您已成功离开译码器！欢迎再次使用\n");
	exit(0);
}



char ruleScanf(bool which) {


	char p[1000];
	if(which)
	printf("请选择您要使用的功能：");

	gets(p);

		if (strlen(p) == 1)
			return p[0];
		else {
			printf("-----字符不合法，请重新选择！-----\n");
			ruleScanf(which);
		}
}




int number = 0;
void coprint(HuffmanTree start, HuffmanTree HT)
{
	char t = " ";
	int n = 0;
	if (start != HT)
	{
		number++;
		coprint(HT + start->rchild, HT);
		if (start->lchild != NULL && start->rchild != NULL)  t = '<';
		while (n<5 * number - 1)
		{
			printf(" ");
			n++;
		}
		printf("%d", start->weight);
		printf(" \n");
		coprint(HT + start->lchild, HT);
		number--;
	}
}
void printree(HuffmanTree HT, int w)
{
	HuffmanTree p;
	p = HT + w;
	coprint(p, HT);
}
