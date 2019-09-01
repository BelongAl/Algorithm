#include<stdio.h>

int maxProfit(int *price , int priceSize)
{
  int i = 0;
  int buy = 0;
  int sell = 0;
  int profit = 0;
  for(i = 0; i < priceSize; i++)
  {
    if(price[i] < price[i + 1] && buy == 0)
    {
      buy = price[i];
    }
    else if(price[i] >  price[i+1] && sell == 0 && buy != 0)
    {
      sell = price[i];
    }
    if(sell != 0)
    {
      profit = (sell - buy)+profit;
      sell = 0;
      buy = 0;
    }
  }
  return profit;
}
int main()
{
  int arr[] = {7,1,5,3,6,4};
  int ret = maxProfit(arr,sizeof(arr)/sizeof(arr[0]));
  printf("%d\n",ret);
  return 0;
}
