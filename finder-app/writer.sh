#!/bin/bash

writefile=$1
writestr=$2

if [ $# != 2 ]
then
    echo "Requiring 2 arguments"
    exit 1
fi

if [ -f $writefile ]
then
    echo "Deleting $writefile because it exists!"
    #rm -f $writefile
fi

folderName=`dirname $writefile`
if [[ ! -d $folderName ]]
then 
    echo "Creating the parent folder: $folderName"
    mkdir -p $folderName
fi

echo $writestr > $writefile

