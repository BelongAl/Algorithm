#!/bin/bash 

proc()
{
  ba=""
  lable=('|' '\\' '-' '/')
  index = 0
  for(( i=0; i<100; i++ ))
  do 
    printf "[%-100s][%d%%][%c]\r" "$bar" "$i" "${lable[$index]}"
    sleep 0.1
    bar=$bar'#'
    ((index++))
    ((index %= 4))
  done
  printf "\n"
} 

main()
{
  proc 
}

main 

#myfun()
#{
#  echo "hello myfun"
#}
#myfun

#read d
# -eq -lt -le -gt -ge -ne 
#if [ $d -eq 1 ];then
#  echo "1+1"
#elif [ $d -eq 2 ];then 
#  echo "2+2"
#else
#  echo $d
#fi

#read s

#for i in {1..100}
#do 
#  echo $i
#done 

#i=0
#for((; i < 100; i++))
#do
#  echo "hello world: $i"
#done

#if [ "$s" == "hello" ];then
#
#echo "HELLO"
#elif [ "$s" == "world" ];then  
#  echo "WORLD"
#else ``
#  echo "$s"
#fi

#printf "%s\n" $s
#echo "hello: $s"
