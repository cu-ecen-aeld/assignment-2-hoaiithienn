#!/bin/sh

filesdir=$1
searchstr=$2

if [ $# != 2 ]
then
    echo "Require 2 arguments"
    return 1
fi

if [ ! -d $filesdir ]
then
    echo "$filesdir doesn't exist"
fi

fileNum=`find -L $filesdir -type f | wc -l`
matchNum=$(expr 0)

for FILE in `find -L $filesdir -type f`
do
    echo "$FILE"
    temp=`grep -r $searchstr $FILE | wc -l`
    matchNum=$(expr $matchNum + $temp)
done

echo "The number of files are $fileNum and the number of matching lines are $matchNum"