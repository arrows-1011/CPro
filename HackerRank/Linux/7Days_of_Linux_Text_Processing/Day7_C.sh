#!/bin/bash

awk '{
f = 1
for (i = 2; i <= $1; i++){
    f = f*i;
}
if (NR != 1) {
    print f
}
}'

