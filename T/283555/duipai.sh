#!/bin/bash

rm ./test/1.in

echo "Start" > ./test/1.out
echo "Start" > ./test/2.out

diff ./test/1.out ./test/2.out

until [ -n "$(diff ./test/1.out ./test/2.out)" ]; do
    echo "Gen..."
    ./gen
    echo "Run 283555"
    ./283555 < ./test/1.in > ./test/1.out
    echo "Run Baoli"
    ./baoli < ./test/1.in > ./test/2.out
    rm ./test/1.in
done