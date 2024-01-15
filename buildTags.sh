#!/bin/bash

cd src && ctags -R .
cd hal && ctags -R ../ && cd ..
