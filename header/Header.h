#pragma once
#include<stdio.h>
#include<stdbool.h>
typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;                  //Huffman树节点类型

typedef char** HuffmanCode;           //Huffman编码类型

typedef struct {
	char character;
	char longChar[20];
}arry, *arrychar;

HuffmanCode HuffmanCoding(HuffmanTree HT, int *w, int n);



arrychar initialHarfman(HuffmanTree HT,int n);
void enCoding(arrychar code,int n); 
void deCoding(arrychar code,int n);
void printCodeW(); 
void printTreeW(arrychar code,int n); 
void exitSystem(); 


char ruleScanf(bool which);

void coprint(HuffmanTree start, HuffmanTree HT);
void printree(HuffmanTree HT, int w);