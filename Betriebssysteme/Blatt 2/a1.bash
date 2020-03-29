#!/bin/bash

function exists {
	if [ -e $2 ]; then
		echo "$2 existiert"
	else
		echo "$2 existiert nicht"
	fi
}

function isFileOrFolder {
	if [ ! -e $2 ]; then
		return 0
	fi
	if [ -f $2 ]; then
		echo "$2 ist eine Datei"
	elif [ -d $2 ]; then
		echo "$2 ist ein Ordner"
	else
		echo "$2 ist weder Ordner noch Datei"
	fi
}

function isSymbolicLink {
	if [ ! -d $2 ]; then
		return 0
	fi
	if [ -h $2 ]; then
		echo "$2 ist ein symbolischer Link"
	else
		echo "$2 ist kein symbolischer Link"
	fi
}

function isOwned {
	if [ ! -e $2 ]; then
		return 0
	fi
	if [ -O $2 ]; then
		echo "$2 gehört dem Benutzer"
	else
		echo "$2 gehört nicht dem Benutzer"
	fi
}

function getOwner {
	if [ ! -e $2 ]; then
		return 0
	fi
	ATTRIBUTE=($(ls -l $2))
	if [ -f $2 ]; then
		OWNER=${ATTRIBUTE[2]}
	elif [ -d $2 ]; then
		OWNER=${ATTRIBUTE[4]}
	fi
	echo "$2 gehört $OWNER"
}

exists /bin/bash $1
isFileOrFolder /bin/bash $1
isSymbolicLink /bin/bash $1
isOwned /bin/bash $1
getOwner /bin/bash $1