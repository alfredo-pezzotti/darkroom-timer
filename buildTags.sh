#!/bin/bash

cd src         && ctags -R .
cd application && ctags -R ../ && cd ..
cd hal         && ctags -R ../ && cd ..
cd util        && ctags -R ../ && cd ..
