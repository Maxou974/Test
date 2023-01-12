#!/usr/bin/zsh

RED="\033[0;31m"
GREEN="\033[0;32m"
NC="\033[0m"

c++ main.cpp
echo "TEST 3"

for i in {1..10}
do

RAND=$(./a.out 3)
OUTPUT=$(./push_swap $RAND | ./checker $RAND)

if [ "$OUTPUT" = "OK" ]; then
	echo "${GREEN}OK${NC}"
else
	echo "${RED}KO\n${RAND}${NC}"
fi

done




echo "TEST 5"

for i in {1..10}
do

RAND=$(./a.out 5)
OUTPUT=$(./push_swap $RAND | ./checker $RAND)

if [ "$OUTPUT" = "OK" ]; then
	echo "${GREEN}OK${NC}"
else
	echo "${RED}KO\n${RAND}${NC}"
fi

done


echo "TEST 100"

for i in {1..10}
do

RAND=$(./a.out 100)
OUTPUT=$(./push_swap $RAND | ./checker $RAND)

if [ "$OUTPUT" = "OK" ]; then
	echo "${GREEN}OK${NC}"
else
	echo "${RED}KO\n${RAND}${NC}"
fi

done

echo "TEST 500"

for i in {1..10}
do

RAND=$(./a.out 500)
OUTPUT=$(./push_swap $RAND | ./checker $RAND)

if [ "$OUTPUT" = "OK" ]; then
	echo "${GREEN}OK${NC}"
else
	echo "${RED}KO\n${RAND}${NC}"
fi

done