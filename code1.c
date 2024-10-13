/*
Name: Jaydee Brown
KUID: 3140576
Lab: Wed, 1PM
Project Desc: Takes a file input of sales over a 12 month period, prints sales, averages, 
higher/lowest sale months, averages*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struc to store sales and month vals
typedef struct{
    float sales;
    char month[16];
    } sale_month;
//comparison operator for sort
int compare(const void *a, const void *b) {
  
    sale_month *saleA = (sale_month *)a;
    sale_month *saleB = (sale_month *)b;
  
    return ((saleA->sales > saleB->sales) - (saleA->sales < saleB->sales));
}
void print_min_max_average(sale_month* dataset){ //prints min, max and average sales
    int min_pos = 0;
    int max_pos = 0;
    float sum = 0; //sum of values in array
    //iterates through structure and compares min and max values, if num is larger than current max, sets its position as new max
    for(int i = 0;i<12;i++){
        //min-max
        sale_month* p = &dataset[i];
        sale_month* min = &dataset[min_pos];
        sale_month* max = &dataset[max_pos];
        if(p->sales<min->sales){
            min_pos=i;
        }
        if(p->sales>max->sales){
            max_pos=i;
        }
        //average
        sum += p->sales;
    }
    float average = sum/12;
    printf("\nSales Summary Report:\n\nMinimum Sales:\t%.2f (%s)\nMaximum Sales:\t%.2f (%s)\nAverage Sales:\t%.2f",dataset[min_pos].sales,dataset[min_pos].month,dataset[max_pos].sales,dataset[max_pos].month,average);
};

void print_6_month_avg(sale_month* dataset){
    printf("\nSix-Month Moving Average Report: \n\n");
    for(int i = 0;i<=6;i++){
        float sum=0;
        float average;
        for(int n=i;n<i+6;n++)
            sum += dataset[n].sales;
        average = sum/6.0;
        printf("%s-%s\t%.2f\n",dataset[i].month,dataset[i+5].month,average);
    }
}

void sort_and_print(sale_month* dataset){ //sorts and prints using qsort
    qsort(dataset,12,sizeof(dataset),compare);
    //print
    printf("\nMonth\tSales\n\n");
    for(int i = 0; i < 12; i++) {
        printf("%s\t%.2f\n", dataset[i].month, dataset[i].sales);    
    }  
}

int main(){
    //char file_name[255];
    FILE *sales_report;

    //accepts user input with basic input checking and opens file if exists
    /*printf("Input file name: ");
    scanf("%254[^\n]",file_name); */
    char file_name[] = "salesreport.txt"; //debug only
    sales_report=fopen(file_name,"r");
    if(sales_report != NULL){
        printf("Opening File...\n");
    } else {
        printf("Invalid file! Quitting program!");
        exit(1);
    }
    //populates structure
    sale_month sale[12];

    for(int i = 0;i<12;i++){
        fscanf(sales_report, "%f", &sale[i].sales);
    }
    char months[12][16] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    
    for(int i = 0;i<12;i++){
        strcpy(sale[i].month,months[i]);
    }
    fclose(sales_report);
    //prints sales per month

    printf("\nMonthly Sales Reports for 2024:\n\nMonth\tSales\n");
    for(int i = 0;i<12;i++){
        printf("%s\t%.2f\n",sale[i].month,sale[i].sales);
    }
    //min-max-average
    print_min_max_average(sale);

    //moving average
    print_6_month_avg(sale);
    //sort + print
    sort_and_print(sale);
};


