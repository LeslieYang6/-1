#include<iostream>

#include<cstring>

#include<math.h>
using namespace std;
//获得参数
void GetParameters(string p,double para[])
{
    int j=0;
    int i;
    int length=(int)p.length();
    //递归的获得每一项的系数
    for(i=0;i<100;i++)
    {
        while(p[j]!='+'&&p[j]!='x'&&p[j]!='.')
        {
            para[i]=para[i]*10+(p[j++]-'0');
        }
        //如果是浮点的系数
        if(p[j]=='.') {
            j++;
            double temp = 0;
            int k = 1;
            while (p[j] <= '9')
                temp = temp + (p[j++] - '0') / pow(10, k++);
            para[i]+=temp;
        }
        //遇到加号停止迭代
        while(p[j]!='+')
        {
            if(j+1==length)
                break;
            j++;
        }
        j++;
        if(j==length)
            break;

    }
    if(i==99&&j<length)
        cerr<<"out of bounds";

}
//加法
void add(double para1[],double para2[],double result[])
{
    for(int i=0;i<100;i++)
        result[i]=para1[i]+para2[i];
}
//减法
void subtract(double para1[],double para2[],double result[])
{
    for(int i=0;i<100;i++)
        result[i]=para1[i]-para2[i];
}

void multiple(double para1[],double para2[],double result[])
{
    int length1=-1;
    int length2=-1;
    //获得多项式的长度
    for(int i=99;i>=0;i--)
    {
        if(para1[i]!=0)
        {
            length1=i+1;
            break;
        }
    }
    for(int i=99;i>=0;i--)
    {
        if(para2[i]!=0)
        {
            length2=i+1;
            break;
        }

    }
    if(length1==-1||length2==-1)
        return;
    if(length1+length2>100)
    {
        cerr<<"out of bounds";
    }
    //第i+j项的系数等于para1[i]+parai[2]
    for(int i=0;i<length1;i++)
        for(int j=0;j<length2;j++)
        {
            result[i+j]=result[i+j]+para1[i]*para2[j];
        }
}


int main()
{
    string p;
    cin>>p;
    int q=0;
    double para1[100];
    double para2[100];
    double result[100];
    for(int b=0;b<100;b++)
       result[b]=para1[b]=para2[b]=0;
    GetParameters(p,para1);
    cin>>p;
    GetParameters(p,para2);
    multiple(para1,para2,result);
    while(q<100)
    {
        cout<<result[q]<<" ";
        q++;
    }

}


