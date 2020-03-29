#!/bin/bash
DIR=$(ls)
select CHOICE in $DIR
do
	echo $CHOICE
	if [ -f $CHOICE ]; then
		less $CHOICE
		break
	else
		echo "Select a regular file"
	fi
done
