#!/usr/bin/zsh

RED="\033[0;31m"
GREEN="\033[0;32m"
NC="\033[0m"

c++ main.cpp


for j in {1..25}

do
echo "TEST ${j}"
RES=0

for i in {1..500}
do

RAND=$(./a.out ${j})
OUTPUT=$(./push_swap $RAND | ./checker $RAND)

if [ "$OUTPUT" = "OK" ]; then
	
else
	echo "${RED}KO \n${RAND}${NC}"
	RES=1
fi

done

if [ ${RES} = 0 ]; then
	echo "${GREEN}OK${NC}"
else

fi

done


for j in {26..100}

do
echo "TEST ${j}"
RES=0

for i in {1..100}
do

RAND=$(./a.out ${j})
OUTPUT=$(./push_swap $RAND | ./checker $RAND)

if [ "$OUTPUT" = "OK" ]; then
	
else
	echo "${RED}KO \n${RAND}${NC}"
	RES=1
fi

done

if [ ${RES} = 0 ]; then
	echo "${GREEN}OK${NC}"
else

fi

done


for j in {101..110}

do
echo "TEST ${j}"
RES=0

for i in {1..100}
do

RAND=$(./a.out ${j})
OUTPUT=$(./push_swap $RAND | ./checker $RAND)

if [ "$OUTPUT" = "OK" ]; then
	
else
	echo "${RED}KO \n${RAND}${NC}"
	RES=1
fi

done

if [ ${RES} = 0 ]; then
	echo "${GREEN}OK${NC}"
else

fi

done

for j in {500..501}

do
echo "TEST ${j}"
RES=0

for i in {1..100}
do

RAND=$(./a.out ${j})
OUTPUT=$(./push_swap $RAND | ./checker $RAND)

if [ "$OUTPUT" = "OK" ]; then

else
	echo "${RED}KO \n${RAND}${NC}"
	RES=1
fi

done

if [ ${RES} = 0 ]; then
	echo "${GREEN}OK${NC}"
else

fi

done


ret=0;
for i in {1..100}
do

RAND=$(./a.out 3)
ret=$(( $ret + $(./push_swap ${RAND} | wc -l) ))

done

ret=$(($ret / 100))

echo "3 average  : $ret" 

ret=0;
for i in {1..100}
do

RAND=$(./a.out 5)
ret=$(( $ret + $(./push_swap ${RAND} | wc -l) ))

done

ret=$(($ret / 100))

echo "5 average  : $ret" 

ret=0;
for i in {1..100}
do

RAND=$(./a.out 100)
ret=$(( $ret + $(./push_swap ${RAND} | wc -l) ))

done

ret=$(($ret / 100))

echo "100 average: $ret" 

ret=0;
for i in {1..100}
do

RAND=$(./a.out 500)
ret=$(( $ret + $(./push_swap ${RAND} | wc -l) ))

done

ret=$(($ret / 100))

echo "500 average: $ret" 

