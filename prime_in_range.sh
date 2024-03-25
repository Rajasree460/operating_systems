#prime in range
read -p "enter the upper lim: " n
echo "prime no. in b/w 1 and $n"
for (( i=1; i<=n; i++ ))
do
flag=0
for (( j=2; j*j<i+1; j++ )) 
do
if [[ $(( i % j )) -eq 0 ]] #if [[ $i % $j -eq 0 ]]
then
flag=1
break #exit
fi
done
if [[ flag -eq 0 ]]
then
echo "$i- prime no"
fi
done
