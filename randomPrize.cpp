

/* 假设c库中有函数rand()能够生成均匀随机的0 - 65535的随机数，现有30万员工参与抽奖，请使用rand()函数
   编写一个完整的可执行程序，从这30万员工中随机抽取10万名中奖员工
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 假设这个函数 就是c库中有函数rand()能够生成均匀随机的0 - 65535的随机数
unsigned short SpecialRand(){
    return rand() % 65536;
}

unsigned int MyRand(unsigned int begin, unsigned int end);
void RandPrize();
void mySwap(unsigned int *array, unsigned int firstIndex, unsigned int secondIndex);

const unsigned int totalWorkerNum = 300000;
const unsigned int prizeWorkerMax = 100000;
unsigned int workers[totalWorkerNum];
unsigned int workerWithPrize[prizeWorkerMax];


int main(){
    for(unsigned int i=0;i<totalWorkerNum;i++){
        workers[i] = i;
    }
    
    RandPrize();

    for(unsigned int i=0;i<prizeWorkerMax;i++){
        printf("workerWithPrize %d\n", workerWithPrize[i]);
    }

    return 0;
}

void RandPrize(){
    unsigned int randSize = totalWorkerNum-1;
    unsigned int prizeLeft = prizeWorkerMax;
    while(prizeLeft>0){
        prizeLeft--;
        unsigned int workerIndex = MyRand(0, randSize);
        workerWithPrize[prizeLeft] = workers[workerIndex];
        mySwap(workers, workerIndex, randSize);
        randSize--;
    }
}

void mySwap(unsigned int *array, unsigned int firstIndex, unsigned int secondIndex){
    unsigned int tmp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = tmp;
}

unsigned int MyRand(unsigned int begin, unsigned int end){
    unsigned short first = SpecialRand();
    unsigned short second = SpecialRand();
    unsigned int num = 0;
    memcpy(&num, &first, 2);
    memcpy((unsigned char*)&num+2, &second, 2);

    // 公式
    unsigned int MAX = 0xFFFFFFFF;
    float r = (float)num/(float)MAX;
    float tmp = r*(end-begin+1);
    unsigned int result = (unsigned int)tmp + begin;

    return result;
}




















