#include"Header.h"
#include<stdio.h>
#pragma warning(disable:4996)


int main() {
	HuffmanTree HT = NULL;
	arrychar CODE = NULL;
	char *code = NULL;
	int n = 0;
	char choice;
	//int w[9] = { 0,5,29,7,8,14,23,3,11 };
	//int n = 8;
	//HuffmanCoding(HT, HC, w, n);
	while (1) {
		printf("---------- Huffman 编/译码器----------\n");
		printf("\n[1]初始化  [2]编码  [3]译码  [4]打印编码文件  [5]打印Huffman树  [6]离开\n\n");
		choice = ruleScanf(true);
		switch (choice) {
		case '1':	printf("请输入字符集大小：");
			scanf("%d", &n);
			CODE = initialHarfman(HT, n);
			break;
		case '2':if (n != 0)
					enCoding(CODE, n);
				 else {
					 FILE *hfm;
					 hfm = fopen("hfmTree.txt", "r");
					 if (hfm == NULL) {
						 printf("文件打开失败！！");
						 exit(0);
					 }
					 CODE = (arrychar)malloc(2014*sizeof(arry));
					 int i = 1;
					 while (fscanf(hfm, "%c %s\n", &CODE[i].character, &CODE[i].longChar) != EOF) {
						 n++;
						 i++;
					 }
					 fclose(hfm);
					 enCoding(CODE, n);
				 }

				 break;
		case '3':if (n != 0)
			deCoding(CODE, n);
				 else {
					 FILE *hfm;
					 hfm = fopen("hfmTree.txt", "r");
					 if (hfm == NULL) {
						 printf("文件打开失败！！");
						 exit(0);
					 }
					 CODE = (arrychar)malloc(2014 * sizeof(arry));
					 int i = 1;
					 while (fscanf(hfm, "%c %s\n", &CODE[i].character, &CODE[i].longChar) != EOF) {
						 n++;
						 i++;
					 }
					 fclose(hfm);
					 deCoding(CODE, n);
				 } 
				 break;
		case '4':printCodeW(); break;
		case '5':if (n != 0)
			printTreeW(CODE,n);
			else {
				FILE *hfm;
				hfm = fopen("hfmTree.txt", "r");
				if (hfm == NULL) {
					printf("文件打开失败！！");
					exit(0);
				}
				CODE = (arrychar)malloc(2014 * sizeof(arry));
				int i = 1;
				while (fscanf(hfm, "%c %s\n", &CODE[i].character, &CODE[i].longChar) != EOF) {
					n++;
					i++;
				}
				fclose(hfm);
				printTreeW(CODE,n);
			}  break;
		case '6':exitSystem(); break;
		default:printf("----没有此选项，请重试----\n");
		}
		printf("\n");
	}
	return 0;
}