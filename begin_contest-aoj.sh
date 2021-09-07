#!/bin/bash

cd `dirname $0`
dir=`pwd`

echo $dir

contest=$1
number=$2


echo "Create contest directory..."
mkdir $contest
cd $contest


echo "Create contest number directory..."
mkdir $number
cd $number


echo "Create files."

# cpp file template
template=$(cat <<EOS
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;

    int result { 0 };

    ////////////////////
    // Write your code.
    ////////////////////

    cout << result << endl;

    return 0;
}
EOS
)

filelist=("a" "b" "c" "d")

for ((i=1; i<=10; i++)); do
for file in ${filelist[@]}
do
    touch ${i}_${file}.cpp
    echo "$template" > ${i}_${file}.cpp
    echo "created file: ${i}_${file}.cpp"
done
done

echo "Add executable into CMakeLists.txt"

cd ..

# Write settings into CMakeLists.txt
echo "" >> ./CMakeLists.txt
echo "# Contest $contest $number" >> ./CMakeLists.txt

for ((i=1; i<=10; i++)); do
for file in ${filelist[@]}
do
    echo "add_executable(${number}_${i}_${file} $number/${i}_${file}.cpp)" >> ./CMakeLists.txt
done
done