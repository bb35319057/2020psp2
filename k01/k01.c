#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double n = 0;

extern double ave_online(double val,double ave);
extern double var_online(double val, double ave, double square_ave);

int main(void)
{
    double val;
    double ave = 0;
    double square_ave = 0;
    double var = 0;
    double u2;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        n++;
        var = var_online(val,ave,square_ave);
        square_ave = ave_online(pow(val,2), square_ave);
        ave = ave_online(val,ave);
    }

    u2 = (n/(n-1))*var;

    printf("sample mean：%.2f\n", ave);
    printf("sample variance：%.2f\n", var);
    printf("population mean (estimated)：%.2f±%.2f\n", ave,sqrt(u2/n));
    printf("population variance (estimated)：%.2f\n", u2);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    return 0;
}

double ave_online(double val,double ave){
    ave = ((n-1)*ave + val)/n;
    return ave;
 }

double var_online(double val,double ave,double square_ave){
    double var;
    var = ((n-1)*square_ave/n + pow(val,2)/n) - pow(((n-1)*ave/n + val/n),2);
    return var;
}