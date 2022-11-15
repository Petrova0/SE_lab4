#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
using namespace std;

#define INT 1 
#define CHAR 2
#define STRING 3

#define INPUT_TIMES 50

char generateChar()
{
    char c;
    int flagCase = rand() % 2;//flagCase用来控制产生的字母是大写还是小写
    if (flagCase == 0)
        c = 'A' + rand() % 26;
    else
        c = 'a' + rand() % 26;
    return c;
}


int main()
{
    
    int length;
    ifstream formatFile;
    formatFile.open("stdin_format.txt");
    formatFile.seekg(0, std::ios::end);
    length = formatFile.tellg();           
    formatFile.seekg(0, std::ios::beg);    

    char * data = new char[length];   
    formatFile.read(data, length);      
    //char data[200];

    //formatFile >> data; 
    ofstream inputFileForOj;
    inputFileForOj.open("input.txt", std::ios::out | std::ios::app); 

    char space_delimiter[] = " ";
    char types[10][15];
    int TypeAndRange[10][3];//假设OJ程序最大接收10个输入


    //按空格分割，每个types[cnt]里存一个type的信息(按字符串形式存)
    char* resultTemp = strtok(data, space_delimiter);
    int cnt = 0;
    while (resultTemp != NULL) {
        strcpy(types[cnt], resultTemp);//
        resultTemp = strtok(NULL, space_delimiter);
        cnt++;
    }


    //[i][0]存类型，[i][1]存左范围,[i][2]存右范围,
    for (int i = 0; i < cnt; i++) {
        char s[15];
        strcpy(s, types[i]);
        if (strcmp(s, "char") == 0){
            TypeAndRange[i][0] = CHAR;
        }
        else {
            char* s_type = strtok(s, "(");
            if (strcmp(s_type, "int") == 0)
                TypeAndRange[i][0] = INT;
            else if (strcmp(s_type, "string") == 0)
                TypeAndRange[i][0] = STRING;
            int returnValue;
            char num1[10];
            char num2[10];
            returnValue = sscanf(types[i], "%*[^(](%[^,])", num1);
            returnValue = sscanf(types[i], "%*[^,],%[^)])", num2);
            TypeAndRange[i][1] = atoi(num1);
            TypeAndRange[i][2] = atoi(num2);
        }
    }

    
    for (int i = 1; i <= INPUT_TIMES; i++) {
        for (int j = 0; j < cnt; j++) {
            switch (TypeAndRange[j][0]) {
                case(INT): {
                    int rangeINT = TypeAndRange[j][2] - TypeAndRange[j][1] + 1;
                    inputFileForOj << (TypeAndRange[j][1] + rand() % rangeINT);
                    break;
                }
                case(CHAR): {
                    inputFileForOj << generateChar();
                    break;
                }
                case(STRING): {
                    int rangeSTRING = TypeAndRange[j][2] - TypeAndRange[j][1] + 1;
                    int len = TypeAndRange[j][1] + rand() % rangeSTRING;
                    for (int w = 0; w < len; w++) {
                        inputFileForOj << generateChar();
                    }
                    break;
                }
            }
            if (j != cnt-1)
                inputFileForOj << " ";
            else
                inputFileForOj << endl;
        }
    }

    formatFile.close();
    inputFileForOj.close();
    return 0;
}