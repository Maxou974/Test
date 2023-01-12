#!/bin/bash

c++ main.cpp

OUTPUT=$(./a.out 100)

./push_swap $OUTPUT | ./checker $OUTPUT