#!/bin/bash

rm -f *.zip

win32-configure && make clean && make zip

win64-configure && make clean && make zip

if [ -d ~/public_html/win/x86_32 ]; then
	cp *i686*.zip ~/public_html/win/x86_32
fi

if [ -d ~/public_html/win/x86_64 ]; then
	cp *.x86_64*.zip	~/public_html/win/x86_64
fi

