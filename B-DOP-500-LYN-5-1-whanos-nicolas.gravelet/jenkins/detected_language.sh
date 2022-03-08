#!/bin/bash

if [ -f Makefile ]
then
    echo "C"
elif [ -f ./app/pom.xml ]
then
    echo "java"
elif [ -f package.json ]
then
    echo "javaScript"
elif [ -f requirements.txt ]
then
    echo "python"
elif [ -f ./app/main.bf ]
then
    echo "befunge"
else
    echo "no language detected"
fi
