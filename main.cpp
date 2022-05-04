#include <iostream>
#include <stdio.h>
#include <string.h>
#include "thread"

//rad extensions,then you can batch scan with xray
using namespace std;
int main(int argv,char *argc[]) {
    if(argv < 4)
    {
        cout << "readme:>>>" <<endl;
        cout << "说明>>>" <<  endl;
        cout << "使用方法：>>>" << endl;
        cout << "先开启一个端口6666，然后再读取url.txt爬行>>>" << endl;
        cout << "extensions_with_rad rad.exe 127.0.0.1:6666 url.txt>>>" << endl;
    }else if(argv == 4)
    {
        char geturl[1024]  = {0};
        int command = argv;
        char rad[1024] = {0};
        char xray[1024] = {0};
        strcpy(rad,argc[1]);
        strcpy
        (xray,argc[2]);
        FILE *url = fopen(argc[3],"r+");
        if(!url)
        {
            printf("文件打开失败");
            return 0;
        }
        while(!feof(url))
        {
            memset(geturl,0,sizeof(geturl));
            fgets(geturl,sizeof(geturl),url);
            char turl[1024] = {0};
            strncpy(turl,geturl,strlen(geturl)-1);
            char runp[1024] = {0};
            sprintf(runp,"%s -t %s --http-proxy %s",rad,turl,xray);
            system(runp);
            _sleep(30);
        }
        fclose(url);
    }




    return 0;
}
