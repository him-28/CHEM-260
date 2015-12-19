#!/bin/bash
int=32
float=12.3456
string="Hello"
printf "Integer= %5d\n" $int
printf "Integer= %05d\n" $int
printf "Integer= %-5d\n" $int
printf "Integer= %+5d\n" $int
printf "Float=%7.2f\n" $float
printf "Float=%7.4f\n" $float
printf "Float=%+7.2f\n" $float
printf "String=%s\n" $string
printf "String=%10s\n" $string
printf "String=%-10s\n" $string
