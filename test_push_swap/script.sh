#!/usr/bin/zsh

RED="\033[0;31m"
GREEN="\033[0;32m"
NC="\033[0m"

make -C ../..
cp ../../push_swap .
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
	echo -n ""
else
	echo "${RED}KO \n${RAND}${NC}"
	RES=1
fi

done

if [ ${RES} = 0 ]; then
	echo "${GREEN}OK${NC}"
else
	echo -n ""
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
	echo -n ""
else
	echo "${RED}KO \n${RAND}${NC}"
	RES=1
fi

done

if [ ${RES} = 0 ]; then
	echo "${GREEN}OK${NC}"
else
	echo -n ""
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
	echo -n ""	
else
	echo "${RED}KO \n${RAND}${NC}"
	RES=1
fi

done

if [ ${RES} = 0 ]; then
	echo "${GREEN}OK${NC}"
else
	echo -n ""
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
	echo -n ""
else
	echo "${RED}KO \n${RAND}${NC}"
	RES=1
fi

done

if [ ${RES} = 0 ]; then
	echo "${GREEN}OK${NC}"
else
	echo -n ""
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


echo -n "leaks:"

R=0
for i in {1..101}
do

RAND=$(./a.out ${i})
OUTPUT=$(valgrind --log-file="val" ./push_swap $RAND | ./checker $RAND)

if [ "$OUTPUT" = "OK" ]; then
	echo -n ""
else
	echo "${RED}KO \n${RAND}${NC}"
	RES=1
fi

if grep "no leaks are possible" val > /dev/null && grep "0 context" val > /dev/null
then echo -n ""
else echo "${RED}leaks with stack of size: ${i} \n ${RAND}" ; cat val; OQEFO=1 ; echo "${NC}"
fi

done

if [ OQEFO ];
then echo "${GREEN} OK${NC}"
else secho -n ""
fi

make clean -C ../..
rm push_swap a.out