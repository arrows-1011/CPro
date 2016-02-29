#!/bin/bash

awk '{
if($1 ~ /.*[aA].*/) print
}'
