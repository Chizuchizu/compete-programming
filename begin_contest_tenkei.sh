#!/bin/bash

cd ed_90
dir=`pwd`

echo $dir

#contest=$1
#number=$2


#echo "Create contest directory..."
#mkdir $contest
#cd $contest


#echo "Create contest number directory..."
#mkdir $number
#cd $number


echo "Create files."

# cpp file template
template=$(cat <<EOS
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {

    return 0;
}
EOS
)


for file in {1..90}
do
    touch ${file}.cpp
    echo "$template" > ${file}.cpp
    echo "created file: ${file}.cpp"
done

echo "Add executable into CMakeLists.txt"

# Write settings into CMakeLists.txt
echo "" >> ./CMakeLists.txt
echo "# Contest ed_90" >> ./CMakeLists.txt

for file in {1..90}
do
    echo "add_executable(ed_90_${file} ${file}.cpp)" >> ./CMakeLists.txt
done