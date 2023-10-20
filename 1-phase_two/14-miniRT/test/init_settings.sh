#!/bin/sh

if [ -z "${LD_LIBRARY_PATH}" ];
then
    # echo "doesn't exist"
    export LD_LIBRARY_PATH=$PWD/criterion-2.4.2/lib
else
    # echo "exist"
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/criterion-2.4.2/lib
fi
