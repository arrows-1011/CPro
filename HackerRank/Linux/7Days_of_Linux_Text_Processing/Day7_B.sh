#!/bin/bash

awk '{
j = length($1)-1
k=1
for (i = 0; i < length($1)/2-1; i++) {
   if (substr($1, i+1, 1) != substr($1, j, 1)) {
        k = 0
        break
   }
   j--
} 
if (k == 1) {
    print $1
}
}'
